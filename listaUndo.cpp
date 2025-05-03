#include "listaUndo.h"
#include "memoryleaks.h"

#include <iostream>

void inicializar_listaUndo(tListaUndo& lista_undo) {
	lista_undo.cont = 0; // Establece a 0 el cont.
	//No hace falta inicializar ya esta inicializada al ser un array dinamico
}

void insertar_final(tListaUndo& lista_undo, const tListaPosiciones lista_pos) {
	if (lista_undo.cont == MAX_UNDO)
	{
		destruye(*(lista_undo.lista[0])); //Eliminamos la primera lista

		for (int i = 0; i < MAX_UNDO - 1; i++) {
			lista_undo.lista[i] = lista_undo.lista[i + 1];
		}
		lista_undo.cont--;
	}

	lista_undo.lista[lista_undo.cont] = new tListaPosiciones(lista_pos); 
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

tListaPosiciones ultimos_movimientos(const tListaUndo& lista) { //última lista de posiciones
	return *(lista.lista[lista.cont - 1]);
}

//V2
void destruye(tListaUndo& listaUndo) {
	for (int i = 0; i < listaUndo.cont; i++) {
		destruye(*(listaUndo.lista[i]));
		delete listaUndo.lista[i];
	}
}

void eliminar_ultimo_elemento(tListaUndo& listaUndo) {

	if (listaUndo.cont > 0) { 
		int ultimoIndice = listaUndo.cont - 1; 
		if (listaUndo.lista[ultimoIndice] != nullptr) {
			destruye(*(listaUndo.lista[ultimoIndice])); // Libera la memoria del contenido
			delete listaUndo.lista[ultimoIndice]; // Libera el puntero
			listaUndo.lista[ultimoIndice] = nullptr;
		}
		listaUndo.cont--;
	}
}

