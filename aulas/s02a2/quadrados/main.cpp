#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

int main()
{
    sf::RenderWindow janela(sf::VideoMode(largura, altura), "Super");
    while(janela.isOpen()){
        sf::Event evento;
        while(janela.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                janela.close();
            }
//            if(evento.type == sf::Event::KeyPressed){
//                if(evento.key.code == sf::Keyboard::Space){

//                }
//            }
        }

        janela.clear();
        janela.display();
    }
    return 0;
}
