
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
    cout << nombreArchivo;
    if (carga_juego(juego, nombreArchivo)) {
        inicializar_listaUndo(listaUndo);
        bool salir = false;
        do {
            mostrar_cabecera();
            mostrar_juego_consola(juego);
            tListaPosiciones listaPos;
            inicializar_listaPosiciones(listaPos);
            int fila, columna;
            //Pide la fila y columna.
            pedir_pos(fila, columna);

            if (controlOperaciones(juego, fila, columna, listaUndo)) { // Si decide salir del juego.
                salir = true;
            }
            else { // Si no decide.
                // Jugada normal
                EstadoJuego estado = juega(juego, fila, columna, listaUndo); // ESTA FUNCI�N NO SE PUEDE METER EN JUEGO.CPP, porque usa funciones de io.h,y no esta incluida.
            }

            mostrar_resultado(juego); // Muestra el resultado una vez acabada la partida.
        } while (!salir && !esta_terminado(juego));

    }
    else {
        cout << "Error al cargar el juego." << endl;
    }
   
    return 0;
}