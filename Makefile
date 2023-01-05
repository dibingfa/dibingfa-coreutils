PROGRAM = dbf-coreutls dbf-yes

All: dbf-coreutils dbf-yes

%: %.c
	gcc $< -o bin/$@

test:
	ls bin

clean:
	rm -rf bin/dbf*