#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

struct Elemento{
    int x;
    int y;
    sf::Color cor;
};

int main()
{
    int casa = 50;
    int largura = 20 * casa;
    int altura = 12 * casa;

    sf::RectangleShape carimbo;
    carimbo.setSize(sf::Vector2f(casa, casa));

    Elemento py;
    py.x = 3 * casa;
    py.y = 5 * casa;
    py.cor = sf::Color::Yellow;

    Elemento bloco;
    bloco.x = 7 * casa;
    bloco.y = 7 * casa;
    bloco.cor = sf::Color::White;

    sf::RenderWindow janela(sf::VideoMode(largura, altura), "Super");
    while(janela.isOpen()){
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

        janela.clear();

        //pintando py
        carimbo.setPosition(py.x, py.y);
        carimbo.setFillColor(py.cor);
        janela.draw(carimbo);

        //pintando bloco
        carimbo.setPosition(bloco.x, bloco.y);
        carimbo.setFillColor(bloco.cor);
        janela.draw(carimbo);


        janela.display();
    }
    return 0;
}










