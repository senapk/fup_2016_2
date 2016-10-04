#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using namespace std;



int main(){
    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    sf::Texture tex_py;
    tex_py.loadFromFile("../black/images/pikachu.png");
    sf::Sprite spr_py(tex_py);

    spr_py.setScale(300.0/tex_py.getSize().x, 300.0/tex_py.getSize().y);

    while(janela.isOpen()){
        sf::Event evento;
        while(janela.pollEvent(evento)){
            if(evento.type == sf::Event::Closed)
                janela.close();
            if(evento.type == sf::Event::MouseButtonPressed){
                if(evento.mouseButton.button == sf::Mouse::Left){
                    if(spr_py.getGlobalBounds().contains(evento.mouseButton.x,
                                                         evento.mouseButton.y))
                        cout << "clicou" << endl;
                }
            }
        }

        //fim
        janela.clear();
        spr_py.setPosition(300, 300);
        janela.draw(spr_py);
        janela.display();
    }

    return 0;
}










