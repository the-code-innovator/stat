#include <stdio.h>
#include <stdlib.h>

int __ascending_comparator__(const void *__pointer_1__, const void *__pointer_2__) {
	return *((double*)__pointer_1__) - *((double*)__pointer_2__);
}

int main(int argc, char *argv[]) {
	if (argc >= 2UL) {
		size_t array_count = (size_t)(argc - 1UL);
		double *array = calloc(array_count, sizeof(double));
		for (size_t iterator = 1UL; iterator < (argc + 1UL); iterator += 1UL) {
			array[iterator] = atof(argv[iterator]);
		}
		qsort(array, array_count, sizeof(double), __ascending_comparator__);
	} else {
		fprintf(stderr, "err: insufficient arguments!\n");
	}
	return 0;
}