#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <vector>

using namespace std;

//variaveis globais
const float largura = 1000;
const float altura = 800;
const float forca = 0.002;
const float grav = 0.001;

struct Bola{
    float raio {50};
    float x;
    float y;
    float vy {0};
    float vx {0};
    sf::Color cor {sf::Color::Red};
};

void aplicar_gravidade(Bola &bola){
    bola.vy += grav;
}

void atualizar_posicao(Bola &bola){
    bola.y += bola.vy;
    bola.x += bola.vx;
}

void controlar_bola(Bola &bola,
                    sf::Keyboard::Key cima, sf::Keyboard::Key baixo,
                    sf::Keyboard::Key esq, sf::Keyboard::Key dir){
    if(sf::Keyboard::isKeyPressed(cima))
        bola.vy -= forca;
    if(sf::Keyboard::isKeyPressed(baixo))
        bola.vy += forca;
    if(sf::Keyboard::isKeyPressed(dir))
        bola.vx += forca;
    if(sf::Keyboard::isKeyPressed(esq))
        bola.vx -= forca;
}

#include <cmath>
float calcular_distancia(float ax, float ay, float bx, float by){
    return sqrt((ax - bx)*(ax - bx) + (ay - by)*(ay - by));
}

void processar_colisao(Bola &a, Bola &b){
    float acx = a.x + a.raio;
    float acy = a.y + a.raio;

    float bcx = b.x + b.raio;
    float bcy = b.y + b.raio;

    float dist = calcular_distancia(acx, acy, bcx, bcy);

    if (dist < (a.raio + b.raio)){
        std::swap(a.vx, b.vx);
        std::swap(a.vy, b.vy);
    }
}

void tratar_colisoes(Bola &bola, sf::Music &music){
    if(bola.y > (altura - 2 * bola.raio)){
        bola.vy = -bola.vy;
        bola.y = altura - 2 * bola.raio; //reposicionar
        bola.cor = sf::Color(rand() % 255, rand() % 255, rand() % 255);
       // puki.play();
    }

    if(bola.y < 0){//se a posicao y da bola passar do limite
        bola.vy = -bola.vy;//inverto a velocidade
        bola.y = 0;//reposiciono a bola
        bola.cor = sf::Color(rand() % 255, rand() % 255, rand() % 255);
        music.play();
    }

    if(bola.x < 0){
        bola.vx = -bola.vx;
        bola.x = 0;
        bola.cor = sf::Color(rand() % 255, rand() % 255, rand() % 255);
    }

    if(bola.x > (largura - 2 * bola.raio)){
        bola.vx = -bola.vx;
        bola.x = largura - 2 * bola.raio;
        bola.cor = sf::Color(rand() % 255, rand() % 255, rand() % 255);
    }
}

void pintar_bola(Bola &bola, sf::CircleShape &circulo,
                 sf::RenderWindow &janela){
    //opcao 1 - usa variavel global
    //opcao 2 - passar como parametro
    circulo.setRadius(bola.raio);
    circulo.setPosition(sf::Vector2f(bola.x, bola.y));
    circulo.setFillColor(bola.cor);
    //pintar pokebola
    janela.draw(circulo);
}

//gera um valor entre min e max
int rand_min_max(int min, int max){
    return rand() %(max - min + 1) + min;
}

int main()
{

    sf::Music puki;
    puki.openFromFile("../muitas_bolas/puk.ogg");
    //lvalue = rvalue
    int qtd = 10;
    vector<Bola> sacola;


    //faca qtd vezes
    for(int i = 0; i < qtd; i++){
        Bola bola;
        bola.x = rand_min_max(0, 900);
        bola.y = rand_min_max(0, 700);
        bola.vx = (rand_min_max(0, 21) - 10)/100.0;
        bola.vy = (rand_min_max(0, 21) - 10)/100.0;
        bola.raio = rand_min_max(20, 50);
        sacola.push_back(bola);
    }


    sf::CircleShape circulo;

    sf::RenderWindow janela(sf::VideoMode(largura, altura), "Super");
    while(janela.isOpen()){
        sf::Event evento;
        while(janela.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                janela.close();
            }
            if(evento.type == sf::Event::KeyPressed){
                if(evento.key.code == sf::Keyboard::Space){
                    //para cada bola na sacola
                    for(auto &bola : sacola){
                        bola.vx = 0;
                        bola.vy = 0;
                    }
                }
            }
        }

        //aplica a gravidade
//        for(auto &bola : sacola)
//            aplicar_gravidade(bola);


        //atualiza posicoes
        for(auto &bola : sacola)
            atualizar_posicao(bola);

        //controlam a bola A
        for(auto &bola : sacola)
            controlar_bola(bola, sf::Keyboard::Up, sf::Keyboard::Down,
                                 sf::Keyboard::Left, sf::Keyboard::Right);

        //colisões da bola A com as Paredes
        for(auto &bola : sacola)
            tratar_colisoes(bola, puki);

        //processar todos com todas
        for(int x = 0; x < qtd; x++){
            for(int y = x + 1; y < qtd; y++){
                //processar_colisao(sacola[x], sacola[y]);
            }
        }

        //limpar a janela
        janela.clear();

    //Bola a
        for(auto &bola : sacola)
            pintar_bola(bola, circulo, janela);

//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
//            circulo.setRadius(raio/2);
//            float xf = xa + raio - raio/2;
//            float yf = ya - raio;
//            circulo.setPosition(sf::Vector2f(xf, yf));
//            circulo.setFillColor(sf::Color::White);
//            janela.draw(circulo);
//        }
        janela.display();
    }
    return 0;
}


//criar a janela
//enquanto a janela estiver aberta{
//	enquanto tiver eventos na fila
//		pegar um evento
//		processa o evento
//		se evento for de fechar a tela
//			fecha a tela

//	limpa a tela
//	desenha os objetos
//	mostra os objetos
//}

//fecha a janela
