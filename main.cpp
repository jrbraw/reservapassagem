#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits>
#include <locale.h>

using namespace std;

void verifica_erro()
{
    cin.clear();  // Limpa o estado de erro de cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpa o buffer de entrada
    cout << "Op��o inv�lida! Por favor, digite uma op��oo v�lida. \n";
}

void lista_assentos(char assentos[10][6]) {
    cout << "   A B C D E F" << endl;
    for (int i = 0; i < 10; i++) {
        // Formatacao do numero de linha (1 a 9 com dois espa�os, 10 com um espa�o)
        (i + 1 < 10) ? cout << i + 1 << "  " : cout << i + 1 << " ";

        // Listando os assentos para cada fileira
        for (int j = 0; j < 6; j++) {
            cout << assentos[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    //DECLARAR VARIAVEIS
    int fileira, indicePoltrona,
    tipo_passagem = 0, numero_fileiras = 10, numero_poltronas = 6;
    char continuar, poltrona;
    char assentos[10][6];

    //SETA O IDIOMA PARA O LOCAL
    setlocale(LC_ALL,"");

    //DEFINE TODOS ASSENTOS COMO LIVRES
    for (int i = 0; i < numero_fileiras; i++){
        for (int j = 0; j < numero_poltronas; j++){
            assentos[i][j] = 'L';
        }
    }

    //LISTA ASSENTOS
    lista_assentos(assentos);

    while (toupper(continuar) != 'N')
    {
        while (true){
            cout << "Digite a fileira (1-10): ";
            cin >> fileira;
            fileira--;
            // Valida o campo contra erros e dados inv�lidos.
            if (fileira > 10 || fileira < 0 || std::cin.fail()){
                verifica_erro();
            }else break; // Se a entrada for v�lida, saia do loop.
        }



        

    }


    return 0;
}
