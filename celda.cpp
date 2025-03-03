#include "celda.h"
//hola
#include <iostream>

void inicializarCelda(tCelda& celda) {
    celda.visible = false;
    celda.estado = VACIA;
    celda.numero = 0;
    celda.marcada = false;
}

tEstado dame_estado(const tCelda& celda){
    return celda.estado;
}
int celda_dame_numero(const tCelda& celda) {
    return celda.numero;
}
bool es_visible(const tCelda& celda) {
    return celda.visible;
}
bool es_mina(const tCelda& celda) {
    return  dame_estado(celda) == MINA;
}
bool celda_esta_vacia(const tCelda& celda) {
    return dame_estado(celda) == VACIA;
}
bool celda_contiene_numero(const tCelda& celda) {
    return dame_estado(celda) == NUMERO;
}
bool esta_marcada(const tCelda& celda) {
    return celda.marcada;
}
void descubrir_celda(tCelda& celda) {
    celda.visible = true;
}
void ocultar_celda(tCelda& celda) {
    celda.visible = false;
}
void poner_mina(tCelda& celda) {
    celda.estado = MINA;
}
void marcar_celda(tCelda& celda) {
    celda.marcada = true;
}
void desmarcar_celda(tCelda& celda) {
    celda.marcada = false;
}
void poner_numero(tCelda& celda, int num) {
    celda.estado = NUMERO;
    celda.numero = num;
}
