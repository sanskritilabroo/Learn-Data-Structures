#include <stdio.h>

typedef struct complex
{
	float real, im;
} complex;



complex add(complex c1, complex c2); //returning a structure of type complex
complex mult(complex c1, complex c2);
complex sub(complex c1, complex c2);



int main()
{
	complex c1, c2, resadd, resmult, ressub;
	printf("Enter 1st number's real and imaginary parts:");
	scanf("%f %f",&c1.real, &c1.im);
	printf("Enter 2nd number's real and imaginary parts:");
	scanf("%f %f",&c2.real, &c2.im);

	resadd = add(c1,c2);
	printf("Real Sum: %.1f \t", resadd.real);
	printf("Imaginary Sum: %.1f \n", resadd.im);

	resmult = mult(c1,c2);
	printf("Real Product: %.1f \t", resmult.real);
	printf("Imaginary Product: %.1f \n", resmult.im);

	ressub = sub(c1,c2);
	printf("Real Difference: %.1f \t", ressub.real);
	printf("Imaginary Difference: %.1f \n", ressub.im);
}



complex add(struct complex c1, struct complex c2)
{
	complex res;
	res.real = c1.real + c2.real;
	res.im = c1.im + c2.im;
	return (res);
}
complex mult(struct complex c1, struct complex c2)
{
	complex res;
	res.real = (c1.real * c2.real) - (c1.im * c2.im);
	res.im = (c1.real * c2.im) + (c1.im * c2.real);
	return (res);
}
complex sub(struct complex c1, struct complex c2)
{
	complex res;
	res.real = c1.real - c2.real;
	res.im = c1.im - c2.im;
	return (res);
}