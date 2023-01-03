All: dibingfa-coreutils

dibingfa-coreutils: dibingfa-coreutils.c
	gcc dibingfa-coreutils.c -o bin/dibingfa-coreutils

clean:
	rm -rf bin/*