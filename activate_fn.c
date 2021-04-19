#include <stdio.h>
#include <math.h>

#include "activate_fn.h"

double activate_fn(double x)
{

	double result;

	result = x;

	// result = 1 / (1 + exp(-x));

	return result;
}

double activate_fn_derivative(double output)
{
	double result;

	/* result = sigmoid(x) * (1 - sigmoid(x)); */
	// result = output * (1 - output);
	result = 1;

	return result;
}
