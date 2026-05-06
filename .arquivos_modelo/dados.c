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
	struct Tipo* novo_tipo = (struct Tipo*)malloc(1 * sizeof(struct Tipo));
	
	if (!novo_tipo){
		return NULL;
	}

	novo_tipo->id = id;
	novo_tipo->dados = dados;
	
	return novo_tipo;
}

struct Tipo* tipo_criarZerado()
{
	struct Tipo* novo_tipo = (struct Tipo*)malloc(1 * sizeof(struct Tipo));

	if (!novo_tipo)
		return NULL;

	return novo_tipo;
}

int tipo_inserirId(struct Tipo* tipo, int id)
{
	if (!tipo)
		return -1;

	tipo->id = id;

	return 0;
}

void tipo_inserirDados(struct Tipo* tipo, void* dados)
{
	if (!tipo)
		return -1;

	tipo->dados = dados;

	return 0;
}

int tipo_pegarId(struct Tipo* tipo)
{
	if (!tipo)
		return -1;

	return tipo->id;
}

void* tipo_pegarDados(struct Tipo* tipo)
{
	if (!tipo)
		return NULL;

	return tipo->dados;
}

void tipo_exibir(struct Tipo* tipo)
{
	if (!tipo){
		return;
		printf("Tipo nao Incializado\n");
	}

	printf("-ID: %d\n-Dados: %c\n", tipo->id, *(tipo->dados));

	return;
}

void tipo_gerarId(struct Tipo* tipo)
{
	static int id_global = 0;

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

