#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"
#include "listaPosiciones.h"
#include "listaUndo.h"

typedef enum {
	ACTIVO,
	PERDIDO,
	ABANDONADO,
	GANADO
} EstadoJuego;

typedef struct {
	tTablero tablero;
	int num_jugadas;
	bool mina_explotada;
	int num_minas;
	int num_descubiertas;
	EstadoJuego estado;
} tJuego;




void inicializar(tJuego& juego, int nfils, int ncols);
int dame_num_jugadas(const tJuego& juego);
int dame_num_filas(const tJuego& juego);
int dame_num_columnas(const tJuego& juego);
int dame_num_minas(const tJuego& juego);
bool contiene_mina(const tJuego& juego, int fila, int columna);
bool es_visible(const tJuego& juego, int fila, int columna);
bool esta_marcada(const tJuego& juego, int fila, int columna);
bool esta_vacia(const tJuego& juego, int fila, int columna);
bool contiene_numero(const tJuego& juego, int fila, int columna);
int dame_numero(const tJuego& juego, int fila, int columna);
bool esta_completo(const tJuego& juego);
bool mina_explotada(const tJuego& juego);
bool esta_terminado(const tJuego& juego);
void poner_mina_juego(tJuego& juego, int fila, int columna);
void marcar_desmarcar(tJuego& juego, int fila, int columna);
void ocultar(tJuego& juego, int fila, int columna);
void descubrir_celdas(tJuego& juego, int fila, int columna, tListaPosiciones& lista_pos);
void explotar_mina(tJuego& juego, int fila, int columna);
void ocultar_juego(tJuego& juego, int fila, int col);
void aplicar_undo(tJuego& juego, tListaUndo& listaUndo);
EstadoJuego procesarJugada(tJuego& juego, int fila, int col, tListaUndo& listaUndo);

//V2
int calcula_nivel(tJuego juego);
tJuego crear_juego(int num_fils, int num_cols, int num_minas);

#endif 