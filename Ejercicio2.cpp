#include <iostream>
#include <fstream>

using namespace std;

// Explicacion para correrlo:
/*
Escribir en la consola: 
        g++ -o Ejercicio2 Ejercicio2.cpp (enter)
        ./Ejercicio2(enter)
*/

// Explicacion de mi codigo:
/*
En este código tengo varias funciones para registrar mensajes en un archivo. La primera función recibe un mensaje y un nivel de severidad,
y dependiendo del nivel (de 0 a 4), el programa tira como [DEBUG], [INFO], [WARNING], [ERROR] o [CRITICAL] y luego lo escribe el mensaje
en un archivo. La segunda función registra un mensaje de error, indicando en qué archivo y línea ocurrió. La tercera función registra un
intento de acceso al programa, pidiendo si el usuario quiere acceder y su nombre de usuario, si la respuesta es válida (si o no) se registra
en el archivo, si no, se muestra un error en la consola. En el `main`, hice un especie demenú donde el usuario puede elegir entre estas opciones 
y se registran los mensajes en el archivo correspondiente. Si el usuario elige una opción incorrecta, lanza un error, lo captura y lo guarda
en el archivo indicando el error, el archivo y la línea donde ocurrió.
*/

void logMessage(string mensaje, int NivelSeveridad){
    ofstream archivo("archivo_salida.txt", ios::app);

    if(!archivo){
        cout<<"Error al abrir el nuevo archivo"<< endl;
    }

    switch (NivelSeveridad){
        case 0: archivo << "[DEBUG]"<< mensaje << endl; 
        break;
        case 1: archivo << "[INFO]"<< mensaje << endl; 
        break;
        case 2: archivo << "[WARNING]"<< mensaje << endl; 
        break;
        case 3: archivo << "[ERROR]"<< mensaje << endl; 
        break;
        case 4: archivo << "[CRITICAL]"<< mensaje << endl; 
        break;
        default:
        archivo << "La opción:"<< NivelSeveridad <<"no es válida."<< endl;
        break;
    }
}

void logMessage(string Mensage_de_Error, string Archivo, int Línea_de_Código){
    ofstream archivo("archivo_salida.txt", ios::app);

    if(!archivo){
        cout<<"Error al abrir el nuevo archivo"<< endl;
    }

    archivo << "El mensaje:" << Mensage_de_Error << " del archivo:" << Archivo << ", ha sido encontrado en la linea:" << Línea_de_Código << endl;

}

void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario){
    if (Mensaje_De_Acceso != "si" && Mensaje_De_Acceso != "no") {
        cout << "ERROR!!! Respuesta inválida. Solo se permite 'si' o 'no'." << endl;
        return; 
    }

    ofstream archivo("archivo_salida.txt", ios::app);

    if(!archivo){
        cout<<"Error al abrir el nuevo archivo"<< endl;
    }

    archivo << "[SECURITY] Nombre de Usuario:" << Nombre_de_Usuario << "Quieres acceder al programa? si/no" << Mensaje_De_Acceso << endl;
    
}


int main(){
    int opcion;

    try{
        while(true){
            cout << "Elegi una opción:"<< endl;
            cout << "1-Registrar mensaje con nivel de severidad"<< endl;
            cout << "2-Registrar mensaje de error en un archivo"<< endl;
            cout << "3-Registrar intento de acceso al programa"<< endl;
            cout << "4-Salir del programa"<< endl;
            cin >> opcion;


            if(opcion == 1){
                string mensaje;
                int lvl;

                cout << "Ingresa tu mensaje: " << endl;
                cin>> mensaje;

                cout << "Ingresa el nivel de severidad de tu mensaje(0-4): " << endl;
                cin >> lvl;

                logMessage(mensaje, lvl);
                cout << "Tu mensaje se registro correctamente en la base de datos." << endl;

            }
            else if (opcion == 2) {
                string mensaje, archivo;
                int linea;

                cout << "Ingresa tu mensaje: ";
                cin >> mensaje;

                cout << "Ingresa el nombre del archivo donde ocurrió el error: " << endl;
                cin >> archivo;

                cout << "Ingresa el número de línea donde ocurrió el error: ";
                cin >> linea;

                logMessage(mensaje, archivo, linea);
                cout << "El error se registro correctamente.\n";
            } 
            else if (opcion == 3) {
                string mensaje, usuario;

                cout << "Quieres acceder al programa? (si/no): ";
                cin >> mensaje;

                cout << "Ingresa tu nombre de usuario: ";
                cin >> usuario;

                logMessage(mensaje, usuario);
                cout << "Acceso registrado correctamente.\n";
            } 
            else if (opcion == 4) {
                cout << "Saliendo del programa.\n";
                break;
            } 
            else {
                throw runtime_error("¡Error detectado! Forzando cierre del programa...");
            }
        }
    }
    catch (const exception &e) {
        logMessage(e.what(), "main.cpp", __LINE__); 
        cout << "Se ha detectado un error: " << e.what() << endl;
        cout << "El programa se cerrará con código de error 1." << endl;
        return 1; 
    }

}

