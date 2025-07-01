#include <iostream>
#include <string>
#include <stream> 

void contruirCena(){
    using namespace std;

    fstream arquivoE;
    arquivoE.open("arquivoE.txt");
    if (!arquivoE.is_open())        cout << "Erro ao abrir o arquivo." << endl;        return;

    string linha;
    while (getline(arquivoE, linha)) {
        cout << linha << endl;
        if(linha[0] == "@")     cout << "Fala: " << linha << endl;
    
    else cout << "FALA MAL FORMATADA OU O PERSONAGEM NAO PUSSUI NOME:" << endl;
    //se nao possui "@" no inicio da linha, assumi que é uma separacao de linha.
    else if(linha == "---") cout << "\n-----------------------------------------\n" << endl;
    else        cout << linha << endl;
}
arquivoE.close();
int main() {
    contruirCena();
    return 0;
}
