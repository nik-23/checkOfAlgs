#ifndef ARR_AND_VEC_UTILS_H_INCLUDED
#define ARR_AND_VEC_UTILS_H_INCLUDED
//модуль що відповідає за вектор та масив (їх заповнення)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>


// Розмір вектора
#define VectorLength 150000

int*** Arr;

int Vector[VectorLength];

void Arr3DMemory(int P, int M, int N);

void Fill_3D_Arr(int ***Arr, int order, int P, int M, int N);

void Fill_Vector(int size, int order);

void FreeArrMemory(int P, int M);
#endif
