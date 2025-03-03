
#include "io.h"
#include "juego.h"
#include "listaPosiciones.h"
#include "listaUndo.h"
#include <iostream>
using namespace std;

int main() {
    tJuego juego;
    tListaUndo lista_undo;
    int fila, columna;

    if (carga_juego(juego)) {
        do {
            cout << "Introduce fila y columna: ";
            cin >> fila >> columna;
            juega(juego, fila, columna, lista_undo.cont);
        } while (!esta_terminado(juego) && !(fila == -1 && columna == -1));
    } else {
        cout << "Error al cargar el juego." << endl;
    }

    return 0;
}