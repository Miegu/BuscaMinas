#include "listaPosiciones.h"
#include <iostream>

void inicializar_listaPosiciones(tListaPosiciones& lista_pos) {
	lista_pos.cont = 0;
	for (int i = 0; i < MAX_LISTA; i++) { // Itera la lista
		lista_pos.lista[i].posx = 0;
		lista_pos.lista[i].posy = 0; // Inicializamos todo a 0.
	}
}

void insertar_final(tListaPosiciones& lista_pos, int x, int y) { // Inserta al final de la lista
	if (lista_pos.cont < MAX_LISTA) { // Solo si esta dentro del rango.
		lista_pos.lista[lista_pos.cont].posx = x;
		lista_pos.lista[lista_pos.cont].posy = y;
		lista_pos.cont++;
	}
}

int longitud(tListaPosiciones lista_pos) {
	return lista_pos.cont;
}

int dame_posX(tListaPosiciones lista_pos, int i) { // Elemento en posicion X.
	return lista_pos.lista[i].posx;
}

int dame_posY(tListaPosiciones lista_pos, int i) { // Elemento en posicion Y.
	return lista_pos.lista[i].posy;
}