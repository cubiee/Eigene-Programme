#include <stdio.h>


typedef struct complex_s{
	float real;
	float imag;
}complex;


complex add(complex, complex);
complex sub(complex, complex);
complex mult(complex, complex);
complex div(complex, complex);


int main(void){
	complex a;
	a.real = 1.0f;
	a.imag = 2.0f;

	complex b;
	b.real = 3.0f;
	b.imag = 4.0f;

	complex c;

	c = add(a, b);
	printf("%f + j %f\n", c.real, c.imag);
	c = sub(a, b);
	printf("%f + j %f\n", c.real, c.imag);
	c = mult(a, b);
	printf("%f + j %f\n", c.real, c.imag);
	c = div(a, b);
	printf("%f + j %f\n", c.real, c.imag);
	return 0;
}

complex add(complex a, complex b){
	complex res;
	res.imag = a.imag + b.imag;
	res.real = a.real + b.real;
	return res;
}

complex sub(complex a, complex b){
	complex res;
	res.imag = a.imag - b.imag;
	res.real = a.real - b.real;
	return res;
}

complex mult(complex a, complex b){
	complex res;
	res.imag = a.real * b.imag + a.imag * b.real;
	res.real = a.real * b.real - a.imag * a.imag;
	return res;
}

complex div(complex a, complex b){
	complex res;
	float divisor = b.real * b.real + b.imag * b.imag;
	res.imag = (a.imag * b.real - a.real * b.imag) / divisor;
	res.real = (a.real * b.real + a.imag * b.imag) / divisor;
	return res;
}