#ifndef TABLERO_H
#define TABLERO_H
#include "celda.h"
const int MAX_FILS = 20;
const int MAX_COLS = 20;


typedef struct {
	int nFils, nCols;
	tCelda datos[MAX_FILS][MAX_COLS];
} tTablero;


void inicializar_tablero(tTablero& tablero, int fils, int cols);
int num_filas(const tTablero& tablero);
int num_columnas(const tTablero& tab);
tCelda dame_celda(const tTablero& tablero, int fila, int columna);
bool es_valida(const tTablero& tablero, int fila, int columna);
void poner_celda(tTablero& tablero, int fila, int columna, tCelda celda);

#endif
