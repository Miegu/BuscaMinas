
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
            tListaPosiciones listaPos;
            inicializar_listaPosiciones(listaPos);
            int fila, columna;
            pedir_pos(fila, columna); // Función del módulo inputOutput

            // Control de operaciones especiales en main
            if (fila == -1 && columna == -1) {
                salir = true;
                cout << "Partida abandonada\n";
            }
            else if (fila == -2 && columna == -2) {
                // Lógica de marcado/desmarcado
                int x, y;
                pedir_pos(x, y);
                if (es_valida(juego.tablero, x, y)) {
                    marcar_desmarcar(juego, x, y);
                }
            }
            else if (fila == -3 && columna == -3) {
                // Operación undo
                if (longitud_listaUndo(listaUndo) > 0) {
                    aplicar_undo(juego, listaUndo);
                    juego.estado = ACTIVO;
                }
            }
            else {
                // Jugada normal
                EstadoJuego estado = juega(juego, fila, columna, listaUndo);
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
