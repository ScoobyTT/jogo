#ifndef REDO_SYSTEM_H
#define REDO_SYSTEM_H

#include "stack.h"

class RedoSystem {
private:
    Stack<string> acoes;  // Pilha para armazenar ações
    int maxHistorico;    // Limite de ações que podemos armazenar
    int acoesDisponiveis; // Número de ações disponíveis para redo

public:
    RedoSystem(int max = 10) : maxHistorico(max), acoesDisponiveis(0) {}
    
    // Adiciona uma ação ao histórico
    void registrarAcao(const string& acao) {
        if (acoes.getSize() >= maxHistorico) {
            // Remove a ação mais antiga se o histórico estiver cheio
            acoes.pop();
        }
        acoes.push(acao);
        acoesDisponiveis = acoes.getSize();
    }
    
    // Executa o redo se houver ações disponíveis
    string redo() {
        if (acoesDisponiveis <= 0) {
            return "Nenhuma ação disponível para redo";
        }
        string acao = acoes.peek(); // Pega a última ação
        acoesDisponiveis--;
        return acao;
    }
    
    // Limpa o histórico de ações
    void limparHistorico() {
        while (!acoes.isEmpty()) {
            acoes.pop();
        }
        acoesDisponiveis = 0;
    }
    
    // Verifica se há ações disponíveis para redo
    bool temAcoesDisponiveis() const {
        return acoesDisponiveis > 0;
    }
    
    // Retorna quantas ações podem ser reexecutadas
    int getAcoesDisponiveis() const {
        return acoesDisponiveis;
    }
};

#endif // REDO_SYSTEM_H
