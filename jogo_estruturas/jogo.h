#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include "decisao.h"

class Jogo {
private:
    Jogador jogador;
    Decisao* decisaoAtual;  // Decisão atual do jogador
    
    // Função auxiliar para mostrar a decisão atual
    void mostrarDecisaoAtual() const {
        std::cout << "\n" << decisaoAtual->texto << std::endl;
        std::cout << "\nESCOLHAS:" << std::endl;
        std::cout << "1 - " << decisaoAtual->opcao1->texto << std::endl;
        std::cout << "2 - " << decisaoAtual->opcao2->texto << std::endl;
    }
    
    // Função auxiliar para processar a escolha do jogador
    void processarEscolha(int escolha) {
        if (escolha == 1) {
            decisaoAtual = decisaoAtual->opcao1;
        } else if (escolha == 2) {
            decisaoAtual = decisaoAtual->opcao2;
        } else {
            std::cout << "Escolha inválida! Tente novamente." << std::endl;
        }
    }
    
public:
    Jogo() : jogador(), decisaoAtual(nullptr) {}
    
    // Inicializa o jogo com o primeiro nó
    void iniciarJogo(Decisao* inicio) {
        decisaoAtual = inicio;
        std::cout << "Bem-vindo ao Jogo de Aventura!" << std::endl;
        std::cout << "Digite seu nome: ";
        std::cin >> jogador.nome;
        jogador.vida = 100;
        jogador.energia = 100;
    }
    
    // Função principal para jogar
    void jogar() {
        while (decisaoAtual != nullptr) {
            mostrarDecisaoAtual();
            int escolha;
            std::cout << "\nDigite sua escolha (1 ou 2): ";
            std::cin >> escolha;
            
            // Processa a escolha e aplica os efeitos
            processarEscolha(escolha);
            if (decisaoAtual != nullptr) {
                decisaoAtual->aplicarEfeitos(jogador);
                std::cout << "\n" << decisaoAtual->resultado << std::endl;
                std::cout << "Vida: " << jogador.vida << ", Energia: " << jogador.energia << std::endl;
            }
        }
        std::cout << "\nFim do jogo!" << std::endl;
    }
};

#endif // JOGO_H
