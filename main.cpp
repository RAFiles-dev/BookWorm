#include <locale.h>
#include "terminal.h"

int main() {
  setlocale(LC_ALL, "Portuguese");
    
  bool loop1, loop2;
  char tecla;
  
  loop1 = true;
  while(loop1) {
    limpar();
    printTxt("bookworm.txt");
    cout << endl;
    cout << "Registre a sua jornada pelo universo liter�rio!\n";
    cout << endl;
    cout << "Para escolher uma op��o, aperte o n�mero correspondente:\n";
    cout << "1) Adicionar uma obra\n";
    cout << "2) Listar todas as obras registrada\n";
    cout << "3) Pesquisar por uma obra registrada\n";
    cout << "4) Alterar uma obra registrada\n";
    cout << "5) Remover uma obra registrada\n";
    cout << "6) Exibir um relat�rio\n";
    cout << "7) Sair do programa\n";
    tecla = getTecla();
    switch(tecla) {
      case '1':
        limpar();
        cout << "Op��o 1 escolhida\n";
        parar(13);
        break;
      case '2':
        limpar();
        cout << "Op��o 2 escolhida\n";
        parar(13);
        break;
      case '3':
        limpar();
        cout << "Op��o 3 escolhida\n";
        parar(13);
        break;
      case '4':
        limpar();
        cout << "Op��o 4 escolhida\n";
        parar(13);
        break;
      case '5':
        limpar();
        cout << "Op��o 5 escolhida\n";
        parar(13);
        break;
      case '6':
        limpar();
        cout << "Op��o 6 escolhida\n";
        parar(13);
        break;
      case '7':
        loop2 = true;
        while(loop2) {
            limpar();
            cout << "Voc� realmente deseja sair? [s/n]\n";
            tecla = getTecla();
            switch(tecla) {
                case 's':
                     loop1 = loop2 = false;
                case 'n':
                     loop2 = false;
            }
        }
        break;
      default:
        limpar();
        cout << "Op��o inv�lida";
        parar(13);
        break;
    }
  }

  return 0;
}
