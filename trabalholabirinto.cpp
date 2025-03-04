#include <iostream>
#include <string>

using namespace std;

const int tamanho = 5;

    //0 Caminho Livre, 1 Parede, 2 Posição inicial do Player, 3 Saída
    int labirinto[tamanho][tamanho] = {
        {0, 1, 0, 0, 3},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {2, 0, 0, 0, 0}
    };

    int jogadori = 4;
    int jogadorj = 0;
    bool jogadorvivo = true;


void exibirmapa(){
    for(int i = 0; i < tamanho; i++){
        cout << "| ";
        for(int j = 0; j < tamanho; j++){
            if(i == jogadori && j == jogadorj){
                cout << "J ";
            }else{
            switch(labirinto[i][j]){
                case 0:
                    cout << ". ";
                    break;
                case 1:
                    cout << "# ";
                    break;
                case 3:
                    cout << "S ";
                    break;
                default:
                    cout << ". ";
                    break;
                }
            }
        }
        cout << "|" << endl;
    }
}

void movimento(char move){
    int novoi = jogadori;
    int novoj = jogadorj;

    if (move == 'w'){
        novoi--;
    }else if (move == 's'){
        novoi++;
    }else if (move == 'a'){
        novoj--;
    }else if (move == 'd'){
        novoj++;
    }

    if(novoi >= 0 && novoi < tamanho && novoj >= 0 && novoj < tamanho && (labirinto[novoi][novoj] == 0 || labirinto[novoi][novoj] == 3 || labirinto[novoi][novoj] == 2)){
        jogadori = novoi;
        jogadorj = novoj;
    }else if(novoi >= 0 && novoi < tamanho && novoj >= 0 && novoj < tamanho && (labirinto[novoi][novoj] == 1)){
        cout << "Ops! O Jogador acabou nao vendo a parede em sua frente..." << endl;
        cout << "Game Over";
        jogadorvivo = false;
    }else{
        cout << "Movimento invalido" << endl;
        cout << "Tome cuidado com aquilo que voce deseja jogador!" << endl;
    }
}

bool vitoria(){
    cout << "EEBBAAAA! O Jogador encontrou a saida!" << endl;
    cout << "Jogador saiu tranquilamente do Labirinto" << endl;
    cout << "Player Wins";
    return true;
}


int main(){
    char jogada;
    cout << "ESCAPE DO LABIRINTO - Meiro kara no dasshutsu " << endl;
    while(jogadorvivo){
        exibirmapa();
        cout << "Digite o Comando (W - Cima, A - Esquerda, S - Baixo, D - Direita): ";
        cin >> jogada;
        jogada = tolower(jogada);
        system("cls");
        movimento(jogada);

        if (labirinto[jogadori][jogadorj] == 3){
            vitoria();
            break;
            }   
    }
    return 0;
}