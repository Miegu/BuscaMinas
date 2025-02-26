#ifndef TABLERO_H
#define TABLERO_H
#include "celda.h"
const int MAX_FILS = 20;
const int MAX_COLS = 20;


typedef struct {
	int nFils, nCols;
	tCelda datos[MAX_FILS][MAX_COLS];
} tTablero;
void inicializar(tTablero tablero);
void inicializar_tablero(tTablero tablero, int nfils, int ncols);
int num_filas(tTablero tablero);
int num_columnas(tTablero tab);
void dame_celda(tTablero tablero, int fila, int columna);
void es_valida(tTablero tablero, int fila, int columna);
void poner_celda(tTablero tablero, int fila, int columna, int celda);

#endif
