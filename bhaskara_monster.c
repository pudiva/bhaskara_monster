#include <stdio.h>

const char intro[] =
"/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n"
"\\                                                                              /\n"
"/                             BHASKARA MONSTER!!1                              \\\n"
"\\                                                                              /\n"
"/                            by black sheep & rogi                             \\\n"
"\\                              Copyright © 2000                                /\n"
"/                                                                              \\\n"
"\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n"
"\n"
"resolvedor de equações de segundo grau na forma:\n"
"\n"
"    A x² + B x + C = 0\n"
"\n"
"utilizando a fórmula de bhaskara:\n"
"\n"
"    Δ = B² - 4 A C\n"
"              ___\n"
"    x = -B ± √‾Δ \n"
"        ‾‾‾2‾A‾‾‾\n"
"\n";

const char fmt_question[] =
"entre com o valor de %c: ";

const char fmt_resultR[] =
"\n"
"as soluções são\n"
"\n"
"   Δ = % 8f\n"
"\n"
"   x ∈ ℝ\n"
"\n"
"tchau\n";

const char fmt_result_nope[] =
"\n"
"não tem solução\n"
"\n"
"tchau\n";

const char fmt_result0[] =
"\n"
"não tem solução real\n"
"\n"
"tchau\n";

const char fmt_result1[] =
"\n"
"a solução é\n"
"\n"
"   Δ = % 8f\n"
"\n"
"   x = % 8f\n"
"\n"
"tchau\n";

const char fmt_result2[] =
"\n"
"as soluções são\n"
"\n"
"   Δ = % 8f\n"
"\n"
"   x ∈ { % 8f, % 8f }\n"
"\n"
"tchau\n";

/* #define DANIMAT 1 */

#ifdef DANIMAT
double raiz(double y)
{
	double x = y;
	int i;

	if (0 <= y)
		for (i = 0; i < 10; ++i)
			x += (y - x * x)/(2 * x);
	else
		x = 0.0/0.0; /* NaN */

	return x;
}
#else
double raiz(double y)
{
	double x;

	if (0 <= y)
		for (x = 0; x*x < y; x += 0.0001);
	else
		x = 0.0/0.0; /* NaN */

	return x;
}
#endif

int main()
{
	double A, B, C, x[2], delta;

	fputs(intro, stdout);
	printf(fmt_question, 'A');
	scanf("%lf", &A);
	printf(fmt_question, 'B');
	scanf("%lf", &B);
	printf(fmt_question, 'C');
	scanf("%lf", &C);

	delta = B*B - 4*A*C;

	if (A == 0 && B == 0 && C == 0)
	{
		printf(fmt_resultR, delta);
		return 0;
	}

	else if (A == 0 && B == 0)
	{
		printf(fmt_result_nope);
		return 0;
	}

	else if (A == 0)
	{
		x[0] = -C / B;
		x[1] = x[0];
	}

	else
	{
		x[0] = (-B - raiz(delta))/(2*A);
		x[1] = (-B + raiz(delta))/(2*A);
	}

	if (x[0] != x[0]) /* NaN */
		printf(fmt_result0);
	else if (x[0] == x[1])
		printf(fmt_result1, delta, x[0]);
	else
		printf(fmt_result2, delta, x[0], x[1]);

	return 0;
}
