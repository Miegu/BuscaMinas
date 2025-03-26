
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
            cout << "Introduce una fila: " << endl;
            cin >> fila;
            cout << "Introduce una columna: " << endl;
            cin >> columna;

            if (controlOperaciones(juego, fila, columna, listaUndo)) { // Si decide salir del juego.
                salir = true;
            }
            else { // Si no decide.
                // Jugada normal
                EstadoJuego estado = juega(juego, fila, columna, listaUndo); // ESTA FUNCIÓN NO SE PUEDE METER EN JUEGO.CPP, porque usa funciones de io.h,y no esta incluida.
                if (estado == PERDIDO || estado == GANADO) {
                    mostrar_juego_consola(juego);
                    mostrar_resultado(juego);
                    cout << "Seguir Jugando? S/N " << endl;
                    char c;
                    cin >> c;
                    if (c == 'n') {
                        salir = true;
                    }
                    else if (c == 's') {
                        juego.estado = ACTIVO;
                        cout << "Nueva Partida: " << endl;
                        inicializar_listaUndo(listaUndo); // Reiniciar histórico
                        carga_juego(juego, nombreArchivo); // Recargar tablero
                        salir = false; // Restablecer estado
                    }


                }
            }
        } while (!salir && !esta_terminado(juego));
    }
    else {
        cout << "Error al cargar el juego." << endl;
    }
   
    return 0;
}