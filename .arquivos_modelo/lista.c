#include <stdlib.h>
#include "dados_c.h" 
#include "lista.h"

struct lista_tipo_t
{
	struct Tipo* tipo;
	struct lista_tipo_t* proximo;
};

struct lista_tipo_t* lista_anexarUltimo(struct lista_tipo_t* lista_tipo, struct Tipo* tipo)
{
	struct lista_tipo_t* tmp_lista_tipo;
	struct lista_tipo_t* novo_no = (struct lista_tipo_t*)malloc(1 * sizeof(struct lista_tipo_t));

	if (!novo_no)
		return NULL;

	novo_no->tipo = tipo;
	novo_no->proximo = NULL;

	if (!lista_tipo)
		return novo_no;

	for (tmp_lista_tipo = lista_tipo; tmp_lista_tipo->proximo; tmp_lista_tipo = tmp_lista_tipo->proximo);
	tmp_lista_tipo->proximo = novo_no;

	return lista_tipo;
}

struct lista_tipo_t* lista_anexarPrimeiro(struct lista_tipo_t* lista_tipo, struct Tipo* tipo)
{
	struct lista_tipo_t* novo_no = (struct lista_tipo_t*)malloc(1 * sizeof(struct lista_tipo_t));

	if (!novo_no)
		return NULL;

	novo_no->tipo = tipo;
	novo_no->proximo = lista_tipo;

	return novo_no;
}

void lista_deletarUltimo(struct lista_tipo_t** lista_tipo)
{
	struct lista_tipo_t* tmp_lista_tipo; 

	for (tmp_lista_tipo = *lista_tipo; tmp_lista_tipo->proximo; tmp_lista_tipo = tmp_lista_tipo = tmp_lista_tipo->proximo);
	tipo_deletar(&(tmp_lista_tipo->tipo));
	free(tmp_lista_tipo);
	tmp_lista_tipo = NULL;

	return;
}

void lista_deletarPrimeiro(struct lista_tipo_t** lista_tipo)
{
	struct lista_tipo_t* tmp_lista_tipo;

	tmp_lista_tipo = (*lista_tipo)->proximo;
	tipo_deletar(&((*lista_tipo)->tipo));
	free(*lista_tipo);
	*lista_tipo = tmp_lista_tipo;

	return;
}

void lista_exibir(struct lista_tipo_t* lista_tipo)
{
	for (; lista_tipo; lista_tipo = lista_tipo->proximo){
		tipo_exibir(lista_tipo->tipo);
	}

	return;
}

struct Tipo* lista_procurar(struct lista_tipo_t* lista_tipo, int id)
{
	struct Tipo* tipo_procurado;

	for (; lista_tipo && tipo_pegarId(lista_tipo->tipo) != id; lista_tipo = lista_tipo->proximo);
	if (!lista_tipo)
		return NULL;	

	tipo_procurado = lista_tipo->tipo;
	return tipo_procurado;
}
