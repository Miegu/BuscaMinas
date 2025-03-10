
#include "io.h"
#include "juego.h"
#include "listaPosiciones.h"
#include "listaUndo.h"
#include <iostream>
using namespace std;

int main() {
    tJuego juego;
    tListaPosiciones lista_pos;
    tListaUndo lista_undo;
    int fila, columna;
    string nombreArchivo;

    cout << "Introduce el nombre del archivo (.txt): ";
    cin >> nombreArchivo;

    if (carga_juego(juego, nombreArchivo)) { // Inicializa el juego y tablero.
        inicializar_listaPosiciones(lista_pos);
        inicializar_listaUndo(lista_undo);
        do {
            mostrar_cabecera();
            mostrar_juego_consola(juego);
            pedir_pos(fila, columna);
            juega(juego, fila, columna, lista_pos);
        } while (!esta_terminado(juego) && !(fila == -1 && columna == -1));
        if (esta_terminado(juego)) { // Una vez finaliza el juego, determina si ha ganado el jugador o a perdido.
            mostrar_cabecera();
            mostrar_juego_consola(juego);
            if (juego.mina_explotada) {
                cout << "La mina ha sido explotada, ha perdido.";
            }
            else {
                cout << "Ha ganado, la mina no ha sido explotada.";
            }
        }
    } else {
        cout << "Error al cargar el juego." << endl;
    }

    return 0;
}