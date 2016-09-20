#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

const float casa = 50.0;
//enum Dir {UP, RIGHT, DOWN, LEFL};

float rotacao = 0;

struct Par{
    int x;
    int y;
};

struct Cobra{
    vector<Par> gomos;
    int dir;
};

void elemento_update(Cobra &cobra){

    int tam = cobra.gomos.size();
    for(int i = tam - 1; i >= 1; i--){
        cobra.gomos[i] = cobra.gomos[i - 1];
    }

    if(cobra.dir == UP)
        cobra.gomos[0].y -= 1;
    else if(cobra.dir == DOWN)
        cobra.gomos[0].y += 1;
    else if(cobra.dir == LEFT)
        cobra.gomos[0].x -= 1;
    else if(cobra.dir == RIGHT)
        cobra.gomos[0].x += 1;
}

void elemento_controlar(Cobra &cobra, sf::Keyboard::Key tecla){

    if(tecla == sf::Keyboard::Up)
        cobra.dir = UP;
    if(tecla == sf::Keyboard::Down)
        cobra.dir = DOWN;
    if(tecla == sf::Keyboard::Left)
        cobra.dir = LEFT;
    if(tecla == sf::Keyboard::Right)
        cobra.dir = RIGHT;
}

int main(){
    sf::Clock relogio;
    sf::Clock relogio_pirueta;
    sf::RenderWindow janela(sf::VideoMode(1000, 600), "Janela");

    sf::Texture tex_py;
    tex_py.loadFromFile("../jararaca/pikachu.png");
    sf::Sprite spr_py(tex_py);
    spr_py.setScale(casa/tex_py.getSize().x, casa/tex_py.getSize().y);


    Cobra cobra;//= {2, 2, DOWN};//inicializacao inline
    cobra.gomos.push_back(Par{2, 2});
    cobra.dir = RIGHT;

    while(janela.isOpen()){
        sf::Event evento;
        while(janela.pollEvent(evento)){
            if(evento.type == sf::Event::Closed)
                janela.close();
            if(evento.type == sf::Event::KeyPressed){
                elemento_controlar(cobra, evento.key.code);
                if(evento.key.code == sf::Keyboard::C)
                    cobra.gomos.push_back(cobra.gomos[0]);
            }
        }


        if(relogio.getElapsedTime() > sf::milliseconds(250)){
            relogio.restart();
            elemento_update(cobra);
        }

        //fim
        janela.clear();

        int i = rotacao;
        for(auto par : cobra.gomos){
            spr_py.setPosition(par.x * casa, par.y * casa);
            spr_py.setOrigin(tex_py.getSize().x/2.0,
                             tex_py.getSize().y/2.0);
            spr_py.setRotation(rotacao);
            janela.draw(spr_py);
            i++;
        }
        if(relogio_pirueta.getElapsedTime() > sf::milliseconds(100)){
            relogio_pirueta.restart();
            rotacao += 10;
        }
        janela.display();
    }

    return 0;
}











