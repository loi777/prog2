CFLAGS = -Wall -lm -g
MAIN = pgmlbp pgmmedia pgmmediana pgmlimiar pgmnega pgmrotacao
all: %: $(MAIN)

pgmlbp: pgmlbp.o imagem.o
    gcc $^ -o $@ $(CFLAGS)
pgmmediana: pgmmediana.o imagem.o
    gcc $^ -o $@ $(CFLAGS)
pgmmedia: pgmmedia.o imagem.o
    gcc $^ -o $@ $(CFLAGS)
pgmlimiar: pgmlimiar.o imagem.o
    gcc $^ -o $@ $(CFLAGS)
pgmrotacao: pgmrotacao.o imagem.o
    gcc $^ -o $@ $(CFLAGS)
pgmnaosei: pgmnaosei.o imagem.o
    gcc $^ -o $@ $(CFLAGS)
pgmnega: pgmnega.o imagem.o
    gcc $^ -o $@ $(CFLAGS)
    
    
imagem.o: imagem.c imagem.h
    gcc -c imagem.c $(CFLAGS)
%.o: %.c imagem.c
    gcc -c $^ $(CFLAGS)
clean:
    rm -rf ./*.o 
purge: clean
    rm -rf $(MAIN)