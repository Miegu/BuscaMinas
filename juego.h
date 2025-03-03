#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"
#include "listaUndo.h"
#include "listaPosiciones.h"

typedef struct {
	tTablero tablero;
	int num_jugadas;
	bool mina_explotada;
	int num_minas;
	int num_descubiertas;
} tJuego;

inicializar(juego, nfils, ncols);
dame_num_jugadas(juego);
dame_num_filas(juego);
dame_num_columnas(juego);
dame_num_minas(juego);
contiene_mina(juego, fila, columna);
es_visible(juego, fila, columna);
esta_marcada(juego, fila, columna);
esta_vacia(juego, fila, columna);
contiene_numero(juego, fila, columna);
dame_numero(juego, fila, columna);
esta_completo(juego);
mina_explotada(juego);
esta_terminado(juego);
poner_mina(juego, fila, columna);
marcar_desmarcar(juego, fila, columna);
ocultar(juego, fila, columna);
juega(juego, fila, columna, lista_pos);

#endif 