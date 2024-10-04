###############################################################################
# Makefile
###############################################################################
CC=gcc
FLAGS=-Wall -g

PROCESS_EXAMPLES=pexample1 pexample2 pexample3 zombie orphan mini-shell

SRCS=$(addsuffix .c, $(PROCESS_EXAMPLES))

all: $(PROCESS_EXAMPLES)

# General building rule
$(PROCESS_EXAMPLES): $(SRCS)
	gcc $(FLAGS) $@.c -o $@

clean:
	@rm -rf $(PROCESS_EXAMPLES)

