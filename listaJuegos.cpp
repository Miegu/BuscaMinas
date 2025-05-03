#include "listaJuegos.h"
#include <iostream>
using namespace std;

void inicializarListaJuegos(tListaJuegos& listaJuegos) {
	listaJuegos.cont = 0;
	listaJuegos.capacidad = MAX_JUEGOS; //Máximo de momento es 1.
	listaJuegos.lista = new tPtrJuego[listaJuegos.capacidad];
}

void destruye(tListaJuegos& listaJuegos) {
	delete[] listaJuegos.lista; //Elimina el puntero del array
}


int insertarJuego(tListaJuegos& listaJuegos, const tJuego juegoNuevo) {
	int posicion = -1;

	if (listaJuegos.cont >= listaJuegos.capacidad) {
		redimensionamiento_juegos(listaJuegos);
	}
	burbujaMejorada(listaJuegos);

	int nivelDificultad = calcula_nivel(juegoNuevo);
	int i = 0;
	while (i < listaJuegos.cont && calcula_nivel(*(listaJuegos.lista[i])) < nivelDificultad)
		i++;

	// Hacemos espacio para el nuevo juego
	for (int j = listaJuegos.cont; j > i; j--)
		listaJuegos.lista[j] = listaJuegos.lista[j - 1];

	// Insertamos el juego
	listaJuegos.lista[i] = new tJuego(juegoNuevo);
	listaJuegos.cont++;
	posicion = i;

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
	if (pos >= 0 && pos < listaJuegos.cont) {
		delete listaJuegos.lista[pos];
		for (int i = pos; i < listaJuegos.cont - 1; i++) {
			listaJuegos.lista[i] = listaJuegos.lista[i + 1];
		}
		listaJuegos.cont--;
	}
}

void redimensionamiento_juegos(tListaJuegos& listaJuegos) {
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
			if (calcula_nivel(*(listaJuegos.lista[j])) < calcula_nivel(*(listaJuegos.lista[j + 1]))) {
				tPtrJuego tmp = listaJuegos.lista[j];
				listaJuegos.lista[j] = listaJuegos.lista[j + 1];
				listaJuegos.lista[j + 1] = tmp;

				inter = true;
			}
		}
		i++;

	} while (inter);
}


int busquedaBinaria(const tListaJuegos listaJuegos, const tJuego buscado) {
	int inicio = 0;
	int fin = listaJuegos.cont - 1;
	int encontrado = -1;

	while (inicio <= fin) {
		int medio = inicio + (fin - inicio) / 2;

		if (calcula_nivel(*(listaJuegos.lista[medio])) == calcula_nivel(buscado)) {
			encontrado = medio;
		}

		if (calcula_nivel(*(listaJuegos.lista[medio])) < calcula_nivel(buscado)) {
			inicio = medio + 1;
		}
		else {
			fin = medio - 1;
		}
	}

	return encontrado;
}

int crearNuevoJuego(tListaJuegos& listaJuegos) {
	int fils, cols, minas;
	cout << "Numero de filas: ";
	cin >> fils;
	cout << "Numero de columnas: ";
	cin >> cols;
	cout << "Numero de minas: ";
	cin >> minas;

	tJuego nuevoJuego = crear_juego(fils, cols, minas);
	int pos = insertarJuego(listaJuegos, nuevoJuego);
	cout << "Juego creado en posicion " << pos << endl;
	return pos;
};