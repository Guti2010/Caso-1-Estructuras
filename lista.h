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

    void agregarTitular(string pData, int position); //Agregar titular a la lista en determinada posición

    void remove(string pData); // Eliminar un elemeto de la lista

    int largoLista (int num); // Determinar la cantidad de elementos

    void  searchTitular(string pData); // Buscar titulares en específico

    void searchPosition(int pIndex); // Buscar la posición de un titular en específico

    void mostrarTitular(string pData); // Mostrar titulares luego de que se buscan

}
