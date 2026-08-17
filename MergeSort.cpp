//ARTHUR DE SOUZA MANDU - 2264814
//Trabalho:Rastreamento do Algoritmo Merge Sort 

#include <iostream> //Biblioteca padrao para entrada e saida
#include <vector> // Necessário para usar std::vector
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()
using namespace std;

// =========================================================
// FUNCAO AUXILIAR PARA IMPRIMIR O PEDACOS DA ARRAY
// Percorre todo o Array e Imprime no terminal o estado do array no momento, permite o rastreamento
// =========================================================
void imprimirEstadoAtual(int arr[], int inicio, int fim){
    cout << "[";
    for (int i = inicio; i <= fim; i++){ //Percorre todo do inicio ao fim do pedaco
        cout << arr[i];
        if (i < fim) cout << ", "; //Se nao for o ultimo elemento, coloca virgula
    }
    cout << "]";
}

// =========================================================
// A LÓGICA DA CONQUISTA (FUNÇÃO MERGE)
// Responsável por unir dois pedaços que já estão ordenados.
// =========================================================
void merge(int arr[], int l, int m, int r, int &passos){
    // PASSO 1: Calcular o tamanho dos sub-vetores
    int n1 = m - l + 1; // Tamanho da metade esquerda
    int n2 = r - m; // Tamanho da metade direita
    // PASSO 2: Criar a "Mesa de Rascunho" (Memória Extra)
    // Usamos vector para garantir que o código compile em qualquer compilador (C++ padrão)
    vector<int> L(n1), R(n2);
    // PASSO 3: Copiar os elementos para os rascunhos
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    // PASSO 4: Mesclagem Ordenada (A comparação real)
    int i = 0; // Índice do rascunho esquerdo
    int j = 0; // Índice do rascunho direito
    int k = l; // Índice do vetor original onde vamos "devolver" os dados
    while (i < n1 && j < n2){
        if (L[i] <= R[j]) { // O menor "vence" e volta para o vetor original
            arr[k] = L[i];
            i++;
        } else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // PASSO 5: Limpeza das Sobras
    // Caso restem elementos em L (porque R acabou primeiro)
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    // Caso restem elementos em R (porque L acabou primeiro)
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

    //Incrementacao do passo para mostrar no relatorio
    passos++;
    int bufferExtra = n1 + n2; //Tamanho da memoria extra utilizada nesta parte
    
    cout << "Merge Passo " << passos << ": "; //Imprime o numero do passo
    imprimirEstadoAtual(arr, l, r); //Chama a funcao para mostrar o pedaco ordenado
    cout << " - ";
    cout << "Buffer Extra: " << bufferExtra << " elementos" << endl; //Mostra o uso de memoria extra
}


// =========================================================
// A LÓGICA DA DIVISÃO (FUNÇÃO RECURSIVA)
// Responsável por quebrar o problema em partes menores.
// =========================================================
void mergeSort(int arr[], int l, int r, int &contador, int &cont_merge){
    // PASSO 1: Condição de parada (Caso Base)
    // Se l >= r, significa que o sub-vetor tem apenas 1 elemento
    if (l < r){
        // PASSO 2: Encontrar o ponto médio
        int m = l + (r - l) / 2;

        //Incrementando o valor a cada divisao
        contador++;

        //Rastreamento da Descida
        cout << "Dividindo: ";
        imprimirEstadoAtual(arr, l, m); // Sub-vetor esquerdo
        cout << " e ";
        imprimirEstadoAtual(arr, m + 1, r); // Sub-vetor direito
        cout << endl;

        // PASSO 3: Divisão (Recursão)
        // Continua quebrando o lado esquerdo e o direito
        mergeSort(arr, l, m, contador, cont_merge); // Quebra a esquerda
        mergeSort(arr, m + 1, r, contador, cont_merge); // Quebra a direita
        // PASSO 4: União (Conquista)
        // Quando as funções acima retornam, chamamos o merge para organizar
        merge(arr, l, m, r, cont_merge);
    }
}

// =========================================================
// FUNCAO PARA ARRAY COM 20 NUMEROS ALEATORIOS SEM REPETIR
// Gera 20 numeros aleatorios diferentes para preencher o Array
// =========================================================
void ArrayAleatorio(int array[], int tamanho){
    int sorteados = 0; //Contador de numeros validos

    while (sorteados < tamanho){ //Loop para preencher todas as 20 posicoes
        int numSorteado = rand() % 100 + 1; //Sorteia entre 1 e 100
        bool repetido = false;

        for (int i = 0; i < sorteados; i++){ //Verifica se o numeroja existe nos que foram gerados
            if (array[i] == numSorteado){
                repetido = true;
                break; //Se achou igual, marca como repetido e sai do for
            }
        }

        if (!repetido){ //Se o numero nao for repetido, guarda no array e incrementa o numero total de numeros gerados
            array[sorteados] = numSorteado;
            sorteados++;
        }
    }
}

// =========================================================
// FUNCAO PARA EXIBIR O ARRAY
// Imprime Array desejada no terminal
// =========================================================
void imprimirArray(int arr[], int tamanho){
    for (int i = 0; i < tamanho; i++){ //Loop para imprimir array
        cout << arr[i];

        //Se for o ultimo elemento, vai ganhar ponto. Se nao, ganha virgula
        if (i == tamanho - 1) cout << ".";
        else cout << ", ";
    }
}

// =========================================================
// FUNÇÃO PRINCIPAL - MAIN
// =========================================================
int main() {
    const int tamanho = 20; //Tamanho padrao para Array data
    int data[tamanho]; //Array
    int copia_de_data[tamanho]; //Array para guardar o estado antes da ordenacao
    int nmr_divisoes = 0; //Contador para relatorio
    int passos_Merge = 0; //Contadoor para relatorio
    srand(time(0)); //Seed para os numeros serem aleatorios a cada execução

    //Funcao para gerar o array aleatorio
    ArrayAleatorio(data, tamanho);

    //Loop para copiar os valores de data para a copia
    for(int i = 0; i < tamanho; i++) copia_de_data[i] = data[i];
    
    cout << "Parte das divisoes MergeSort e Passos Merge" << endl;
    mergeSort(data, 0, tamanho - 1, nmr_divisoes, passos_Merge); //Vetor completo (do índice 0 até 19)
    cout << endl << endl;
    cout << "Parte do Relatorio Geral" << endl; //Parte final com relatorio
    cout << "Aluno: Arthur de Souza Mandu" << endl;
    cout << "Codigo Aluno: 2264814" << endl;
    cout << "Array Sorteado: "; //Imprime a copia(Array original)
    imprimirArray(copia_de_data, tamanho);
    cout << endl;
    cout << "Numero de divisoes: " << nmr_divisoes << endl;
    cout << "Numero de merges: " << passos_Merge << endl;
    cout << "Array Ordenado: "; //Imprime array ordenado
    imprimirArray(data, tamanho);
    return 0;
} 