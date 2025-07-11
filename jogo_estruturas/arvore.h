#include <iostream>
#include "jogo.h"
#include "jogador.h"

    // Construtor
    jogo::Jogo() : raiz(nullptr), scoreInicio(nullptr), scoreFim(nullptr) {
        // No construtor, você pode tentar carregar scores de um arquivo aqui.
        carregarScores(); // Função a ser implementada
    }
    void jogo::carregarScores() {
        std::cout << "(Scores carregados do arquivo - Funcionalidade de arquivo a ser implementada)" << endl;
    }
    // Métodos de Score 
    void jogo::adicionarScore(const JogadorScore& novoJogador) {
        ScoreNode* novaNode = new ScoreNode{novoJogador, nullptr, nullptr};

        if (scoreInicio == nullptr) { // Lista vazia
            scoreInicio = novaNode;
            scoreFim = novaNode;
        } else {
            // Insercao ordenada por vitorias (decrescente)
            ScoreNode* atual = scoreInicio;
            while (atual != nullptr && novoJogador.vitorias <= atual->jogador.vitorias) {
                // Se vitorias iguais, pode ordenar por total_jogos (crescente) ou nome
                if (novoJogador.vitorias == atual->jogador.vitorias && novoJogador.total_jogos >= atual->jogador.total_jogos) {
                    // Mantem a ordem se vitorias iguais, inserindo depois de quem tem menos jogos
                    atual = atual->prox;
                } else if (novoJogador.vitorias < atual->jogador.vitorias) {
                    atual = atual->prox;
                } else {
                    break; // Encontrou a posicao correta
                }
            }
            if (atual == nullptr) { // Inserir no fim
                scoreFim->prox = novaNode;
                novaNode->ant = scoreFim;
                scoreFim = novaNode;
            } else if (atual == scoreInicio) { // Inserir no inicio
                novaNode->prox = scoreInicio;
                scoreInicio->ant = novaNode;
                scoreInicio = novaNode;
            } else { // Inserir no meio
                novaNode->prox = atual;
                novaNode->ant = atual->ant;
                atual->ant->prox = novaNode;
                atual->ant = novaNode;
            }
        }
        salvarScores(); // Salva scores sempre que um novo é adicionado
    }

    
    //  Métodos da Árvore 
    Lista* jogo::adicionarFalas(const string textos[], int n) { // Usando vector para flexibilidade
        Lista* inicio = nullptr;
        Lista* fim = nullptr;
        for (const string& texto_item : textos) {
            Lista* nova = new Lista{texto_item, nullptr, nullptr};
            if (inicio == nullptr) {
                inicio = nova;
                fim = nova;
            } else {
                fim->prox = nova;
                nova->ant = fim;
                fim = nova;
            }
        }
        return inicio;
    }

    Nodo* jogo::criarNodo(const string textos[], int n) { 
        Nodo* novo = new Nodo;
        novo->falas = adicionarFalas(textos);
        novo->op1 = nullptr;
        novo->op2 = nullptr;
     
        return novo;
    }

    /*

    // função construirCenas
    void jogo::construirCenas() {
        // Cena raiz
        raiz = criarNodo({"Você acorda em uma floresta misteriosa.",
                         "Dois caminhos se abrem: esquerda e direita."});

        // Esquerda da raiz
        raiz->op1 = criarNodo({"Você segue pela esquerda e encontra um lago brilhante.",
                              "Um barulho estranho vem da água."});

        // Direita da raiz
        raiz->op2 = criarNodo({"Você segue pela direita e encontra uma caverna escura.",
                              "Uma sombra se move dentro dela."});

        // Filhos da esquerda
        raiz->op1->op1 = criarNodo({"Você se aproxima do lago e vê uma criatura mágica.",
                                   "Ela oferece uma poção."});

        raiz->op1->op2 = criarNodo({"Você ignora o lago e continua andando pela mata.",
                                   "Um grupo de viajantes aparece."});

        // Filhos da direita
        raiz->op2->op1 = criarNodo({"Você entra na caverna e encontra um baú trancado.",
                                   "Há símbolos antigos nas paredes."});

        raiz->op2->op2 = criarNodo({"Você contorna a caverna e chega ao topo de uma montanha.",
                                   "A vista é deslumbrante, mas há uma tempestade se aproximando."});
        
        
    }
    */

    void jogo::exibirCena(Nodo* nodo) {
        Lista* atual = nodo->falas;
        while (atual != nullptr) {
            std::cout << atual->texto << std::endl;
            atual = atual->prox;
        }
    }
