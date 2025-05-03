#include "listaPosiciones.h"
#include <iostream>

void inicializar_listaPosiciones(tListaPosiciones& lista_pos) {
	lista_pos.cont = 0;
	lista_pos.capacidad = MAX_LISTA; //Máximo lista de momento
	lista_pos.lista = new tPtrPosicion[MAX_LISTA]; //Asigna puntero de tamaño 30
}

void insertar_final(tListaPosiciones& lista_pos, int x, int y) { // Inserta al final de la lista
	if (lista_pos.cont == lista_pos.capacidad) {
		redimensionamiento_posiciones(lista_pos); //Redimensiona si no hay capacidad
	}

	//Define una posicion nueva
	tPosicion posicion;
	posicion.posx = x;
	posicion.posy = y;

	lista_pos.lista[lista_pos.cont - 1] = new tPosicion(posicion); //Inserta al final
	lista_pos.cont++;
}

int longitud(const tListaPosiciones& lista_pos) {
	return lista_pos.cont;
}

int dame_posX(const tListaPosiciones& lista_pos, int i) { // Elemento en posicion X.
	int posx;
	tPosicion actual = damePosicion(lista_pos, i);
	if (i >= 0 && i < lista_pos.cont) {
		posx = actual.posx; //Maybe crear una funcion que te de una posicion en una posicion exacta?
	}
	else posx = -1;
	return posx;
}

int dame_posY(const tListaPosiciones& lista_pos, int i) { // Elemento en posicion Y.
	int posy;
	tPosicion actual = damePosicion(lista_pos, i);
	if (i >= 0 && i < lista_pos.cont) {
		posy = actual.posy;
	}
	else posy = -1;
	return posy;
}

//VERSIÓN 2
void destruye(tListaPosiciones& listaPosiciones) {
	delete[] listaPosiciones.lista;
}

tPosicion damePosicion(const tListaPosiciones listaPosiciones, int pos) {
	return *(listaPosiciones.lista[pos]);
}


void redimensionamiento_posiciones(tListaPosiciones& listaPosiciones) {
	tPtrPosicion* listaAmpliada = new tPtrPosicion[MAX_LISTA * 2];
	for (int i = 0; i < listaPosiciones.cont; i++)
		listaAmpliada[i] = listaPosiciones.lista[i];
	delete[] listaPosiciones.lista; // Corregido
	listaPosiciones.lista = listaAmpliada;
	listaPosiciones.capacidad *= 2;
}

}