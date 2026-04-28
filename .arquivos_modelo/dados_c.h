#ifndef DADOS_C_H
#define DADOS_C_H

#include <stdio.h>
#include <stdlib.h>

int extern id_global;

struct Tipo;

struct Tipo* tipo_criarTudo(int id, void* dados);
struct Tipo* tipo_criarZerado();

void tipo_inserirId(struct Tipo* tipo, int id);
void tipo_inserirDados(struct Tipo* tipo, void* dados);

int tipo_pegarId(struct Tipo* tipo);
void* tipo_pegarDados(struct Tipo* tipo);

void tipo_exibir(struct Tipo* tipo);
void tipo_gerarId(struct Tipo* tipo);
void tipo_deletar(struct Tipo** tipo);

#endif
