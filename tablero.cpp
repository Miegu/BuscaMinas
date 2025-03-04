#include "tablero.h"

#include <iostream>


void inicializar_tablero(tTablero& tablero, int fils, int cols){
	tablero.nFils = fils;
	tablero.nCols = cols;
	for (int i = 0; i < fils; i++) { // Filas
		for (int j = 0; j < cols; j++) { // Columnas
			inicializarCelda(tablero.datos[i][j]); // Inicializa la celda
		}
	}
}

bool es_valida(const tTablero& tablero, int fila, int columna) { // Para ver si la celda [fila][columna] es válida.
	bool valida = false;
	if (fila >= 0 && fila < tablero.nFils && columna >= 0 && columna < tablero.nCols) {
		valida = true;
	}
	return valida;
}

tCelda& dame_celda(tTablero& tablero, int fila, int columna) {
	if (es_valida(tablero, fila, columna)) {
		return tablero.datos[fila][columna]; // Si es válida (true), retorna la celda
	}
}


void poner_celda(tTablero& tablero, int fila, int columna, tCelda celda) {
	if (es_valida(tablero, fila, columna)) {
		tablero.datos[fila][columna] = celda;
	}
}

int num_filas(const tTablero& tablero) {
	return tablero.nFils;
}

int num_columnas(const tTablero& tablero) {
	return tablero.nCols;
}