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
        cerr << "Erro ao abrir o arquivo " << nome << endl;
        cerr << "Verifique se o arquivo está presente na pasta do programa." << endl;
        exit(EXIT_FAILURE);
    }

    string linha;
    while (getline(arquivo, linha)) {
        cout << linha << endl;
    }
}

char getTecla() {
    while (true) {
        if (_kbhit()) {
            return _getch();
        }
    }
}

void parar() {
    bool loop = true;
    char tecla;

    cout << "Pressione Enter para continuar...";
    while (loop) {
        tecla = getTecla();
        if (tecla == 13) {
            loop = false;
        }
    }
}

void limpar() {
    system("cls");
}

#endif
