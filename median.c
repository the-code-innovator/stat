#include <stdio.h>
#include <stdlib.h>

int __ascending_comparator__(const void *__pointer_1__, const void *__pointer_2__) {
	return *((double*)__pointer_1__) - *((double*)__pointer_2__);
}

int main(int argc, char *argv[]) {
	if (argc >= 2UL) {
		size_t array_length = (size_t)(argc - 1);
		double *array = calloc(array_length, sizeof(double));
		double median_value = 0.0;
		for (size_t iterator = 1UL; iterator < (array_length + 1UL); iterator += 1UL) {
			array[iterator - 1UL] = atof(argv[iterator]);
		}
		qsort(array, array_length, sizeof(double), __ascending_comparator__);
		if (array_length % 2UL == 0UL) {
			median_value = (array[array_length / 2UL] + array[array_length / 2UL - 1UL]) / 2UL;
		} else {
			median_value = array[array_length / 2UL];
		}
		fprintf(stdout, "ARRAY::MEDIAN -> %lf\n", median_value);
	} else {
		fprintf(stderr, "err: insufficient arguments!\n");
	}
	return 0;
}