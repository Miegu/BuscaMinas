#include "io.h"
#include "juego.h"
#include "listaUndo.h"
#include <iostream>
using namespace std;

int main() {
    tJuego juego;
    tListaUndo listaUndo;
    string nombreArchivo;
    EstadoJuego estado;

    cout << "Introduce el nombre del archivo: ";
    getline(cin, nombreArchivo);
    nombreArchivo += ".txt";

    if (carga_juego(juego, nombreArchivo)) {
        inicializar_listaUndo(listaUndo);

        do {
            mostrar_cabecera();
            mostrar_juego_consola(juego);

            int fila, columna;
            pedir_pos(fila, columna);

            estado = estadoJuego(juego, fila, columna, listaUndo);

        } while ((estado != ABANDONADO) && !esta_terminado(juego));
        mostrar_resultado(juego);
    }
    else {
        cout << "Error al cargar el juego." << endl;
    }

    return 0;
}