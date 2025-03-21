#include <iostream>
#include <fstream>

using namespace std;

// Explicacion para correrlo:
/*
Escribir en la consola: 
        g++ -o Ejercicio2 Ejercicio2.cpp (enter)
        ./Ejercicio2(enter)
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

