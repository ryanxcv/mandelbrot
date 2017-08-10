#include <complex.h>
#include <math.h>
#include <stdio.h>

#define MAX_ITERS 100

void putpixel(char hue, char mult) {
	putchar(-hue*mult);
	putchar( hue*mult);
	putchar( 255*mult);
}

// compute function and output pixel
void f(complex double c) {
	complex double z = c;
	int i; // complex function iterations
	for (i = 0; i < MAX_ITERS && fabs(z) < 10; i++)
		z = z*z + c;
	putpixel(fmin(255, log2(i + 2 - log2(log2(fabs(z)))) * 40), i < MAX_ITERS);
}

int main() {
	int w = 1920, h = 1080;
	printf("P6\n%d %d\n255\n", w, h); // make PPM header

	// compute function at each pixel
	for (float y = 0; y < h; y++)
		for (float x = 0; x < w; x++)
			f((3*x/w - 2) + (2*y/h - 1) * I);

	return 0;
}
