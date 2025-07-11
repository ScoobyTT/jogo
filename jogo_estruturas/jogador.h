#ifndef "jogador.h"
#define "jogador.h"
#include <iostream>
#include <string>
#include <algorithm> // Para std::sort ou outras operações de lista
#include "jogo.cpp"

void jogo::atualizarScore(const string& nomeJogador, bool venceu) {
        ScoreNode* atual = scoreInicio;
        while (atual != nullptr) {
            if (atual->jogador.nome == nomeJogador) {
                atual->jogador.total_jogos++;
                if (venceu) {
                    atual->jogador.vitorias++;
                } else {
                    atual->jogador.derrotas++;
                }
                // Remover e adicionar novamente para manter a ordenacao
                removerScoreNode(atual);
                adicionarScore(atual->jogador); // Adiciona novamente para reordenar
                return;
            }
            atual = atual->prox;
        }

        // Se o jogador nao foi encontrado, adiciona um novo
        JogadorScore novo = {nomeJogador, 1, (venceu ? 1 : 0), (venceu ? 0 : 1)};
        adicionarScore(novo);
    }
    void jogo::removerScoreNode(ScoreNode* nodeToRemove) {
        if (nodeToRemove == nullptr) return;

        if (nodeToRemove->ant) {
            nodeToRemove->ant->prox = nodeToRemove->prox;
        } else { // Era o inicio
            scoreInicio = nodeToRemove->prox;
        }

        if (nodeToRemove->prox) {
            nodeToRemove->prox->ant = nodeToRemove->ant;
        } else { // Era o fim
            scoreFim = nodeToRemove->ant;
        }
        delete nodeToRemove;
    }

    void jogo::verificarScore() {
        using namespace std;
        cout << "\n--- Score dos Jogadores ---" << endl;
        if (scoreInicio == nullptr) {
            cout << "Nenhum score registrado ainda." << endl;
            cout << "Pressione Enter para voltar ao menu..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        ScoreNodo* atual = scoreInicio;
        int rank = 1;
        while (atual != nullptr) {
            cout << rank << ". Nome: " << atual->jogador.nome
                 << " | Jogos: " << atual->jogador.total_jogos
                 << " | Vitorias: " << atual->jogador.vitorias
                 << " | Derrotas: " << atual->jogador.derrotas << endl;
            atual = atual->prox;
            rank++;
        }
        cout << "Pressione Enter para voltar ao menu..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void jogo::salvarScores() {
        std::cout << "\n(Scores salvos no arquivo - Funcionalidade de arquivo a ser implementada)" << endl;
    }
      void destruirScores() {
        ScoreNode* atual = scoreInicio;
        while (atual != nullptr) {
            ScoreNode* temp = atual;
            atual = atual->prox;
            delete temp;
        }
        scoreInicio = nullptr;
        scoreFim = nullptr;
    }

    void jogo::listarArvoreEmOrdem(Nodo* nodo) { // Exemplo de percurso em pre-ordem
        using namespace std;
        if (nodo == nullptr) cout << "Erro! Arvore vazia." << endl;return;
        cout << "Cena: ";
        if (nodo->falas && nodo->falas->texto.length() > 20) {
            cout << "\"" << nodo->falas->texto.substr(0, 20) << "..." << "\"" << endl;
        } else if (nodo->falas) {
            cout << "\"" << nodo->falas->texto << "\"" << endl;
        } else {
            cout << "(Sem texto)" << endl;
        }
        listarArvoreEmOrdem(nodo->op1);
        listarArvoreEmOrdem(nodo->op2);
    }

    void jogo::buscarEstatisticas() {
        using namespace std;
        cout << "\n--- Buscar Estatisticas ---" 
         << "1. Buscar por nome do jogador" 
         << "2. Buscar por numero de jogos ganhos (Minimo)" << endl; // Exemplo
         << "0. Voltar" 
         << "Escolha uma opcao: " << endl;
        
        int escolha;
        cin >> escolha;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (escolha) {
            case 1: {
                string nomeBusca;
                cout << "Digite o nome do jogador: ";
                getline(cin, nomeBusca);
                ScoreNode* atual = scoreInicio;
                bool encontrado = false;
                while (atual != nullptr) {
                    if (atual->jogador.nome == nomeBusca) {
                        cout << "Nome: " << atual->jogador.nome
                             << " | Jogos: " << atual->jogador.total_jogos
                             << " | Vitorias: " << atual->jogador.vitorias
                             << " | Derrotas: " << atual->jogador.derrotas << endl;
                        encontrado = true;
                        break;
                    }
                    atual = atual->prox;
                }
                if (!encontrado) {
                    cout << "Jogador '" << nomeBusca << "' nao encontrado." << endl;
                }
                break;
            }
            case 2: { // Exemplo: Buscar jogadores com mais de X vitórias
                int minVitorias;
                cout << "Digite o numero minimo de vitorias: ";
                cin >> minVitorias;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                ScoreNode* atual = scoreInicio;
                bool encontrado = false;
                cout << "Jogadores com " << minVitorias << " ou mais vitorias:" << endl;
                while (atual != nullptr) {
                    if (atual->jogador.vitorias >= minVitorias) {
                        cout << "Nome: " << atual->jogador.nome
                             << " | Jogos: " << atual->jogador.total_jogos
                             << " | Vitorias: " << atual->jogador.vitorias
                             << " | Derrotas: " << atual->jogador.derrotas << endl;
                        encontrado = true;
                    }
                    atual = atual->prox;
                }
                if (!encontrado) {
                    cout << "Nenhum jogador encontrado com essa quantidade de vitorias." << endl;
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Opcao invalida." << endl;
        }
    }

    //  Destrutor e Liberacao de Memoria 
    ~Jogo() {
        destruirArvore(raiz);
        destruirScores();
        //  salvar o destrutor scores no arquivo para garantir que não se percam.
        // salvarScores(); // se eu quiser salvar ao fechar o programa
    }

private:
    void jogo::destruirArvore(Nodo* nodo) {
        if (nodo == nullptr) return;
        destruirArvore(nodo->op1);
        destruirArvore(nodo->op2);

        // Libera a lista de falas de cada nodo
        Lista* atual = nodo->falas;
        while (atual != nullptr) {
            Lista* temp = atual;
            atual = atual->prox;
            delete temp;
        }
        delete nodo;
    }


