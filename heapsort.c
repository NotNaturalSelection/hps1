#include <stdint-gcc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common.h"

void swap(uint32_t *arr, int64_t index1, int64_t index2) {
    uint32_t tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}

void heapify(uint32_t *arr, int64_t size, int64_t root) {
    int64_t largest = root;
    int64_t left = 2 * root + 1;
    int64_t right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        swap(arr, root, largest);
        heapify(arr, size, largest);
    }
}

void heapsort(uint32_t *arr, int64_t size) {
    for (int64_t i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (int64_t i = size - 1; i >= 0; i--) {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
}

int32_t main(int32_t argc, char **argv) {
    int64_t elements = ELEM_NUM;
    int64_t cycles = CYCLE_NUM;
    if (argc > 1) {
        elements = strtol(argv[1], NULL, 10);
    }
    if (argc > 2) {
        cycles = strtol(argv[2], NULL, 10);
    }
    test_sort(cycles, elements, heapsort, "heapsort", true);
    return 0;
}