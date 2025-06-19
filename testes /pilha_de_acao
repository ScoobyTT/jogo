#ifndef JOGO_H
#define JOGO_H
#include <iostream>
#include "decisao.h"
#include "redo_system.h"

class Jogo {
private:
    Jogador jogador;
    Decisao* decisaoAtual;  // Decisão atual do jogador
    RedoSystem sistemaRedo; // Sistema de redo para registrar ações
    
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
            // Registrar ação no sistema de redo
            sistemaRedo.registrarAcao("Escolheu opção 1: " + decisaoAtual->opcao1->texto);
            decisaoAtual = decisaoAtual->opcao1;
        } else if (escolha == 2) {
            // Registrar ação no sistema de redo
            sistemaRedo.registrarAcao("Escolheu opção 2: " + decisaoAtual->opcao2->texto);
            decisaoAtual = decisaoAtual->opcao2;
        } else {
            std::cout << "Escolha inválida! Tente novamente." << std::endl;
        }
    }
    
public:
    Jogo() : jogador(), decisaoAtual(nullptr), sistemaRedo(10) {} // Limite de 10 ações no redo
    
    // Inicializa o jogo com o primeiro nó
    void iniciarJogo(Decisao* inicio) {
        decisaoAtual = inicio;
        // Registrar início do jogo
        sistemaRedo.registrarAcao("Início do jogo");
        std::cout << "Bem-vindo ao Jogo de Aventura!" << std::endl;
        std::cout << "Digite seu nome: ";
        std::cin >> jogador.nome;
    }

    // Mostra o histórico de ações disponíveis para redo
    void mostrarHistoricoRedo() const {
        std::cout << "\nHistórico de Ações (" << sistemaRedo.getAcoesDisponiveis() << " disponíveis):" << std::endl;
        if (sistemaRedo.temAcoesDisponiveis()) {
            std::cout << "- " << sistemaRedo.peek() << " (última ação)" << std::endl;
        } else {
            std::cout << "Nenhuma ação disponível para redo" << std::endl;
        }
    }

    // Executa o redo da última ação
    void executarRedo() {
        if (sistemaRedo.temAcoesDisponiveis()) {
            std::cout << "\nRefazendo ação: " << sistemaRedo.redo() << std::endl;
            // Aqui você poderia implementar a lógica específica para refazer a ação
        } else {
            std::cout << "Nenhuma ação disponível para redo" << std::endl;
        }
    }

    // Limpa todo o histórico de ações
    void limparHistorico() {
        sistemaRedo.limparHistorico();
        std::cout << "Histórico de ações limpo!" << std::endl;
    }

    // Verifica se há ações disponíveis para redo
    bool temRedoDisponivel() const {
        return sistemaRedo.temAcoesDisponiveis();
    }
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
