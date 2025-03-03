#include "juego.h"
#include <iostream>

void inicializar(tJuego &juego, int nfils, int ncols) {
	juego.mina_explotada = false;
	juego.num_descubiertas = 0;
	juego.num_jugadas = 0;
	juego.num_minas = 0;
	juego.tablero.nFils = nfils;
	juego.tablero.nCols = ncols;
	inicializar_tablero(juego.tablero); // Inicializa el tablero
}


int dame_num_jugadas(tJuego juego) { // Nº de Jugadas
	return juego.num_jugadas;
}

int dame_num_filas(tJuego juego) { // Nº de Filas
	return num_filas(juego.tablero);
}

int dame_num_columnas(tJuego juego) { // Nº de Columnas
	return num_columnas(juego.tablero);
}

int dame_num_minas(tJuego juego) { // Nº de Minas
	return juego.num_minas;
}

bool contiene_mina(tJuego juego, int fila, int columna) { //True si la celda contiene una MINA.
	bool contiene = false;
	if (es_valida(juego.tablero, fila, columna)) {
		if (es_mina(juego.tablero.datos[fila][columna])) {
			contiene = true;
		}
	}
	return contiene;
}

bool es_visible(tJuego juego, int fila, int columna) { // !!! La función en celda se llama igual y coge esta en vez de la otra.
	bool visible = false;
	if (es_valida(juego.tablero, fila, columna)) {
		if (es_visible(juego.tablero.datos[fila][columna])) {
			visible = true;
		}
	}
	return viisble;
}

bool esta_marcada(tJuego juego, int fila, int columna) { // !!! El mismo problema.
	bool marcada = false;
	if (es_valida(juego.tablero, fila, columna)) {
		if (esta_marcada(juego.tablero.datos[fila][columna]) {
			marcada = true;
		}
	}
	return marcada;
}

bool esta_vacia(tJuego juego, int fila, int columna) { // x2
	bool vacia = false;
	if (es_valida(juego.tablero, fila, columna)) {
		if (esta_vacia(juego.tablero.datos[fila][columna])) {
			vacia = true;
		}
	}
	return vacia;
}

bool contiene_numero(tJuego juego, int fila, int columna) { // x3
	bool contiene = false;
	if (es_valida(juego.tablero, fila, columna)) {
		if (contiene_numero(juego.tablero.datos[fila][columna])) {
			contiene = true;
		}
	}
	return contiene;

}

int dame_numero(tJuego juego, int fila, int columna) {
	if (es_valida(juego.tablero, fila, columna)) { // True si es válida
		if (contiene_numero(juego.tablero.datos[fila][columna])) { // True si contiene un nº
			return dame_numero(juego.tablero.datos[fila][columna]); // Retorna el valor del nº
		}
	}
}

bool esta_completo(tJuego juego) { 
	bool completo = true;
	for (int i = 0; i < juego.tablero.nFils; i++) {
		for (int j = 0; j < juego.tablero.nCols; j++) {
			if (!(es_mina(juego.tablero.datos[i][j]))) { // si NO es una mina.
				if (!es_visible(juego.tablero.datos[i][j])) {
					completo = false; // Si hay una celda sin descubrir, no esta completo.
				}
			}
		}
	}
	return completo;
}

bool mina_explotada(tJuego juego) { // Mina explotada
	bool explotada = false;
	if (juego.mina_explotada) {
		explotada = true;
	}
	return explotada;
}

esta_terminado(tJuego juego) {

}

poner_mina(tJuego juego, int fila, int columna) {

}

void marcar_desmarcar(tJuego &juego, int fila, int columna) {
	if (es_valida(juego.tablero.datos[fila][columna])) { // Mira si es válida
		if (esta_marcada(juego.tablero.datos[fila][columna].marcada)) { //Si esta marcada, la desmarca
			desmarcar_celda(juego.tablero.datos[fila][columna]);
		}
		else {
			marcar_celda(juego.tablero.datos[fila][columna]); //Si no, la marca.
		}
	}
}

void ocultar(tJuego &juego, int fila, int columna) {
	if (es_valida(juego.tablero.datos[fila][columna])) {
		if (es_visible(juego.tablero.datos[fila][columna])) {
			ocultar_celda(juego.tablero.datos[fila][columna]); // Oculta la celda, si es visible.
		}
	}
}

void juega(tJuego juego, int fila, int columna, int lista_pos) {

}
