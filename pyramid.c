/*
 * pyramid.c
 *
 * Copyright (C) 2011-2012,  Alex Petrovich <alex@libslack.so>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

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
