#include "listaPosiciones.h"
#include "memoryleaks.h"
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
	lista_pos.lista[lista_pos.cont] = new tPosicion(); //Inserta al final

	lista_pos.lista[lista_pos.cont]->posx = x;
	lista_pos.lista[lista_pos.cont]->posy = y;
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
	for (int i = 0; i < listaPosiciones.cont; i++) {
		delete listaPosiciones.lista[i]; // Libera cada objeto dinámico
	}
	delete[] listaPosiciones.lista; // Libera el array de punteros
	listaPosiciones.lista = nullptr; 
	listaPosiciones.cont = 0; // Reinicia el contador
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