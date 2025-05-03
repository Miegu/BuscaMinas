#include "listaUndo.h"
#include <iostream>

void inicializar_listaUndo(tListaUndo& lista_undo) {
	lista_undo.cont = 0; // Establece a 0 el cont.
	//No hace falta inicializar ya esta inicializada al ser un array dinamico
}

void insertar_final(tListaUndo& lista_undo, const tListaPosiciones lista_pos) {
	if (lista_undo.cont >= MAX_UNDO)
	{
		delete lista_undo.lista[0]; // Liberamos el primer elemento
		for (int i = 0; i < MAX_UNDO - 1; i++)
			lista_undo.lista[i] = lista_undo.lista[i + 1];
		lista_undo.cont--;
	}

	lista_undo.lista[lista_undo.cont] = new tListaPosiciones(lista_pos); //No debería de ser lista_undo.cont-1?
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
	return *(lista.lista[lista.cont - 1]);
}

//V2
void destruye(tListaUndo& listaUndo) {
	delete[] listaUndo.lista;
}

void eliminar_ultimo_elemento(tListaUndo& listaUndo) {
	delete listaUndo.lista[listaUndo.cont - 1];
}
