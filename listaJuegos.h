#ifndef LISTAJUEGOS_H
#define LISTAJUEGOS_H

#include "juego.h"

const int MAX_JUEGOS = 1;
typedef tJuego* tPtrJuego; //Puntero a un juego

typedef struct {
	tPtrJuego* lista;
	int cont;
	int capacidad;
} tListaJuegos;

void inicializarListaJuegos(tListaJuegos& listaJuegos);
void destruye(tListaJuegos& listaJuegos);
int insertarJuego(tListaJuegos& listaJuegos, const tJuego juegoNuevo);
int numero_juegos(const tListaJuegos listaJuegos);
bool es_vacia(const tListaJuegos listaJuegos);
tJuego dame_juegos(const tListaJuegos listaJuegos, const int pos);
void eliminar(tListaJuegos& listaJuegos, const int pos);
void redimensionamiento(tListaJuegos& listaJuegos);
void burbujaMejorada(tListaJuegos& listaJuegos);
int busquedaBinaria(const tListaJuegos listaJuegos, const tJuego buscado);

#endif // !LISTAJUEGOS_H

