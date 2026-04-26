#!/bin/bash

LISTA_C_H=~/.arquivos_modelo/lista_c.h
LISTA_C=~/.arquivos_modelo/lista.c
LISTA_CPP_H=~/.arquivos_modelo/lista_cpp.h

DADOS_C_H=~/.arquivos_modelo/dados_c.h
DADOS_C=~/.arquivos_modelo/dados.c
DADOS_CPP_H=~/.aquivos_modelo/dados_cpp.h

GENERIC_H=~/.arquivos_modelo/generc.h
GENERIC_C=~/.arquivos_modelo/generc.c
GENERIC_CPP=~/.arquivos_modelo/generc.cpp

MAKEFILE=~/.arquivos_modelo/Makefile

avisoErro() {
	echo "Escreva: ~/.modelos_c_c++ [QUANTIDADE] [ARQUIVO] [OPCOES]..."
	echo "	-ARQUIVO: extensao do arquivo ('c' ou 'cpp')"
	echo "	-QUANTIDADE: quantidade de arquivos para criar"
	echo "  -OPCOES:"
	echo "   lista: cria arquivos de listas"
	echo "   dados: cria arquivos de dados"
	echo "   generc: cria arquivos genericos"

	rm -rf ./apps
	rm -rf ./bin
	rm -rf ./include
	rm -rf ./obj
	rm -rf ./src

	exit 1
}

if [[ $# -lt 3 || $# -gt 18 ]]; then
	avisoErro
fi

mkdir ./apps
mkdir ./bin
mkdir ./include
mkdir ./obj
mkdir ./src
mkdir ./src/debug

if (( $# % 3 == 0 )); then
	while [ $# -ne 0 ]; do
		if [[ "$2" == "c" ]]; then
			i=0

			if [[ "$3" == "lista" ]]; then
				while [[ $i -ne $1 ]]; do
					cp $LISTA_C ./src/lista$i.c
					cp $LISTA_C_H ./include/lista_c$i.h
					
					((i++))		
				done	
			elif [[ "$3" == "dados" ]]; then
				while [[ $i -ne $1 ]]; do
					cp $DADOS_C ./src/dados$i.c
					cp $DADOS_C_H ./include/dados_c$i.h

					((i++))
				done
			elif [[ "$3" == "generic" ]]; then
				while [[ $i -ne $1 ]]; do
					cp $GENERIC_C ./src/generic$i.c
					cp $GENERIC_H ./include/generic$i.h

					((i++))
				done
			else
				avisoErro
			fi

			if [[ ! -f ./apps/app.c ]]; then
				cp $GENERIC_C ./apps/app.c
			fi
		elif [[ "$2" == "cpp" ]]; then
			i=0

			if [[ "$3" == "lista" ]]; then
				while [[ $i -ne $1 ]]; do
					cp $LISTA_CPP_H ./include/lista_cpp$i.h

					((i++))
				done
			elif [[ "$3" == "dados" ]]; then
				while [[ $i -ne $1 ]]; do
					cp $DADOS_CPP_H ./include/dados_cpp$i.h
				
					((i++))
				done
			elif [[ "$3" == "generic" ]]; then
				while [[ $i -ne $1 ]]; do
					cp $GENERIC_CPP ./src/generic$i.cpp
					cp $GENERIC_H ./include/generic$i.cpp
					
					((i++))
				done
			else
				avisoErro
			fi

			if [[ ! -f ./apps/app.cpp ]]; then
				cp $GENERIC_CPP ./apps/app.cpp
			fi
		else
			avisoErro
		fi
		
		shift 3;
	done
else
	avisoErro
fi

cp $MAKEFILE .

exit 0
