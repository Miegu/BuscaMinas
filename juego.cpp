#include "juego.h"
#include <iostream>

void inicializar(tJuego &juego, int nfils, int ncols) {
	juego.mina_explotada = false;
	juego.num_descubiertas = 0;
	juego.num_jugadas = 0;
	juego.num_minas = 0;
	juego.tablero.nFils = nfils;
	juego.tablero.nCols = ncols;
	inicializar_tablero(juego.tablero, nfils, ncols); // Inicializa el tablero
}


int dame_num_jugadas(const tJuego& juego) { // Nº de Jugadas
	return juego.num_jugadas;
}

int dame_num_filas(const tJuego& juego) { // Nº de Filas
	return num_filas(juego.tablero);
}

int dame_num_columnas(const tJuego& juego) { // Nº de Columnas
	return num_columnas(juego.tablero);
}

int dame_num_minas(const tJuego& juego) { // Nº de Minas
	return juego.num_minas;
}

bool contiene_mina(const tJuego& juego, int fila, int columna) { //True si la celda contiene una MINA.
	bool contiene = false;
	if (es_valida(juego.tablero, fila, columna)) {
		if (es_mina(juego.tablero.datos[fila][columna])) {
			contiene = true;
		}
	}
	return contiene;
}

bool es_visible(const tJuego& juego, int fila, int columna) { // !!! La función en celda se llama igual y coge esta en vez de la otra.
	bool visible = false;
	if (es_valida(juego.tablero, fila, columna)) {
		if (celda_es_visible(juego.tablero.datos[fila][columna])) {
			visible = true;
		}
	}
	return visible;
}

bool esta_marcada(const tJuego& juego, int fila, int columna) { // !!! El mismo problema.
	bool marcada = false;
	if (es_valida(juego.tablero, fila, columna)) {
		if (celda_esta_marcada(juego.tablero.datos[fila][columna])) {
			marcada = true;
		}
	}
	return marcada;
}

bool esta_vacia(const tJuego& juego, int fila, int columna) { // x2
	bool vacia = false;
	if (es_valida(juego.tablero, fila, columna)) {
		if (celda_esta_vacia(juego.tablero.datos[fila][columna])) {
			vacia = true;
		}
	}
	return vacia;
}

bool contiene_numero(const tJuego& juego, int fila, int columna) { // x3
	bool contiene = false;
	if (es_valida(juego.tablero, fila, columna)) {
		if (celda_contiene_numero(juego.tablero.datos[fila][columna])) {
			contiene = true;
		}
	}
	return contiene;

}

int dame_numero(const tJuego& juego, int fila, int columna) {
	if (es_valida(juego.tablero, fila, columna)) { // True si es válida
		if (contiene_numero(juego, fila, columna)) { // True si contiene un nº
			return celda_dame_numero(juego.tablero.datos[fila][columna]); // Retorna el valor del nº
		}
	}
}

bool esta_completo(const tJuego& juego) { 
	bool completo = true;
	for (int i = 0; i < juego.tablero.nFils; i++) {
		for (int j = 0; j < juego.tablero.nCols; j++) {
			if (!(es_mina(juego.tablero.datos[i][j]))) { // si NO es una mina.
				if (!celda_es_visible(juego.tablero.datos[i][j])) {
					completo = false; // Si hay una celda sin descubrir, no esta completo.
				}
			}
		}
	}
	return completo;
}

bool mina_explotada(const tJuego& juego) { // Mina explotada
	bool explotada = false;
	if (juego.mina_explotada) {
		explotada = true;
	}
	return explotada;
}

bool esta_terminado(const tJuego& juego) {

}

void poner_mina(tJuego juego, int fila, int columna) {
	if(es_valida(juego.tablero, fila, columna) && !es_mina(juego.tablero.datos[fila][columna])){
		int direcciones[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
		for (int i = 0; i < 8; i++) {
			int nFila = fila + 1 * direcciones[i][0];
			int nCol = columna + 1 * direcciones[i][1];
			if()
	}
}

void marcar_desmarcar(tJuego& juego, int fila, int columna) {
	if (es_valida(juego.tablero, fila, columna)) { // Mira si es válida
		if (celda_esta_marcada(juego.tablero.datos[fila][columna])) { //Si esta marcada, la desmarca
			desmarcar_celda(juego.tablero.datos[fila][columna]);
		}
		else {
			marcar_celda(juego.tablero.datos[fila][columna]); //Si no, la marca.
		}
	}
}

void ocultar(tJuego &juego, int fila, int columna) {
	if (es_valida(juego.tablero, fila, columna)) {
		if (celda_es_visible(juego.tablero.datos[fila][columna])) {
			ocultar_celda(juego.tablero.datos[fila][columna]); // Oculta la celda, si es visible.
		}
	}
}

void juega(tJuego& juego, int fila, int columna, int lista_pos) {

}
