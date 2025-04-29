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
			juego.estado = PERDIDO;
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
	int direcciones[8][2] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };

	for (int i = 0; i < 8; i++) {
		int nFila = fila + direcciones[i][0];
		int nCol = columna + direcciones[i][1];

		if (es_valida(juego.tablero, nFila, nCol) &&
			!es_visible(juego, nFila, nCol) &&
			!esta_marcada(juego, nFila, nCol)) {

			tCelda celda = dame_celda(juego.tablero, nFila, nCol);
			descubrir_celda(celda);

			poner_celda(juego.tablero, nFila, nCol, celda);

			insertar_final(lista_pos, nFila, nCol);
			juego.num_descubiertas++;
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

		for (int i = 0; i < longitud(ultimoMov); i++) {
			int fila = dame_posX(ultimoMov, i);
			int col = dame_posY(ultimoMov, i);

			if (es_valida(juego.tablero, fila, col)) {
				tCelda celda = dame_celda(juego.tablero, fila, col);

				ocultar_celda(celda);

				poner_celda(juego.tablero, fila, col, celda);
				juego.num_descubiertas--;
			}
		}

		eliminar_ultimo(listaUndo);
	}
}

EstadoJuego estadoJuego(tJuego& juego, int fila, int col, tListaUndo& listaUndo) {
	EstadoJuego estado = ACTIVO;

	if (fila == -1 && col == -1) {
		estado = ABANDONADO;
		cout << "Partida abandonada\n";
	}
	else if (fila == -2 && col == -2) {
		int x, y;
		cout << endl;
		cout << "\nIntroduce una fila a marcar: ";
		cin >> x;
		cout << "\nIntroduce una columna a marcar: ";
		cin >> y;

		if (es_valida(juego.tablero, x, y)) {
			marcar_desmarcar(juego, x, y);
		}
		else {
			cout << "Coordenadas invalidas \n";
		}
	}
	else if (fila == -3 && col == -3) {
		if (longitud_listaUndo(listaUndo) > 0) {
			aplicar_undo(juego, listaUndo);
		}
	}
	else {
		jugar(juego, fila, col, listaUndo);
		if (mina_explotada(juego)) {
			estado = PERDIDO;
		}
	}

	juego.estado = estado;
	return estado;


}


void jugar(tJuego& juego, int fila, int col, tListaUndo& listaUndo) {
	tListaPosiciones listaPos;
	inicializar_listaPosiciones(listaPos);

	if (es_valida(juego.tablero, fila, col) &&
		!es_visible(juego, fila, col) &&
		!esta_marcada(juego, fila, col)) {

		tCelda celda = dame_celda(juego.tablero, fila, col);
		descubrir_celda(celda);
		poner_celda(juego.tablero, fila, col, celda);

		insertar_final(listaPos, fila, col);
		juego.num_descubiertas++;
		juego.num_jugadas++;

		if (contiene_mina(juego, fila, col)) {
			explotar_mina(juego, fila, col);
			juego.estado = PERDIDO;
		}
		else if (esta_vacia(juego, fila, col)) {
			descubrir_celdas(juego, fila, col, listaPos);
		}
		insertar_final(listaUndo, listaPos);
	}

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


