#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using namespace std;

struct Elem{
    int x; //4 bytes
    int y; //4
    int xold;//4
    int yold;//4
    sf::Color cor;
};

struct Cenario{
    Elem py;
    Elem fruta;
    vector<Elem> pedras;
    int qtd_pedras;
};

void inicializar(Cenario &cenario, int casa){
    Elem &py = cenario.py;
    py.x = 0 * casa;
    py.y = 0 * casa;
    py.cor = sf::Color::Yellow;

    cenario.qtd_pedras = 5;

    cenario.fruta.x = 0 * casa;
    cenario.fruta.y = 2 * casa;
    cenario.fruta.cor = sf::Color::Red;

    auto &pedras = cenario.pedras;

    for(int i = 0; i < cenario.qtd_pedras; i++){
        Elem p;
        p.x = (i + 2) * casa;
        p.y = i * casa;
        p.cor = sf::Color::White;
        pedras.push_back(p);
    }
}

void empurrar(Elem &agente, Elem &obstaculo){
    if(agente.x == obstaculo.x && agente.y == obstaculo.y){
        obstaculo.x += -agente.xold + agente.x;
        obstaculo.y += -agente.yold + agente.y;
    }
}

void atualizar_posicao(Elem &elemento){
    elemento.xold = elemento.x;
    elemento.yold = elemento.y;
}


void desenhar_tudo(Cenario &cenario,
                   sf::Sprite &sprite_py, sf::RectangleShape &carimbo,
                   sf::RenderWindow &janela){
    auto &py = cenario.py;
    auto &pedras = cenario.pedras;
    auto &fruta = cenario.fruta;

    carimbo.setPosition(fruta.x, fruta.y);
    carimbo.setFillColor(fruta.cor);
    janela.draw(carimbo);

    //pintando py
    sprite_py.setPosition(py.x, py.y);
    //carimbo.setFillColor(py.cor);
    janela.draw(sprite_py);

    for(auto &peda : pedras){
        //post é um apelido para obstaculos[i]
        carimbo.setPosition(peda.x, peda.y);
        carimbo.setFillColor(peda.cor);
        janela.draw(carimbo);
    }

}

void movimentar(Elem &py, sf::Event &evento, int casa){
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

int main()
{
    int casa = 128;
    int ncol = 12;
    int nlin = 6;
    //    int largura = ncol * casa;
    //    int altura = nlin * casa;

    sf::Texture tex_py;
    tex_py.loadFromFile("../quadrados/pikachu.png");
    sf::Sprite sprite_py(tex_py);

    sf::RectangleShape carimbo;
    carimbo.setSize(sf::Vector2f(casa, casa));

    Cenario cenario;
    auto &py = cenario.py;
    auto &pedras = cenario.pedras;
    auto &fruta = cenario.fruta;

    inicializar(cenario, casa);

    sf::RenderWindow janela(sf::VideoMode(ncol * casa, nlin * casa), "Super");
    while(janela.isOpen()){
        //inicio
        atualizar_posicao(py);
        for(auto &pedra : pedras)
            atualizar_posicao(pedra);

        sf::Event evento;
        while(janela.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                janela.close();
            }
            if(evento.type == sf::Event::KeyPressed){
                movimentar(py, evento, casa);
            }
        }

        //inicio
//        if(py.x == largura || py.x < 0 ||
//            py.y == altura || py.y < 0){
//            py.x = py.xold;
//            py.y = py.yold;
//        }

        for(int i = 0; i < (int) pedras.size() - 1; i++){
            for(int j = i + 1; j < (int) pedras.size(); j++){
                empurrar(pedras[i], pedras[j]);
                empurrar(pedras[j], pedras[i]);
            }
        }


        //fim

        janela.clear();

//        for(auto &peda : pedras){
//            empurrar(py, peda);
//        }



        ////        if(py.x == pedra.x && py.y == pedra.y){
        ////            pedra.x += -py.xold + py.x;
        ////            pedra.y += -py.yold + py.y;
        ////        }

        desenhar_tudo(cenario, sprite_py, carimbo, janela);

        janela.display();
    }
    return 0;
}










