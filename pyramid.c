#include <stdlib.h>
#include <stdio.h>

void draw_triangle(int base, int offset, int length) {
	int i, i1, i2;

	for(i = (base % 2) ? 1 : 2; i <= base; i += 2) {
		for(i2 = 0; i2 != length; i2++) {
			for(i1 = 1; i1 <= ((base - i) / 2) + offset; i1++)
				fputc(' ', stdout);

			for(i1 = 1; i1 <= i; i1++)
				fputc('X', stdout);

			for(i1 = 1; i1 <= (base - i) / 2; i1++)
				fputc(' ', stdout);
		}

		fputc('\n', stdout);
	}
}

int main(int argc, char **argv) {
	int base;

	if(argc < 2) {
		fputs("ERROR: You did not give enough arguments.\n", stderr);
		exit(1);
	}

	base = atoi(argv[1]);
	if(!(base % 2)) {
		draw_triangle(base, base/2, 1);
		draw_triangle(base, 0, 2);
	} else
		draw_triangle(base, 0, 1);

	return 0;
}
