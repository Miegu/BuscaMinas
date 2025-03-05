#include "listaPosiciones.h"
#include <iostream>

void inicializar_listaPosiciones(tListaPosiciones& lista_pos) {
	lista_pos.cont = 0;
}

void insertar_final(tListaPosiciones& lista_pos, int x, int y) { // Inserta al final de la lista
	if (lista_pos.cont < MAX_LISTA) { // Solo si esta dentro del rango.
		lista_pos.lista[lista_pos.cont].posx = x;
		lista_pos.lista[lista_pos.cont].posy = y;
		lista_pos.cont++;
	}
}

int longitud(const tListaPosiciones& lista_pos) {
	return lista_pos.cont;
}

int dame_posX(const tListaPosiciones& lista_pos, int i) { // Elemento en posicion X.
	int posx;
	if (i >= 0 && i < lista_pos.cont) {
		posx = lista_pos.lista[i].posx;
	}
	else posx = -1;
	return posx;
}

int dame_posY(const tListaPosiciones& lista_pos, int i) { // Elemento en posicion Y.
	int posy;
	if (i >= 0 && i < lista_pos.cont) {
		posy = lista_pos.lista[i].posy;
	}
	else posy = -1;
	return posy;
}