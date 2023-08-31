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

    bool buscar(const string& palabraABuscar, string& resultado) {
    Nodo* actual = cabeza;
    while (actual) {
        // Buscar si la palabra está contenida en el string del nodo
        if (actual->dato.find(palabraABuscar) != string::npos) {
            resultado = actual->dato;
            return true;
        }
        actual = actual->siguiente;
    }
    cout << "No se encontraron elementos con las palabras dadas" << endl;
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

    

    ~ListaDobleEnlazada() { //getNext
        Nodo* actual = cabeza;
        while (actual) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }
};


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

void buscarPorPalabras(ListaDobleEnlazada& lista) { //pedir al usuario palabra por palabra una lista de estas para buscar elementos que las contengan
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


void eliminarPorPalabras(ListaDobleEnlazada& lista) { //pedir al usuario palabra por palabra una lista de estas para eliminar elementos que las contengan
    vector<string> palabrasABuscar;

    cout << "Ingrese las palabras que desea buscar para eliminar elementos (terminar con 'Listo'):" << endl;
    string palabra;
    while (cin >> palabra && palabra != "Listo") {
        palabrasABuscar.push_back(palabra);
    }

    for (const string& palabra : palabrasABuscar) {
        string resultado;
        if (lista.buscar(palabra, resultado)) {
           lista.eliminar(resultado);
        } 
    }
    return;
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


int main() {
    
    ListaDobleEnlazada lista;

    insertar(lista, "Descubren Nueva Especie de Mariposa Bioluminiscente en la Selva Amazónica");
    insertar(lista, "Investigadores Desarrollan Vacuna Eficaz contra la Alergia al Polen");
    insertar(lista, "Empresa de Tecnología Anuncia Avances en la Creación de Robots Autónomos");
    insertar(lista, "Estudio Revela que el Consumo de Chocolate Oscuro Está Relacionado con la Felicidad");
    insertar(lista, "Exploradores Descubren Antigua Ciudad Submarina en las Costas del Mediterráneo");
    insertar(lista, "Artista Local Realiza Exhibición de Esculturas Gigantes Hechas de Material Reciclado");

    getAll(lista);
    cout << endl;

    buscarPorPalabras(lista);

    getAll(lista);
    cout << endl;
    

    
}