src = permutation.c

obj = $(src:.c=.o)

all: permutation

permutation: $(obj)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f $(obj) permutation

