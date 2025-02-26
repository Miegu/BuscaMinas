#ifndef CELDA_H
#define CELDA_H
#include <string>

typedef enum { NUMERO, VACIA, MINA } tEstado;

typedef struct {
	bool visible;
	tEstado estado;
	int numero;
	bool marcada;
} tCelda;
void inicializarCelda(tCelda& celda);
int dame_estado(const tCelda& celda);
int dame_numero(tCelda celda);
bool es_visible(tCelda celda);
bool es_mina(const tCelda& celda);
bool esta_vacia(tCelda celda);
bool contiene_numero(tCelda celda);
bool esta_marcada(tCelda celda);
void descubrir_celda(tCelda celda);
void ocultar_celda(tCelda celda);
void poner_mina(tCelda celda);
void marcar_celda(tCelda celda);
void desmarcar_celda(tCelda celda);
void poner_numero(tCelda celda, int num);


#endif