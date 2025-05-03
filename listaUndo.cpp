#include "listaUndo.h"
#include "memoryleaks.h"

#include <iostream>

void inicializar_listaUndo(tListaUndo& lista_undo) {
	lista_undo.cont = 0; // Establece a 0 el cont.
	//No hace falta inicializar ya esta inicializada al ser un array dinamico
}

 void insertar_final(tListaUndo& lista_undo, const tListaPosiciones lista_pos) {
       if (lista_undo.cont == MAX_UNDO) {
           destruye(*(lista_undo.lista[0])); // Elimina la primera lista
           delete lista_undo.lista[0];

           for (int i = 0; i < MAX_UNDO - 1; i++) {
               lista_undo.lista[i] = lista_undo.lista[i + 1];
           }
           lista_undo.cont--;
       }

       // Crea una copia lista_pos
       tListaPosiciones* nuevaLista = new tListaPosiciones;
       inicializar_listaPosiciones(*nuevaLista);
       for (int i = 0; i < lista_pos.cont; i++) {
           insertar_final(*nuevaLista, dame_posX(lista_pos, i), dame_posY(lista_pos, i));
       }

       lista_undo.lista[lista_undo.cont] = nuevaLista;
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
	listaUndo.cont = 0;
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

