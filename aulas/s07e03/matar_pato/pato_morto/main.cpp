#include <iostream>
#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>

using namespace std;

struct Elemento{
    float x, y, vx, vy;
    float tamanho;
    sf::Color cor;
    bool existe;
};

const int LARGURA = 800;
const int ALTURA = 600;
const int VEL_ATIRADOR = 10;

sf::RenderWindow janela(sf::VideoMode(LARGURA, ALTURA), "Corre! Bala!");
sf::RectangleShape rec_atirador;
sf::RectangleShape rec_pato;
sf::RectangleShape rec_bnut;

Elemento atirador;
Elemento pato;
Elemento bnut;


void inicializacao(){
    atirador.tamanho = 100;
    atirador.x = 0;
    atirador.y = ALTURA - atirador.tamanho;
    atirador.vx = 0;
    atirador.vy = 0;
    atirador.cor = sf::Color::Red;
    atirador.existe = true;

    pato.tamanho = 50;
    pato.x = 100;
    pato.y = 100;
    pato.vx = 1;
    pato.vy = 1;
    pato.cor = sf::Color::Yellow;
    pato.existe = true;
}

void prender_pato(){
    if(pato.y < 0){
        pato.y = 0;
        pato.vy = -pato.vy;
    }

    if(pato.x > LARGURA - pato.tamanho){
        pato.x = LARGURA - pato.tamanho;
        pato.vx = -pato.vx;
    }

    if(pato.y > ALTURA/2 - pato.tamanho){
        pato.y = ALTURA/2 - pato.tamanho;
        pato.vy = -pato.vy;
    }

    if(pato.x < 0){
        pato.x = 0;
        pato.vx = -pato.vx;
    }
}

void movimentar_atirador(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        atirador.x -= VEL_ATIRADOR;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        atirador.x += VEL_ATIRADOR;

}

void processar_eventos(sf::Event &evento){
    if(evento.type == sf::Event::KeyPressed){
        if(evento.key.code == sf::Keyboard::Space){
            bnut.existe = true;
            bnut.x = atirador.x + atirador.tamanho / 2;
            bnut.y = atirador.y;
            bnut.vy = -VEL_ATIRADOR;
            bnut.tamanho = 10;
            bnut.cor = sf::Color::White;
        }
    }
}

void logica(){
    //aleatorizar o pato
    pato.vx += ((rand() % 21) - 10)/10.0;
    pato.vy += ((rand() % 21) - 10)/10.0;

    //atualizar posicao pato
    pato.x += pato.vx;
    pato.y += pato.vy;

    bnut.x += bnut.vx;
    bnut.y += bnut.vy;

    if(bnut.y < ALTURA/2)
        bnut.cor = sf::Color::Black;
    else
        bnut.cor = sf::Color::White;

    if(bnut.x > pato.x && bnut.x < (pato.x + pato.tamanho)){
        if(bnut.y > pato.y && bnut.y < (pato.y + pato.tamanho)){
            bnut.existe = false;
            pato.vy = -10;
            pato.tamanho *= 0.8;
        }
    }
    pato.tamanho += 0.1;

    prender_pato();
    movimentar_atirador();

}

void pintura(){
    janela.clear();

    rec_atirador.setSize(sf::Vector2f(atirador.tamanho, atirador.tamanho));
    rec_atirador.setPosition(sf::Vector2f(atirador.x, atirador.y));
    rec_atirador.setFillColor(atirador.cor);
    janela.draw(rec_atirador);

    sf::RectangleShape lagoa;
    lagoa.setPosition(sf::Vector2f(0, 0));
    lagoa.setSize(sf::Vector2f(LARGURA, ALTURA/2));
    lagoa.setFillColor(sf::Color::Cyan);
    janela.draw(lagoa);

    rec_pato.setSize(sf::Vector2f(pato.tamanho, pato.tamanho));
    rec_pato.setPosition(sf::Vector2f(pato.x, pato.y));
    rec_pato.setFillColor(pato.cor);
    janela.draw(rec_pato);

    if(bnut.existe){
        rec_bnut.setSize(sf::Vector2f(bnut.tamanho, bnut.tamanho));
        rec_bnut.setPosition(bnut.x, bnut.y);
        rec_bnut.setFillColor(bnut.cor);
        janela.draw(rec_bnut);
    }

    janela.display();
}

int main()
{
    srand(1);
    inicializacao();
    janela.setFramerateLimit(30);
    while(janela.isOpen()){
        sf::Event evento;
        while(janela.pollEvent(evento)){
            if(evento.type == sf::Event::Closed)
                janela.close();
            processar_eventos(evento);
        }
        logica();
        pintura();
    }
    return 0;
}

