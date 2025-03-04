#include <iostream>
#include <string>
#include <limits>
#include <iomanip>


using namespace std;

int main(){
    int pedido, lanche, bebidas, sobremesa;
    float valor1 = 0, comida, quantidade;
    string nome;
    cout << "Bem Vindo a Lanchonete Senhor!! " << endl;
    cout << "Antes de comecarmos o atendimento, pf insira o seu nome: ";
    getline(cin , nome);
    
    cout << "Ola " << nome << "!";
    do{
    pedido = 0;
    cout << "\nPor favor, escolha a categoria desejada:" << endl;
    cout << "1 - Lanches" << endl;
    cout << "2 - Bebidas" << endl;
    cout << "3 - Sobremesas" << endl;
    cout << "4 - Finalizar Pedido" << endl;
    cin >> pedido;

    if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Desculpa Senhor, ocorreu algum erro. Por favor, tente novamente!" << endl;
            pedido = 0;
        }else{
        
        switch (pedido){
        case 1:
        cout << "Vc escolheu a opcao 1 - Lanches!" << endl;
        cout << "Lanches Disponiveis: " << endl;
        cout << " 1 - Hamburguer (R$ 10,00)" << endl;
        cout << "2 - Cheeseburguer (R$ 12,00)"<< endl;
        cout << "3 - X Bacon (R$ 15,00)" << endl;
        cin >> lanche;

            switch(lanche){
                case 1:
                    comida = 10.00;
                    cout << "Vc escolheu a opcao 1 - Hamburguer" << endl;
                    cout << "Qual a quantidade do pedido?" << endl;
                    cin >> quantidade;
                    cout << "Vc escolheu " << quantidade << " Hamburguer(s)" << endl;
                    valor1 += quantidade * comida;
                    cout << "Vamos te redirecionar para o menu. Caso queira sair, apenas finalize o pedido";
                    system("cls");
                    break;


                case 2:
                    comida = 12.00;
                    cout << "Vc escolheu a opcao 2- Cheeseburguer" << endl;
                    cout << "Qual a quantidade do pedido?" << endl;
                    cin >> quantidade;
                    cout << "Vc escolheu " << quantidade << " Cheeseburguer(s)" << endl;
                    valor1 += quantidade * comida;
                    cout << "Vamos te redirecionar para o menu. Caso queira sair, apenas finalize o pedido";
                    system("cls");
                    break;

                case 3:
                  comida = 15.00;
                  cout << "Vc esccolheu a opcao 3 - X Bacon" << endl;
                  cout << "Qual a quantidade do pedido?" << endl;
                  cin >> quantidade;
                  cout << "Vc escolheu " << quantidade << " X Bacon(s)" << endl;
                  valor1 += quantidade * comida;
                  cout << "Vamos te redirecionar para o menu. Caso queira sair, apenas finalize o pedido";
                  system("cls");
                  break;

                default:
                  cout << "Opcao Invalida, tente novamente" << endl;
                  break;

              }
              break;

        case 2:
          cout << "Vc escolheu a opcao 2 - Bebidas!" << endl;
          cout << "Bebidas Disponiveis: " << endl;
          cout << "1 - Refrigerantes (R$ 5,00)" << endl;
          cout << "2 - Suco (R$ 7,00)" << endl;
          cout << "3 - Agua (R$ 3,00)" << endl;
          cin >> bebidas;

            switch(bebidas){
                case 1:
                  comida = 5.00;
                  cout << "Vc escolhu a opcao 1 - Refrigerantes" << endl;
                  cout << "Qual a quantidade do pedido?" << endl;
                  cin >> quantidade;
                  cout << "Vc escolheu " << quantidade << " Refrigerante(s)" << endl;
                  valor1 += quantidade * comida;
                  cout << "Vamos te redirecionar para o menu. Caso queira sair, apenas finalize o pedido";
                  system("cls");

                  break;
        
                case 2:
                  comida =7.00;
                  cout << "Vc escolheu a opcao 2 - Suco" << endl;
                  cout << "Qual a quantidade do pedido?" << endl;
                  cin >> quantidade;
                  cout << "Vc escolheu " << quantidade << " Suco(s)" << endl;
                  valor1 += quantidade * comida;
                  cout << "Vamos te redirecionar para o menu. Caso queira sair, apenas finalize o pedido";
                  system("cls");
                  break;

                case 3:
                  comida = 3.00;
                  cout << "Vc escolheu a opcao 3- Agua" << endl;
                  cout << "Qual a quantidade do pedido?" << endl;
                  cin >> quantidade;
                  cout << "Vc escolheu " << quantidade << " Agua(s)" << endl;
                  valor1 += quantidade * comida;
                  cout << "Vamos te redirecionar para o menu. Caso queira sair, apenas finalize o pedido";
                  system("cls");
                  break;

                default:
                  cout << "Opcao Invalida, tente novamente" << endl;
                  break;
    
              }
              break;

        case 3:
          cout << "Vc escolheu a opcao 3 - Sobremesas!" << endl;
          cout << "Sobremesas Disponiveis: " << endl;
          cout << "1 - Sorvete (R$ 8,00)" << endl;
          cout << "2 - Bolo (R$ 6,00)" << endl;
          cout << "3 - Pudim (R$ 5,00)" << endl;
          cin >> sobremesa;

            switch(sobremesa){
              case 1:
                comida = 8.00;         
                cout << "Vc escolheu a opcao 1 - Sorvete" << endl;
                cout << "Qual a quantidade do pedido?" << endl;
                cin >> quantidade;
                cout << "Vc escolheu " << quantidade << " Sorvete(s)" << endl;
                valor1 += quantidade * comida;
                cout << "Vamos te redirecionar para o menu. Caso queira sair, apenas finalize o pedido";
                system("cls");
                break;
        
              case 2:
                comida = 6.00;
                cout << "Vc escolheu a opcao 2 - Bolo" << endl;
                cout << "Qual a quantidade do pedido?" << endl;
                cin >> quantidade;
                cout << "Vc escolheu " << quantidade << " Bolo(s)" << endl;
                valor1 += quantidade * comida;
                cout << "Vamos te redirecionar para o menu. Caso queira sair, apenas finalize o pedido";
                system("cls");
                break;

              case 3:
                comida = 5.00;
                cout << "Vc escolheu a opcao 3 - Pudim" << endl;
                cout << "Qual a quantidade do pedido?" << endl;
                cin >> quantidade;
                cout << "Vc escolheu " << quantidade << " Pudim(ns)" << endl;
                valor1 += quantidade * comida;
                cout << "Vamos te redirecionar para o menu. Caso queira sair, apenas finalize o pedido";
                system("cls");
                break;
        
              default:
                cout << "Opcao Invalida, tente novamente" << endl;
                break;
              }
              break;

        case 4:
          cout << "Vc desejou finalizar o pedido" << endl;
          cout << "Estamos te redirecionando para o pagamento" << endl;
          break;
      
        default:
          cout << "Opcao invalida, tente novamente" << endl;
          break;

            break;
            }
        }

    }while(pedido != 4);

    cout << fixed << setprecision(2);
    cout << "Seu pedido ficou por: R$" << valor1 << endl;
      if(valor1 > 50){
        cout << "Por sua compra ter dado mais de R$ 50,00, voce ganhou um deconto de 10%" << endl;
        valor1 -= ((valor1 * 10) / 100);
        } else{
        cout << "Seu pedido nao foi superior a condicao minima para o desconto" << endl;
      }
      cout << "Seu pedido saira por R$ " << valor1 << endl;
      cout << "Obrigado pela sua compra! Volte Sempre!" << endl;
    return 0;
  }