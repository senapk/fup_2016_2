#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <SFML/Audio.hpp>

//#include <SFML/Window.hpp>

const int NLIN = 8;
const int NCOL = 6;
const int CASA = 80;
int intervalo = 300;
const int offset = 300;

using namespace std;
sf::RenderWindow janela(sf::VideoMode(900, 700),
                          "Motoca do AlexKidd");


void descer_blocos(int mat[NLIN][NCOL]){
    for(int l = NLIN - 2; l >= 0; l--)
        for(int c = 0; c < NCOL; c++)
            mat[l + 1][c] = mat[l][c];
    for(int c = 0; c < NCOL; c++)
        mat[0][c] = 0;
    mat[0][rand() % NCOL] = 1;
}

void pintar_blocos(int mat[NLIN][NCOL]){
    sf::RectangleShape rect(sf::Vector2f(CASA, CASA));
    for(int l = 0; l < NLIN; l++){
        for(int c = 0; c < NCOL; c++){
            if(mat[l][c] == 1)
                rect.setFillColor(sf::Color(200, 200, 200));
            else
                rect.setFillColor(sf::Color(50, 50, 50));
            rect.setPosition(offset + c * CASA, l * CASA);
            janela.draw(rect);
        }
    }
}

void pintar_moto(int moto){
    sf::RectangleShape rect(sf::Vector2f(CASA, CASA));
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(offset + moto * CASA, (NLIN - 1) * CASA);
    janela.draw(rect);

}

bool movimentar_moto(sf::Event::KeyEvent tecla, int &moto){
    if(tecla.code == sf::Keyboard::Left)
        if(moto != 0){
            moto--;
            return true;
        }
    if(tecla.code == sf::Keyboard::Right)
        if(moto < NCOL - 1){
            moto++;
            return true;
        }
    if(tecla.code == sf::Keyboard::Up && intervalo > 200)
        intervalo -= 20;
    if(tecla.code == sf::Keyboard::Down && intervalo < 400)
        intervalo += 20;


    return false;

}

bool testar_colisao(int mat[NLIN][NCOL], int moto){
    if(mat[NLIN - 1][moto] == 1)
        return true;
    return false;
}


#include <sstream>
int main(){
    sf::Music trilha_sonora;
    trilha_sonora.openFromFile("../corrida/alexkidd.ogg");
    sf::Music rao;
    rao.openFromFile("../corrida/rao.ogg");
    sf::Font fonte;
    fonte.loadFromFile("../corrida/hack.ttf");
    sf::Text texto;
    texto.setFont(fonte);
    texto.setCharacterSize(20);
    texto.setFillColor(sf::Color::White);

    trilha_sonora.setLoop(true);
    trilha_sonora.play();
    srand(time(NULL));
    int mat[NLIN][NCOL];
    sf::Clock relogio;
    int moto = 0;
    int pontos = 0;

    while(janela.isOpen()){
        sf::Event evento;
        while(janela.pollEvent(evento)){
            if(evento.type == sf::Event::Closed)
                janela.close();
            if(evento.type == sf::Event::KeyPressed)
                if(movimentar_moto(evento.key, moto))
                    rao.play();
        }
        if(testar_colisao(mat, moto))
            janela.close();

        if(relogio.getElapsedTime() > sf::milliseconds(intervalo)){
            relogio.restart();
            descer_blocos(mat);
            pontos++;
        }

        janela.clear();
        pintar_blocos(mat);
        pintar_moto(moto);
        std::stringstream buffer;
        buffer << "Pontos :" << pontos;
        texto.setPosition(sf::Vector2f(0, 0));
        texto.setString(buffer.str());
        janela.draw(texto);

        janela.display();
    }

    cout << "Hello World!" << endl;
    return 0;
}
