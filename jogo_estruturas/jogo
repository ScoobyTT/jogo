#ifndef HISTORIA_H
#define HISTORIA_H
#include <iostream>
#include <string> // string é uma classe fundamental e geralmente permitida, mas se não, teremos que usar char arrays. Presumo que string seja ok.
#include <limits> // numeric_limits para cin.ignore()

// A estrutura Cena é a base da nossa árvore de decisão de jogo.
struct Cena {
    std::string texto;
    std::string escolha1;
    std::string escolha2;
    Cena* op1 = nullptr; // Opção 1 leva a esta cena
    Cena* op2 = nullptr; // Opção 2 leva a esta cena
    bool is_victory_ending = false; // Indica se esta cena é um final de vitória
    bool is_defeat_ending = false; // Indica se esta cena é um final de derrota

    Cena(std::string t, std::string e1 = "", std::string e2 = "", bool victory = false, bool defeat = false)
        : texto(t), escolha1(e1), escolha2(e2), is_victory_ending(victory), is_defeat_ending(defeat) {}
};

#endif // HISTORIA_H

// --- Fim do conteúdo de historia.h ---

#include <iostream>
#include <string>

#include <fstream>   // Para leitura/escrita de arquivos



using namespace std;

// Estrutura para o score do jogador
struct jogadorScore {
    string nome;
    int total_jogos;
    int vitorias;
    int derrotas;
};

// Nó para a lista duplamente encadeada de scores
struct ScoreNodo {
    jogadorScore jogador;
    ScoreNodo* prox;
    ScoreNodo* ant;
};

class Jogo {
private:
    Cena* raizCena;             // Raiz da árvore de cenas do jogo
    ScoreNodo* scoreInicio;     // Início da lista de scores
    ScoreNodo* scoreFim;        // Fim da lista de scores
    string jogadorAtualNome;    // Nome do jogador atual

    // Funções auxiliares privadas
    void construirCenas();
    void destruirCenas(Cena* cena); // Função recursiva para liberar a árvore
    void destruirScores();
    void salvarScores();
    void removerScoreNode(ScoreNodo* nodeToRemove);
    void listarCenasEmOrdem(Cena* cena); // Renomeada para ser consistente com a sua, mas adaptada para Cena*

public:
    // Construtor
    Jogo() : raizCena(nullptr), scoreInicio(nullptr), scoreFim(nullptr) {
        carregarScores();
        construirCenas(); // Chama a função para construir a árvore de cenas
    }

    // Destrutor
    ~Jogo() {
        salvarScores();          // Salva scores ao fechar o programa
        destruirCenas(raizCena); // Libera a memória da árvore de cenas
        destruirScores();        // Libera a memória da lista de scores
    }

    // Métodos de Jogo e Menu
    void jogarCena(Cena* atual);
    void carregarScores(); // Método público para carregar (chamado no construtor)
    void adicionarScore(const jogadorScore& novoJogador);
    void atualizarScore(const std::string& nomeJogador, bool venceu);
    void verificarScore();
    void exibirMenuPrincipal();
    void mostrarHistoria();
    void mostrarRegras();
    void exibirMenuPosJogo();
    void exibirInformacoesTecnicas();
    void buscarEstatisticas();
    void gerenciarSaida();
};

// Implementação dos métodos da classe Jogo

void Jogo::construirCenas() {
    // Cenas - Marcando explicitamente os finais de vitória/derrota
    Cena* c1 = new Cena(
        "Voce acorda em um buraco, o qual nao teria caido se prestasse mais atencao. Voce ve um grande cipo pendurado do topo ate voce.\nO que vai fazer?",
        "Subir ate o topo pelo cipo.",
        "Investigar seus bolsos."
    );

    Cena* c2 = new Cena(
        "Voce sobe no cipo, mas ele era fragil demais. Você cai e desmaia outra vez. Que ideia em...\nGame Over.",
        "", "", false, true // Final de derrota
    );

    Cena* c3 = new Cena(
        "Voce investiga seus bolsos e encontra seu celular. O sinal está fraco e a bateria também. O que vai fazer?",
        "Subir no cipo para tentar mais sinal.",
        "Ligar a lanterna para investigar o local."
    );

    Cena* c4 = new Cena(
        "Voce sobe com o celular na mao. Esta perto do topo, mas sem sinal. Voce estica o braço, se desequilibra e cai. Você e seu celular estao inteiros, por sorte.\nO que vai fazer?",
        "Ligar para alguem e jogar o celular para fora.",
        "Tentar sair subindo pelo cipo novamente."
    );

    Cena* c5 = new Cena(
        "Voce liga para emergencia, coloca no viva-voz e joga o celular pra fora. Alguem atende. O resgate esta chegando. Voce este a salvo!",
        "", "", true, false // Final de vitória
    );

    Cena* c6 = new Cena(
        "Seu plano falha e voce cai, desmaiando. Voce já tentou isso antes, nao tentou?\nGame Over.",
        "", "", false, true // Final de derrota
    );

    Cena* c7 = new Cena(
        "Voce liga a lanterna e investiga o local, mas nao acha nada. O que vai fazer?",
        "Investigar outra vez.",
        "Escolher uma musica."
    );

    Cena* c8 = new Cena(
        "Voce investiga de novo, mas a bateria acaba. O que vai fazer?",
        "Gritar por ajuda."
    );

    Cena* c9 = new Cena(
        "Voce grita... e atrai uma onça selvagem. Ela nem pula no buraco, mas você desmaia de medo.\nGame Over.",
        "", "", false, true // Final de derrota
    );

    Cena* c10 = new Cena(
        "Voce so tem duas musicas. Qual vai escolher?",
        "Musica de seresta.",
        "Musica de balada."
    );

    Cena* c11 = new Cena(
        "Voce toca a musica de seresta. Começa a chover. A agua sobe, e voce flutua ate a saida do buraco.\nVoce esta salvo!",
        "", "", true, false // Final de vitória
    );

    Cena* c12 = new Cena(
        "Voce toca musica de balada. E animada e contagiante. O que vai fazer?",
        "Dançar.",
        "Gritar sem motivo."
    );

    Cena* c13 = new Cena(
        "Voce danca animado. Sua mente imagina se conseguiria subir o cipo suado. Voce vai tentar?",
        "Xingar o narrador e subir pelo cipo.",
        "Bajular o narrador."
    );

    Cena* c14 = new Cena(
        "Voce xinga o narrador e tenta subir... e consegue??? Qual a logica disso? Mas voce esta a salvo!",
        "", "", true, false // Final de vitória
    );

    Cena* c15 = new Cena(
        "Voce bajula o narrador. Uma escada aparece magicamente. Parabens, você esta a salvo!",
        "", "", true, false // Final de vitória
    );

    Cena* c16 = new Cena(
        "Voce grita sem motivo. Uma onça aparece e te encara. O que vai fazer?",
        "Tacar o celular na onça.",
        "Pedir ajuda ao animal."
    );

    Cena* c17 = new Cena(
        "Voce taca o celular na onça. Ela se assusta, escorrega e cai no buraco.\nFim tragico. Game Over.",
        "", "", false, true // Final de derrota
    );

    Cena* c18 = new Cena(
        "Voce implora ajuda a onca. Ela sente pena, entra no buraco e te carrega pra fora. Voce esta salvo!",
        "", "", true, false // Final de vitória
    );

    // Ligando as cenas (construindo a árvore)
    c1->op1 = c2;
    c1->op2 = c3;

    c3->op1 = c4;
    c3->op2 = c7;

    c4->op1 = c5;
    c4->op2 = c6;

    c7->op1 = c8;
    c7->op2 = c10;

    c8->op1 = c9;

    c10->op1 = c11;
    c10->op2 = c12;

    c12->op1 = c13;
    c12->op2 = c16;

    c13->op1 = c14;
    c13->op2 = c15;

    c16->op1 = c17;
    c16->op2 = c18;

    raizCena = c1; // Define a cena inicial do jogo
}

void Jogo::jogarCena(Cena* atual) {
    while (atual != nullptr) {
        cout << "\n" << atual->texto << "\n";

        // Verifica se é um final (vitória ou derrota)
        if (atual->is_victory_ending) {
            cout << "\n>>> Parabens! Voce alcançou um final de VITORIA! <<<\n";
            atualizarScore(jogadorAtualNome, true);
            return; // Encerra a função, o jogo termina
        } else if (atual->is_defeat_ending) {
            cout << "\n>>> Que pena! Voce alcançou um final de DERROTA! <<<\n";
            atualizarScore(jogadorAtualNome, false);
            return; // Encerra a função, o jogo termina
        }

        // Se não for um final, apresenta as opções
        bool has_op1 = (atual->op1 != nullptr);
        bool has_op2 = (atual->op2 != nullptr);

        if (has_op1) cout << "1 - " << atual->escolha1 << "\n";
        if (has_op2) cout << "2 - " << atual->escolha2 << "\n";

        int escolha;
        cout << "Escolha: ";
        // Loop para garantir entrada válida
        while (!(cin >> escolha) || (escolha != 1 && escolha != 2 && escolha != 0) ||
               (escolha == 1 && !has_op1) || (escolha == 2 && !has_op2)) {
            cout << "Opcao invalida ou não disponivel. Digite 1, 2 ou 0 para sair: ";
            cin.clear(); // Limpa o estado de erro do cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada inválida
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer após a leitura

        if (escolha == 1 && has_op1) {
            atual = atual->op1;
        } else if (escolha == 2 && has_op2) {
            atual = atual->op2;
        } else if (escolha == 0) {
            cout << "Saindo do jogo atual..." << endl;
            atualizarScore(jogadorAtualNome, false); // Considera sair como derrota
            return;
        }
    }
}

// Métodos de Score
void Jogo::carregarScores() {
    ifstream arquivo("scores.txt");
    if (!arquivo.is_open()) {
        cout << "(Arquivo de scores nao encontrado ou erro ao abrir. Criando um novo.)" << endl;
        return;
    }

    string nome;
    int total_jogos, vitorias, derrotas;
    string line;

    while (getline(arquivo, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);

        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) {
            // Erro na linha, pule-a
            continue;
        }

        try {
            nome = line.substr(0, pos1);
            total_jogos = stoi(line.substr(pos1 + 1, pos2 - (pos1 + 1)));
            vitorias = stoi(line.substr(pos2 + 1, pos3 - (pos2 + 1)));
            derrotas = stoi(line.substr(pos3 + 1));

            jogadorScore loadedJogador = {nome, total_jogos, vitorias, derrotas};
            adicionarScore(loadedJogador);
        } catch (const std::invalid_argument& e) {
            cerr << "Erro de conversao de numero ao carregar score: " << e.what() << endl;
            continue;
        } catch (const std::out_of_range& e) {
            cerr << "Numero fora do intervalo ao carregar score: " << e.what() << endl;
            continue;
        }
    }
    arquivo.close();
    cout << "(Scores carregados do arquivo 'scores.txt')" << endl;
}

void Jogo::adicionarScore(const jogadorScore& novoJogador) {
    ScoreNodo* novaNode = new ScoreNodo{novoJogador, nullptr, nullptr};

    if (scoreInicio == nullptr) { // Lista vazia
        scoreInicio = novaNode;
        scoreFim = novaNode;
    } else {
        // Insercao ordenada por vitorias (decrescente)
        // Se vitorias iguais, pode ordenar por total_jogos (crescente)
        ScoreNodo* atual = scoreInicio;
        while (atual != nullptr &&
               (novoJogador.vitorias < atual->jogador.vitorias ||
                (novoJogador.vitorias == atual->jogador.vitorias && novoJogador.total_jogos > atual->jogador.total_jogos))) {
            atual = atual->prox;
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
}

void Jogo::atualizarScore(const string& nomeJogador, bool venceu) {
    ScoreNodo* atual = scoreInicio;
    while (atual != nullptr) {
        if (atual->jogador.nome == nomeJogador) {
            atual->jogador.total_jogos++;
            if (venceu) {
                atual->jogador.vitorias++;
            } else {
                atual->jogador.derrotas++;
            }
            // Salva os dados antes de remover o nó
            jogadorScore tempJogador = atual->jogador;
            removerScoreNode(atual); // Remove o nó da posição antiga
            adicionarScore(tempJogador); // Adiciona novamente para reordenar
            return;
        }
        atual = atual->prox;
    }

    // Se o jogador nao foi encontrado, adiciona um novo
    jogadorScore novo = {nomeJogador, 1, (venceu ? 1 : 0), (venceu ? 0 : 1)};
    adicionarScore(novo);
}

void Jogo::removerScoreNode(ScoreNodo* nodeToRemove) {
    if (nodeToRemove == nullptr) return;

    if (nodeToRemove->ant) {
        nodeToRemove->ant->prox = nodeToRemove->prox;
    } else { // Era o início
        scoreInicio = nodeToRemove->prox;
    }

    if (nodeToRemove->prox) {
        nodeToRemove->prox->ant = nodeToRemove->ant;
    } else { // Era o fim
        scoreFim = nodeToRemove->ant;
    }
    delete nodeToRemove;
}

void Jogo::verificarScore() {
    cout << "\n--- Score dos Jogadores ---" << endl;
    if (scoreInicio == nullptr) {
        cout << "Nenhum score registrado ainda." << endl;
    } else {
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
    }
    cout << "\nPressione Enter para voltar ao menu..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa buffer antes de esperar enter
}

// Métodos de Jogo e Menu
void Jogo::exibirMenuPrincipal() {
    int escolha;
    do {
        cout << "\n=== JOGO-ED1: Uma Aventura com Arvores de Decisao ===" << endl
             << "1. Conhecer a Historia do Jogo" << endl
             << "2. Regras do Jogo" << endl
             << "3. Jogar" << endl
             << "4. Verificar Score" << endl
             << "5. Informacoes Tecnicas" << endl
             << "0. Sair" << endl
             << "-----------------------------------------------------" << endl
             << "Escolha uma opcao: ";
        // Garante que a entrada seja um número e limpa o buffer
        while (!(cin >> escolha)) {
            cout << "Entrada invalida. Digite um numero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer após a leitura

        switch (escolha) {
            case 1:
                mostrarHistoria();
                break;
            case 2:
                mostrarRegras();
                break;
            case 3:
                cout << "\n--- Iniciar Novo Jogo ---" << endl;
                cout << "Qual o seu nome, aventureiro? ";
                getline(cin, jogadorAtualNome);
                if (jogadorAtualNome.empty()) { // Garante que o nome não seja vazio
                    jogadorAtualNome = "Aventureiro Desconhecido";
                    cout << "Nome vazio. Usando nome padrao: " << jogadorAtualNome << endl;
                }
                jogarCena(raizCena); // Inicia o jogo a partir da raiz da árvore de cenas
                exibirMenuPosJogo(); // Exibe menu pós-jogo após o término da cena
                break;
            case 4:
                verificarScore();
                break;
            case 5:
                exibirInformacoesTecnicas();
                break;
            case 0:
                gerenciarSaida();
                cout << "Obrigado por jogar! Saindo..." << endl;
                break; // O loop termina e o destrutor será chamado
            default:
                cout << "Opçao invalida. Tente novamente." << endl;
        }
    } while (escolha != 0);
}

void Jogo::mostrarHistoria() {
    cout << "\n--- Historia do Jogo ---" << endl
         << "Este é um jogo de aventura onde suas escolhas moldam seu destino." << endl
         << "Voce acorda em um buraco escuro e deve tentar sair dele a todo custo." << endl
         << "Cada decisao pode levar a uma vitoria gloriosa ou a uma derrota inesperada." << endl
         << "Boa sorte!" << endl
         << "\nPressione Enter para voltar ao menu..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Jogo::mostrarRegras() {
    cout << "\n--- Regras do Jogo ---" << endl
         << "1. Leia atentamente a descricao de cada cena." << endl
         << "2. Escolha entre as opções disponíveis (geralmente 1 ou 2)." << endl
         << "3. Suas escolhas sao permanentes e afetarão o desfecho do jogo." << endl
         << "4. O objetivo é alcançar um final de vitoria. Um final de derrota termina o jogo." << endl
         << "\nPressione Enter para voltar ao menu..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


// Menu Pós-Jogo
void Jogo::exibirMenuPosJogo() {
    int escolha;
    do {
        cout << "\n--- Fim de Jogo ---" << endl
             << "1. Deseja Jogar Novamente?" << endl
             << "2. Verificar Score" << endl
             << "0. Fechar o jogo" << endl
             << "----------------------" << endl;
        cout << "Escolha uma opçao: ";
        while (!(cin >> escolha)) {
            cout << "Entrada invalida. Digite um numero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (escolha) {
            case 1:
                cout << "Iniciando um novo jogo..." << endl;
                return; // Retorna para o loop do menu principal que chamará jogarCena() novamente
            case 2:
                verificarScore();
                break;
            case 0:
                cout << "Fechando o jogo. Obrigado por jogar!" << endl;
                gerenciarSaida(); // Pergunta se quer salvar antes de sair definitivamente
                exit(0); // Sai do programa
            default:
                cout << "Opção invalida. Tente novamente." << endl;
        }
    } while (escolha != 0);
}

// Menu de Informações Técnicas
void Jogo::exibirInformacoesTecnicas() {
    int escolha;
    do {
        cout << "\n--- Informaçoes Tecnicas ---" << endl;
        cout << "1. Mostrar a descriçao da Cena Raiz" << endl;
        cout << "2. Listar a arvore de cenas (percurso Pre-Ordem)" << endl;
        cout << "3. Buscar estatisticas de jogo por nome/vitorias" << endl;
        cout << "0. Voltar ao menu anterior" << endl;
        cout << "----------------------------" << endl;
        cout << "Escolha uma opçao: ";
        while (!(cin >> escolha)) {
            cout << "Entrada inválida. Digite um número: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (escolha) {
            case 1:
                cout << "\n--- Descrição da Cena Raiz ---" << endl;
                if (raizCena) cout << raizCena->texto << endl;
                else cout << "Árvore de cenas nao construída." << endl;
                break;
            case 2:
                cout << "\n--- Listando Arvore em Pre-Ordem ---" << endl;
                if (raizCena) {
                    listarCenasEmOrdem(raizCena);
                } else {
                    cout << "Arvore de cenas vazia." << endl;
                }
                break;
            case 3:
                buscarEstatisticas();
                break;
            case 0:
                cout << "Voltando..." << endl;
                break;
            default:
                cout << "Opção invalida. Tente novamente." << endl;
        }
        cout << "\nPressione Enter para continuar..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (escolha != 0);
}

// Função recursiva para percorrer e listar as cenas em Pre-Ordem
void Jogo::listarCenasEmOrdem(Cena* cena) {
    if (cena == nullptr) return; // Se o nó é nulo, não faz nada.

    cout << "Cena: ";
    if (!cena->texto.empty()) { // Verifica se a string não está vazia

        if (cena->texto.length() > 50) { // Mostra um trecho se for muito longo
            cout << "\"" << cena->texto.substr(0, 50) << "..." << "\"" << endl;
        } else {
            cout << "\"" << cena->texto << "\"" << endl;
        }
    } else {
        cout << "(Sem texto)" << endl;
    }
    listarCenasEmOrdem(cena->op1);
    listarCenasEmOrdem(cena->op2);
}

void Jogo::buscarEstatisticas() {
    cout << "\n--- Buscar Estatísticas ---" << endl;
    cout << "1. Buscar por nome do jogador" << endl;
    cout << "2. Buscar por número de vitórias (Mínimo)" << endl;
    cout << "0. Voltar" << endl;
    cout << "Escolha uma opção: ";

    int escolha;
    while (!(cin >> escolha)) {
        cout << "Entrada inválida. Digite um número: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (escolha) {
        case 1: {
            string nomeBusca;
            cout << "Digite o nome do jogador: ";
            getline(cin, nomeBusca);
            ScoreNodo* atual = scoreInicio;
            bool encontrado = false;
            while (atual != nullptr) {
                if (atual->jogador.nome == nomeBusca) {
                    cout << "Nome: " << atual->jogador.nome
                         << " | Jogos: " << atual->jogador.total_jogos
                         << " | Vitórias: " << atual->jogador.vitorias
                         << " | Derrotas: " << atual->jogador.derrotas << endl;
                    encontrado = true;
                    break;
                }
                atual = atual->prox;
            }
            if (!encontrado) {
                cout << "Jogador '" << nomeBusca << "' não encontrado." << endl;
            }
            break;
        }
        case 2: {
            int minVitorias;
            cout << "Digite o número mínimo de vitórias: ";
            while (!(cin >> minVitorias)) {
                cout << "Entrada inválida. Digite um número: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            ScoreNodo* atual = scoreInicio;
            bool encontrado = false;
            cout << "Jogadores com " << minVitorias << " ou mais vitórias:" << endl;
            while (atual != nullptr) {
                if (atual->jogador.vitorias >= minVitorias) {
                    cout << "Nome: " << atual->jogador.nome
                         << " | Jogos: " << atual->jogador.total_jogos
                         << " | Vitórias: " << atual->jogador.vitorias
                         << " | Derrotas: " << atual->jogador.derrotas << endl;
                    encontrado = true;
                }
                atual = atual->prox;
            }
            if (!encontrado) {
                cout << "Nenhum jogador encontrado com essa quantidade de vitórias." << endl;
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Opção inválida." << endl;
    }
}

void Jogo::gerenciarSaida() {
    int escolhaSalvar;
    cout << "\nDeseja salvar seu progresso antes de sair?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Não" << endl;
    cout << "Escolha: ";
    while (!(cin >> escolhaSalvar) || (escolhaSalvar != 1 && escolhaSalvar != 2)) {
        cout << "Escolha inválida. Digite 1 para Sim ou 2 para Não: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa buffer
    if (escolhaSalvar == 1) {
        salvarScores();
        cout << "Scores salvos com sucesso!" << endl;
    } else {
        cout << "Scores não salvos." << endl;
    }
}

// Funções auxiliares para liberar memória (privadas)
void Jogo::destruirCenas(Cena* cena) {
    if (cena == nullptr) return;
    // Percorre recursivamente os filhos
    destruirCenas(cena->op1);
    destruirCenas(cena->op2);
    // Finalmente, deleta o nó atual
    delete cena;
}

void Jogo::destruirScores() {
    ScoreNodo* atual = scoreInicio;
    while (atual != nullptr) {
        ScoreNodo* temp = atual;
        atual = atual->prox;
        delete temp;
    }
    scoreInicio = nullptr;
    scoreFim = nullptr;
}

void Jogo::salvarScores() {
    ofstream arquivo("scores.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para salvar scores." << endl;
        return;
    }
    ScoreNodo* atual = scoreInicio;
    if (atual == nullptr) {
        cout << "Nenhum score para salvar." << endl;
    } else {
        while (atual != nullptr) {
            arquivo << atual->jogador.nome << ","
                    << atual->jogador.total_jogos << ","
                    << atual->jogador.vitorias << ","
                    << atual->jogador.derrotas << endl;
            atual = atual->prox;
        }
    }
    arquivo.close();
    cout << "(Scores salvos no arquivo 'scores.txt')" << endl;
}

// Função main para iniciar o jogo
int main() {
    Jogo meuJogo;
    meuJogo.exibirMenuPrincipal(); // Inicia o loop principal do menu
    return 0;
}
