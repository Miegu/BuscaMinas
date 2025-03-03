#ifndef LISTAUNDO_H
#define LISTAUNDO_H
#include "listaPosiciones.h"

const int MAX_UNDO = 30;
typedef struct {
	tListaPosiciones lista[MAX_UNDO];
	int cont;
} tListaUndo;

void inicializar_listaUndo(tListaUndo& lista_undo);
void insertar_final(tListaUndo& lista_undo, const tListaPosiciones& lista_pos);
tListaPosiciones ultimos_movimientos(const tListaUndo lista_undo);


#endif 

