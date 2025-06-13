struct nodo {
    Jogador player;
    nodo* dir;
    nodo* esq;
};

class jogo {
public:
    nodo* raiz;
    
    jogo() : raiz(nullptr) {}
    
    // Função auxiliar recursiva para inserir
    nodo* insereRec(nodo* raiz, Jogador player) {
        if (raiz == nullptr) {
            return new nodo {player};
        }
        
        if (player.nome < raiz->player.nome) {
            raiz->esq = insereRec(raiz->esq, player);
        } else if (player.nome > raiz->player.nome) {
            raiz->dir = insereRec(raiz->dir, player);
        }
        
        return raiz;
    }
    
    // Função pública para inserir
    void inserirJogador(Jogador player) {
        raiz = insereRec(raiz, player);
    }
    
    // Função para mostrar a árvore em ordem
    void mostrarArvore(nodo* raiz, int nivel = 0) {
        if (raiz == nullptr) {
            return;
        }
        
        // Mostra a subárvore direita primeiro
        mostrarArvore(raiz->dir, nivel + 1);
        
        // Mostra o nó atual
        for (int i = 0; i < nivel; i++) {
            cout << "  ";
        }
        cout << "Jogador: " << raiz->player.nome 
             << " (Vida: " << raiz->player.vida 
             << ", Energia: " << raiz->player.energia << ")" << endl;
        
        // Mostra a subárvore esquerda
        mostrarArvore(raiz->esq, nivel + 1);
    }
    
    // Método para mostrar a árvore completa
    void mostrarArvoreCompleta() {
        cout << "\nÁrvore de Jogadores:" << endl;
        mostrarArvore(raiz);
    }
};
