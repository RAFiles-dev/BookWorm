#ifndef CRUD_H
#define CRUD_H

#include <fstream>
#include <iostream>
#include <vector>
#include "biblioteca.h"

using namespace std;

class cGerenciadorCrud {
public:
    void salvar(vector<cObra> vetor) {
        remove("data.txt");
        ofstream arquivo("data.txt");
        if (!arquivo) {
            cerr << "Erro ao abrir o arquivo data.txt" << endl;
            exit(EXIT_FAILURE);
        }
        for (auto o : vetor) {
            string tipo = o.getTipo();
            arquivo << o.getNome() << endl;
            arquivo << o.getGenero() << endl;
            arquivo << o.getAutor() << endl;
            arquivo << o.getDescricao() << endl;
            arquivo << tipo << endl;
            if (tipo == "Livro" || tipo == "Quadrinho") {
                arquivo << o.getPaginas() << endl;
                arquivo << o.getCapitulos() << endl;
                if (tipo == "Quadrinho") {
                    arquivo << o.getEstilo() << endl;
                }
            } else if (tipo == "Filme") {
                arquivo << o.getDuracao() << endl;
            } else if (tipo == "Série") {
                arquivo << o.getTemporadas() << endl;
                arquivo << o.getM_episodios() << endl;
                arquivo << o.getM_duracao() << endl;
            }
        }
        arquivo.close();
    }
    void carregar(cBibliotecario &b) {
        ifstream arquivo("data.txt");
        if (!arquivo) {
            cerr << "Erro ao abrir o arquivo data.txt" << endl;
            return;
        }
        string nome, genero, autor, descricao, tipo;
        while (getline(arquivo, nome)) {
            getline(arquivo, genero);
            getline(arquivo, autor);
            getline(arquivo, descricao);
            getline(arquivo, tipo);
            if (tipo == "Livro") {
                int paginas, capitulos;
                arquivo >> paginas >> capitulos;
                arquivo.ignore();
                cLivro livro(nome, genero, autor, descricao, tipo, paginas, capitulos);
                b.adicionar(livro, false);
            } else if (tipo == "Quadrinho") {
                int paginas, capitulos;
                string estilo;
                arquivo >> paginas >> capitulos;
                arquivo.ignore();
                getline(arquivo, estilo);
                cQuadrinho quadrinho(nome, genero, autor, descricao, tipo, paginas, capitulos, estilo);
                b.adicionar(quadrinho, false);
            } else if (tipo == "Filme") {
                int duracao;
                arquivo >> duracao;
                arquivo.ignore();
                int h = duracao / 3600;
                int m = (duracao % 3600) / 60;
                int s = (duracao % 3600) % 60;
                cFilme filme(nome, genero, autor, descricao, tipo, h, m, s);
                b.adicionar(filme, false);
            } else if (tipo == "Série") {
                int temporadas, episodios, m_duracao;
                arquivo >> temporadas >> episodios >> m_duracao;
                arquivo.ignore();
                int h = m_duracao / 3600;
                int m = (m_duracao % 3600) / 60;
                int s = (m_duracao % 3600) % 60;
                cSerie serie(nome, genero, autor, descricao, tipo, temporadas, episodios, h, m, s);
                b.adicionar(serie, false);
            } else {
                cObra obra(nome, genero, autor, descricao, tipo);
                b.adicionar(obra, false);
            }
        }
        arquivo.close();
    }
};

#endif
