#314CA_Dumistracel_Eduard_Costin
CC=gcc
CFLAGS=-Wall -Wextra -g -std=c99

TARGETS=main

build: $(TARGETS)

main: main.c add.c default.c shw.c
	$(CC)  $(CFLAGS) main.c default.c add.c shw.c blh.c UPG.c EXP.c rmv.c rotate.c COL.c all.h -o main

pack:
	zip -FSr 3XYCA_FirstnameLastname_Tema1.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
