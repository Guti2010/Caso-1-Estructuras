// Se usará una lista enlazada simple
class Nodo {
public:
    int valor;
    Nodo* siguiente;

    Nodo(int val) : valor(val), siguiente(nullptr) {}
};

class ListaSimple {
private:
    Nodo* cabeza;

public:
    ListaSimple() : cabeza(nullptr) {}

    // Método para insertar un elemento en la lista al final de esta
    void insertarAlFinal(int val) {
        Nodo* nuevo_nodo = new Nodo(val);
        if (!cabeza) {
            cabeza = nuevo_nodo;
        } else {
            Nodo* nodo_actual = cabeza;
            while (nodo_actual->siguiente) {
                nodo_actual = nodo_actual->siguiente;
            }
            nodo_actual->siguiente = nuevo_nodo;
        }
    }

    void eliminar(int val) {
        if (!cabeza) {
            return;  // La lista está vacía, no se puede eliminar nada
        }

        if (cabeza->valor == val) {
            Nodo* nodo_a_eliminar = cabeza;
            cabeza = cabeza->siguiente;
            delete nodo_a_eliminar;
            return;
        }

        Nodo* nodo_anterior = cabeza;
        while (nodo_anterior->siguiente && nodo_anterior->siguiente->valor != val) {
            nodo_anterior = nodo_anterior->siguiente;
        }

        if (nodo_anterior->siguiente) {
            Nodo* nodo_a_eliminar = nodo_anterior->siguiente;
            nodo_anterior->siguiente = nodo_a_eliminar->siguiente;
            delete nodo_a_eliminar;
        }

    // Método para imprimir los elementos de la lista
    void imprimir() {
        Nodo* nodo_actual = cabeza;
        while (nodo_actual) {
            std::cout << nodo_actual->valor << " -> ";
            nodo_actual = nodo_actual->siguiente;
        }
        std::cout << "nullptr" << std::endl;
    }
}

int main() {
    ListaSimple lista;
    lista.insertarAlInicio(3);
    lista.insertarAlInicio(7);
    lista.insertarAlFinal(12);
    lista.imprimir();  // Salida: 7 -> 3 -> 12 -> nullptr
    return 0;
}

};