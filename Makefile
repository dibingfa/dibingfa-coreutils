PROGRAM = dbf-coreutils dbf-yes dbf-echo

all: $(PROGRAM)

%: %.c
	gcc -g -O0 $< -o bin/$@

test:
	ls bin

clean:
	rm -rf bin/dbf*