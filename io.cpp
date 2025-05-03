#include "io.h"
#include <iostream>

using namespace std;


void mostrar_cabecera() {
    cout << "Buscaminas" << endl;
    cout << "----------" << endl;
    cout << "Instrucciones:" << endl;
    cout << "- Introduce las coordenadas para descubrir una celda." << endl;
    cout << "- Usa -1 -1 para abandonar la partida." << endl;
    cout << "- Usa -2 -2 para marcar/desmarcar una celda." << endl;
    cout << "- Usa -3 -3 para deshacer una jugada." << endl;
}

void pedir_pos(int& fila, int& columna) {
    cout << "Introduce una fila: ";
    while (!(cin >> fila)) {
        cout << "Entrada invalida. Introduce un numero: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "\nIntroduce una columna: ";
    while (!(cin >> columna)) {
        cout << "Entrada invalida. Introduce un numero: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << endl;
}

void mostrar_resultado(tJuego juego) {
    mostrar_juego_consola(juego);
    if (juego.estado == PERDIDO) {
        cout << "La mina a explotado, has perdido :c " << endl;
    }
    else if (juego.estado == GANADO) {
        cout << "Has ganado! No ha explotado ninguna mina." << endl;
    }
    else if (juego.estado == ABANDONADO) {
        cout << "Partida Abandonada" << endl;
    }
}


bool carga_juego(tJuego& juego, const string& nombreArchivo) {
    bool carga = false;

    ifstream archivoInput(nombreArchivo);
    int posx, posy; // Posiciones de la mina

    if (archivoInput.is_open()) {
        int fils, cols, minas;
        archivoInput >> fils >> cols >> minas;
        inicializar(juego, fils, cols);
        juego.num_minas = minas;
        for (int i = 0; i < minas; i++) {
            archivoInput >> posx >> posy;
            if (es_valida(juego.tablero, posx, posy)) {
                poner_mina_juego(juego, posx, posy);
            } // Pone la mina
        }
        carga = true;
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    archivoInput.close();
    return carga;
}

//V2
bool cargar_juegos(tListaJuegos& listaJuegos) {
    bool apertura = false;
    ifstream archivoInput;
    string nombreFichero;
    cout << "Introduce el nombre del fichero de la Lista de Juegos: " << endl;
    cin >> nombreFichero;
    nombreFichero += ".txt";
    int numJuegos, posicion;


    archivoInput.open(nombreFichero);
    if (archivoInput.is_open() && archivoInput >> numJuegos && numJuegos != 0) {
        int numFilas, numColumnas, numMinas;

        for (int i = 0; i < numJuegos; i++) {
            tJuego juegoNuevo; //Crea un JUEGO NUEVO

            archivoInput >> numFilas;
            archivoInput >> numColumnas;

            inicializar(juegoNuevo, numFilas, numColumnas); //Inicializamos el juego
            archivoInput >> numMinas;

            for (int j = 0; j < numMinas; j++) {
                int filaMina, columnaMina;

                archivoInput >> filaMina;
                archivoInput >> columnaMina;

                poner_mina_juego(juegoNuevo, filaMina, columnaMina); //Colocamos las minas
            }

            posicion = insertarJuego(listaJuegos, juegoNuevo);
            cout << "Insertado en la posicion " << posicion + 1 << endl;
        }

        apertura = true;
    }

    return apertura;
}

void mostrar_juegos(const tListaJuegos listaJuegos) { //Ya a la hora de insertarlos se ordena
    cout << "Mostrando lista de juegos por nivel de dificultad. . . . " << endl;
    for (int i = 0; i < listaJuegos.cont; i++) {
        tJuego actual = *(listaJuegos.lista[i]);
        cout << "Juego " << i << ":" << endl;
        cout << "      Dimension: " << actual.tablero.nFils << " x " << actual.tablero.nCols << endl;
        cout << "      Minas: " << actual.num_minas << endl;
    }
}

bool guardar_juegos(tListaJuegos& listaJuegos) {
    bool apertura = false;

    string nombreFichero;
    ofstream archivoOutput;
    cout << "Introduce el nombre del fichero: " << endl;
    cin >> nombreFichero;
    nombreFichero += ".txt";


    archivoOutput.open(nombreFichero);

    if (archivoOutput.is_open()) { //Falta terminar
        apertura = true;
    }

    return apertura;
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