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

	if (listaJuegos.cont == listaJuegos.capacidad) {
		redimensionamiento(listaJuegos);
	}

	listaJuegos.lista[listaJuegos.cont - 1] = new tJuego(juegoNuevo); //Lo inserta al final

	burbujaMejorada(listaJuegos); //Ordena la lista

	posicion = busquedaBinaria(listaJuegos, juegoNuevo);

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

	do {
		inter = false;

		for (int j = 0; j < listaJuegos.cont - i - 1; j++) {
			if (calcula_nivel(*(listaJuegos.lista[j])) > calcula_nivel(*(listaJuegos.lista[j + 1]))) {
				tPtrJuego tmp = listaJuegos.lista[j];
				listaJuegos.lista[j] = listaJuegos.lista[j + 1];
				listaJuegos.lista[j + 1] = tmp;

				inter = true;
			}
		}
		i++;

	}while(inter);
}

int busquedaBinaria(const tListaJuegos listaJuegos, const tJuego buscado) {
	int inicio = 0;
	int fin = listaJuegos.cont - 1;

	while (inicio <= fin) {
		int medio = inicio + (fin - inicio) / 2;

		if (calcula_nivel(*(listaJuegos.lista[medio])) == calcula_nivel(buscado)) {
			return medio;
		}

		if (calcula_nivel(*(listaJuegos.lista[medio])) < calcula_nivel(buscado)) {
			inicio = medio + 1;
		}
		else {
			fin = medio - 1;
		}
	}

}