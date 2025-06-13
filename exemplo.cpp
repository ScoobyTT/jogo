#include <iostream>
#include "jogo.h"

int main() {
    // Criando as decisões do jogo
    Decisao* fim = new Decisao();
    fim->texto = "Você encontrou o tesouro! Parabéns!";
    fim->resultado = "Você ganhou o jogo!";
    fim->opcao1 = nullptr;
    fim->opcao2 = nullptr;

    // Criando uma decisão intermediária
    Decisao* decisao2 = new Decisao();
    decisao2->texto = "Você chegou a uma encruzilhada."
                     "\n1 - Ir para a esquerda"
                     "\n2 - Ir para a direita";
    decisao2->resultado = "Você seguiu pela direita e encontrou o tesouro!";
    decisao2->opcao1 = nullptr;
    decisao2->opcao2 = fim;

    // Criando a decisão inicial
    Decisao* inicio = new Decisao();
    inicio->texto = "Você está em uma floresta escura."
                   "\n1 - Explorar a floresta"
                   "\n2 - Seguir pelo caminho principal";
    inicio->resultado = "Você seguiu pelo caminho principal e chegou a uma encruzilhada.";
    inicio->opcao1 = nullptr;
    inicio->opcao2 = decisao2;

    // Criando o jogo
    Jogo jogo;
    jogo.iniciarJogo(inicio);
    jogo.jogar();

    // Liberando a memória
    delete fim;
    delete decisao2;
    delete inicio;

    return 0;
}
