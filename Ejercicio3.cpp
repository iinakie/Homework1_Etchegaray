#include <iostream>
#include <memory>

using namespace std;

// Explicacion para correrlo:
/*
Escribir en la consola: 
        g++ -o Ejercicio3 Ejercicio3.cpp (enter)
         ./Ejercicio3(enter)
*/

struct Node{
    int value;
    shared_ptr<Node> next;

    Node(int val) : value(val), null(nextptr);
}

