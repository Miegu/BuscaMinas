#include "io.h"
#include <iostream>
#include <string>

//Subprogramas:
void mostrar_cabecera() {
    cout << "Buscaminas" << endl;
    cout << "----------" << endl;
}

void pedir_pos(int& fila, int& columna) { // PREGUNTAR
    cout << "Introduce una fila: ";
    cin >> fila;
    cout << endl;
    cout << "Introduce una columna: ";
    cin >> columna;
}

void mostrar_resultado(tJuego juego) { // Muestra el resultado final del juego.
    if (esta_completo(juego)) { // Si ha terminado el juego
        if (mina_explotada(juego)) {
            cout << "El jugador a terminado, ya que ha explotado una mina." << endl;
        }
        else {
            cout << "El jugador ha ganado, no ha explotado ninguna mina." << endl;
        } // Fila y columna -1, se acaba.

    }
}
bool carga_juego(tJuego& juego) {
    bool carga = false;
    ifstream archivoInput;
    int posx, posy; // Posiciones de la mina
    istream& operator>> (istream & in, tJuego & juego);
    archivoInput.open("buscaminas.txt"); //nombre random

    if (archivoInput.is_open()) {
        archivoInput >> juego.tablero.nFils;
        archivoInput >> juego.tablero.nCols;
        archivoInput >> juego.num_minas;
        for (int i = 0; i < juego.num_minas; i++) {
            archivoInput >> posx;
            archivoInput >> posy;
            poner_mina(juego.tablero.datos[posx][posy]); // Pone la mina
        }
        carga = true;

    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    archivoInput.close();
    return carga;
}




//subprogramas privados
void mostrarCoutSeparadorMat(const tJuego& juego, int huecoCelda);
void mostrarCeldaConsola(const tJuego& juego, int f, int c, int huecos);
void colorNumero(int numero);



void mostrarCoutSeparadorMat(const tJuego& juego, int huecoCelda) {
    cout << "\t -+";
    for (int col = 0; col < dame_num_columnas(juego); ++col) {
        cout << setw(huecoCelda + 1) << setfill('-') << '+' << setfill(' ');
    }
    cout << endl;
}


void mostrar_juego_consola(const tJuego& juego) {
    cout << "        Jugadas: " << dame_num_jugadas(juego) << endl << endl;
    // mostrar cabecera
    cout << "\t  |";
    for (int col = 0; col < dame_num_columnas(juego); col++) {
        cout << LBLUE << setw(N_HUECOS) << col << RESET << '|';
    }
    cout << endl;

    // mostrar separador
    mostrarCoutSeparadorMat(juego, N_HUECOS);

    // mostrar tablero
    for (int f = 0; f < dame_num_filas(juego); f++) {
        // mostrar numero de fila
        cout << "\t" << LBLUE << setw(2) << f << RESET << '|';
        // mostrar la fila
        for (int c = 0; c < dame_num_columnas(juego); c++) {
            mostrarCeldaConsola(juego, f, c, N_HUECOS);
            cout << '|';
        }
        cout << endl;

        mostrarCoutSeparadorMat(juego, N_HUECOS);
    }
    cout << endl;
}



void colorNumero(int numero) {
    switch (numero)
    {
    case 1: cout << BLUE; break;
    case 2: cout << GREEN; break;
    case 3: cout << RED; break;
    case 4: cout << DBLUE; break;
    case 5: cout << DGREEN; break;
    case 6: cout << DRED; break;
    default:
        break;
    }
}


void mostrarCeldaConsola(const tJuego& juego, int fila, int columna, int huecos) {
    if (!es_visible(juego, fila, columna) && !esta_marcada(juego, fila, columna)) {
        cout << BG_GRAY << GRAY << setw(huecos) << setfill(' ') << ' ' << RESET;
    }
    else {
        cout << BG_BLACK << BLACK;
        if (!esta_marcada(juego, fila, columna)) {
            if (contiene_mina(juego, fila, columna)) {
                cout << RED << setw(huecos) << setfill(' ') << CHAR_MINA << RESET;
            }
            else {
                if (esta_vacia(juego, fila, columna)) {
                    cout << setw(huecos) << setfill(' ') << ' ' << RESET;
                }
                else {
                    if (contiene_numero(juego, fila, columna)) {
                        int numero = dame_numero(juego, fila, columna);
                        colorNumero(numero);
                        cout << setw(huecos) << setfill(' ') << numero << RESET;
                    }
                    else {
                        cout << BG_RED << RED << setw(huecos) << setfill(' ') << ' ' << RESET;
                    }
                }
            }
        }
        else {
            cout << BG_ORANGE << ORANGE << setw(huecos) << setfill(' ') << ' ' << RESET;
        }
    }
}