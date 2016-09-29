strtest: hw1.c clean
	gcc hw1.c -o strtest.out

run: strtest
	clear
	./strtest.out

clean:
	rm -f *.out
