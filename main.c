#include <stdio.h>
#include <stdint.h>

#include <stdlib.h>

#include "activate_fn.h"
#include "helpers.h"

/*
	To play around with different datasets,
	comment or uncomment them here...
*/
#include "dataset_finnbox.h" // <--
// #include "dataset_sum.h" // <--

static double synaptic_weights[INPUT_SIZE + 1];

const double LEARNING_RATE = 9e-5;
const int EPOCH_COUNT = 100000;
const int NEURAL_INPUT_SIZE = INPUT_SIZE + 1;

double forward_once(double input[INPUT_SIZE])
{
	double result = dot(input, synaptic_weights, INPUT_SIZE);
	result += synaptic_weights[NEURAL_INPUT_SIZE - 1];
	result = activate_fn(result);

	return result;
}

void forward(double input[][INPUT_SIZE], double output[], int sample_count)
{
	for (int i = 0; i < sample_count; i++)
	{
		double result = dot(input[i], synaptic_weights, INPUT_SIZE);

		// adding bias
		result += synaptic_weights[NEURAL_INPUT_SIZE - 1];

		output[i] = activate_fn(result);
	}
}

void println(double a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%.7lf ", a[i]);
	}
	printf("\n");
}

void train(double training_set_inputs[][INPUT_SIZE], double training_set_outputs[], const int sample_count, int epoch_index)
{
	int verbose = epoch_index % 5000 == 0;
	if (verbose)
	{
		printf("#%d:\n", epoch_index);
	}

	double error[sample_count];
	double output[sample_count];

	forward(training_set_inputs, output, sample_count);

	double transpose[NEURAL_INPUT_SIZE][sample_count];

	for (int i = 0; i < sample_count; i++)
	{
		error[i] = output[i] - training_set_outputs[i];
		error[i] *= activate_fn_derivative(output[i]);
	}

	for (int i = 0; i < NEURAL_INPUT_SIZE; i++)
	{
		for (int j = 0; j < sample_count; j++)
		{
			// is bias if i == INPUT_SIZE
			transpose[i][j] = (i < INPUT_SIZE ? training_set_inputs[j][i] : 1.0);
		}
	}

	double adjustments[NEURAL_INPUT_SIZE];

	for (int i = 0; i < NEURAL_INPUT_SIZE; i++)
	{
		adjustments[i] = dot(error, transpose[i], sample_count) / sample_count;
		adjustments[i] *= LEARNING_RATE;
	}

	for (int i = 0; i < NEURAL_INPUT_SIZE; i++)
	{
		synaptic_weights[i] -= adjustments[i];
	}

	if (verbose)
	{
		double sum_error = 0;
		for (int i = 0; i < NEURAL_INPUT_SIZE; i++)
			sum_error += adjustments[i];
		printf("%.9lf\n", sum_error);
	}
}

void run_test(double input[][INPUT_SIZE], double expected[], int count)
{
	double output[count];
	forward(input, output, count);

	double avg = 0;

	printf("Predict		Expected	Diff\n");

	for (int i = 0; i < count; i++)
	{
		double diff = 0;
		if (expected != NULL)
		{
			diff = (output[i] - expected[i]);
			if (diff < 0)
			{
				diff = -diff;
			}
			avg += diff;
		}

		printf("%.3lf		%.3lf		%.2lf\n",
			   output[i], expected[i], diff);
	}
	avg /= count;
	printf("Average diff = %.4lf \n", avg);
}

int main(int argc, char *argv[])
{
	srand(1);

	for (int i = 0; i < INPUT_SIZE + 1; i++)
	{
		synaptic_weights[i] = 2 * ((double)rand() / RAND_MAX) - 1;
	}

	printf("Training...\n");
	for (int epoch = 0; epoch < EPOCH_COUNT; epoch++)
	{
		train(input_train, output_train, TRAIN_COUNT, epoch);
	}

	run_test(input_test, output_test, TEST_COUNT);
	// run_test(input_train, output_train, TRAIN_COUNT);

	printf("\n\nNetwork weights:\n");
	println(synaptic_weights, INPUT_SIZE + 1);

	return 0;
}
