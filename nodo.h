#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Nodo
{
public:
    string dato;
    Nodo *siguiente;
    Nodo *anterior;

    Nodo(const string &valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};