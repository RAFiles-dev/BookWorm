#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <vector>
#include "terminal.h"

using namespace std;

class cObra {
    protected:
        string nome;
        string autoria;
        int paginas;
    public:
        cObra(string n, string a, int p) {
            nome = n; autoria = a; paginas = p;
        }
        void setNome(string n) {
            nome = n;
        }
        void setAutoria(string a) {
            autoria = a;
        }
        void setPaginas(int p) {
            paginas = p;
        }
        string getNome() {
            return nome;
        }
        string getAutoria() {
            return autoria;
        }
        int getPaginas() {
            return paginas;
        }
};

class cBibliotecario {
    private:
        vector<cObra> obra;
        
        int getIndice(string n) {           
            for(int i = 0; i < obra.size(); i++) {
                if(obra[i].getNome() == n) {
                    return i;
                }
            }
            return -1;
        }
    public:
        void adicionar(cObra o){
            if(getIndice(o.getNome()) == -1) {
                obra.emplace_back(o);
            }
        }
        void listar() {
            if(obra.size() != 0) {
                cout << "Lista de todas as obras registradas\n";
                cout << endl;
                for(int i = 0; i < obra.size(); i++) {
                    cout << i+1 << "a Obra\n";
                    cout << "Nome: " << obra[i].getNome() << endl;
                    cout << "Autoria: " << obra[i].getAutoria() << endl;
                    cout << "Páginas: " << obra[i].getPaginas() << endl;
                    if(i + 1 < obra.size()) {
                         cout << endl;
                    }
                }   
            } else {
                cout << "Nenhuma obra registrada\n"; 
            }
        }
        void pesquisar(string n) {
            bool achou = false;
            for(int i = 0; i < obra.size(); i++) {
                if(obra[i].getNome() == n) {
                    cout << "Obra encontrada\n";
                    cout << endl;
                    cout << "Nome: " << obra[i].getNome() << endl;
                    cout << "Autoria: " << obra[i].getAutoria() << endl;
                    cout << "Páginas: " << obra[i].getPaginas() << endl;
                    achou = true;
                    break;
                }
            }
            if(!achou) {
                cout << n << " não foi encontrado. Verifique se digitou corretamente o nome registrado.\n";
            }       
        }
        /*int alterar(string n) {
            for(int i = 0; i < obra.size(); i++) {
                if(obra[i].getNome() == n) {
                    
                }
            }
            cout << n << " não foi encontrado! Verique se o nome está digitado corretamente\n";
            parar();
        }*/
        void remover(string n) {
            for(int i = 0; i < obra.size(); i++) {
                if(obra[i].getNome() == n) {
                    obra.erase(obra.begin()+i);
                }
            }
        }
        /*int exibir() {
            
        }*/
};

/*class cLivro : public cObra {
        
};

class cFilme : public cObra {
      
};

class cSerie : public cObra {
      
};*/

#endif
