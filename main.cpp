
#include "io.h"
#include "juego.h"
#include "listaUndo.h"
#include <iostream>
using namespace std;

int main() {
    tJuego juego;
    tListaUndo listaUndo;
    string nombreArchivo;
    
    // Solicitar nombre de archivo con getline para espacios
    cout << "Introduce el nombre del archivo: ";
    getline(cin, nombreArchivo); 
    nombreArchivo += ".txt";
    if (carga_juego(juego, nombreArchivo)) {
        inicializar_listaUndo(listaUndo);
        bool salir = false;
        do {
            mostrar_cabecera();
            mostrar_juego_consola(juego);
            pedir_pos(fila, columna);
            juega(juego, fila, columna, lista_pos);
        } while (!esta_terminado(juego) && !(fila == -1 && columna == -1));
    } else {
        cout << "Error al cargar el juego." << endl;
    }

    return 0;
}
