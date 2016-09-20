#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

const float casa = 50;


//enum Dir {UP, RIGHT, DOWN, LEFL};

struct Par{
    int x;
    int y;
    sf::Color cor;
};

struct Cobra{
    vector<Par> gomos;
    int dir;
};

void elemento_update(Cobra &cobra){
    Par aux = cobra.gomos[0];
    if(cobra.dir == UP)
        cobra.gomos[0].y -= 1;
    else if(cobra.dir == DOWN)
        cobra.gomos[0].y += 1;
    else if(cobra.dir == LEFT)
        cobra.gomos[0].x -= 1;
    else if(cobra.dir == RIGHT)
        cobra.gomos[0].x += 1;

    int tam = cobra.gomos.size();
    for(int i = 1; i < tam; i++){
        std::swap(aux.x, cobra.gomos[i].x);
        std::swap(aux.y, cobra.gomos[i].y);
    }
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
    srand(time(NULL));
    sf::Clock relogio;
    sf::Clock relogio_maca;

    int largura = 800;
    int altura = 600;

    int nlin = altura / casa;
    int ncol = largura / casa;

    sf::RenderWindow janela(sf::VideoMode(largura, altura), "Janela");

    Par maca;
    maca.x = rand() % ncol;
    maca.y = rand() % nlin;
    maca.cor = sf::Color(rand() % 255, rand() % 255, rand() % 255);

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(casa - 4, casa - 4));

    Cobra cobra;//= {2, 2, DOWN};//inicializacao inline
    cobra.gomos.push_back(Par{2, 2, sf::Color::Black});
    cobra.dir = RIGHT;

    while(janela.isOpen()){
        sf::Event evento;
        while(janela.pollEvent(evento)){
            if(evento.type == sf::Event::Closed)
                janela.close();
            if(evento.type == sf::Event::KeyPressed){
                elemento_controlar(cobra, evento.key.code);
            }
        }


        if(cobra.gomos[0].x == maca.x && cobra.gomos[0].y == maca.y){
            cobra.gomos.push_back(maca);
            maca.x = rand() % ncol;
            maca.y = rand() % nlin;
            maca.cor = sf::Color(rand() % 255, rand() % 255, rand() % 255);
            relogio_maca.restart();
        }

        if(relogio_maca.getElapsedTime() > sf::milliseconds(5000)){
            relogio_maca.restart();
            maca.x = rand() % ncol;
            maca.y = rand() % nlin;
            maca.cor = sf::Color(rand() % 255, rand() % 255, rand() % 255);
        }

        if(relogio.getElapsedTime() > sf::milliseconds(250)){
            relogio.restart();
            elemento_update(cobra);
        }

        //fim
        janela.clear();

        rect.setFillColor(sf::Color(200, 100, 100));
        for(int l = 0; l < nlin; l++){
            for(int c = 0; c < ncol; c++){
                rect.setPosition(c * casa + 2, l * casa + 2);
                janela.draw(rect);
            }
        }

        rect.setFillColor(maca.cor);
        rect.setPosition(maca.x * casa + 2, maca.y * casa + 2);
        janela.draw(rect);


        for(auto gomo : cobra.gomos){
            rect.setFillColor(gomo.cor);
            rect.setPosition(gomo.x * casa + 2, gomo.y * casa + 2);
            janela.draw(rect);
        }
        janela.display();
    }

    return 0;
}











