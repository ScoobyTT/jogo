#ifndef DECISAO_H
#define DECISAO_H

#include <string>

struct Jogador {
    std::string nome;
    int vida;
    int energia;
};

struct Decisao {
    std::string texto;  // Texto da decisão
    std::string resultado;  // Resultado da decisão
    Decisao* opcao1;    // Próxima decisão se escolher opção 1
    Decisao* opcao2;    // Próxima decisão se escolher opção 2
    
    // Função para aplicar efeitos na vida/energia do jogador
    void aplicarEfeitos(Jogador& jogador) const {
        // Aqui você pode implementar diferentes efeitos
        // por exemplo:
        // jogador.vida -= 10;
        // jogador.energia -= 5;
    }
};

#endif // DECISAO_H
