#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include <vector>
#include "terminal.h"

using namespace std;

class cBibliotecario {
    private:
        vector<cObra> obra;
    public:
        int pesquisar(string nome) {           
            auto x = find(obra.begin(), obra.end(), nome);
            if(x != obra.end()) {
              return distance(obra.begin(), x);
            }
            return -1;
        }
        int adicionar(cObra o){
            if(pesquisar(o) == -1) {
                limpar();
                cout << "Esse nome já foi utilizado! Tente uma variação ou faça alterações na obra já registrada\n";
                cout << "Pressione Enter para continuar...\n";
                parar(enter);
            } else {
                
            }
        }
        int listar() {
            
        }
        int procurar() {
            
        }
        int alterar() {
            
        }
        int remover() {
            
        }
}

class cObra {
    protected:
        string nome;
        string autor;
        int numPaginas;
        string tipo;    
};

class cLivro : public cObra {
        
};

class cFilme : public cObra {
      
};

class cSerie : public cObra {
      
};

#endif
