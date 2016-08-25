#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>

using namespace std;

int main()
{

    sf::Music puki;
    puki.openFromFile("../bubassauro/puk.ogg");
    //lvalue = rvalue
    float raio = 50.0;
    sf::CircleShape circulo(raio);
    float xa = 100.0, ya = 100.0;
    float vya = 0;
    float vxa = 0;

    sf::Color cor = sf::Color::Red;
    float largura = 800;
    float altura = 600;
    float forca = 0.002;


    float grav = 0.001;

    circulo.setPosition(sf::Vector2f(xa, ya));
    circulo.setFillColor(sf::Color::Magenta);

    sf::RenderWindow janela(sf::VideoMode(largura, altura), "Super");
    while(janela.isOpen()){
        sf::Event evento;
        while(janela.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                janela.close();
            }
            if(evento.type == sf::Event::KeyPressed){
                if(evento.key.code == sf::Keyboard::Space){
                    vxa = 0;
                    vya = 0;
                }
            }
        }
        vya = vya + grav;
        ya = ya + vya;
        xa = xa + vxa;

//        se up pressionada
//            puxe para cima

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            vya = vya - forca;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            vya = vya + forca;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            vxa = vxa + forca;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            vxa = vxa - forca;
        }


        if(ya > (altura - 2 * raio)){
            vya = -vya;
            ya = altura - 2 * raio; //reposicionar
            cor = sf::Color(rand() % 255, rand() % 255, rand() % 255);
            puki.play();
        }

        if(ya < 0){//se a posicao y da bola passar do limite
            vya = -vya;//inverto a velocidade
            ya = 0;//reposiciono a bola
            cor = sf::Color(rand() % 255, rand() % 255, rand() % 255);
        }

        if(xa < 0){
            vxa = -vxa;
            xa = 0;
            cor = sf::Color(rand() % 255, rand() % 255, rand() % 255);
        }

        if(xa > (largura - 2 * raio)){
            vxa = -vxa;
            xa = largura - 2 * raio;
            cor = sf::Color(rand() % 255, rand() % 255, rand() % 255);
        }

        //limpar a janela
        janela.clear();

        //configurar pokebola
        circulo.setRadius(raio);
        circulo.setPosition(sf::Vector2f(xa, ya));
        circulo.setFillColor(cor);
        //pintar pokebola
        janela.draw(circulo);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            circulo.setRadius(raio/2);
            float xf = xa + raio - raio/2;
            float yf = ya - raio;
            circulo.setPosition(sf::Vector2f(xf, yf));
            circulo.setFillColor(sf::Color::White);
            janela.draw(circulo);

        }



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
