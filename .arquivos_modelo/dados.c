#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

struct Tipo
{
	int id;
	void* dados;
};

struct Tipo* tipo_criarTudo(int id, void* dados)
{
	struct Tipo* novo_tipo = (struct Tipo*)malloc(1 * struct novo_tipo);

	if (!novo_tipo)
		return NULL;

	novo_tipo->id = id;
	novo_tipo->dados = dados;

	return novo_tipo;
}

struct Tipo* tipo_criarZerado()
{
	struct Tipo* novo_tipo = (struct Tipo*)malloc(1 * struct novo_tipo);

	if (!novo_tipo)
		return NULL;

	return novo_tipo;
}

void tipo_inserirId(struct Tipo* tipo, int id)
{
	tipo->id = id;

	return;
}

void tipo_inserirDados(struct Tipo* tipo, void* dados)
{
	tipo->dados = dados;

	return;
}

int tipo_pegarId(struct Tipo* tipo)
{
	return tipo->id;
}

void* tipo_pegarDados(struct Tipo* tipo)
{
	return tipo->dados;
}

void tipo_exibir(struct Tipo* tipo)
{
	printf("-ID: %d\n-Dados: %c\n", tipo->id, *(tipo->dados));

	return;
}

void tipo_gerarId(struct Tipo* tipo)
{
	if (!tipo)
		return;

	tipo->id = id_global;
	id_global++;

	return;
}

void tipo_deletar(struct Tipo** tipo)
{
	if (!(*tipo))
		return;

	free(*tipo);
	*tipo = NULL;

	return;
}

