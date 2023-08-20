#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

#include "sorting_algorithms.h"
#include "arr_and_vec_utils.h"
#include "Measurements.h"

clock_t Shell_3D(int*** arr, int P, int M, int N)
{
    int tmp, t, j, k;

    clock_t time_start, time_stop;

    if (P < 4) {
        t = 1;
    }
    else {
        t = (int)log2f((float)P) - 1;
    }
   int Stages[t];
    // початок відліку часу
    time_start = clock();
    Stages[t-1] = 1;
    for (int i = t - 2; i >= 0; i--) {
        Stages[i] = 2 * Stages[i + 1] + 1;
    }
    for (int p = 0; p < t; p++) {
        k = Stages[p];
        for (int i = k; i < P; i++) {
                j = i;
                while (j >= k && arr[j][0][0] <= arr[j - k][0][0]) {
                    for (int m = 0; m < M; m++) {
                        for (int n = 0; n < N; n++) {
                            tmp = arr[j][m][n];
                            arr[j][m][n] = arr[j - k][m][n];
                            arr[j - k][m][n] = tmp;
                        }
                    }
                    j -= k;
                }
            }
        }

    free(Stages);
     // кінець відліку часу
    time_stop = clock();
    return time_stop - time_start;
}
clock_t Shell_2( int N)
{
    int tmp, t, j, k;
    int* Stages;
    clock_t time_start, time_stop;
     if (N < 4)
    {
        t = 1; }
    else
    {
        t = (int)log2f((float)N) - 1;
    }
    Stages = (int*)malloc(t * sizeof(int));
    // початок відліку часу
    time_start = clock();
    if (N < 4)
    {
        t = 1;
    }
    else
    {
        t = (int)log2f((float)N) - 1;
    }
    Stages[t - 1] = 1;
    for (int i = t - 2; i >= 0; i--) {
        Stages[i] = 2 * Stages[i + 1] + 1; }
    for (int p = 0; p < t; p++)
    {
        k = Stages[p];
        for (int i = k; i < N; i++)
        {
            j = i;
            while (j >= k && Vector[j] < Vector[j - k])
            {
                tmp = Vector[j];
                Vector[j] = Vector[j - k];
                Vector[j - k] = tmp;
                j = j - k;
            } }
    }
     // кінець відліку часу
    time_stop = clock();
    free(Stages);
    return time_stop - time_start;
}



clock_t selection3D(int*** arr, int P, int M, int N)
{
    int min, imin;
    clock_t time_start, time_stop;
    // початок відліку часу
    time_start = clock();
    for (int s = 0; s < P - 1; s++) {
        min = arr[s][0][0];
        imin = s;
        for (int i = s + 1; i < P; i++) {
            if (arr[i][0][0] <= min) {
                min = arr[i][0][0];
                imin = i;
            }
        }
        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                int tmp = arr[s][m][n];
                arr[s][m][n] = arr[imin][m][n];
                arr[imin][m][n] = tmp;
            }
        }
    }
 // кінець відліку часу
    time_stop = clock();
    return time_stop - time_start;
}

clock_t Select1( int N) {
    int Min, imin;
    clock_t time_start, time_stop;
    // початок відліку часу
    time_start = clock();
    for (int s = 0; s < N - 1; s++) {
        Min = Vector[s];
        imin = s;
        for (int i = s + 1; i < N; i++) {
            if (Vector[i] < Min) {
                Min = Vector[i];
                imin = i;
            }
        }
        Vector[imin] = Vector[s];
        Vector[s] = Min;
    }
     // кінець відліку часу
    time_stop = clock();
    return time_stop - time_start;
}




clock_t selectionSort3D(int*** Arr3D, int P, int M, int N)
{
    clock_t time_start, time_stop;
    // початок відліку часу
    time_start = clock();

    int L = 0;
    int R = P - 1;
    while (L < R) {
        int imin = L;
        int imax = L;
        for (int i = L + 1; i < R + 1; i++) {
            if (Arr3D[i][0][0] < Arr3D[imin][0][0]) {
                imin = i;
            } else {
                if (Arr3D[i][0][0] > Arr3D[imax][0][0]) {
                    imax = i;
                }
            }
        }

        if (imin != L) {
            for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                int tmp = Arr3D[L][m][n];
                Arr3D[L][m][n] = Arr3D[imin][m][n];
                Arr3D[imin][m][n] = tmp;
            }
        }

        }
        if (imax != R) {
            if(imax == L){
               for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                int tmp = Arr3D[R][m][n];
                Arr3D[R][m][n] = Arr3D[imin][m][n];
                Arr3D[imin][m][n] = tmp;
            }

        }
            } else {
                for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                int tmp = Arr3D[R][m][n];
                Arr3D[R][m][n] = Arr3D[imax][m][n];
                Arr3D[imax][m][n] = tmp;
            }
        }
            }
        }
        L = L + 1;
        R = R - 1;
    }
 // кінець відліку часу
    time_stop = clock();
    return time_stop - time_start;
}
//Алгоритм сортування методом прямого вибору №8 для одновимірного масиву.
clock_t Select8( int N)
{
// ініціалізація змінних.
    int L, R, imin, imax, tmp, originalAL;

    clock_t time_start, time_stop;
    // початок відліку часу
    time_start = clock();
    L=0; R=N-1;
    while (L<R){
        imin=L; imax=L;
        originalAL = Vector[0];
        for(int i=L+1; i<R+1; i++) {
            if (Vector[i] < Vector[imin]) { imin = i; }
            else {
                if (Vector[i] > Vector[imax]) imax = i;
            }
        }
        if (imin!=L) {
            tmp=Vector[imin];
            Vector[imin]=Vector[L];
            Vector[L]=tmp;
            if (imax==L) { imax = imin; }
        }
        if (imax!=R) {
            if (imax==L) {
                tmp=originalAL;
                Vector[imin]=Vector[R];
                Vector[R]=tmp;
            } else {
                tmp=Vector[imax];
                Vector[imax]=Vector[R];
                Vector[R]=tmp;
            }
        }
        L=L+1; R=R-1;
    }
      // кінець відліку часу
    time_stop = clock();
    return time_stop - time_start;
}

