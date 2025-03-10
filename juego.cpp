#include "juego.h"
#include <iostream>
using namespace std;

void inicializar(tJuego &juego, int nfils, int ncols) {
	juego.mina_explotada = false;
	juego.num_descubiertas = 0;
	juego.num_jugadas = 0;
	juego.num_minas = 0;
	juego.tablero.nFils = nfils;
	juego.tablero.nCols = ncols;
	inicializar_tablero(juego.tablero, nfils, ncols); // Inicializa el tablero
}


int dame_num_jugadas(const tJuego& juego) { // N� de Jugadas
	return juego.num_jugadas;
}

int dame_num_filas(const tJuego& juego) { // N� de Filas
	return num_filas(juego.tablero);
}

int dame_num_columnas(const tJuego& juego) { // N� de Columnas
	return num_columnas(juego.tablero);
}

int dame_num_minas(const tJuego& juego) { // N� de Minas
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

bool es_visible(const tJuego& juego, int fila, int columna) { // !!! La funci�n en celda se llama igual y coge esta en vez de la otra.
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
	if (es_valida(juego.tablero, fila, columna)) { // True si es v�lida
		if (contiene_numero(juego, fila, columna)) { // True si contiene un n�
			return celda_dame_numero(juego.tablero.datos[fila][columna]); // Retorna el valor del n�
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
void explotar_mina(tJuego & juego, int fila, int columna) {
	tCelda celda = dame_celda(juego.tablero, fila, columna);
		if (es_mina(celda) && es_visible(juego, fila, columna)) {
				juego.mina_explotada = true;
				juego.num_descubiertas++; // Actualizar contador
			}
		}

bool mina_explotada(const tJuego & juego) {
		return juego.mina_explotada;
	}

bool esta_terminado(const tJuego& juego) {
	return (mina_explotada(juego) || esta_completo(juego));
}

void poner_mina_juego(tJuego& juego, int fila, int columna) {
	if(es_valida(juego.tablero, fila, columna) && !es_mina(juego.tablero.datos[fila][columna])){
		poner_mina(juego.tablero.datos[fila][columna]);
		int direcciones[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
		for (int i = 0; i < 8; i++) {
			int nFila = fila + 1 * direcciones[i][0];
			int nCol = columna + 1 * direcciones[i][1];
			if (esta_vacia(juego, nFila, nCol)) {
				poner_numero(juego.tablero.datos[nFila][nCol], 1);
			}
			else if (contiene_numero(juego, nFila, nCol)) {
				int num = dame_numero(juego, nFila, nCol);
				poner_numero(juego.tablero.datos[nFila][nCol], num + 1);
			}
		}
	}
}

void marcar_desmarcar(tJuego& juego, int fila, int columna) {
	if (es_valida(juego.tablero, fila, columna)) { // Mira si es v�lida
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
void descubrir_celdas(tJuego& juego, int fila, int columna) {
	int direcciones[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
	for (int i = 0; i < 8; i++) {
		int nFila = fila + 1 * direcciones[i][0];
		int nCol = columna + 1 * direcciones[i][1];
		tCelda& celda = juego.tablero.datos[nFila][nCol];
		if (!esta_marcada(juego, nFila, nCol)) {
			descubrir_celda(celda);
		}
	}
}
void juega(tJuego& juego, int fila, int columna, tListaPosiciones& lista_pos) {
		if (es_valida(juego.tablero, fila, columna) && !es_visible(juego, fila, columna) && !esta_marcada(juego, fila, columna)) {
			descubrir_celda(juego.tablero.datos[fila][columna]);
			if (contiene_mina(juego, fila, columna)) {
				explotar_mina(juego, fila, columna);
			}
			else if (dame_numero(juego, fila, columna) == 0) {
				descubrir_celdas(juego, fila, columna);
			}
			juego.num_jugadas++;
		}


}
