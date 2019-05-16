#include <stdio.h>
#include <stdlib.h>

typedef struct __mode_element__ {
	double element_data;
	size_t element_count;
} mode_element_t;

size_t get_unique_element_count(double *array, size_t array_length) {
	size_t unique_count = 1UL;
	double flag_element = array[0UL];
	for (size_t iterator = 1UL; iterator < array_length; iterator += 1UL) {
		if (array[iterator] != flag_element) {
			unique_count += 1UL;
			flag_element = array[iterator];
		}
	}
	return unique_count;
}

mode_element_t* construct_mode_array(double *array, size_t array_length, size_t unique_length) {
	mode_element_t *mode_array = calloc(unique_length, sizeof(mode_element_t));
	double flag_data = array[0UL];
	size_t flag_count = 1UL;
	size_t mode_array_iterator = 0UL;
	for (size_t iterator = 1UL; iterator < array_length; iterator += 1UL) {
		if (array[iterator] != flag_data) {
			mode_array[mode_array_iterator].element_count = flag_count;
			mode_array[mode_array_iterator].element_data = flag_data;
			mode_array_iterator += 1UL;
			flag_count = 1UL;
			flag_data = array[iterator];
		} else {
			flag_count += 1UL;
		}
	}
	mode_array[mode_array_iterator].element_count = flag_count;
	mode_array[mode_array_iterator].element_data = flag_data;
	return mode_array;
}

int __ascending_comparator_array__(const void *__pointer_1__, const void *__pointer_2__) {
	return *((double*)__pointer_1__) - *((double*)__pointer_2__);
}

int __ascending_comparator_mode__(const void *__pointer_1__, const void *__pointer_2__) {
	return (
		((mode_element_t*)__pointer_2__)->element_count != ((mode_element_t*)__pointer_1__)->element_count
	) ? (
		((mode_element_t*)__pointer_2__)->element_count - ((mode_element_t*)__pointer_1__)->element_count
	) : (
		((mode_element_t*)__pointer_1__)->element_data - ((mode_element_t*)__pointer_2__)->element_data
	);
}

int __descending_comparator_mode__(const void *__pointer_1__, const void *__pointer_2__) {
	return (
		((mode_element_t*)__pointer_2__)->element_count != ((mode_element_t*)__pointer_1__)->element_count
	) ? (
		((mode_element_t*)__pointer_2__)->element_count - ((mode_element_t*)__pointer_1__)->element_count
	) : (
		((mode_element_t*)__pointer_2__)->element_data - ((mode_element_t*)__pointer_1__)->element_data
	);
}

int main(int argc, char *argv[]) {
	if (argc >= 2UL) {
		size_t array_count = (size_t)(argc - 1UL);
		double *array = calloc(array_count, sizeof(double));
		for (size_t iterator = 0UL; iterator < array_count; iterator += 1UL) {
			array[iterator] = atof(argv[iterator + 1UL]);
		}
		qsort(array, array_count, sizeof(double), __ascending_comparator_array__);
		size_t unique_count = get_unique_element_count(array, array_count);
		mode_element_t *mode_array = construct_mode_array(array, array_count, unique_count);
		qsort(mode_array, unique_count, sizeof(mode_element_t), __ascending_comparator_mode__);
		fprintf(stdout, "ARRAY::MODE -> %lf @ %zu\n", mode_array[0UL].element_data, mode_array[0UL].element_count);
	} else {
		fprintf(stderr, "err: insufficient arguments!\n");
	}
	return 0;
}