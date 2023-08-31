// Autor. Alejandro Gutiérrez Chaves

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Nodo {
public:
    string dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(const string& valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

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
        
        
    }

    bool buscar(const string& palabraABuscar, std::string& resultado) {
    Nodo* actual = cabeza;
    while (actual) {
        // Buscar si la palabra está contenida en el string del nodo
        if (actual->dato.find(palabraABuscar) != std::string::npos) {
            resultado = actual->dato;
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
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

    

    ~ListaDobleEnlazada() {
        Nodo* actual = cabeza;
        while (actual) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }
};


void insertar(ListaDobleEnlazada &lista, const string &dato){
   lista.agregar(dato);
   lista.contador++;
   return;
}

void topfive(ListaDobleEnlazada& lista){
   cout << "Top 5 elementos más relevantes:" << endl;
   lista.top5();
   return;
}

void getAll(ListaDobleEnlazada& lista){
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

   cout << "Elementos encontrados:" << endl;
    for (const string& palabra : palabrasABuscar) {
        string resultado;
        if (lista.buscar(palabra, resultado)) {
           cout << resultado << endl;
        } 
    }
    return;
}


void eliminarPorPalabras(ListaDobleEnlazada& lista) {
    vector<string> palabrasABuscar;

    cout << "Ingrese las palabras que desea buscar para eliminar elementos (terminar con 'Listo'):" << endl;
    string palabra;
    while (cin >> palabra && palabra != "Listo") {
        palabrasABuscar.push_back(palabra);
    }
    cout << "Elementos eliminados correctamente" << endl;

    for (const string& palabra : palabrasABuscar) {
        string resultado;
        if (lista.buscar(palabra, resultado)) {
           lista.eliminar(resultado);
        } 
    }
    return;
}



void cambiarPosition(ListaDobleEnlazada& lista, int posicionInicial, int nuevaPosicion) {
    int contador = lista.contador; // Esto asume que tienes un miembro "contador" en la clase ListaDobleEnlazada
    
    // Verificar si las posiciones son válidas
    if (posicionInicial <= 0 || posicionInicial > contador || posicionInicial-nuevaPosicion <=0 || posicionInicial-nuevaPosicion>contador ) {
        cout << "Reubicación inválida." << endl;
        return;
    }

    lista.reubicar(posicionInicial, nuevaPosicion);
}


int main() {
    
    ListaDobleEnlazada lista;

    insertar(lista, "Hola mundo");
    insertar(lista, "Hola gente");
    insertar(lista, "c");
    insertar(lista, "d");
    insertar(lista, "e");
    insertar(lista, "f");

    getAll(lista);
    cout << endl;
    
    cambiarPosition(lista,2,-2);

    getAll(lista);
    cout << endl;
    lista.eliminar("f");
    getAll(lista);

    cambiarPosition(lista,6,-2);

    getAll(lista);
    cout << endl;
    topfive(lista);

    

    
    

    
}