#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using namespace std;

struct Elemento{
    int x; //4 bytes
    int y; //4
    int xold;//4
    int yold;//4
    sf::Color cor;
};

int main2()
{
    int casa = 128;
    int ncol = 12;
    int nlin = 6;
    int largura = ncol * casa;
    int altura = nlin * casa;

    sf::Texture tex_py;
    tex_py.loadFromFile("../quadrados/pikachu.png");
    sf::Sprite sprite_py(tex_py);

    sf::RectangleShape carimbo;
    carimbo.setSize(sf::Vector2f(casa, casa));

    Elemento py;
    py.x = 0 * casa;
    py.y = 0 * casa;
    py.cor = sf::Color::Yellow;

    Elemento pedra;
    pedra.x = 0 * casa;
    pedra.y = 1 * casa;
    pedra.cor = sf::Color::White;

    Elemento fruta;
    fruta.x = 0 * casa;
    fruta.y = 2 * casa;
    fruta.cor = sf::Color::Red;

    //obstaculos eh uma variavel do tipo vector(uma estrutura de dados inteligente)
    vector<Elemento> obstaculos(10);

    //alocacao estatica na memoria de um vetor com espaco
    //pra 10 var do tipo Elemento
    //Elemento obstaculos[10];

    for(int i = 0; i < 10; i++){
        Elemento &poste = obstaculos[i];
        poste.x = (i + 1) * casa;
        poste.y = i * casa;
        poste.cor = sf::Color::Green;
    }

    sf::RenderWindow janela(sf::VideoMode(ncol * casa, nlin * casa), "Super");
    while(janela.isOpen()){
        //inicio
        py.xold = py.x;
        py.yold = py.y;

        sf::Event evento;
        while(janela.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                janela.close();
            }
            if(evento.type == sf::Event::KeyPressed){
                if(evento.key.code == sf::Keyboard::Right){
                    py.x += casa;
                }
                if(evento.key.code == sf::Keyboard::Down){
                    py.y += casa;
                }
                if(evento.key.code == sf::Keyboard::Left){
                    py.x -= casa;
                }
                if(evento.key.code == sf::Keyboard::Up){
                    py.y -= casa;
                }
            }
        }

        //inicio
        if(py.x == largura || py.x < 0 ||
           py.y == altura || py.y < 0){
           py.x = py.xold;
           py.y = py.yold;
        }

        for(auto &poste : obstaculos){
            if(py.x == poste.x && py.y == poste.y){
                py.y = py.yold;
                py.x = py.xold;
                break;
            }
        }


        //fim

        janela.clear();



        //pintando bloco
        carimbo.setPosition(pedra.x, pedra.y);
        carimbo.setFillColor(pedra.cor);
        janela.draw(carimbo);

        carimbo.setPosition(fruta.x, fruta.y);
        carimbo.setFillColor(fruta.cor);
        janela.draw(carimbo);

        //pintando py
        sprite_py.setPosition(py.x, py.y);
        //carimbo.setFillColor(py.cor);
        janela.draw(sprite_py);


        for(auto &poste : obstaculos){
            //post é um apelido para obstaculos[i]
            carimbo.setPosition(poste.x, poste.y);
            carimbo.setFillColor(poste.cor);
            janela.draw(carimbo);
        }

        janela.display();
    }
    return 0;
}

//fazer a lista do mercantil e comprar tudo que comeca com a letra b
int main(){
    vector<string> mercantil = {"banana", "uva", "ovo", "bucha",
                                "batata", "biscoito", "bolacha", "arroz", "b"};

    for(auto &elem : mercantil){
        cout << elem << " " ;
    }
    cout << endl;//quebra de linha

    //com indice
    for(int i = 0; i < (int) mercantil.size() - 1; i++)
        if(mercantil[i + 1][0] == 'b')
            cout << mercantil[i] << " ";
    cout << endl;

//    for(auto &item : mercantil){
//        if(item.size() > 1)
//            if(item[0] == 'b' && item[1] == 'a')
//                cout << item << " ";
//    }
    cout << endl;





    return 0;
}










