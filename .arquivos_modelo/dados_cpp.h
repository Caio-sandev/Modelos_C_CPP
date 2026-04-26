#ifndef DADOS_CPP_H
#define DADOS_CPP_H

#include <iostream>
using namespace std;

class Tipo
{
	public:
		Tipo(int id, void* dados)
		{
			this->id = id;
			this->dados = dados;
		}

		Tipo(void* dados)
		{
			id = id_global;
			id_global++;

			this->dados = dados;
		}

		Tipo(int id)
		{
			this->id = id;
			dados = NULL;	
		}

		Tipo()
		{
			dados = NULL;
		}

		int pegarId()
		{
			return id;
		}

		void* pegarDados()
		{
			return dados;
		}

		void inserirId(int id)
		{
			this->id = id;

			return;
		}

		void inserirDados(void* dados)
		{
			this->dados = dados;

			return;
		}	

		void exibir()
		{
			cout << "-ID: " << id << endl << "-Dados: " << dados << endl;

			return;
		}

	private:
		int id;
		void* dados;
};

#endif
