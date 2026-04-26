all: clean inter exec _debug_exec _debug_all
	@tree

clean:
	@echo "Excluindo Arquivos Intermediarios..."
	@rm -f ./obj/*
	@echo "Excluindo Executaveis..."
	@rm -f ./bin/*

inter:
	@echo "Criando Arquivos Intermediarios..."
	@g -c ./src/&.c -I ./include/ -o ./obj/&.o

exec:
	@echo "Criando Executaveis..."
	@g ./apps/&.c ./obj/* -I ./include/ -o ./bin/&

run:
	@echo "Executando &..."
	@./bin/&

_debug_exec:
	@echo "Criando Executavel com Depuracao Simples..."
	@g -ggdb ./apps/&.c ./obj/* -I ./include/ -o ./src/debug/&
	
_debug_all:
	@echo "Criandp Executavel com Depuracao Completa..."
	@g -ggdb ./apps/&.c ./src/*.c -I ./include/ -o ./src/debug/&_completo

debug_exec:
	@echo "Executando Debug Simples..."
	@./src/debug/&

debug_all:
	@echo "Executando Debug Completo..."
	@./src/debug/&_completo

