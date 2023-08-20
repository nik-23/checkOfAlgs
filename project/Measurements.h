#ifndef MEASUREMENTS_H_INCLUDED
#define MEASUREMENTS_H_INCLUDED
//Модуль, що проводить роботу із вимірами часу відповідно до завдання КР
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define measurements_number 28

#define rejected_number 2

#define min_max_number 3

extern clock_t Res[measurements_number];

float MeasurementProcessing();

void ArrSortMeasurement(clock_t (*abc)(int*** Arr, int P, int M, int N),int P, int M, int N, int type);

void VectorSortMeasurement(clock_t (*abc)(int size), int size, int type);
#endif
