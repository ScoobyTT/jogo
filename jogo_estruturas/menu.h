#ifndef "menu.h"
#define "menu.h"
  
#include <iostream>
#include <string>
#include "jogo.cpp" // Inclua o arquivo de cabeçalho do jogo
#include "arvore.h" // Inclua o arquivo de cabeçalho da árvore
#include "jogador.h" // Inclua o arquivo de cabeçalho do jogador
#include "cenas.h"

     void jogo::exibirMenuPrincipal() {
        int escolha;
        do {
            using namespace std;
            cout << "\n=== JOGO-ED1: Uma Aventura com Árvores de Decisão ===" << endl
             << "1. Conhecer a História do Jogo" 
             << "2. Regras do Jogo" 
             << "3. Jogar" 
             << "4. Verificar Score" 
             << "0. Sair" 
             << "-----------------------------------------------------" 
             << "Escolha uma opcao: " << endl;
            cin >> escolha;
            // Limpa o buffer do teclado
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (escolha) {
                case 1:
                    mostrarHistoria();
                    break;
                case 2:
                    mostrarRegras();
                    break;
                case 3:
                    jogar();
                    break;
                case 4:
                    verificarScore();
                    break;
                case 0:
                    cout << "Obrigado por jogar! Saindo..." << endl;
                    break;
                default:
                    cout << "Opcao invalida. Tente novamente." << endl;
            }
        } while (escolha != 0);
    }

    void jogo::mostrarHistoria() {
        using namespace std;
        cout << "\n--- Historia do Jogo ---" << endl;
         << "Este é um jogo de aventura onde suas escolhas moldam seu destino." 
         << "Você acorda em um local misterioso e deve navegar por caminhos perigosos." 
         << "Cada decisão pode levar a uma vitoria gloriosa ou a uma derrota inesperada."
         << "Boa sorte, aventureiro!" << endl;
         << "Pressione Enter para voltar ao menu..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    void jogo::mostrarRegras() {
        using namespace std;
        cout << "\n--- Regras do Jogo ---" << 
         << "1. Leia atentamente a descricao de cada cena." 
         << "2. Escolha entre as opcoes disponiveis (geralmente 1 para Esquerda, 2 para Direita)." << endl;
         << "3. Suas escolhas sao permanentes e afetarao o desfecho do jogo." << endl;
         << "4. O objetivo e alcancar um final de vitoria. Um final de derrota termina o jogo." << endl;
         << "Pressione Enter para voltar ao menu..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    void jogo::jogar() {
        using namespace std;
        cout << "\n--- Iniciar Novo Jogo ---" << endl;
        cout << "Qual o seu nome, aventureiro? ";
        getline(cin, jogadorAtualNome);

        Nodo* atual = raiz;
        bool jogo_ativo = true;
        bool vitoria_atual = false;

        while (atual != nullptr && jogo_ativo) {
            cout << "\n--- Cena Atual ---" << endl;
            exibirCena(atual);


            if (atual->op1 == nullptr && atual->op2 == nullptr) {
                cout << "\nFim do caminho nesta historia." << endl;
                
                } else if (atual == raiz->op2->op1) 
                    cout << "Você ficou preso no baú! Fim da aventura. DERROTA!" << endl;
                    vitoria_atual = false;
                } else { 
                    cout << "Você chegou a um beco sem saída. Tente novamente!" << endl;
                    vitoria_atual = false; 
                }
                jogo_ativo = false;
            } else {
                int escolha;
                cout << "\nEscolha seu proximo passo: ";
                if (atual->op1 != nullptr) cout << "[1] Esquerda ";
                if (atual->op2 != nullptr) cout << "[2] Direita ";
                cout << "| [0] Sair do jogo\n> ";
                cin >> escolha;

                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer

                if (escolha == 1 && atual->op1 != nullptr) {
                    atual = atual->op1;
                } else if (escolha == 2 && atual->op2 != nullptr) {
                    atual = atual->op2;
                } else if (escolha == 0) {
                    cout << "Saindo do jogo atual..." << endl;
                    jogo_ativo = false;
                } else {
                    cout << "Escolha invalida ou caminho inexistente. Tente novamente." << endl;

                }
            }
        
        // Após o jogo terminar ou o jogador sair
        if (!jogadorAtualNome.empty()) { // Verifica se um nome de jogador foi inserido
            atualizarScore(jogadorAtualNome, vitoria_atual);
        }
        exibirMenuPosJogo(); // Exibe o menu pós-jogo
   



    void jogo::exibirMenuPosJogo() {
        using namespace std;
        int escolha;
        do {
            cout << "\n--- Fim de Jogo ---" << endl;
            cout << "1. Jogar Novamente" << endl;
            cout << "2. Informacoes Tecnicas" << endl;
            cout << "0. Sair para o Menu Principal" << endl;
            cout << "----------------------" << endl;
            cout << "Escolha uma opcao: ";
            cin >> escolha;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (escolha) {
                case 1:
                    jogar(); // Inicia um novo jogo
                    break;
                case 2:
                    exibirInformacoesTecnicas();
                    break;
                case 0:
                    cout << "Voltando ao Menu Principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida. Tente novamente." << endl;
            }
        } while (escolha != 0);
    }

    //  Menu de Informacoes Tecnicas 
    void jogo::exibirInformacoesTecnicas() {
        using namespace std;
        int escolha;
        do {
            cout << "\n--- Informacoes Tecnicas ---" << endl;
            cout << "1. Mostrar a lista de falas de um nodo (Ex: Cena Raiz)" << endl; // Adapte para mostrar uma lista específica
            cout << "2. Listar a arvore em ordem (percurso)" << endl;
            cout << "3. Buscar estatisticas de jogo por nome/numero de jogos" << endl;
            cout << "0. Voltar ao menu anterior" << endl;
            cout << "----------------------------" << endl;
            cout << "Escolha uma opcao: ";
            cin >> escolha;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (escolha) {
                case 1:
                    // Exemplo: mostrar falas da raiz
                    cout << "\n--- Falas da Cena Raiz ---" << endl;
                    if (raiz) exibirCena(raiz);
                    else cout << "Arvore nao construida." << endl;
                    break;
                case 2:
                    cout << "\n--- Listando Arvore em Ordem (Pre-ordem) ---" << endl;
                    listarArvoreEmOrdem(raiz); // Pode implementar pre-ordem, in-ordem, pos-ordem
                    break;
                case 3:
                    buscarEstatisticas();
                    break;
                case 0:
                    cout << "Voltando..." << endl;
                    break;
                default:
                    cout << "Opcao invalida. Tente novamente." << endl;
            }
            cout << "Pressione Enter para continuar..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (escolha != 0);
    }
    
