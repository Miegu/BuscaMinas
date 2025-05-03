#include "juego.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void inicializar(tJuego& juego, int nfils, int ncols) {
	juego.mina_explotada = false;
	juego.num_descubiertas = 0;
	juego.num_jugadas = 0;
	juego.num_minas = 0;
	juego.tablero.nFils = nfils;
	juego.tablero.nCols = ncols;
	juego.estado = ACTIVO;
	inicializar_tablero(juego.tablero, nfils, ncols); // Inicializa el tablero
}


int dame_num_jugadas(const tJuego& juego) {
	return juego.num_jugadas;
}

int dame_num_filas(const tJuego& juego) {
	return num_filas(juego.tablero);
}

int dame_num_columnas(const tJuego& juego) {
	return num_columnas(juego.tablero);
}

int dame_num_minas(const tJuego& juego) {
	return juego.num_minas;
}

bool contiene_mina(const tJuego& juego, int fila, int columna) {
	bool contiene = false;
	if (es_valida(juego.tablero, fila, columna)) {
		tCelda celda = dame_celda(juego.tablero, fila, columna);
		if (es_mina(celda)) {
			contiene = true;
		}
	}
	return contiene;
}

bool es_visible(const tJuego& juego, int fila, int columna) {
	bool visible = false;
	if (es_valida(juego.tablero, fila, columna)) {
		tCelda celda = dame_celda(juego.tablero, fila, columna);
		if (celda_es_visible(celda)) {
			visible = true;
		}
	}
	return visible;
}

bool esta_marcada(const tJuego& juego, int fila, int columna) {
	bool marcada = false;
	if (es_valida(juego.tablero, fila, columna)) {
		tCelda celda = dame_celda(juego.tablero, fila, columna);
		if (celda_esta_marcada(celda)) {
			marcada = true;
		}
	}
	return marcada;
}

bool esta_vacia(const tJuego& juego, int fila, int columna) {
	bool vacia = false;
	if (es_valida(juego.tablero, fila, columna)) {
		tCelda celda = dame_celda(juego.tablero, fila, columna);
		if (celda_esta_vacia(celda)) {
			vacia = true;
		}
	}
	return vacia;
}

bool contiene_numero(const tJuego& juego, int fila, int columna) {
	bool contiene = false;
	if (es_valida(juego.tablero, fila, columna)) {
		tCelda celda = dame_celda(juego.tablero, fila, columna);
		if (celda_contiene_numero(celda)) {
			contiene = true;
		}
	}
	return contiene;

}

int dame_numero(const tJuego& juego, int fila, int columna) {
	int numero = 0;
	if (es_valida(juego.tablero, fila, columna)) { // True si es válida
		if (contiene_numero(juego, fila, columna)) { // True si contiene un nº
			tCelda celda = dame_celda(juego.tablero, fila, columna);
			numero = celda_dame_numero(celda); // Retorna el valor del nº
		}
	}
	return numero;
}

bool esta_completo(const tJuego& juego) {
	bool completo = true;
	for (int i = 0; i < juego.tablero.nFils; i++) {
		for (int j = 0; j < juego.tablero.nCols; j++) {

			tCelda celda = dame_celda(juego.tablero, i, j);

			if (!(es_mina(celda))) { // si NO es una mina.
				if (!celda_es_visible(celda)) {
					completo = false; // Si hay una celda sin descubrir, no esta completo.
				}
			}
		}
	}
	return completo;
}
void explotar_mina(tJuego& juego, int fila, int columna) {
	if (es_valida(juego.tablero, fila, columna)) {
		tCelda celda = dame_celda(juego.tablero, fila, columna);
		if (es_mina(celda) && es_visible(juego, fila, columna)) {
			juego.mina_explotada = true;
		}
	}
}

bool mina_explotada(const tJuego& juego) {
	return juego.mina_explotada;
}

bool esta_terminado(const tJuego& juego) {
	return (mina_explotada(juego) || esta_completo(juego));
}

void poner_mina_juego(tJuego& juego, int fila, int columna) {
	if (es_valida(juego.tablero, fila, columna)) {
		tCelda celda = dame_celda(juego.tablero, fila, columna);
		if (!es_mina(celda)) {
			poner_mina(celda);
			poner_celda(juego.tablero, fila, columna, celda);
			juego.num_minas++;

			int direcciones[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

			for (int i = 0; i < 8; i++) {
				int nFila = fila + direcciones[i][0];
				int nCol = columna + direcciones[i][1];
				if (es_valida(juego.tablero, nFila, nCol)) {
					tCelda nCelda = dame_celda(juego.tablero, nFila, nCol);
					int num = dame_numero(juego, nFila, nCol);
					poner_numero(nCelda, num + 1);
					poner_celda(juego.tablero, nFila, nCol, nCelda);
				}
			}
		}
	}
}

void marcar_desmarcar(tJuego& juego, int fila, int columna) {
	if (es_valida(juego.tablero, fila, columna) && !es_visible(juego, fila, columna)) {
		tCelda celda = dame_celda(juego.tablero, fila, columna);
		if (celda_esta_marcada(celda)) {
			desmarcar_celda(celda);
		}
		else {
			marcar_celda(celda);
		}
		poner_celda(juego.tablero, fila, columna, celda);
	}
}


void ocultar(tJuego& juego, int fila, int columna) {
	tCelda celda = dame_celda(juego.tablero, fila, columna);
	if (es_valida(juego.tablero, fila, columna)) {
		if (celda_es_visible(celda)) {
			ocultar_celda(celda); // Oculta la celda, si es visible.
			poner_celda(juego.tablero, fila, columna, celda);
		}
	}
}


void descubrir_celdas(tJuego& juego, int fila, int columna, tListaPosiciones& lista_pos) {
	if (es_valida(juego.tablero, fila, columna) &&
		!es_visible(juego, fila, columna) &&
		!esta_marcada(juego, fila, columna)) {

		tCelda celda = dame_celda(juego.tablero, fila, columna);
		descubrir_celda(celda);
		poner_celda(juego.tablero, fila, columna, celda);
		insertar_final(lista_pos, fila, columna); //Añade a la lista dinamica de posiciones
		juego.num_descubiertas++;
		if (contiene_mina(juego, fila, columna)) {
			juego.mina_explotada = true;
		}
		else if (esta_vacia(juego, fila, columna)) {
			int direcciones[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

			for (int i = 0; i < 8; i++) {
				int nFila = fila + direcciones[i][0];
				int nCol = columna + direcciones[i][1];
				descubrir_celdas(juego, nFila, nCol, lista_pos);
			}
		}
	}
}


void ocultar_juego(tJuego& juego, int fila, int col) {
	if (es_valida(juego.tablero, fila, col)) {
		tCelda celda = dame_celda(juego.tablero, fila, col);
		ocultar_celda(celda);  // Del módulo celda
		poner_celda(juego.tablero, fila, col, celda);
		juego.num_descubiertas--;
	}
}

void aplicar_undo(tJuego& juego, tListaUndo& listaUndo) {
	if (longitud_listaUndo(listaUndo) > 0) {
		tListaPosiciones ultimoMov = ultimos_movimientos(listaUndo);

		for (int i = 0; i < longitud(ultimoMov); i++) { //Las vuelve a ocultar
			int fila = dame_posX(ultimoMov, i);
			int col = dame_posY(ultimoMov, i);

			if (es_valida(juego.tablero, fila, col)) {
				tCelda celda = dame_celda(juego.tablero, fila, col);

				ocultar_celda(celda);

				poner_celda(juego.tablero, fila, col, celda);
				juego.num_descubiertas--;
			}

		}

		eliminar_ultimo_elemento(listaUndo); //Elimina la última lista de undo.
		eliminar_ultimo(listaUndo); //Reduce el contador
	}
}


EstadoJuego procesarJugada(tJuego& juego, int fila, int col, tListaUndo& listaUndo) {
	juego.estado = ACTIVO;

	if (fila == -1 && col == -1) {
		cout << "Partida Abandonada";
		juego.estado = ABANDONADO;
	}
	else if (fila == -2 && col == -2) {
		int x, y;
		cout << endl;
		cout << "una fila a marcar";
		cin >> x;
		cout << "una columna a marcar";
		cin >> y;
	}
	else if (fila == -3 && col == -3) {
		if (longitud_listaUndo(listaUndo) > 0) {
			aplicar_undo(juego, listaUndo);
			juego.num_jugadas--;
		}
	}
	else {
		tListaPosiciones listaPos;
		inicializar_listaPosiciones(listaPos); //Inicializa lista posiciones

		if (es_valida(juego.tablero, fila, col) &&
			!es_visible(juego, fila, col) &&
			!esta_marcada(juego, fila, col)) {

			descubrir_celdas(juego, fila, col, listaPos); //Descubre las celdas

			insertar_final(listaUndo, listaPos); //Inserta la lista en la lista final de undo.
			destruye(listaPos);

			if (contiene_mina(juego, fila, col)) {
				juego.estado = PERDIDO;
			}
			else if (esta_completo(juego)) {
				juego.estado = GANADO;
			}

			juego.num_jugadas++;
		}
		
	}
	return  juego.estado;
}



//V2

int calcula_nivel(tJuego juego) {
	int filas = dame_num_filas(juego);
	int columnas = dame_num_columnas(juego);
	int numMinas = dame_num_minas(juego);

	return (filas * columnas) / numMinas;
}

tJuego crear_juego(int num_fils, int num_cols, int num_minas) {
	tJuego juegoNuevo;
	srand(time(NULL));
	inicializar(juegoNuevo, num_fils, num_cols);

	for (int i = 0; i < num_minas; i++) {
		int fila_random = rand() % num_fils;
		int columna_random = rand() % num_cols;
		poner_mina_juego(juegoNuevo, fila_random, columna_random); //La coloca
	}

	return juegoNuevo;

}


