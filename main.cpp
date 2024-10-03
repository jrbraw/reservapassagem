#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits>
#include <locale.h>
#include <typeinfo>

using namespace std;

void verifica_erro()
{
    cin.clear();  // Limpa o estado de erro de cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpa o buffer de entrada
    cout << "Opçãoo inválida! Por favor, digite uma opção válida. \n";
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
    int fileira, indicePoltrona, trocar_tipo,
    tipo_passagem = 0, numero_fileiras = 10, numero_poltronas = 6;
    char continuar, poltrona, manter_assento;
    char assentos[10][6];

    //SETA O IDIOMA PARA O LOCAL
    setlocale(LC_ALL,"");

    //DEFINE TODOS ASSENTOS COMO LIVRES
    for (int i = 0; i < numero_fileiras; i++){
        for (int j = 0; j < numero_poltronas; j++){
            assentos[i][j] = 'L';
        }
    }

    
    

    while (toupper(continuar) != 'N'){

        bool etapa_fileira = false, etapa_poltrona = false,  etapa_tipo = false;

        //LISTA ASSENTOS
        lista_assentos(assentos);

        while (etapa_fileira == false){
            cout << "Digite a fileira (1-10): ";
            cin >> fileira;
            fileira--;

            // Valida o campo contra erros e dados inválidos.
            if (fileira > 10 || fileira < 0 || std::cin.fail()){
                verifica_erro();
            }else etapa_fileira = true; // Se a entrada for válida, saia do loop.
        }

        while (etapa_poltrona == false){
            cout << "Digite a poltrona [A][B][C][D][E][F]: ";
            cin >> poltrona;
            indicePoltrona = toupper(poltrona) - 'A';

            if (indicePoltrona < 0 || indicePoltrona > 5 || std::cin.fail())
            {
                verifica_erro();
            }else etapa_poltrona = true;  // Se a entrada for válida, saia do loop.
        }

        // Verifica se o assento já está reservado.
        if (assentos[fileira][indicePoltrona] == 'R'){
            cout << "Esse assento já está reservado. Por favor, escolha outro." << endl;
            continue;
        }
        
        while (etapa_tipo == false) {
            
            cout << "Tipo de passagem (1-Executivo, 2-Econômico): ";
            cin >> tipo_passagem;
            
            switch (tipo_passagem){
            case 1:
                cout << indicePoltrona << endl;
                if(indicePoltrona != 0 && indicePoltrona != 5){
                    cout << "Passagem executiva tem prioridade nos assentos [A] e [F]." << endl;
                    cout << "Deseja manter o assento? (s/n): ";
                    cin >> manter_assento;

                    switch (toupper(manter_assento)){
                    case 'S':
                        assentos[fileira][indicePoltrona] = 'R';
                        cout << "Assento reservado com sucesso." << endl;
                        break;
                    case 'N':
                        break;
                    default:
                        verifica_erro();
                        break;
                    }

                }else{
                    assentos[fileira][indicePoltrona] = 'R';
                    cout << "Assento reservado com sucesso." << endl;
                }
                
                etapa_tipo = true;
                break;
            case 2:
                cout << "Tipo de passagem 2-Econômico" << endl;
                if(indicePoltrona == 0 || indicePoltrona == 5){
                    cout << "Passagem Econômica não é permitido para os assentos [A] e [F]" << endl;
                    cout << "Você deseja trocar o tipo de passagem ou Cancelar? (1-Trocar tipo, 2 - Cancelar): ";
                    cin >> trocar_tipo;

                    switch (trocar_tipo)
                    {
                    case 1:
                        break;
                    case 2:
                        etapa_tipo = true;
                        break;
                    default:
                        verifica_erro();
                        break;
                    }

                }
                
                break;            
            default:
                verifica_erro();
                break;
            }   
        }

        cout << "Deseja reservar outra passagem? (s/n):";
        cin >> continuar;

        switch (toupper(continuar))
        {
        case 'S':
            break;        
        case 'N':
            continuar = 'N';
            lista_assentos(assentos);
            return 0;        
        default:
            verifica_erro();
            break;
        }

        

    }


    return 0;
}
