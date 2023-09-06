// Autor. Alejandro Gutiérrez Chaves

#include <iostream>
#include <string>
#include "MetodosOperacion.h"

using namespace std;

int main()
{
    ListaDobleEnlazada lista;
    palabraClave(lista,"Messi");
    topfive(lista);
    cout << endl;
    getAll(lista);
    cout << endl;
    buscarPorPalabras(lista);
    cout << endl;
    eliminarPorPalabras(lista);
    cout << endl;
    getAll(lista);
    cout << endl;
    reubicar(lista, 5, -5);
    getAll(lista);
}