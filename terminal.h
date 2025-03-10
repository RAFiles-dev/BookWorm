#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>

using namespace std;

void printTxt(const string& nome) {
    ifstream arquivo(nome);

    if (!arquivo.is_open()) {
        cerr << "Erro ao procurar o arquivo " << nome << endl;
        cerr << "Verifique se o arquivo está presente na pasta do CRUD." << endl;
        exit(EXIT_FAILURE);
    }

    string linha;
    while (getline(arquivo, linha)) {
        cout << linha << endl;
    }
}

char getTecla() {
    while(true) {
        if(_kbhit()) {
            return _getch();
        }
    }
}

void parar(char x) {
     bool loop = true;
     char tecla;
     
     while(loop) {
         tecla = getTecla();
         if(tecla == x) {
             loop = false;
         }
     }
}

void limpar() {
     system("cls");
}

#endif
