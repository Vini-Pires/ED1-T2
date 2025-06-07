principal: principal.o
	@echo "Gerando arquivos executável"
	gcc *.o -o principal

principal.o: principal.c
	@echo "Compilando e gerando objetos"
	gcc -c *.c

clean: 
	@echo "Apagando objetos e executáveis antigos..."
	rm -f *.o principal
#	del /f *.o

run: 
	./principal

# LINUX 
# MAKE (CRIA E PREPARA ARQUIVOS .O)
# MAKE RUN (EXECUTA)
# MAKE CLEAN (LIMPA ARQUIVOS .O)
# ls (VERIFICAR ARQUIVOS)


# WINDOWS
# mingw32-make (CRIA E PREPARA ARQUIVOS .O)
# mingw32-make run (EXECUTA)
# mingw32-make clean (LIMPA ARQUIVOS .O)
# ls (VERIFICAR ARQUIVOS)