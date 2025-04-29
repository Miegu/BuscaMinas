#include "listaJuegos.h"
#include <iostream>

void inicializarListaJuegos(tListaJuegos& listaJuegos) {
	listaJuegos.cont = 0;
	listaJuegos.capacidad = MAX_JUEGOS; //Máximo de momento es 1.
	listaJuegos.lista = new tPtrJuego[listaJuegos.capacidad];
}

void destruye(tListaJuegos& listaJuegos) {
	delete[] listaJuegos.lista; //Elimina el puntero del array
}

int insertarJuego(tListaJuegos& listaJuegos, const tJuego juegoNuevo) { //Incluir REDIMENSIONAMIENTO, BUSQUEDA BINARIA Y ALGORITMO DE ORDENACION
	int posicion = 0;

	if (listaJuegos.cont == 0) { //Si NO hay ningun juego metido
		listaJuegos.lista[0] = new tJuego(juegoNuevo);
		listaJuegos.cont++;
	}
	else {
		if (listaJuegos.cont == listaJuegos.capacidad) { //Si no hay suficiente capacidad redimensiona.
			redimensionamiento(listaJuegos);
		}

		listaJuegos.lista[listaJuegos.cont] = new tJuego(juegoNuevo); //Lo inserta al final.
		listaJuegos.cont++;

		burbujaMejorada(listaJuegos); //La ordena

		posicion = busquedaBinaria(listaJuegos,juegoNuevo);
	}

	return posicion;

}

int numero_juegos(const tListaJuegos listaJuegos) {
	return listaJuegos.cont; //Retorna el nº de juegos del contador
}

bool es_vacia(const tListaJuegos listaJuegos) {
	bool vacia = false;
	if (listaJuegos.cont == 0) {
		vacia = true;
	}
	return vacia;

}

tJuego dame_juegos(const tListaJuegos listaJuegos, const int pos) { //Retorna el juego
	tJuego juego = *(listaJuegos.lista[pos]);
	return juego;
}

void eliminar(tListaJuegos& listaJuegos, const int pos) {
	delete listaJuegos.lista[pos - 1]; //Elimina el puntero, no el objeto!
}


void redimensionamiento(tListaJuegos& listaJuegos) {
	tPtrJuego* juegoAmpliado = new tPtrJuego[listaJuegos.capacidad * 2]; //Duplicamos la capacidad.

	for (int i = 0; i < listaJuegos.cont; i++) { //Copia los punteros de la anterior lista
		juegoAmpliado[i] = listaJuegos.lista[i];
	}

	delete[] listaJuegos.lista; //Eliminamos el array anterior

	listaJuegos.lista = juegoAmpliado; //Ponemos el nuevo puntero
	listaJuegos.capacidad *= 2;
}

void burbujaMejorada(tListaJuegos& listaJuegos) { //Ordenar por complejidad.
	bool inter = true;
	int i = 0;
	while ((i < listaJuegos.cont - 1) && inter) {
		inter = false;

		for (int j = listaJuegos.cont - 1; j > i; j--) { //Desde el siguiente a la i hasta el último.
			if (calcula_nivel(*(listaJuegos.lista[j])) < calcula_nivel(*(listaJuegos.lista[j-1]))) {
				tPtrJuego tmp = listaJuegos.lista[j]; //Intercambiamos punteros.
				listaJuegos.lista[j] = listaJuegos.lista[j - 1];
				listaJuegos.lista[j - 1] = tmp;
				inter = true;
			}
		}
		if (inter) {
			i++;
		}
	}
}

int busquedaBinaria(const tListaJuegos listaJuegos, const tJuego buscado) {
	int inicio = 0, fin = listaJuegos.cont - 1, medio;
	int encontrado = -1;

	while (inicio <= fin) {
		medio = (inicio + fin) / 2;

		if (calcula_nivel(*(listaJuegos.lista[medio])) == calcula_nivel(buscado)) {
			encontrado = medio; // Encontrado
		}
		else if (calcula_nivel(*(listaJuegos.lista[medio])) < calcula_nivel(buscado)) {
			inicio = medio + 1; // Buscar en la mitad derecha
		}
		else {
			fin = medio - 1; // Buscar en la mitad izquierda
		}
	}
	return encontrado;
}