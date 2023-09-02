// Autor. Alejandro Gutiérrez Chaves

#include <iostream>
#include <string>
#include "MetodosOperacion.h"

using namespace std;



int main() {
    ListaDobleEnlazada lista;
    insertar(lista, "Descubren Nueva Especie de Mariposa Bioluminiscente en la Selva Amazónica");
    insertar(lista, "Investigadores Desarrollan Vacuna Eficaz contra la Alergia al Polen");
    insertar(lista, "Empresa de Tecnología Anuncia Avances en la Creación de Robots Autónomos");
    insertar(lista, "Estudio Revela que el Consumo de Chocolate Oscuro Está Relacionado con la Felicidad");
    insertar(lista, "Exploradores Descubren Antigua Ciudad Submarina en las Costas del Mediterráneo");
    insertar(lista, "Artista Local Realiza Exhibición de Esculturas Gigantes Hechas de Material Reciclado");
    insertar(lista, "Científicos Descubren Nueva Especie de Flores que Florecen en la Oscuridad");
    insertar(lista, "Avances en la Investigación Espacial: Nueva Misión para Explorar un Planeta Desconocido");
    insertar(lista, "Apertura del Primer Hotel Submarino: Una Experiencia de Lujo Bajo el Mar");
    insertar(lista, "Desarrollan Dispositivo Revolucionario que Convierte el Aire en Agua Potable");
    insertar(lista, "Artista Urbano Transforma Calles Grises en Obras de Arte a Gran Escala");
    insertar(lista, "Descubren Antiguo Manuscrito que Revela Secretos de una Civilización Perdida");

    topfive();
    cout << endl;
    getAll(lista);
    cout << endl;
    buscarPorPalabras(lista);
    cout << endl;
    eliminarPorPalabras(lista);
    cout << endl;
    getAll(lista);
    cout << endl;
    reubicar(lista,1,-3);
    getAll(lista);
     
}