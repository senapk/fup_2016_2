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
    int casa = 128;
    int largura = 10 * casa;
    int altura = 6 * casa;

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
    pedra.x = 4 * casa;
    pedra.y = 4 * casa;
    pedra.cor = sf::Color::White;

    Elemento poste;
    poste.x = 2 * casa;
    poste.y = 2 * casa;
    poste.cor = sf::Color::Green;

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
                    if(py.x == pedra.x && py.y == pedra.y){
                        pedra.x += casa;
                    }
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
        sprite_py.setPosition(py.x, py.y);
        //carimbo.setFillColor(py.cor);
        janela.draw(sprite_py);

        //pintando bloco
        carimbo.setPosition(pedra.x, pedra.y);
        carimbo.setFillColor(pedra.cor);
        janela.draw(carimbo);

        //pintando o poste
        carimbo.setPosition(poste.x, poste.y);
        carimbo.setFillColor(poste.cor);
        janela.draw(carimbo);



        janela.display();
    }
    return 0;
}










