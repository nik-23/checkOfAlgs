#ifndef SORTING_ALGORITHMS_H_INCLUDED
#define SORTING_ALGORITHMS_H_INCLUDED
#include "Measurements.h"
//Модуль, що відповідає за алгоритми сортування

clock_t selection3D(int ***Arr, int P, int M, int N);
int selection3D_permutations(int ***Arr, int P, int M, int N);

clock_t Shell_3D(int ***Arr, int P, int M, int N);
int Shell_3D_permutations(int ***Arr, int P, int M, int N);


clock_t selectionSort3D(int ***Arr, int P, int M, int N);
int selectionSort3D_permutations(int ***Arr, int P, int M, int N);

clock_t Select8(int size);
int Select8_permutations(int size);

clock_t Shell_2(int size);
int Shell_2_permutations(int size);

clock_t Select1(int size);
int Select1_permutations(int size);
#endif
