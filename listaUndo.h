#ifndef LISTAUNDO_H
#define LISTAUNDO_H
#include "listaPosiciones.h"


const int MAX_UNDO = 2;

typedef struct {
	tListaPosiciones* lista[MAX_UNDO]; //Puntero a un array de tListaPosiciones y ESTATICO
	int cont;
} tListaUndo;

void inicializar_listaUndo(tListaUndo& lista_undo);
int longitud_listaUndo(const tListaUndo& listaUndo);
void insertar_final(tListaUndo& lista_undo, const tListaPosiciones lista_pos);
void eliminar_ultimo(tListaUndo& lista);
tListaPosiciones ultimos_movimientos(const tListaUndo& lista_undo);

//V2
void destruye(tListaUndo& listaUndo);
void eliminar_ultimo_elemento(tListaUndo& listaUndo);

#endif 

