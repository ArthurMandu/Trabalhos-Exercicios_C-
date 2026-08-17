//ARTHUR DE SOUZA MANDU - 2264814
//Trabalho: Quick Sort X Insertion Sort

#include <iostream> //Biblioteca padrao para entrada e saida
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()
#include <chrono>   // Biblioteca para medir tempo
#include <iomanip> //Para a tabela no final
using namespace std; //Namespace padrao

//Struct para padronizar e facilitar a organização e salvamento dos dados  
struct Estatisticas{
    long long duracao = 0; //Tempo de duracao
    long long comparacoes = 0; //numero de comparacoes
    long long trocas = 0; //numero de trocas
};

// Funcao para trocar de posicao dois elementos
void trocarElementos(int &a, int &b){
    int temp = a; //variavel auxiliar temporaria
    a = b; //troca os valores
    b = temp; //trocas os valores
}

// Funcao Partition do Quick Sort
//Posiciona o pivo na posicao correta
int partition(int array[], int baixo, int alto, long long &comparacoes, long long &trocas){

    int pivo = array[alto]; //define pivo como ultimo elemento
    int i = baixo - 1; //indice do menor elemento

    for(int j = baixo; j < alto; j++){ //percorre o array

        comparacoes++; //conta comparacao

        if(array[j] < pivo){ //verifica se o elemento atual e menor que o pivo
            i++; //avanca o indice do menor elemento

            trocarElementos(array[i], array[j]); //funcao para trocar os elementos
            trocas++; // Conta troca
        }
    }

    trocarElementos(array[i + 1], array[alto]); //coloca pivo na posicao correta
    trocas++; // Conta troca final do pivo

    return i + 1; //retorna a posicao do pivo
}

// Funcao do Quick Sort
void quickSort(int array[], int baixo, int alto, long long &comparacoes, long long &trocas){

    if(baixo < alto){ //varifica se existe elemento para ordenar
        int posicaoPivo = partition(array, baixo, alto, comparacoes, trocas); //particiona o array

        quickSort(array, baixo, posicaoPivo - 1, comparacoes, trocas); //ordena lado esquerdo

        quickSort(array, posicaoPivo + 1, alto, comparacoes, trocas); //ordena lado direito
    }
}

// Função do Insertion Sort
void insertionSort(int array[], int tamanho, long long &comparacoes, long long &trocas){

    for (int i = 1; i < tamanho; i++){ //percorre o vetor a partir do segundo elemento
        int chave = array[i];
        int j = i - 1;

        //move os elementos maiores para frente
        while (j >= 0){
            comparacoes++; //conta comparacao entre elementos

            if (array[j] > chave){ //verifica se elemento atual e maior que a chave
                array[j + 1] = array[j]; //move elemento para frente
                trocas++; //conta alteracao de posicao
                j--; //volta uma posicao
            }
            else{
                break; //cai aqui se ja estiver ordenado
            }
        }

        array[j + 1] = chave;
        trocas++; // Conta insercao da chave
    }
}

//Funcao para fazer uma apresentacao inicial do software
void apresentacao(){
    cout << "\033[1mEste software em C++ foi desenvolvido para comparar o desempenho dos algoritmos de ordenacao Quick Sort e Insertion Sort em diferentes cenarios de execucao. O programa realiza testes com vetores aleatorios, quase ordenados e invertidos, analisando o tempo de execucao, numero de comparacoes e quantidade de trocas realizadas por cada algoritmo. Os resultados sao organizados em tabelas no terminal, permitindo visualizar de forma pratica as diferencas de desempenho entre os metodos de ordenacao e relaciona-las com suas complexidades teoricas\033[0m" << endl;
    cout << endl;
}

//Funcao para responder as perguntas do relatorio de performance
void responderPerguntas(){
    cout << endl;
    cout << "\033[1m-------------Explicacao dos Fenomenos------------- \033[0m" << endl;
    cout << "\033[32mPor que a diferenca de performance entre os dois algoritmos foi tao drastica no Cenario 2 (10k quase ordenados)?\033[0m";
    cout << "\033[36m R: No Cenario 2 (10k quase ordenados), a diferenca de performance foi tao grande porque o Insertion Sort e extremamente eficiente quando o vetor ja esta quase em ordem. Nesse caso, ele precisa fazer poucas movimentacoes e comparacoes, aproximando seu desempenho de O(n). Enquanto o Quick Sort utilizado escolhe sempre o ultimo elemento como pivo. Em vetores quase ordenados, essa escolha gera divisoes desequilibradas, fazendo o algoritmo realizar muito mais chamadas recursivas e aumentando bastante o numero de comparacoes.\033[0m" << endl;
    cout << "\033[32mO que aconteceu com o Quick Sort no Cenario 3 (20k invertidos)? Ele secomportou como esperado?\033[0m";
    cout << "\033[36m R: No Cenario 3 (20.000 elementos invertidos), o Quick Sort se comportou exatamente como esperado para sua implementacao. Como o pivo escolhido foi sempre o ultimo elemento, e o vetor estava em ordem inversa, o pivo acabava sendo o menor elemento do trecho analisado. Isso fazia o particionamento ficar extremamente desbalanceado, levando o algoritmo ao pior caso de complexidade de O(n^2). Nesse cenario, o Quick Sort perde muita eficiencia e pode ate ficar mais lento que algoritmos simples.\033[0m" << endl;
    cout << "\033[32mNo cenario de 50 elementos, a complexidade teorica do Quick Sort o tornou visivelmente mais rapido que o Insertion?\033[0m";
    cout << "\033[36m R: No cenario de apenas 50 elementos, a complexidade teorica do Quick Sort não o tornou visivelmente mais rapido que o Insertion Sort. Isso acontece porque, em conjuntos pequenos, o custo das chamadas recursivas e do particionamento do Quick Sort pode compensar sua vantagem teorica. O Insertion Sort possui uma implementacao mais simples, com baixo custo operacional, funcionando muito bem para poucos elementos. Por isso, em vetores pequenos, e comum que ambos apresentem tempos parecidos, e as vezes o Insertion Sort pode ate ser mais rapido na pratica.\033[0m" << endl;
}

// Funcao para mostrar tabela comparativa
void MostrarTabela(const string &nomeAlgoritmo, const Estatisticas &etapa1, const Estatisticas &etapa2, const Estatisticas &etapa3){

    cout << endl;
    cout << "\033[1m==================== " << nomeAlgoritmo << " ====================\033[0m" << endl; //titulo 
    cout << endl;

    cout << left; //alinhamento a esquerda

    cout << "+----------------------+----------------+----------------+----------------+" << endl;

    //cabecalho
    cout << "| " << setw(20) << "Etapa"
        << "| " << setw(14) << "Tempo (us)"
        << "| " << setw(14) << "Comparacoes"
        << "| " << setw(14) << "Trocas"
        << "|" << endl;

    cout << "+----------------------+----------------+----------------+----------------+" << endl;

    // Etapa 1
    cout << "| " << setw(20) << "Aquecimento"
            << "| " << setw(14) << etapa1.duracao
        << "| " << setw(14) << etapa1.comparacoes
        << "| " << setw(14) << etapa1.trocas
        << "|" << endl;

    // Etapa 2
    cout << "| " << setw(20) << "Agulha no Palheiro"
        << "| " << setw(14) << etapa2.duracao
        << "| " << setw(14) << etapa2.comparacoes
        << "| " << setw(14) << etapa2.trocas
        << "|" << endl;

    // Etapa 3
    cout << "| " << setw(20) << "Pior Cenario"
        << "| " << setw(14) << etapa3.duracao
        << "| " << setw(14) << etapa3.comparacoes
        << "| " << setw(14) << etapa3.trocas
        << "|" << endl;

    cout << "+----------------------+----------------+----------------+----------------+" << endl;
}

// Função para mostrar estatisticas
void MostrarEstatisticas(long long comparacoes, long long trocas,std::chrono::microseconds duracao){
    cout << "Tempo de execucao: " << duracao.count() << " microssegundos" << endl;
    cout << "Total de comparacoes: " << comparacoes << endl;
    cout << "Total de trocas: "<< trocas << endl;
}

// Gera array em ordem decrescente
void GerarArrayDecrescente(int array[], int tamanho){

    int valor = tamanho;

    for(int i = 0; i < tamanho; i++){

        array[i] = valor;
        valor--;
    }
    cout << endl;
}

void GerarArrayAleatorio(int array[], int tamanho){
    int sorteados = 0; //Contador de numeros validos

    while (sorteados < tamanho){ //Loop para preencher todas as 50 posicoes
        int numSorteado = rand() % 100 + 1; // Sorteia entre 1 e 100
        bool repetido = false; //variavel de controle

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

// Gera array ordenado de 1 ate tamanho
void GerarArrayOrdenado(int array[], int tamanho){

    for(int i = 0; i < tamanho; i++){
        array[i] = i + 1;
    }
}

//Funcao para salvar o tempo de duracao em uma variavel da struct
void SalvarDuracao(long long duracao, Estatisticas &estatistica){  
    // Salva os valores na struct
    estatistica.duracao = duracao;
}

// Funcao para trocar 10 elementos aleatorios no array
void BaguncarArrayOrdenado(int array[], int tamanho){
    cout << endl;
    cout << "\033[1;33mEtapa 2: 10.000 Elementos\033[0m";
    cout << "\033[33m\nIndices sorteados para troca da Etapa 2: A Agulha no Palheiro:\033[0m" << endl;


    for(int i = 0; i < 10; i++){ //realiza 10 trocas aleatorias

        int indice1 = rand() % tamanho;
        int indice2 = rand() % tamanho;

        // Mostra os indices sorteados
        cout << "(" << indice1 << ", " << indice2 << ")" << endl;

        // Realiza a troca
        trocarElementos(array[indice1], array[indice2]);
    }
    cout << endl;
}

// Funcao para copiar um array para outro array
void CopiarArray(int array1[], int tamanho, int array2[]){
    //Loop para copiar os valores de uma array para outra
    for(int i = 0; i < tamanho; i++) array2[i] = array1[i];
}


int main(){
    const int tamanhoMax = 20000; //Tamanho maximo para Array
    int tamanhoEtapa1 = 50; //Tamanho para a etapa 1
    int tamanhoEtapa2 = 10000; //Tamanho para a etapa 2
    int tamanhoEtapa3 = 20000; //Tamanho para a etapa 3
    int arrayInsertion[tamanhoMax]; //Array vitima do Insertion
    int arrayQuick[tamanhoMax]; //Array vitima do Quick
    Estatisticas insertion1, insertion2, insertion3; //Structs para as etapas do Insertion Sort
    Estatisticas quick1, quick2, quick3; //Structs para as etapas do Quick Sort
    srand(time(0)); //Seed para os numeros serem aleatorios a cada execução

    apresentacao();

    //Funcao para gerar o array aleatorio
    GerarArrayAleatorio(arrayInsertion, tamanhoEtapa1);
    //Funcao para copiar o array para o outro
    CopiarArray(arrayInsertion, tamanhoEtapa1, arrayQuick);

    cout << "\033[1;31mEtapa 1: 50 Elementos\033[0m" << endl;
    cout << "\033[91mO Aquecimento - \033[0m";
    cout << "\033[42mInsertion Sort\033[0m" << endl;
    auto inicioInsertion = std::chrono::high_resolution_clock::now();   //Inicio da contagem de tempo  
    insertionSort(arrayInsertion, tamanhoEtapa1, insertion1.comparacoes, insertion1.trocas);
    auto fimInsertion = std::chrono::high_resolution_clock::now();  //Fim da contagem de tempo
    auto duracaoInsertion = std::chrono::duration_cast<std::chrono::microseconds>(fimInsertion - inicioInsertion);  //Calcula tempo em microssegundos
    MostrarEstatisticas(insertion1.comparacoes, insertion1.trocas, duracaoInsertion);   //Mostra Estatisticas

    cout << "\033[91mO Aquecimento - \033[0m";
    cout << "\033[46mQuick Sort\033[0m" << endl;
    auto inicioQuick = std::chrono::high_resolution_clock::now();    // Inicio da contagem de tempo
    quickSort(arrayQuick, 0, tamanhoEtapa1 - 1, quick1.comparacoes, quick1.trocas);
    auto fimQuick = std::chrono::high_resolution_clock::now();   // Fim da contagem de tempo
    auto duracaoQuick = std::chrono::duration_cast<std::chrono::microseconds>(fimQuick - inicioQuick); // Calcula tempo em microssegundos
    MostrarEstatisticas(quick1.comparacoes, quick1.trocas, duracaoQuick);  // Mostra estatisticas

    //salvar duracao em suas devidas structs
    SalvarDuracao(duracaoInsertion.count(), insertion1);
    SalvarDuracao(duracaoQuick.count(), quick1);

    // Funcao para gerar array ordenado
    GerarArrayOrdenado(arrayInsertion, tamanhoEtapa2);

    // Funcao que faz a bagunca
    BaguncarArrayOrdenado(arrayInsertion, tamanhoEtapa2);

    //Funcao para copiar o array para o outro
    CopiarArray(arrayInsertion, tamanhoEtapa2, arrayQuick);

    cout << "\033[93mA Agulha no Palheiro - \033[0m";
    cout << "\033[42mInsertion Sort\033[0m" << endl;
    auto inicioInsertion2 = std::chrono::high_resolution_clock::now();    // Inicio da contagem de tempo
    insertionSort(arrayInsertion, tamanhoEtapa2, insertion2.comparacoes, insertion2.trocas);
    auto fimInsertion2 = std::chrono::high_resolution_clock::now();   // Fim da contagem de tempo
    auto duracaoInsertion2 = std::chrono::duration_cast<std::chrono::microseconds>(fimInsertion2 - inicioInsertion2); // Calcula tempo em microssegundos
    MostrarEstatisticas(insertion2.comparacoes, insertion2.trocas, duracaoInsertion2);  // Mostra estatisticas

    cout << "\033[93mA Agulha no Palheiro - \033[0m";
    cout << "\033[46mQuick Sort\033[0m" << endl;
    auto inicioQuick2 = std::chrono::high_resolution_clock::now();    // Inicio da contagem de tempo
    quickSort(arrayQuick, 0, tamanhoEtapa2 - 1, quick2.comparacoes, quick2.trocas);
    auto fimQuick2 = std::chrono::high_resolution_clock::now();   // Fim da contagem de tempo
    auto duracaoQuick2 = std::chrono::duration_cast<std::chrono::microseconds>(fimQuick2 - inicioQuick2); // Calcula tempo em microssegundos
    MostrarEstatisticas(quick2.comparacoes, quick2.trocas, duracaoQuick2);  // Mostra estatisticas

    //salvar duracao em suas devidas structs
    SalvarDuracao(duracaoInsertion2.count(), insertion2);
    SalvarDuracao(duracaoQuick2.count(), quick2);

    // Funcao para gerar array decrescente
    GerarArrayDecrescente(arrayInsertion, tamanhoEtapa3);

    // Copia para o Quick
    CopiarArray(arrayInsertion, tamanhoEtapa3, arrayQuick);

    cout << "\033[1;35mEtapa 3: 20.000 Elementos\033[0m" << endl;
    cout << "\033[95mO Pior Cenario - \033[0m";
    cout << "\033[42mInsertion Sort\033[0m" << endl;
    auto inicioInsertion3 = std::chrono::high_resolution_clock::now();    // Inicio da contagem de tempo
    insertionSort(arrayInsertion, tamanhoEtapa3, insertion3.comparacoes, insertion3.trocas);
    auto fimInsertion3 = std::chrono::high_resolution_clock::now();   // Fim da contagem de tempo
    auto duracaoInsertion3 = std::chrono::duration_cast<std::chrono::microseconds>(fimInsertion3 - inicioInsertion3); // Calcula tempo em microssegundos
    MostrarEstatisticas(insertion3.comparacoes, insertion3.trocas, duracaoInsertion3);  // Mostra estatisticas

    cout << "\033[95mO Pior Cenario - \033[0m";
    cout << "\033[46mQuick Sort\033[0m" << endl;
    auto inicioQuick3 = std::chrono::high_resolution_clock::now();    // Inicio da contagem de tempo
    quickSort(arrayQuick, 0, tamanhoEtapa3 - 1, quick3.comparacoes, quick3.trocas);
    auto fimQuick3 = std::chrono::high_resolution_clock::now();   // Fim da contagem de tempo
    auto duracaoQuick3 = std::chrono::duration_cast<std::chrono::microseconds>(fimQuick3 - inicioQuick3); // Calcula tempo em microssegundos
    MostrarEstatisticas(quick3.comparacoes, quick3.trocas, duracaoQuick3);  // Mostra estatisticas

    //salvar duracao em suas devidas structs
    SalvarDuracao(duracaoInsertion3.count(), insertion3);
    SalvarDuracao(duracaoQuick3.count(), quick3);

    cout << endl;
    MostrarTabela( "INSERTION SORT", insertion1, insertion2, insertion3);
    MostrarTabela( "QUICK SORT", quick1, quick2, quick3);

    responderPerguntas();
    return 0;
}