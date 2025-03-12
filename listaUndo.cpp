#include "listaUndo.h"
#include <iostream>

void inicializar_listaUndo(tListaUndo& lista_undo) {
	lista_undo.cont = 0; // Establece a 0 el cont.
}

void insertar_final(tListaUndo& lista_undo, const tListaPosiciones& lista_pos) {
	if (lista_undo.cont == MAX_UNDO) {
		for (int i = 0; i < MAX_UNDO - 1; i++) {
			lista_undo.lista[i] = lista_undo.lista[i + 1];
			
		}
		lista_undo.cont--;
	}
		lista_undo.lista[lista_undo.cont] = lista_pos;
		lista_undo.cont++;
	}

void eliminar_ultimo(tListaUndo& lista) {
	if (lista.cont > 0) {
		lista.cont--;
	}
}
int longitud_listaUndo(const tListaUndo& listaUndo) {
	return listaUndo.cont;
}

tListaPosiciones ultimos_movimientos(const tListaUndo& lista) {
	return lista.lista[lista.cont - 1];
}

