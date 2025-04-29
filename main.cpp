// Nicole Vergara
// Seyam Acuba


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
    tListaJuegos listaJuegos;

    //cout << "Introduce el nombre del archivo: ";
    //getline(cin, nombreArchivo);
    //nombreArchivo += ".txt";

    //if (carga_juego(juego, nombreArchivo)) {
        //inicializar_listaUndo(listaUndo);

        //do {
          //  mostrar_cabecera();
            //mostrar_juego_consola(juego);

            //int fila, columna;
            //pedir_pos(fila, columna);

            //estado = estadoJuego(juego, fila, columna, listaUndo);

        //} while ((estado != ABANDONADO) && !esta_terminado(juego));
        //mostrar_resultado(juego);
    //}
    //else {
      //  cout << "Error al cargar el juego." << endl;
    //}

    //return 0;

    //VERSIÓN 2:
    inicializarListaJuegos(listaJuegos); //Funciona la inicialización

    if (!cargar_juegos(listaJuegos)) {
        int filas, columnas, minas;
        cout << "Introduce el numero de filas: " << endl;
        cin >> filas;
        cout << "Introduce el numero de columnas: " << endl;
        cin >> columnas;
        cout << "Introduce el numero de minas: " << endl;
        cin >> minas;
        crear_juego(filas, columnas, minas);

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
        mostrar_juegos(listaJuegos);
    }

    return 0;
}