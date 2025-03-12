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
    public:
        cObra(string n, string a) {
            nome = n; autoria = a;
        }
        void setNome(string n) {
            nome = n;
        }
        void setAutoria(string a) {
            autoria = a;
        }
        string getNome() {
            return nome;
        }
        string getAutoria() {
            return autoria;
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
                limpar();
                cout << o.getNome() << " foi adicionado com sucesso.\n";
                cout << endl;
                parar();
            } else {
                cout << o.getNome() << " já está registrado.\n";
                cout << endl;
                parar();
            }
        }
        void listar() {
            limpar();
            if(obra.size() != 0) {
                cout << "Lista de todas as obras registradas\n";
                cout << endl;
                for(int i = 0; i < obra.size(); i++) {
                    cout << i+1 << "a Obra\n";
                    cout << "Nome: " << obra[i].getNome() << endl;
                    cout << "Autoria: " << obra[i].getAutoria() << endl;
                    cout << endl;
                }
                parar();
            } else {
                cout << "Nenhuma obra registrada\n";
                cout << endl;
                parar();
            }
        }
        void pesquisar(string n) {
            limpar();
            bool achou = false;
            for(int i = 0; i < obra.size(); i++) {
                if(obra[i].getNome() == n) {
                    achou = true;
                    cout << "Obra encontrada\n";
                    cout << endl;
                    cout << "Nome: " << n << endl;
                    cout << "Autoria: " << obra[i].getAutoria() << endl;
                    break;
                }
            }
            if(!achou) {
                cout << n << " não foi encontrado. Verifique se digitou corretamente o nome registrado.\n";
            }
            cout << endl;
            parar();       
        }
        /*void alterar(string n) {
            for(int i = 0; i < obra.size(); i++) {
                if(obra[i].getNome() == n) {
                    
                }
            }
            cout << n << " nï¿½o foi encontrado! Verique se o nome estï¿½ digitado corretamente\n";
            parar();
        }*/
        void remover(string n) {
            limpar();
            bool achou = false;
            for(int i = 0; i < obra.size(); i++) {
                if(obra[i].getNome() == n) {
                    achou = true;
                    obra.erase(obra.begin()+i);
                    cout << n << " foi removido com sucesso.\n";
                    break;
                }
            }
            if(!achou) {
                cout << n << " não está registrado.\n";
            }
            cout << endl;
            parar();
        }
        /*void exibir() {
            
        }*/
};

class cLivro : public cObra {
        
};

class cFilme : public cObra {
      
};

class cSerie : public cObra {
      
};

#endif
