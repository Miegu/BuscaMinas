#include "listaUndo.h"
#include <iostream>

void inicializar_listaUndo(tListaUndo& lista_undo) {
	lista_undo.cont = 0; // Establece a 0 el cont.
}

void insertar_final(tListaUndo& lista_undo, const tListaPosiciones& lista_pos) {
	// inserta lista_pos al final de lalista.Si no hay espacio desplaza todos los elementos hacia la izquierda, descartando el colocadoen la posición 0. Finalmente inserta en la última posición.
	if (lista_undo.cont < MAX_UNDO) {
		lista_undo.lista[lista_undo.cont] = lista_pos;
		lista_undo.cont++;
	}
	else { // Si es mayor, desplaza hacia la izquierda
		for (int i = 0; i < MAX_UNDO - 1; i++) {
			lista_undo.lista[i] = lista_undo.lista[i + 1];
		}
		lista_undo.lista[MAX_UNDO - 1] = lista_pos; // Finalmente la inserta en la última posición.
	}

}

tListaPosiciones ultimos_movimientos(const tListaUndo lista_undo) { // Devuelve la última lista
	if (lista_undo.cont > 0) {
		return lista_undo.lista[lista_undo.cont - 1];
	}
	else {
		// Return an empty tListaPosiciones if there are no movements
		tListaPosiciones empty;
		inicializar_listaPosiciones(empty);
		return empty;
	}
}