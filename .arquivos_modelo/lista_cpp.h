#ifndef LISTA_CPP_H
#define LISTA_CPP_H

#include "dados_cpp.h"

class NoTipo
{
	public:
		Tipo tipo;
		NoTipo* proximo = NULL;

		NoTipo(Tipo& tipo)
		{
			this->tipo = tipo;
		}
};

class ListaTipo
{
	public:
		struct Iterador
		{	
			NoTipo* no_iterador;
			
			Tipo& operator*()
			{
				return no_iterador->tipo;
			}

			Iterador& operator++()
			{
				if (no_iterador)
					no_iterador = no_iterador->proximo;

				return *this;
			}

			bool operator!=(const Iterador& outro) const
			{
				return no_iterador != outro.no_iterador;
			}
		};

		Iterador begin()
		{
			return Iterador{ no_principal };
		}

		Iterador end()
		{
			return Iterador{ NULL };
		}

		ListaTipo(Tipo& tipo)
		{
			no_principal = new NoTipo(tipo);
		}

		void anexarPorUltimoNaLista(Tipo& tipo)
		{
			NoTipo* tmp_no;
			NoTipo* novo_no = new NoTipo(tipo);

			for (tmp_no = no_principal; tmp_no->proximo; tmp_no = tmp_no->proximo);
			tmp_no->proximo = novo_no;

			return;
		}

		void anexarEmPrimeiroNaLista(Tipo& tipo)
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
			
			if (!no_principal)
				return;

			for (tmp_no = no_principal; tmp_no->proximo->proximo; tmp_no = tmp_no->proximo);
			delete tmp_no->proximo;
			tmp_no->proximo = NULL;
			
			return;
		}

		void deletarEmPrimeiroNaLista()
		{
			NoTipo* tmp_no = no_principal->proximo;

			if (!no_principal)
				return;

			delete no_principal;
			no_principal = tmp_no;

			return;
		}	

		void exibirLista()
		{
			NoTipo* tmp_lista;

			for (tmp_lista = no_principal; tmp_lista; tmp_lista = tmp_lista->proximo){
				tmp_lista->tipo.exibir();
			}

			return;
		}

		struct Tipo* procurarTipoNaLista(int id)
		{
			NoTipo* tmp_no;

			for (tmp_no = no_principal; tmp_no->proximo; tmp_no = tmp_no->proximo){
				int tipo_id = tmp_no->tipo.pegarId();

				if (tipo_id == id)
					tmp_tipo = &(tmp_no->tipo);
			}	

			return tmp_tipo;
		}


	private:
		NoTipo* no_pri
};	

#endif
