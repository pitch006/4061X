
dime: dime.c dime.h util.c util.h
	gcc -Wall -o dime dime.c util.c

clean:
	rm -f dime
