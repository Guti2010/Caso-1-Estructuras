// Métodos avanzados para cumplir con lo que pide el cliente

#include <iostream>
#include <string>
#include <vector>
#include "lista.h"
#include <unordered_set>
#include "news.cpp"


void insertar(ListaDobleEnlazada &lista, const string &dato)
{ // insertar dato por dato
    lista.agregar(dato);
    lista.contador++;
    return;
}

void palabraClave(ListaDobleEnlazada &lista,const string &palabra ){
    Newsapi newsapi;
    vector<News *> allrecords = newsapi.getRecords(palabra);
    for (News* record : allrecords) {
        // Verificar si record no es nulo (por seguridad)
        if (record != nullptr) {
            insertar(lista,record->getTitle());
        }
    }
}

void topfive(ListaDobleEnlazada &lista)
{ // obtener top 5 de los elementos
    cout << "Top 5 elementos más relevantes:" << endl;
    vector<string> elementosLista;
    lista.recorrer(elementosLista);
    int lugar = 0;
    for (const string &elemento : elementosLista)
    {
        lugar++;
        if (lugar > 5)
        {
            return;
        }
        cout << lugar << ". " << elemento << endl;
    }
}

void getAll(ListaDobleEnlazada &lista)
{ // mostraar todos los elementos de la lista
    cout << "Todos los elementos de la lista:" << endl;
    vector<string> elementosLista;
    lista.recorrer(elementosLista);
    int lugar = 0;
    for (const string &elemento : elementosLista)
    {
        lugar++;
        cout << lugar << ". " << elemento << endl;
    }
    return;
}

void buscarPorPalabras(ListaDobleEnlazada &lista)
{
    vector<string> palabrasABuscar;

    cout << "Ingrese las palabras que desea buscar (terminar con 'Listo'):" << endl;
    string palabra;
    while (cin >> palabra && palabra != "Listo")
    {
        palabrasABuscar.push_back(palabra);
    }
    vector<string> resultados; // Almacenar resultados

    lista.buscar(palabrasABuscar, resultados, 1, 0);

    if (resultados.empty())
    {
        cout << "No se encontraron elementos con las palabras dadas" << endl;
    }
    else
    {
        cout << "Elementos encontrados:" << endl;
        for (const string &resultado : resultados)
        {
            cout << resultado << endl;
        }
    }
}

void eliminarPorPalabras(ListaDobleEnlazada &lista)
{ // pedir al usuario palabra por palabra una lista de estas para eliminar elementos que las contengan
    vector<string> palabrasABuscar;

    cout << "Ingrese las palabras que desea buscar para eliminar (terminar con 'Listo'):" << endl;
    string palabra;
    while (cin >> palabra && palabra != "Listo")
    {
        palabrasABuscar.push_back(palabra);
    }
    vector<string> resultados; // Almacenar resultados

    lista.buscar(palabrasABuscar, resultados, 1, 0);

    if (resultados.empty())
    {
        cout << "No se encontraron elementos con las palabras dadas" << endl;
    }
    else
    {
        cout << "Elemnetos eliminados correctamente" << endl;
        for (const string &resultado : resultados)
        {
            lista.eliminar(resultado);
        }
    }
}

void reubicar(ListaDobleEnlazada &lista, int posicionInicial, int nuevaPosicion)
{ // cambiar la relavancia de cada elemento de la lista
    int contador = lista.contador;
    cout << contador << endl;
    // Verificar si las posiciones son válidas
    if (posicionInicial <= 0 || posicionInicial > contador || posicionInicial - nuevaPosicion <= 0 || posicionInicial - nuevaPosicion > contador)
    {
        cout << "Reubicación inválida." << endl;
        return;
    }

    vector<string> rellenar;
    string titular = lista.buscar(rellenar, rellenar, 2, posicionInicial);
    lista.eliminar(titular);
    lista.insertar(titular, posicionInicial - nuevaPosicion);
}
