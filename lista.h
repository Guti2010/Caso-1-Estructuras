// Se usará una lista doble enlazada

// Métodos de la lista según lectura

#include <iostream>
#include <string>

class doublelinkedList {
public: 
    doublelinkedList();

    bool empty(); // ir construyendo la lista

    void getNext(); // obtener el elemento siguiente al nodo actual

    void getPrevious(); // obtener el elemento anterior al nodo actual

    void addFront(data); // Agregar un elemeto al inicio de la lista 

    void addBack(data); // Agregar un elemeto al final de la lista

    void remove(data); // Eliminar un elemeto de la lista

    int largoLista (); // Determinar la cantidad de elementos

    void  searchTitular(data); // Buscar titulares en específico

    void searchPosition(int pIndex); // Buscar la posición de un titular en específico

    void mostrarTitular(data); // Mostrar titulares luego de que se buscan

    void crearLista(data); // Crear el conjunto de 
}
