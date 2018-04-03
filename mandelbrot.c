#include <complex.h>
#include <math.h>
#include <stdio.h>

#define MAX_ITERS 100

int putpixel(char hue, char mult) {
	putchar(-hue*mult);
	putchar( hue*mult);
	putchar( 255*mult);
	return 1;
}

// compute function and output pixel
void f(complex c) {
	complex z = c;
	int i = 0; // complex function iterations
	while (fabs(z = z*z + c) < 4)
		if (++i > MAX_ITERS) {
			putpixel(0, 0);
			return;
		}
	putpixel(fmin(255, log2(i + 2 - log2(log2(fabs(z)))) * 40), 1);
}

int main() {
	int w = 1920, h = 1080;
	printf("P6\n%d %d\n255\n", w, h); // make PPM header

	// compute function at each pixel
	for (float y = h; y--;)
		for (float x = w; x--;)
			f((1 - 3*x/w) + (1 - 2*y/h) * I);
}
