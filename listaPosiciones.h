#ifndef LISTAPOSICIONES_H
#define LISTAPOSICIONES_H

const int MAX_LISTA = 30;

typedef struct {
	int posx;
	int posy;
} tPosicion;

typedef tPosicion* tPtrPosicion;

typedef struct {
	tPtrPosicion* lista;
	int cont;
	int capacidad;
}tListaPosiciones;


void inicializar_listaPosiciones(tListaPosiciones& lista_pos);
void insertar_final(tListaPosiciones& lista_pos, int x, int y);
int longitud(const tListaPosiciones& lista_pos);
int dame_posX(const tListaPosiciones& lista_pos, int i);
int dame_posY(const tListaPosiciones& lista_pos, int i);
void destruye(tListaPosiciones& listaPosiciones);
tPosicion damePosicion(const tListaPosiciones listaPosiciones, int pos);
void redimensionamiento(tListaPosiciones& listaPosiciones);

#endif
