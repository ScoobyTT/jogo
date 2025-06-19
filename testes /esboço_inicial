#include <iostream>
#include "stack.h"
#include "queue.h"
#include "linked_list.h"
#include "redo_system.h"
using namespace std;

struct Jogador {
    string nome;
    int vida;
    int energia;
    LinkedList<string> inventario; // Lista para itens
};

struct Inimigo {
    string nome;
    int vida;
    Queue<string> acoes; // Fila para ações
};

class Jogo {
private:
    Stack<string> decisoes; // Pilha para decisões
    Jogador jogador;
    LinkedList<Inimigo> inimigos;
    RedoSystem sistemaRedo; // Sistema redo para reexecutar ações
    
public:
    Jogo() {
        jogador.nome = "Jogador";
        jogador.vida = 100;
        jogador.energia = 100;
        sistemaRedo = RedoSystem(10); // Limite de 10 ações no histórico
    }
    
    void iniciarJogo() {
        cout << "Bem-vindo ao Jogo de Aventura!" << endl;
        cout << "Digite seu nome: ";
        cin >> jogador.nome;
        
        // Adicionando itens iniciais ao inventário
        jogador.inventario.add("Espada");
        jogador.inventario.add("Poção de Cura");
    }
    
    void mostrarInventario() {
        cout << "\nInventário de " << jogador.nome << ":" << endl;
        Node<string>* current = jogador.inventario.head;
        while (current != nullptr) {
            cout << "- " << current->data << endl;
            current = current->next;
        }
    }
    
    void registrarAcao(const string& acao) {
        sistemaRedo.registrarAcao(acao);
    }
    
    void redoAcao() {
        if (sistemaRedo.temAcoesDisponiveis()) {
            string acao = sistemaRedo.redo();
            cout << "\nReexecutando ação: " << acao << endl;
            // Aqui você implementaria a lógica para reexecutar a ação
        } else {
            cout << "\nNenhuma ação disponível para redo" << endl;
        }
    }
};

int main() {
    Jogo jogo;
    int op;
    string acao;
    
    while(true) {
        cout << "\n...... JOGO DE AVENTURA....." << endl;
        cout << "ESCOLHA UMA OPCAO: " << endl;
        cout << "1 - Iniciar o jogo" << endl;
        cout << "2 - Ver inventário" << endl;
        cout << "3 - Ver histórico de decisões" << endl;
        cout << "4 - Registrar nova ação" << endl;
        cout << "5 - Reexecutar última ação (Redo)" << endl;
        cout << "0 - Sair" << endl;
        cout << "DIGITE A OPCAO DESEJADA: ";
        cin >> op;
        
        switch(op) {
            case 1:
                jogo.iniciarJogo();
                break;
            case 2:
                jogo.mostrarInventario();
                break;
            case 3:
                // Mostrar histórico de decisões
                break;
            case 4: {
                cout << "Digite a ação para registrar: ";
                cin.ignore(); // Limpa o buffer
                getline(cin, acao);
                jogo.registrarAcao(acao);
                cout << "Ação registrada com sucesso!" << endl;
                break;
            }
            case 5:
                jogo.redoAcao();
                break;
            case 0:
                return 0;
        }
    }
    return 0;
}
