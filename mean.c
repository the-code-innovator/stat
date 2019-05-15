#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc >= 2UL) {
		size_t array_length = (size_t)(argc - 1);
		double *array = calloc(array_length, sizeof(double));
		double sum_array = 0.0;
		for (size_t iterator = 1UL; iterator < (array_length + 1UL); iterator += 1UL) {
			array[iterator - 1UL] = atof(argv[iterator]);
			sum_array += array[iterator - 1UL];
		}
		double mean_array = sum_array / (double)(array_length);
		fprintf(stdout, "ARRAY::MEAN -> %lf\n", mean_array);
	} else {
		fprintf(stderr, "err: insufficient arguments!\n");
	}
	return 0;
}