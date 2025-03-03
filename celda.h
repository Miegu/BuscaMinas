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
tEstado dame_estado(const tCelda& celda);
int celda_dame_numero(const tCelda& celda);
bool celda_es_visible(const tCelda& celda);
bool es_mina(const tCelda& celda);
bool celda_esta_vacia(const tCelda& celda);
bool celda_contiene_numero(const tCelda& celda);
bool celda_esta_marcada(const tCelda& celda);
void descubrir_celda(tCelda& celda);
void ocultar_celda(tCelda& celda);
void poner_mina(tCelda& celda);
void marcar_celda(tCelda& celda);
void desmarcar_celda(tCelda& celda);
void poner_numero(tCelda& celda, int num);
 
#endif 

