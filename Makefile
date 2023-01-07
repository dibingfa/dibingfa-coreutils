PROGRAM = dbf-coreutils dbf-yes

all: $(PROGRAM)

%: %.c
	gcc $< -o bin/$@

test:
	ls bin

clean:
	rm -rf bin/dbf*