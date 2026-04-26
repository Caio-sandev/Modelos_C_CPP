#ifndef LISTA_C_H
#define LISTA_C_H

#include <stdlib.h>
#include "dados_c.h"

struct lista_tipo_t;
struct lista_tipo_t* lista_anexarUltimo(struct lista_tipo_t* lista_tipo, struct Tipo* tipo);
struct lista_tipo_t* lista_anexarPrimeiro(struct lista_tipo_t* lista_tipo, struct Tipo* tipo);;
void lista_deletarUltimo(struct lista_tipo_t** lista_tipo);
void lista_deletarPrimeiro(struct lista_tipo_t** lista_tipo);
void lista_exibir(struct lista_tipo_t* lista_tipo);
struct Tipo lista_procurar(struct lista_tipo_t* lista_tipo, int id);

#endif
