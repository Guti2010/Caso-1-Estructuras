Estructuras de Datos
Este proyecto implementa una lista doblemente enlazada para gestionar noticias obtenidas desde la API de NewsAPI, usando la biblioteca nlohmann/json para manejar JSON de forma sencilla. 
Permite insertar, buscar, eliminar y reubicar elementos en la lista, así como consultar noticias por palabra clave.

Estructura del proyecto
    app/
    json.hpp
    lista.h
    main.cpp
    Makefile
    MetodosOperacion.h
    news.cpp
    nodo.h
  Funcionalidades principales
    Consulta de noticias usando palabras clave (Newsapi::getRecords)
  Gestión de lista doblemente enlazada (ListaDobleEnlazada):
    Insertar elementos
    Buscar por palabras
    Eliminar por palabras
    Reubicar elementos
    Mostrar todos los elementos
    Mostrar top 5 elementos
  Compilación y ejecución
    Con docker: docker run -it --rm -v "%cd%:/home" -w /home gcc bash
    Ingresar lo siguiente en el bash:
      apt update -y
      apt install -y libcurl4-openssl-dev
      g++ -o app doublelist.cpp -lcurl
      ./app



Uso
El programa realiza las siguientes operaciones automáticamente:

Consulta noticias sobre una palabra especial y las agrega a la lista.
Muestra el top 5 y todos los elementos.
Permite buscar y eliminar elementos por palabras ingresadas por el usuario.
Permite reubicar elementos en la lista.

Autor: Alejandro Gutiérrez Chaves
