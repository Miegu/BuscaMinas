#ifndef IO_H
#define IO_H

#include "juego.h"
#include "colors.h"
#include <iostream> 
#include <fstream>
#include <iomanip>

using namespace std;

const int N_HUECOS = 2; // huecos a dejar en el formato de las celdas.
const char CHAR_MINA = '*';     // Mina


void mostrar_cabecera();
void mostrar_juego_consola(const tJuego& juego);
bool carga_juego(tJuego& juego);

#endif 

