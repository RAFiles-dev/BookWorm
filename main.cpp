#include <locale.h>
#include <iostream>
#include "terminal.h"
#include "biblioteca.h"
#include "crud.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    cBibliotecario b;
    cGerenciadorCrud gc;
    
    gc.carregar(b);

    bool loop1, loop2, loop3, loop4;
    char tecla;

    string nome;
    string genero;
    string autor;
    string descricao;
    string tipo;

    int paginas;
    int capitulos;

    string estilo;
    
    int h;
    int m;
    int s;
    
    int temporadas;
    int m_episodios;

    loop1 = true;
    while (loop1) {
        limpar();
        printTxt("artark.txt");
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
        switch (tecla) {
            case '1':
                loop2 = true;
                while (loop2) {
                    limpar();
                    cout << "Adicionado uma obra :D\n";
                    cout << endl;
                    cout << "Digite o nome do obra: ";
                    getline(cin, nome);
                    cout << endl;
                    cout << "Voc� confirma esse nome? [s/n]\n";
                    loop3 = true;
                    while (loop3) {
                        tecla = getTecla();
                        switch (tecla) {
                            case 's':
                                loop2 = loop3 = false;
                            case 'n':
                                loop3 = false;
                        }
                    }
                }
                loop2 = true;
                while (loop2) {
                    limpar();
                    cout << "Adicionando uma obra :D\n";
                    cout << endl;
                    cout << "Digite o g�nero: ";
                    getline(cin, genero);
                    cout << endl;
                    cout << "Voc� confirma esse(s) autor(es)? [s/n]\n";
                    loop3 = true;
                    while (loop3) {
                        tecla = getTecla();
                        switch (tecla) {
                            case 's':
                                loop2 = loop3 = false;
                            case 'n':
                                loop3 = false;
                        }
                    }
                }
                loop2 = true;
                while (loop2) {
                    limpar();
                    cout << "Adicionando uma obra :D\n";
                    cout << endl;
                    cout << "Digite o(s) autor(es) da obra: ";
                    getline(cin, autor);
                    cout << endl;
                    cout << "Voc� confirma esse(s) autor(es)? [s/n]\n";
                    loop3 = true;
                    while (loop3) {
                        tecla = getTecla();
                        switch (tecla) {
                            case 's':
                                loop2 = loop3 = false;
                            case 'n':
                                loop3 = false;
                        }
                    }
                }
                loop2 = true;
                while (loop2) {
                    limpar();
                    cout << "Adicionando uma obra :D\n";
                    cout << endl;
                    cout << "Digite uma descri��o: ";
                    getline(cin, descricao);
                    cout << endl;
                    cout << "Voc� confirma essa descri��o? [s/n]\n";
                    loop3 = true;
                    while (loop3) {
                        tecla = getTecla();
                        switch (tecla) {
                            case 's':
                                loop2 = loop3 = false;
                            case 'n':
                                loop3 = false;
                        }
                    }
                }
                loop2 = true;
                while (loop2) {
                    limpar();
                    cout << "Adicionando uma obra :D\n";
                    cout << endl;
                    cout << "Selecione o tipo de obra que deseja registrar:\n";
                    cout << "1) Livro\n";
                    cout << "2) Quadrinho\n";
                    cout << "3) Filme\n";
                    cout << "4) S�rie\n";
                    tecla = getTecla();
                    switch (tecla) {
                        case '1':
                            tipo = "Livro";
                            break;
                        case '2':
                            tipo = "Quadrinho";
                            break;
                        case '3':
                            tipo = "Filme";
                            break;
                        case '4':
                            tipo = "S�rie";
                            break;
                    }
                    cout << endl;
                    cout << "Voc� confirma esse tipo (" << tipo << ")? [s/n]\n";
                    loop3 = true;
                    while (loop3) {
                        tecla = getTecla();
                        switch (tecla) {
                            case 's':
                                loop2 = loop3 = false;
                            case 'n':
                                loop3 = false;
                        }
                    }
                }
                if (tipo == "Livro") {
                    loop2 = true;
                    while (loop2) {
                        limpar();
                        cout << "Adicionando um livro :D\n";
                        cout << endl;
                        cout << "Digite o n�mero de p�ginas: ";
                        cin >> paginas;
                        cin.ignore();
                        cout << endl;
                        cout << "Voc� confirma essa descri��o? [s/n]\n";
                        loop3 = true;
                        while (loop3) {
                            tecla = getTecla();
                            switch (tecla) {
                                case 's':
                                    loop2 = loop3 = false;
                                case 'n':
                                    loop3 = false;
                            }
                        }
                    }
                    loop2 = true;
                    while (loop2) {
                        limpar();
                        cout << "Adicionando um livro :D\n";
                        cout << endl;
                        cout << "Digite o n�mero de capitulos: ";
                        cin >> capitulos;
                        cin.ignore();
                        cout << endl;
                        cout << "Voc� confirma essa descri��o? [s/n]\n";
                        loop3 = true;
                        while (loop3) {
                            tecla = getTecla();
                            switch (tecla) {
                                case 's':
                                    loop2 = loop3 = false;
                                case 'n':
                                    loop3 = false;
                            }
                        }
                    }
                    b.adicionar(cLivro(nome, genero, autor, descricao, "Livro", paginas, capitulos), true);
                    gc.salvar(b.getObras());
                } else if (tipo == "Quadrinho") {
                    loop2 = true;
                    while (loop2) {
                        limpar();
                        cout << "Adicionando um quadrinho :D\n";
                        cout << endl;
                        cout << "Digite o n�mero de p�ginas: ";
                        cin >> paginas;
                        cin.ignore();
                        cout << endl;
                        cout << "Voc� confirma essa descri��o? [s/n]\n";
                        loop3 = true;
                        while (loop3) {
                            tecla = getTecla();
                            switch (tecla) {
                                case 's':
                                    loop2 = loop3 = false;
                                case 'n':
                                    loop3 = false;
                            }
                        }
                    }
                    loop2 = true;
                    while (loop2) {
                        limpar();
                        cout << "Adicionando um quadrinho :D\n";
                        cout << endl;
                        cout << "Digite o n�mero de capitulos: ";
                        cin >> capitulos;
                        cin.ignore();
                        cout << endl;
                        cout << "Voc� confirma essa descri��o? [s/n]\n";
                        loop3 = true;
                        while (loop3) {
                            tecla = getTecla();
                            switch (tecla) {
                                case 's':
                                    loop2 = loop3 = false;
                                case 'n':
                                    loop3 = false;
                            }
                        }
                    }
                    loop2 = true;
                    while (loop2) {
                        limpar();
                        cout << "Adicionando um quadrinho :D\n";
                        cout << endl;
                        cout << "Digite o estilo de desenho: ";
                        getline(cin, estilo);
                        cout << endl;
                        cout << "Voc� confirma essa descri��o? [s/n]\n";
                        loop3 = true;
                        while (loop3) {
                            tecla = getTecla();
                            switch (tecla) {
                                case 's':
                                    loop2 = loop3 = false;
                                case 'n':
                                    loop3 = false;
                            }
                        }
                    }
                    b.adicionar(cQuadrinho(nome, genero, autor, descricao, "Quadrinho", paginas, capitulos, estilo), true);
                } else if (tipo == "Filme") {
                    loop2 = true;
                    while (loop2) {
                        limpar();
                        cout << "Adicionando um filme :D\n";
                        cout << endl;
                        cout << "Digite a dura��o (utilize espa�o para separar): ";
                        cin >> h >> m >> s;
                        cin.ignore();
                        cout << endl;
                        cout << "Voc� confirma essa descri��o? [s/n]\n";
                        loop3 = true;
                        while (loop3) {
                            tecla = getTecla();
                            switch (tecla) {
                                case 's':
                                    loop2 = loop3 = false;
                                case 'n':
                                    loop3 = false;
                            }
                        }
                    }
                    b.adicionar(cFilme(nome, genero, autor, descricao, "Filme", h, m, s), true);
                } else if (tipo == "S�rie") {
                    loop2 = true;
                    while (loop2) {
                        limpar();
                        cout << "Adicionando uma s�rie :D\n";
                        cout << endl;
                        cout << "Digite o n�mero de temporadas: ";
                        cin >> temporadas;
                        cin.ignore();
                        cout << endl;
                        cout << "Voc� confirma essa descri��o? [s/n]\n";
                        loop3 = true;
                        while (loop3) {
                            tecla = getTecla();
                            switch (tecla) {
                                case 's':
                                    loop2 = loop3 = false;
                                case 'n':
                                    loop3 = false;
                            }
                        }
                    }
                    loop2 = true;
                    while (loop2) {
                        limpar();
                        cout << "Adicionando uma s�rie :D\n";
                        cout << endl;
                        cout << "Digite o n�mero m�dio de episodios por temporada: ";
                        cin >> m_episodios;
                        cin.ignore();
                        cout << endl;
                        cout << "Voc� confirma essa descri��o? [s/n]\n";
                        loop3 = true;
                        while (loop3) {
                            tecla = getTecla();
                            switch (tecla) {
                                case 's':
                                    loop2 = loop3 = false;
                                case 'n':
                                    loop3 = false;
                            }
                        }
                    }
                    loop2 = true;
                    while (loop2) {
                        limpar();
                        cout << "Adicionando uma s�rie :D\n";
                        cout << endl;
                        cout << "Digite a dura��o m�dia de um epis�dio (utilize espa�o para separar): ";
                        cin >> h >> m >> s;
                        cin.ignore();
                        cout << endl;
                        cout << "Voc� confirma essa descri��o? [s/n]\n";
                        loop3 = true;
                        while (loop3) {
                            tecla = getTecla();
                            switch (tecla) {
                                case 's':
                                    loop2 = loop3 = false;
                                case 'n':
                                    loop3 = false;
                            }
                        }
                    }
                    b.adicionar(cSerie(nome, genero, autor, descricao, "S�rie", temporadas, m_episodios, h, m, s), true);
                }
                break;
            case '2':
                b.listar();
                break;
            case '3':
                loop2 = true;
                while (loop2) {
                    limpar();
                    cout << "Pesquizando uma obra\n";
                    cout << endl;
                    cout << "Digite o nome do livro: ";
                    getline(cin, nome);
                    cout << endl;
                    cout << "Voc� confirma esse nome? [s/n]\n";
                    loop3 = true;
                    while (loop3) {
                        tecla = getTecla();
                        switch (tecla) {
                            case 's':
                                loop2 = loop3 = false;
                            case 'n':
                                loop3 = false;
                        }
                    }
                }
                b.pesquisar(nome);
                break;
            case '4':
                /*loop2 = true;
                while (loop2) {
                    limpar();
                    cout << "Alterando uma obra\n";
                    cout << endl;
                    cout << "Digite o nome do livro: ";
                    getline(cin, nome);
                    cout << endl;
                    cout << "Voc� confirma esse nome? [s/n]\n";
                    loop3 = true;
                    while (loop3) {
                        tecla = getTecla();
                        switch (tecla) {
                            case 's':
                                loop2 = loop3 = false;
                            case 'n':
                                loop3 = false;
                        }
                    }
                }
                b.alterar(nome);
                gc.salvar(b.getObras());*/
                break;
            case '5':
                loop2 = true;
                while (loop2) {
                    limpar();
                    cout << "Remover uma obra\n";
                    cout << endl;
                    cout << "Digite o nome do livro: ";
                    getline(cin, nome);
                    cout << endl;
                    cout << "Voc� confirma esse nome? [s/n]\n";
                    loop3 = true;
                    while (loop3) {
                        tecla = getTecla();
                        switch (tecla) {
                            case 's':
                                loop2 = loop3 = false;
                            case 'n':
                                loop3 = false;
                        }
                    }
                }
                b.remover(nome);
                gc.salvar(b.getObras());
                break;
            case '6':
                b.exibir();
                break;
            case '7': {
                loop2 = true;
                while (loop2) {
                    limpar();
                    cout << "Voc� realmente deseja sair? [s/n]\n";
                    tecla = getTecla();
                    switch (tecla) {
                        case 's':
                            gc.salvar(b.getObras());      
                            loop1 = loop2 = false;
                        case 'n':
                            loop2 = false;
                    }
                }
                break;
            }
        }
    }
    return 1;
}
