salida_out = lab1

salida_headers = funciones.h
salida_source = $(salida_headers:.h=.c) main.c

CC     = gcc
CFLAGS = -Wall -lm

depends = .depends


$(salida_out) : $(salida_objects)
	$(CC) $(CFLAGS) -o $@ $^ -lm

$(objetcs) :
	$(CC) $(CFLAGS) -c -o $@ $*.c

$(depends) : $(salida_source) $(salida_headers)
	@$(CC) -MM $(salida_source) > $@

clean :
	$(RM) $(salida_out) $(salida_objects) $(zipfile) $(depends)
.PHONY : build zip clean

sinclude : $(depends)