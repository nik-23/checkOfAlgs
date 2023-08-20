#ifndef ARR_AND_VEC_UTILS_H_INCLUDED
#define ARR_AND_VEC_UTILS_H_INCLUDED
//Модуль із загальними даними та їхніми ініціалізаціями (масив, вектор і його розмірність)
//також підключення потрібних бібліотек та експорт функцій
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
//Бібліотека для динамічного виділення пам'яті і роботі з нею

// Розмір вектора
#define VectorLength 10000
// Оголошення тривимірного масиву для використання його в сортуваннях
int*** Arr;
// Оголошення вектора для використання його в сортуваннях
int Vector[VectorLength];
//Функція динамічного виділення пам'яті для масиву
void Arr3DMemory(int P, int M, int N);
// Функція яка заповнює 3-вимірний масив відповідно випадку заповненності(впорядкований , випадковий , обернено-впорядкований)
void Fill_3D_Arr(int ***Arr, int order, int P, int M, int N);
// Функція яка заповнює вектор відповідно до випадку заповненності(впорядкований , випадковий , обернено-впорядкований)
void Fill_Vector(int size, int order);
//Функція звільнення виділенної пам'яті під масив
void FreeArrMemory(int P, int M);
#endif // ARR_AND_VEC_UTILS_H_INCLUDED
