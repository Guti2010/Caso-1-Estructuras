// Métodos avanzados para cumplir con lo que pide el cliente 

#include <iostream>
#include <string>
#include <vector>
#include "lista.h"
#include <unordered_set>

void insertar(ListaDobleEnlazada &lista, const string &dato){ //insertar dato por dato
   lista.agregar(dato);
   lista.contador++;
   return;
}

void topfive(ListaDobleEnlazada& lista){ //obtener top 5 de los elementos
   cout << "Top 5 elementos más relevantes:" << endl;
   lista.top5();
   return;
}

void getAll(ListaDobleEnlazada& lista){ //mostraar todos los elementos de la lista
   cout << "Todos los elementos de la lista:" << endl;
   lista.recorrer();
   return;
}

void buscarPorPalabras(ListaDobleEnlazada& lista) {
    vector<string> palabrasABuscar;

    cout << "Ingrese las palabras que desea buscar (terminar con 'Listo'):" << endl;
    string palabra;
    while (cin >> palabra && palabra != "Listo") {
        palabrasABuscar.push_back(palabra);
    }

    vector<string> resultados;  // Almacenar resultados

    for (const string& palabra : palabrasABuscar) {
        vector<string> resultadosParciales;  // Resultados para esta palabra
        lista.buscar(palabra, resultadosParciales);

        // Agregar los resultados parciales a resultados, evitando duplicados
        for (const string& resultadoParcial : resultadosParciales) {
            bool yaAgregado = false;
            for (const string& resultadoExistente : resultados) {
                if (resultadoParcial == resultadoExistente) {
                    yaAgregado = true;
                    break;
                }
            }
            if (!yaAgregado) {
                resultados.push_back(resultadoParcial);
            }
        }
    }
    

    if (resultados.empty()) {
        cout << "No se encontraron elementos con las palabras dadas" << endl;
    } else {
        cout << "Elementos encontrados:" << endl;
        for (const string& resultado : resultados) {
            cout << resultado << endl;
        }
    }
}


void eliminarPorPalabras(ListaDobleEnlazada& lista) { //pedir al usuario palabra por palabra una lista de estas para eliminar elementos que las contengan
    vector<string> palabrasABuscar;

    cout << "Ingrese las palabras que desea buscar (terminar con 'Listo'):" << endl;
    string palabra;
    while (cin >> palabra && palabra != "Listo") {
        palabrasABuscar.push_back(palabra);
    }

    vector<string> resultados;  // Almacenar resultados

    for (const string& palabra : palabrasABuscar) {
        vector<string> resultadosParciales;  // Resultados para esta palabra
        lista.buscar(palabra, resultadosParciales);

        // Agregar los resultados parciales a resultados, evitando duplicados
        for (const string& resultadoParcial : resultadosParciales) {
            bool yaAgregado = false;
            for (const string& resultadoExistente : resultados) {
                if (resultadoParcial == resultadoExistente) {
                    yaAgregado = true;
                    break;
                }
            }
            if (!yaAgregado) {
                resultados.push_back(resultadoParcial);
            }
        }
    }
    

    if (resultados.empty()) {
        cout << "No se encontraron elementos con las palabras dadas" << endl;
    } else {
        cout << "Elementos eliminados correctamente" << endl;
        for (const string& resultado : resultados) {
            lista.eliminar(resultado);
        }
    }
}



void cambiarPosition(ListaDobleEnlazada& lista, int posicionInicial, int nuevaPosicion) { //cambiar la relavancia de cada elemento de la lista
    int contador = lista.contador; 
    
    // Verificar si las posiciones son válidas
    if (posicionInicial <= 0 || posicionInicial > contador || posicionInicial-nuevaPosicion <=0 || posicionInicial-nuevaPosicion>contador ) {
        cout << "Reubicación inválida." << endl;
        return;
    }

    lista.reubicar(posicionInicial, nuevaPosicion);
}




