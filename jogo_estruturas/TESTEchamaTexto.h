#ifndef "Ctxt"
#define "Ctxt"
#include <iostream>  // Para std::cout, std::cin, std::endl
#include <string>    // Para std::string, std::getline
#include <fstream>   // Para std::fstream, std::ios

// A função agora recebe um argumento: o número da linha que você quer ler.
// Linhas sao contadas a partir de 1.
void lerEPrintarLinhaEspecifica(int numeroDaLinhaAlvo) {
    // using namespace std; // É uma boa prática evitar 'using namespace std;' dentro de funcoes.
                            // Preferível no topo do arquivo .cpp ou usar 'std::' prefixo.

    std::fstream arquivoE;
    arquivoE.open("arquivoE.txt", std::ios::in); // Abre o arquivo para leitura

    //abertura do arquivo txt
    if (!arquivoE.is_open()) {
        std::cout << "Erro ao abrir o arquivo 'arquivoE.txt'." << std::endl;
        return; // Retorna se o arquivo nao puder ser aberto
    }

    std::string linha;
    int contadorLinhas = 0; // Inicia um contador de linhas

    // Loop para ler o arquivo linha por linha
    while (std::getline(arquivoE, linha)) {
        contadorLinhas++; // Incrementa o contador para cada linha lida

        // Verifica se chegamos à linha que queremos
        if (contadorLinhas == numeroDaLinhaAlvo) {
            // **CORREÇÃO E ADAPTAÇÃO:** Aplicando a lógica de formatação que você tinha para *esta* linha
            if (linha.length() > 0 && linha[0] == '@') {
                std::cout << "Fala: " << linha.substr(1) << std::endl; // Imprime a fala, removendo o '@'
            } else if (linha == "---") {
                std::cout << "\n-----------------------------------------\n" << std::endl;
            } else {
                // Se nao eh fala nem separador, apenas imprime a linha como ela eh
                std::cout << linha << std::endl;
            }
            break; // **IMPORTANTE:** Sai do loop 'while' assim que a linha é encontrada e impressa
        }
    }

    // Se o loop terminou e a linha alvo nao foi encontrada (por exemplo, numero maior que o arquivo)
    if (contadorLinhas < numeroDaLinhaAlvo) {
        std::cout << "A linha " << numeroDaLinhaAlvo << " nao existe no arquivo." << std::endl;
    }

    arquivoE.close(); // Fecha o arquivo
}

int main() {
    // Exemplo de uso: Para ler e imprimir a 3a linha do arquivo
    std::cout << "Tentando ler a linha 3:" << std::endl;
    lerEPrintarLinhaEspecifica(3);

    std::cout << "\n--- Nova tentativa ---\n" << std::endl;

    // Exemplo: Para ler e imprimir a 1a linha
    std::cout << "Tentando ler a linha 1:" << std::endl;
    lerEPrintarLinhaEspecifica(1);

    std::cout << "\n--- Nova tentativa ---\n" << std::endl;

    // Exemplo: Tentando ler uma linha que nao existe
    std::cout << "Tentando ler a linha 100 (provavelmente nao existe):" << std::endl;
    lerEPrintarLinhaEspecifica(100);

    return 0;
}
