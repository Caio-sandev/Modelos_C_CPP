#ifndef LISTA_CPP_H
#define LISTA_CPP_H

#include "dados_cpp.h"

class NoTipo
{
	public:
		Tipo* tipo;
		NoTipo* proximo = NULL;

		NoTipo(Tipo* tipo)
		{
			this->tipo = tipo;
			proximo = NULL;
		}

		NoTipo()
		{
			tipo = NULL;
			proximo = NULL;
		}	
};

class ListaTipo
{
	private:
		NoTipo* no_principal;

	public:
		ListaTipo(Tipo* tipo)
		{
			no_principal = new NoTipo(tipo);
		}

		ListaTipo()
		{
			no_principal = new NoTipo;
		}

		void anexarPorUltimoNaLista(Tipo* tipo)
		{
			NoTipo* tmp_no;
			NoTipo* novo_no = new NoTipo(tipo);

			for (tmp_no = no_principal; tmp_no->proximo; tmp_no = tmp_no->proximo);
			tmp_no->proximo = novo_no;

			return;
		}

		void anexarEmPrimeiroNaLista(Tipo* tipo)
		{
			NoTipo* tmp_no;
			NoTipo* novo_no = new NoTipo(tipo);

			tmp_no = no_principal;
			novo_no->proximo = tmp_no;
			no_principal = novo_no;

			return;
		}

		void deletarPorUltimoNaLista()
		{
			NoTipo* tmp_no;

			for (tmp_no = no_principal, tmp_no->proximo; tmp_no = tmp_no->proximo);
			delete tmp_no->tipo;
			delete tmp_no;
			tmp_no = NULL;

			return;
		}

		void deletarEmPrimeiroNaLista()
		{
			NoTipo* tmp_no = no_principal->proximo;

			delete no_principal->tipo;
			delete no_principal;
			no_principal = tmp_no;

			return;
		}	

		void exibirLista()
		{
			NoTipo* tmp_lista;

			for (tmp_lista = no_principal; tmp_lista->proximo; tmp_lista = tmp_lista->proximo){
				tmp_lista->tipo->exibir();
			}

			return;
		}

		struct Tipo* procurarTipoNaLista(int id)
		{
			NoTipo* tmp_no;

			for (tmp_no = no_principal; id != tmp_no->tipo->pegarId() && tmp_no; tmp_no = tmp_no->proximo);
			if (!tmp_no)
				return NULL;

			return tmp_no->tipo;
		}
};	

#endif
