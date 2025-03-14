#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <vector>
#include "terminal.h"

using namespace std;

class cObra {
protected:
    string nome;
    string genero;
    string autor;
    string descricao;
    string tipo;
public:
    cObra(string n, string g, string a, string d, string t) {
        nome = n;
        genero = g;
        autor = a;
        descricao = d;
        tipo = t;
    }
    void setNome(string n) {
        nome = n;
    }
    void setGenero(string g) {
        genero = g;
    }
    void setAutor(string a) {
        autor = a;
    }
    void setDescricao(string d) {
        descricao = d;
    }
    void setTipo(string t) {
        tipo = t;
    }
    string getNome() {
        return nome;
    }
    string getGenero() {
        return genero;
    }
    string getAutor() {
        return autor;
    }
    string getDescricao() {
        return descricao;
    }
    string getTipo() {
        return tipo;
    }
    virtual int getPaginas() {return 0;}
    virtual int getCapitulos() { return 0; }
    virtual string getEstilo() { return ""; }
    virtual int getDuracao() { return 0; }
    virtual int getTemporadas() { return 0; }
    virtual int getM_episodios() { return 0; }
    virtual int getM_duracao() { return 0; }
    virtual int getDuracao_t() { return 0; }
};

class cBibliotecario {
private:
    vector<cObra> obra;
    
    int getIndice(string n) {
        for (int i = 0; i < obra.size(); i++) {
            if (obra[i].getNome() == n) {
                return i;
            }
        }
        return -1;
    }
public:
    vector<cObra> getObras() { return obra; }
    void adicionar(cObra o, bool mostrar) {
        limpar();
        string n = o.getNome();
        if (getIndice(n) == -1) {
            obra.emplace_back(o);
            if(mostrar) {
                cout << n << " foi adicionado com sucesso.\n";
                parar();
            }
        } else {
            cout << n << " já está registrado.\n";
            parar();
        }
    }
    void listar() {
        limpar();
        if (obra.size() != 0) {
                        
            cout << "Lista de todas as obras registradas\n";
            cout << endl;
            for (int i = 0; i < obra.size(); i++) {
                string tipo = obra[i].getTipo();
                cout << i + 1 << "a Obra - " << tipo << endl;
                cout << "Nome: " << obra[i].getNome() << endl;
                cout << "Autor: " << obra[i].getAutor() << endl;
                cout << "Descrição: " << obra[i].getDescricao() << endl;
                if(tipo == "Livro" || tipo == "Quadrinho") {
                    cout << "Páginas: " << obra[i].getPaginas() << endl;
                    cout << "Capitulos: " << obra[i].getCapitulos() << endl;
                    if(tipo == "Quadrinho") {
                        cout << "Estilo de desenho: " << obra[i].getEstilo() << endl;
                    }
                    cout << endl;
                } else if(tipo == "Filme") {
                    cout << "Duração: " << obra[i].getDuracao() << endl;
                    cout << endl;
                } else if(tipo == "Série") {
                    cout << "Número de temporadas: " << obra[i].getTemporadas() << endl;
                    cout << "Número médio de episódios por temporada: " << obra[i].getM_episodios() << endl;
                    cout << "Duracao média de um episódio: " << obra[i].getM_duracao() << endl;
                    cout << "Duracao total média: " << obra[i].getDuracao_t() << endl;
                    cout << endl;
                }
            }
        } else {
            cout << "Nenhuma obra registrada\n";
            cout << endl;
        }
        parar();
    }
    void pesquisar(string n) {
        limpar();
        int i = getIndice(n);
        string tipo = obra[i].getTipo();
        if (i != -1) {
            cout << "Obra encontrada - " << tipo << "\n";
            cout << endl;
            cout << "Nome: " << n << endl;
            cout << "Autor: " << obra[i].getAutor() << endl;
            cout << "Descrição: " << obra[i].getDescricao() << endl;
            if(tipo == "Livro" || tipo == "Quadrinho") {
                cout << "Páginas: " << obra[i].getPaginas() << endl;
                cout << "Capitulos: " << obra[i].getCapitulos() << endl;
                if(tipo == "Quadrinho") {
                    cout << "Estilo de desenho: " << obra[i].getEstilo() << endl;
                }
                cout << endl;
            } else if(tipo == "Filme") {
                cout << "Duração: " << obra[i].getDuracao() << endl;
                cout << endl;
            } else if(tipo == "Série") {
                cout << "Número de temporadas: " << obra[i].getTemporadas() << endl;
                cout << "Número médio de episódios por temporada: " << obra[i].getM_episodios() << endl;
                cout << "Duracao média de um episódio: " << obra[i].getM_duracao() << endl;
                cout << "Duracao total média: " << obra[i].getDuracao_t() << endl;
                cout << endl;
            }
        } else {
            cout << n << " não foi encontrado. Verifique se digitou corretamente o nome registrado.\n";
            cout << endl;
        }
        parar();
    }
    /*void alterar(string n) {
        limpar();
        int i = getIndice(n);
        if (i != -1) {
            
        } else {
            cout << n << " não foi encontrado. Verifique se digitou corretamente o nome registrado.\n";
        }
        parar();
    }*/
    void remover(string n) {
        limpar();
        int i = getIndice(n);
        if (i != -1) {
            obra.erase(obra.begin() + i);
            cout << n << " foi removido com sucesso.\n";
        } else {
            cout << n << " não foi encontrado. Verifique se digitou corretamente o nome registrado.\n";
        }
        cout << endl;
        parar();
    }
    void exibir() {
        limpar();
        int paginas_t = 0, duracao_t = 0;
        for (int i = 0; i < obra.size(); i++) {
            if (obra[i].getTipo() == "Livro" || obra[i].getTipo() == "Quadrinho") {
                paginas_t += obra[i].getPaginas();
            } else if (obra[i].getTipo() == "Filme") {
                duracao_t += obra[i].getDuracao();
            } else if (obra[i].getTipo() == "Série") {
                duracao_t += obra[i].getDuracao_t();
            }
        }
        cout << "Relatório\n";
        cout << endl;
        cout << "Total de páginas das obras: " << paginas_t << endl;
        cout << "Total de duração das obras: " << duracao_t / 3600 << ":" << (duracao_t % 3600) / 60 << ":" << (duracao_t % 3600) % 60 << endl;
        cout << endl;
        parar();
    }
};

class cLivro : public cObra {
protected:
    int paginas;
    int capitulos;
public:
    cLivro(string n, string g, string a, string d, string t, int p, int c) : cObra(n, g, a, d, t) {
        paginas = p;
        capitulos = c;
    }
    void setPaginas(int p) {
        paginas = p;
    }
    void setCapitulos(int c) {
        capitulos = c;
    }
    int getPaginas() {
        return paginas;
    }
    int getCapitulos() {
        return capitulos;
    }
};

class cQuadrinho : public cLivro {
private:
    string estilo;
public:
    cQuadrinho(string n, string g, string a, string d, string t, int p, int c, string e) : cLivro(n, g, a, d, t, p, c) {
        estilo = e;
    }
    void setEstilo(string e) {
        estilo = e;
    }
    string getEstilo() {
        return estilo;
    }
};

class cDuracao {
private:
    int horas, minutos, segundos;
public:
    cDuracao(int h, int m, int s) {
        horas = h;
        minutos = m;
        segundos = s;
    }
    int getDuracao() {
        return horas * 3600 + minutos * 60 + segundos;
    }
};

class cFilme : public cObra {
private:
    cDuracao* duracao;
public:
    cFilme(string n, string g, string a, string d, string t, int h, int m, int s) : cObra(n, g, a, d, t) {
        duracao = new cDuracao(h, m, s);
    }
    void setDuracao(int h, int m, int s) {
        duracao = new cDuracao(h, m, s);
    }
    int getDuracao() {
        return duracao->getDuracao();
    }
};

class cSerie : public cObra {
private:
    int temporadas;
    int m_episodios;
    cDuracao* m_duracao;
public:
    cSerie(string n, string g, string a, string d, string t, int tr, int me, int h, int m, int s) : cObra(n, g, a, d, t) {
        temporadas = tr;
        m_episodios = me;
        m_duracao = new cDuracao(h, m, s);
    }
    void setTemporadas(int tr) {
        temporadas = tr;
    }
    void setM_episodios(int me) {
        m_episodios = me;
    }
    void setM_duracao(int h, int m, int s) {
        m_duracao = new cDuracao(h, m, s);
    }
    int getTemporadas() {
        return temporadas;
    }
    int getM_episodios() {
        return m_episodios;
    }
    int getM_Duracao() {
        return m_duracao->getDuracao();
    }
    int getDuracao_t() {
        return temporadas * m_episodios * m_duracao->getDuracao();
    }
};

#endif
