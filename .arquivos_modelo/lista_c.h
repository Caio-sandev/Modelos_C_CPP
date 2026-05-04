#ifndef LISTA_C_H
#define LISTA_C_H

#include <stdlib.h>
#include "dados_c.h"

struct lista_tipo_t;
int lista_naoInicializada(struct lista_tipo_t* lista_tipo);
struct lista_tipo_t* lista_anexarPorUltimo(struct lista_tipo_t* lista_tipo, struct Tipo* tipo);
struct lista_tipo_t* lista_anexarEmPrimeiro(struct lista_tipo_t* lista_tipo, struct Tipo* tipo);
void lista_deletarPorUltimo(struct lista_tipo_t** lista_tipo);
void lista_deletarEmPrimeiro(struct lista_tipo_t** lista_tipo);
void lista_exibir(struct lista_tipo_t* lista_tipo);
struct Tipo* lista_procurar(struct lista_tipo_t* lista_tipo, int id);

#endif
