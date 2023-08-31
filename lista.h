// Autor. Alejandro Gutiérrez Chaves

#include <iostream>
#include <string>
#include <vector>
#include "nodo.h"
#include <algorithm>
#include <unordered_set>
using namespace std;

class ListaDobleEnlazada {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaDobleEnlazada() : cabeza(nullptr), cola(nullptr) {}

    int contador = 0;
    void agregar(const string& valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (!cabeza) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        } else {
            nuevoNodo->anterior = cola;
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
        
       return; 
    }

    bool buscar(const string& palabraABuscar, vector<string>& resultados) {
        Nodo* actual = cabeza;
        bool encontrado = false;  // Indica si se encontró al menos un resultado
        unordered_set<string> elementosAgregados;  // Utilizamos un unordered_set para evitar duplicados

        while (actual) {
            if (actual->dato.find(palabraABuscar) != string::npos) {
                if (elementosAgregados.find(actual->dato) == elementosAgregados.end()) {
                    resultados.push_back(actual->dato);
                    elementosAgregados.insert(actual->dato);
                }
                encontrado = true;
            }
            actual = actual->siguiente;
        }

        if (!encontrado) {
            cout << "No se encontraron elementos con la palabra '" << palabraABuscar << "'." << endl;
        }

        return encontrado;
    }



    bool eliminar(const string& valor) {
        Nodo* actual = cabeza;
        while (actual) {
            if (actual->dato == valor) {
                if (actual->anterior) {
                    actual->anterior->siguiente = actual->siguiente;
                } else {
                    cabeza = actual->siguiente;
                }
                if (actual->siguiente) {
                    actual->siguiente->anterior = actual->anterior;
                } else {
                    cola = actual->anterior;
                }
                delete actual;
                contador--;
                return true;
            }
            actual = actual->siguiente;
        }
        
        return false;
    }

    void recorrer() {
        Nodo* actual = cabeza;
        contador = 0;
        while (actual) {
            contador++;
            cout << contador << ". " << actual->dato << endl;
            actual = actual->siguiente;
        }
    }

    void top5() {
        Nodo* actual = cabeza;
        int position = 0;
        while (position<5) {
            position++;
            cout << position << ". " << actual->dato << endl;
            actual = actual->siguiente;
        }
    }

    void reubicar(int posicionInicial, int offset) {
        int nuevaPosicion = posicionInicial - offset;
        Nodo* actual = cabeza;
        for (int i = 1; i < posicionInicial; ++i) {
            actual = actual->siguiente;
        }

        Nodo* nodoMovido = actual;
        Nodo* nodoAnterior = actual->anterior;
        Nodo* nodoSiguiente = actual->siguiente;

        if (posicionInicial - offset == contador) {
            Nodo* nodoAnterior = actual->anterior;
            Nodo* nodoSiguiente = actual->siguiente;

            // Si ya es el último nodo, no es necesario hacer nada
            if (nodoSiguiente) {
                if (nodoAnterior) {
                    nodoAnterior->siguiente = nodoSiguiente;
                } else {
                    cabeza = nodoSiguiente;
                }
                nodoSiguiente->anterior = nodoAnterior;

                // Mover el nodo al final de la lista
                actual->anterior = cola;
                actual->siguiente = nullptr;
                cola->siguiente = actual;
                cola = actual;
            }

            return;
        }

        if (nodoAnterior) {
            nodoAnterior->siguiente = nodoSiguiente;
        } else {
            cabeza = nodoSiguiente;
        }

        if (nodoSiguiente) {
            nodoSiguiente->anterior = nodoAnterior;
        } else {
            cola = nodoAnterior;
        }

        actual = cabeza;
        for (int i = 1; i < nuevaPosicion; ++i) {
            actual = actual->siguiente;
        }

        if (actual) {
            nodoMovido->anterior = actual->anterior;
            nodoMovido->siguiente = actual;
            if (actual->anterior) {
                actual->anterior->siguiente = nodoMovido;
            } else {
                cabeza = nodoMovido;
            }
            actual->anterior = nodoMovido;
        }
    }

    

    ~ListaDobleEnlazada() { //getNext
        Nodo* actual = cabeza;
        while (actual) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }
};
