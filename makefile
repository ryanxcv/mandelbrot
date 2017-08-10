default: mandelbrot
	./$< | feh -

mandelbrot: mandelbrot.c
	cc -lm -O3 -o $@ $<
