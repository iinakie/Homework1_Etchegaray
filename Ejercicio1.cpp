#include <iostream>
#include <vector>
using namespace std;

// Explicacion para correrlo:
/*
Escribir en la consola: 
        g++ -o Ejercicio1 Ejercicio1.cpp (enter)
        ./Ejercicio1(enter)
*/

//Explicacion de mi codigo:
/*
Este programa creo una matriz cuadrada de tamaño n x n y la lleno con números del 1 hasta n*n. Primero, el dejo que usuario ingrese el número n.
Si n es menor o igual a 1, el programa muestra un mensaje de error, y sino se ejecuta. La función crearM genera la matriz y la llena. 
Luego, la función imprimirM imprime los elementos de la matriz empezando desde el último hasta el primero, mostrando la posición y el valor de 
cada "casillero". En este código uso vector<vector<int>> para manejar la matriz mas facil.
*/

vector<vector<int> > crearM(int n){
    vector<vector<int> > matriz(n, vector<int>(n));

    int contador = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] = contador++;
        }
    }
    return matriz;
}

void imprimirM(const vector<vector<int> >&matriz, int n){
    for(int i = n * n - 1; i >= 0; i--){
        int fila = i/n;
        int columna = i % n;
        cout << "M[" << fila << "][" << columna << "] =" << matriz[fila][columna] << endl;
    }
}

int main(){
    int n;
    cout << "Ingresa un n para tu matriz cuadrada: " << endl;
    cin >> n;
    if(n<=1){
        cout << "El numero tiene que ser mayor a 1";
        return 1;
    }
    vector<vector<int> > matriz = crearM(n);
    imprimirM(matriz, n);
    return 0;
}