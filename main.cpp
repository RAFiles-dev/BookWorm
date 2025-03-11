#include <locale.h>
#include "terminal.h"
#include "biblioteca.h"

int main() {
  cBibliotecario b;
  cGerenciadorCrud gc;
  
  setlocale(LC_ALL, "Portuguese");
    
  bool loop1, loop2, loop3, loop4;
  char tecla;
  string nome;
  string autor;
  int numPag;
  
  loop1 = true;
  while(loop1) {
    limpar();
    printTxt("bookworm.txt");
    cout << endl;
    cout << "Guarde a sua jornada pelo universo cultural!\n";
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
        loop2 = true;
        while(loop2) {
          limpar();
          cout << "Adicionando uma obra :D\n";
          cout << endl;
          cout << "Selecione o tipo de obra que deseja registrar:\n";
          cout << "1) Livro\n";
          cout << "2) Filme\n";
          cout << "3) S�rie\n";
          cout << endl;
          cout << "4) Voltar\n";
          tecla = getTecla();
          switch(tecla) {
            case '1':
              loop3 = true;
              while(loop3) {
                limpar();
                cout << "Adicionando um livro :D\n";
                cout << endl;
                cout << "Digite o nome do livro (ou \"voltar\")\n";
                cout << ">> ";
                getline(cin, nome);
                cout << endl;
                cout << "Voc� confirma esse nome? [s/n]\n";
                loop4 = true;
                while(loop4) {
                  tecla = getTecla();
                  switch(tecla) {
                    case 's':
                      loop3 = loop4 = false;
                    case 'n':
                      loop4 = false;
                  }    
                }
              }
              loop3 = true;
              while(loop3) {
                limpar();
                cout << "Adicionando um livro :D\n";
                cout << endl;
                cout << "Digite o nome do(s) autor(es): ";
                getline(cin, autor);
                cout << endl;
                cout << "Voc� confirma o(s) autor(es)? [s/n]\n";
                loop4 = true;
                while(loop4) {
                  tecla = getTecla();
                  switch(tecla) {
                    case 's':
                      loop3 = loop4 = false;
                    case 'n':
                      loop4 = false;
                  }    
                }
              }
              loop3 = true;
              while(loop3) {
                limpar();
                cout << "Adicionando um livro :D\n";
                cout << endl;
                cout << "Digite o n�mero de p�ginas: ";
                cin >> numPag;
                cout << endl;
                cout << "Voc� confirma o n�mero de p�ginas? [s/n]\n";
                loop4 = true;
                while(loop4) {
                  tecla = getTecla();
                  switch(tecla) {
                    case 's':
                      loop3 = loop4 = false;
                    case 'n':
                      loop4 = false;
                  }    
                }
              }
              limpar();
              cout << "Adicionando um livro :D\n";
              cout << endl;
              cout << "Nome: " << nome << endl;
              cout << "Autor(es): " << autor << endl;
              cout << "N�mero de p�ginas: " << numPag << endl;
              cout << endl;
              cout << "Voc� deseja registrar com essas informa��es? [s/n]\n";
              loop3 = true;
                while(loop3) {
                  tecla = getTecla();
                  switch(tecla) {
                    case 's':
                      loop2 = loop3 = false;
                    case 'n':
                      loop4 = false;
                  }    
                }
            case '2':
              cout << "Adicionando um filme :D\n";
            case '3':
              cout << "Adicionando uma s�rie :D\n";
            case '4':
                 loop2 = false;
          }
        }
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
