// OBSERVACOES:
// O arquivo "nomes.txt" ja deve estar criado e deve estar no mesmo diretorio que o executavel do programa
// O tempo gasto na ordenacao e feito em microssegundos
// O numero de passos foi contato na troca de nomes

#include <iostream> //Biblioteca padrao do C++
#include <fstream>  //Biblioteca para leitura e escrita de arquivo
#include <chrono>   //Biblioteca para contar o tempo de execucao
using namespace std;

// Funcao para ler o arquivo e deixar o array pronto
string *lerArquivo(int &count){
    string linha, palavra;

    // Leitura do arquivo nomes.txt
    ifstream arquivo("nomes.txt");
    if (!arquivo){
        cout << "Erro ao abrir o arquivo." << endl;
        abort();
    }

    getline(arquivo, linha);
    arquivo.close();

    // Conta os nomes antes de criar o array
    count = 0;
    for (int i = 0; i < (int)linha.size(); i++)
        if (linha[i] == '\'')
            count++;
    count /= 2;

    // Cria o array com o tamanho variando por conta da alocacao dinamica
    string *array_string = new string[count];

    // Preenche o array
    int index = 0;
    for (int i = 0; i < (int)linha.size(); i++){
        if (linha[i] == '\''){
            palavra = "";
            i++;
            while (linha[i] != '\''){
                palavra += linha[i];
                i++;
            }
            array_string[index] = palavra;
            index++;
        }
    }

    return array_string;
}

// Funcao do algoritmo do Bubble Sort e de exibir os resultados
long long bubbleSort(string *array_string, int count){
    long passos = 0;
    string temporaria;

    // Inicio da contagem do tempo de execucao
    auto inicio = chrono::high_resolution_clock::now();
    // Ordenacao
    for (int i = 0; i < count; i++){
        for (int j = i + 1; j < count; j++){
            if (array_string[i] > array_string[j]){
                passos++;
                temporaria = array_string[i];
                array_string[i] = array_string[j];
                array_string[j] = temporaria;
            }
        }
    }
    // fim da contagem e calculo pela diferenca
    auto fim = chrono::high_resolution_clock::now();
    auto duracao = chrono::duration_cast<chrono::microseconds>(fim - inicio);

    // Saida
    cout << "Ordenacao Alfabetica: " << endl;
    cout << endl;
    for (int i = 0; i < count; i++){
        cout << array_string[i];
        if (i == count - 1)
            cout << ".";
        else if (i == count - 2)
            cout << " e ";
        else
            cout << ", ";
    }
    cout << endl;
    cout << endl;
    cout << "Numero de passos realizados: " << passos << " passos!" << endl;
    cout << "Tempo de ordenacao: " << duracao.count() << " microssegundos!" << endl;
    cout << "Numero total de nomes ordenados: " << count << " nomes!" << endl;

    return passos;
}

int main(){
    int count = 0;

    string *array_string = lerArquivo(count);
    if (array_string == nullptr)
        abort();

    bubbleSort(array_string, count);

    delete[] array_string;
    return 0;
}