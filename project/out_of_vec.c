#include "Measurements.h"
#include "out_of_vec.h"
#include "arr_and_vec_utils.h"
#include "sorting_algorithms.h"
//Розміри 3-вимірного масиву, який використовуємо для підрахунку часу роботи алгоритмів
//P - перерізи, M - рядки в перерізі, N - стовпчики в перерізі //Порядок значень у кожному кейсі такий : P, M, N
const int Research[16][3] = {
        {15000, 1, 1},
        {15000, 2, 2},
        {15000, 4, 4},
        {15000, 8, 8},
        {15000, 16, 16},
        {15000, 32, 32},
        {15000, 64, 64},
        {15000, 128, 128},
        {12800, 2, 800},
        {12800, 4, 400},
        {12800, 8, 200},
        {12800, 16, 100},
        {12800, 100, 16},
        {12800, 200, 8},
        {12800, 400, 4},
        {12800, 800, 2},
};
//Функція, яка виводить на екран масив
void Output_Arr(int ***Arr, int P, int M, int N)
{
    int j, k, i;

    printf("__________________________________________");
    for (k = 0; k < P; k++)
    {
        printf("\n\n");
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
            {
                printf("%4d", Arr[k][i][j]);
            }
            printf("\n");
        }
    }
    printf("__________________________________________");
    printf("\n\n");
}
//Функція, яка виводить на екран вектор
void Output_Vec(int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", Vector[i]);
    }
    printf("\n\n");
}
//Функція, яка виводить на екран таблицю з часом сортувань
void Table(float ordered, float random, float reversed, int type)
{
    if (type == 1)
    {
        printf("\nSELECTION_SORT_8 |");
    }
    if (type == 2)
    {
        printf("\nSHELL_2          |");
    }
    if (type == 3)
    {
        printf("\nSELECTION_SORT_1 |");
    }
    printf("%12.3f| %12.3f |%12.3f| \n", ordered, random,reversed);}
//Функція для запуску відповідного алгоритму сортування вектору / масиву //виводить час сортування аглоритму
//який обирається користувачем
void Time(int method, int type)
{
    system("cls");
    if(type == 1)
    {
        clock_t(*algorithm_arr[3])(int***, int, int, int) = {selectionSort3D, Shell_3D,selection3D};
        int P, M, N, cases = 8, current_case = 0; for (int p = 0; p < 2; p++)
        {
            printf("\n\t\t\t\tCase of research : %d\n", p + 1);
            for (; current_case < cases; current_case++)
            {
                P = Research[current_case][0];


                M = Research[current_case][1];
                N = Research[current_case][2];
                printf("\n\nSizes of array's : P = %d, M = %d, N = %d\n\n", P, M, N);
                printf("\t \t    Ordered\t   Random \t  Reversed \n");
                Arr3DMemory(P, M, N);
                if (method == 4)
                {
                    for (int alg = 0; alg < 3; alg++)
                    {
                        ArrSortMeasurement(algorithm_arr[alg], P, M, N, alg + 1);
                    } }
                else
                {
                    ArrSortMeasurement(algorithm_arr[method - 1], P, M, N, method);
                }
                FreeArrMemory(P, M);
            }
            cases = 16;
        }
    }
    else if(type == 2)
    {
        clock_t(*algorithm_vec[3])(int) = {Select8, Shell_2,Select1};
        printf("Length of vector : %d\n", 15000);
        printf("\t Ordered Random Reversed \n");
        if(method == 4)
        {
            for (int alg = 0; alg < 3; alg++)
            {
                VectorSortMeasurement(algorithm_vec[alg], 10000, alg + 1);
            } }
        else
        {
            VectorSortMeasurement(algorithm_vec[method - 1], 10000, method);
        } }}//Функція для запуску відповідного алгоритму сортування масиву / вектору //виводить результат сортування аглоритму
//який обирається користувачем
void Sorting(int method, int type)
{
    if(type == 1)
    {
        clock_t(*algorithm_arr)(int***, int, int, int) = selectionSort3D;
        int P = 3, M = 4, N = 4;
        Arr3DMemory(P, M, N);
        system("cls");
        if(method == 1)
        {
            printf("selectionSort#8 sorting for array , sizes : P = %d, M = %d, N = %d\n\n", P, M, N); }

        if(method == 2)
        {
            printf("Shell_3D sorting for array , sizes : P = %d, M = %d, N = %d\n\n", P, M, N);
            algorithm_arr = Shell_3D;

        }
        if(method == 3)
        {
            printf("selectionSort#1 sorting for array , sizes : P = %d, M = %d, N = %d\n\n", P, M, N);
            algorithm_arr = selection3D;
        }
        for (int i = 1; i <= 3; i++)
        {
            Fill_3D_Arr(Arr, i, P, M, N); if (i == 1)
                printf("Ordered\n");
            if (i == 2)
                printf("Random\n");
                if (i == 3)
                printf("Reversed\n");
                Output_Arr(Arr, P, M, N);
                algorithm_arr (Arr, P, M, N);
                if (i == 1)
                printf("Ordered sorted\n");
                if (i == 2)
                printf("Random sorted\n");
                if (i == 3)
                printf("Reversed sorted\n");
                Output_Arr(Arr, P, M, N);
        }
        FreeArrMemory(P, M);
    }
    if(type == 2)
    {
        int size = 10;
        clock_t(*algorithm_vec)(int) = Select8;
        system("cls");
        if(method == 1)
        {
            printf("selectionSort#8 sorting for vector , length : %d\n\n", size); }
        if(method == 2)
        {
            printf("Shell_2 sorting for vector , length : %d\n\n", size);
            algorithm_vec = Shell_2;
        }
        if(method == 3)
        {
            printf("selectionSort#1 sorting for vector , length : %d\n\n", size);
            algorithm_vec = Select1;
        }
        for (int i = 1; i <= 3; i++)
        {
            if (i == 1)
                printf("Ordered\n"); if (i == 2)
                printf("Random\n"); if (i == 3)
                printf("Reversed\n");
            Fill_Vector(size, i);
            Output_Vec(size);
            algorithm_vec(size);
            if (i == 1)
                printf("Ordered sorted\n");
            if (i == 2)
                printf("Random sorted\n");
            if (i == 3)
                printf("Reversed sorted\n");
            Output_Vec(size);
        }
    } }
