#include <iostream>
#include <chrono>  

#define texto1 "Hola me llamo Iñaki, no soy tan bueno programando igualmente estoy aca intentadolo"
#define texto2 "Hola me llamo Iñaki, no soy tan bueno programando igualmente estoy aca intentadolo"
#define texto3 "Hola me llamo Iñaki, no soy tan bueno programando igualmente estoy aca"

// Explicacion para correrlo:
/*
Escribir en la consola: 
        g++ -o Ejercicio4 Ejercicio4.cpp (enter)
        ./Ejercicio4(enter)
*/

// Explicacion de mi codigo:
/*
En la primer funcion comparo a dos cadenas de texto, de forma que compara caracter por caracter luego de probar si las cadenas son iguales o no
(devuelve true o false), le suma 1 a cada cadena para que evalue el siguiente caracter. Mas adelante en el main se puede ver como mido el tiempo de 
ejecucion lo que ayuda a ver el rendimiento del programa. A la hora de ver el tiempo de compilación de cada cadena, uso los `constexpr` para realizar 
la comparación de manera anticipada durante la compilación, es decir, en vez de calcular las comparaciones en tiempo de ejecución, las evaluaciones de 
las cadenas se hacen mientras el programa se compila. Y al finalizar el programa imprime: si las cadenas son o no iguales y el tiempo que tardo
el programa en procesarlo.
*/


constexpr bool compararC(const char* cadena1, const char* cadena2) {
    if (*cadena1 == '\0' && *cadena2 == '\0') {
        return true;
    }
    if (*cadena1 == '\0' || *cadena2 == '\0') {
        return false;
    }
    if (*cadena1 != *cadena2) {
        return false;
    }
    return compararC(cadena1 + 1, cadena2 + 1);
}


constexpr bool intentos[3] = {
    compararC(texto1, texto2),
    compararC(texto1, texto3),
    compararC(texto1, texto2),
};

int main() {
    auto startTime = std::chrono::high_resolution_clock::now();
    
    bool iguales = intentos[1]; // Cambiar del 0 al 2, dependiendo cuales textos(del 1 al 3) quiero comparar
    std::cout << "Las cadenas son iguales: " << (iguales ? "verdadero" : "falso") << std::endl;
    
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    std::cout << "Tiempo de ejecución: " << elapsedTime.count() << " nanosegundos" << std::endl;

    return 0;
}

// Explicacion porque elegi char* en vez de string:
/*
Elegi char* primero porque era lo que me acordaba de la cursada pasada, el uso de punteros. Ademas con este se usa la memoria mas correctamente 
y a la hora de hacaer la recursion es mas facil ya que accedo a cada caracter de la cadena, con el cadena1 +1 muevo el puntero y asi accedo a 
cada uno(como si fuese un array y voy iterando en el). En comparacion con los string, si quisiera hacer lo mismo en el caso de la recursion
seria distinto, ya que estos gestionan la memoria automaticamente y no puedo acceder a cada uno de los caracteres, como si lo hacen los punteros. 
Y ademas deberia de aplicar varias funciones mas 
*/

