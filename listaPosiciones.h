#ifndef LISTAPOSICIONES_H
#define LISTAPOSICIONES_H

const int MAX_LISTA = 30;
typedef struct {
	int posx;
	int posy;
} tPosicion;
typedef struct {
	tPosicion lista[MAX_LISTA];
	int cont;
} tListaPosiciones;

void inicializar_listaPosiciones (tListaPosiciones lista_pos);
void insertar_final(tListaPosiciones lista_pos, int x, int y);
int longitud(tListaPosiciones lista_pos);
int dame_posX(tListaPosiciones lista_pos, int i);
int dame_posY(tListaPosiciones lista_pos, int i);


#endif
