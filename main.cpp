// Nicole Vergara
// Seyam Acuba


#include "io.h"
#include "juego.h"
#include "listaUndo.h"
#include "listaJuegos.h"
#include <iostream>
#include "memoryleaks.h"
using namespace std;


int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    tListaUndo listaUndo;
    inicializar_listaUndo(listaUndo);
    tListaJuegos listaJuegos;
    inicializarListaJuegos(listaJuegos);
    tJuego juego;

    bool jugarPartida = false;
    int pos;
    // Si no hay juegos, cargarlos
    if (!cargar_juegos(listaJuegos)) {
        cout << "Creando nuevo juego..." << endl;
        pos = crearNuevoJuego(listaJuegos);
        jugarPartida = true;
        mostrar_juegos(listaJuegos);
        juego = dame_juegos(listaJuegos, pos);
    }
    else {
        mostrar_juegos(listaJuegos);

        int opcion;
        cout << "1. Juego nuevo" << endl;
        cout << "2. Juego existente" << endl;
        cout << "Opcion: " << endl;
        cin >> opcion;

        if (opcion == 1) {
            jugarPartida = true;
            pos = crearNuevoJuego(listaJuegos);
            mostrar_juegos(listaJuegos);
            juego = dame_juegos(listaJuegos, pos);
        }
        else {
            int seleccion;
            cout << "Seleccione juego (0-" << numero_juegos(listaJuegos) - 1 << "): ";
            cin >> seleccion;

            if (seleccion >= 0 && seleccion < numero_juegos(listaJuegos)) {
                juego = dame_juegos(listaJuegos, seleccion);
                pos = seleccion;
                jugarPartida = true;
            }
        }

    }
    if (jugarPartida) {
        // Jugar
        EstadoJuego estado = ACTIVO;
        do {
            mostrar_cabecera();
            mostrar_juego_consola(juego);
            int fila, columna;
            pedir_pos(fila, columna);
            estado = procesarJugada(juego, fila, columna, listaUndo);
        } while (estado == ACTIVO);

        // Finalizar
        if (esta_terminado(juego) && pos >= 0) {
            eliminar(listaJuegos, pos);
        }
        mostrar_resultado(juego);
    }

    // Guardar estado final
    guardar_juegos(listaJuegos);

    destruye(listaJuegos);
    destruye(listaUndo);
    

    return 0;
}