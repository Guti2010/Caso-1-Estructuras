// Métodos avanzados para cumplir con lo que pide el cliente 

#include <iostream>
#include <string>

top5();{ // Mostrar el top 5 de titulares por relevancia
    
    //Métodos necesarios de la lista

    getNext(); // recorrer la lista
    searchPosition(); // buscar que esté el titular entre los primeros 5 titulares
    mostrarTitular(); // mostrar estos titulares
}
    


mostrarTodoLosTitulares();{ // Mostrar todos los titulares por relevancia

    //Métodos necesarios de la lista

    getNext(); // recorrer la lista
    mostrarTitular(); // mostrar toda la lista de titulares
}


mostrarTitulares();{ // Mostrar todos los titulares según filtro hecho con base a palabras que indique el usuario

    //Métodos necesarios de la lista

    getNext(); // recorrer la lista
    mostrarTitular(); // mostrar toda la lista de titulares que cumplen con las palabras 
}


eliminarTitulares();{ // Eliminar todos los titulares según filtro hecho con base a palabras que indique el usuario

    //Métodos necesarios de la lista

    getNext(); // recorrer la lista
    remove(); // eliminar aquellos titulres que contengan las palabras brindadas
}


modificarPosiciones();{  // Modificar posiciones de titulares según indique el usuario 

    //Métodos necesarios de la lista

    getNext(); // recorrer la lista
    getPrevius(); // devolverse en la lista en caso de querer aumentar de posición de una titular
    remove(); // remover los titulares necesarios para acomodarlos a como quiere el cliente
    addFront() / addBack(); //depende del lugar donde se necesite insertar el titular e insertar los demás en órden según la posicion del titular modificado
    mostrarTitular(); // mostrar al usuario el cambio hecho en el órden de los titulares
}




