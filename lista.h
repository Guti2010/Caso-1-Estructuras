// Autor. Alejandro Gutiérrez Chaves

#include <iostream>
#include <string>
#include <vector>
#include "nodo.h"
#include <algorithm>
using namespace std;

class ListaDobleEnlazada
{
private:
    Nodo *cabeza;
    Nodo *cola;

public:
    ListaDobleEnlazada() : cabeza(nullptr), cola(nullptr) {}

    int contador = 0;

    void agregar(const string &valor)
    {
        Nodo *nuevoNodo = new Nodo(valor);
        if (!cabeza)
        {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        }
        else
        {
            nuevoNodo->anterior = cola;
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }

        return;
    }

    string buscar(vector<string> &palabrasABuscar, vector<string> &resultados, int modoBusqueda, int posicion)
    {
        // Indica si se encontró al menos un resultado
        if (modoBusqueda == 1)
        {
            for (const string &palabra : palabrasABuscar)
            {
                Nodo *actual = cabeza;
                bool encontrado = false;
                vector<string> resultadosParciales; // Resultados para esta palabra
                // Agregar los resultados parciales a resultados, evitando duplicados
                while (actual)
                {
                    if (actual->dato.find(palabra) != string::npos)
                    {
                        resultadosParciales.push_back(actual->dato);
                        encontrado = true;
                    }
                    actual = actual->siguiente;
                }

                if (!encontrado)
                {
                    cout << "No se encontraron elementos con la palabra '" << palabra << "'." << endl;
                }

                for (const string &resultadoParcial : resultadosParciales)
                {
                    bool yaAgregado = false;
                    for (const string &resultadoExistente : resultados)
                    {
                        if (resultadoParcial == resultadoExistente)
                        {
                            yaAgregado = true;
                            break;
                        }
                    }
                    if (!yaAgregado)
                    {
                        resultados.push_back(resultadoParcial);
                    }
                }
            }
            return "";
        }
        if (modoBusqueda == 2)
        {
            int index = 1; // La cabeza equivale a la posición 1
            Nodo *actual = cabeza;

            while (actual && index < posicion)
            {
                actual = actual->siguiente;
                index++;
            }

            if (actual && index == posicion)
            {
                return actual->dato;
            }
        }
        return "";
    }

    bool eliminar(const string &valor)
    {
        Nodo *actual = cabeza;
        while (actual)
        {
            if (actual->dato == valor)
            {
                if (actual->anterior)
                {
                    actual->anterior->siguiente = actual->siguiente;
                }
                else
                {
                    cabeza = actual->siguiente;
                }
                if (actual->siguiente)
                {
                    actual->siguiente->anterior = actual->anterior;
                }
                else
                {
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

    void recorrer(vector<string> &elementos)
    {
        Nodo *actual = cabeza;
        while (actual)
        {
            elementos.push_back(actual->dato);
            actual = actual->siguiente;
        }
    }

    void insertar(const string &valor, int posicion)
    {
        contador++;
        int contador2 = 1;
        Nodo *actual = cabeza;
        posicion--;
        // Crear un nuevo nodo con el valor dado
        Nodo *nuevoNodo = new Nodo(valor);

        // Si la posición deseada es 0, establecer el nuevo nodo como la cabeza
        if (posicion == 0)
        {
            nuevoNodo->siguiente = cabeza;
            cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
            contador++;
            return;
        }

        while (actual && contador2 < posicion)
        {
            actual = actual->siguiente;
            contador2++;
        }
        // Conectar el nuevo nodo con los nodos adyacentes
        nuevoNodo->siguiente = actual->siguiente;
        nuevoNodo->anterior = actual;
        if (actual->siguiente)
        {
            actual->siguiente->anterior = nuevoNodo;
        }
        actual->siguiente = nuevoNodo;
    }
};
