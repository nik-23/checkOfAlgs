
#include "arr_and_vec_utils.h"
int ***Arr;
//виділення пам'яті під тривимірний масив
void Arr3DMemory(int P, int M, int N)
{
Arr = (int***)malloc(P * sizeof(int**));
for (int k = 0; k < P; k++)
{
Arr[k] = (int**)malloc(M * sizeof(int*));
for (int i = 0; i < M; i++){

Arr[k][i] = (int*)malloc(N * sizeof(int));
}}}

//функція, що буде заповнювати масив щоразу
void Fill_3D_Arr(int ***Arr, int sorted, int P, int M, int N)
{
int end = P*M*N, start = 1; for (int k = 0; k < P; k++)
for (int j = 0; j < N; j++)
for (int i = 0; i < M; i++) {
    if (sorted == 1)

        Arr[k][i][j] = start++;
    if (sorted == 2)
        Arr[k][i][j] = rand() % (P * M * N);
    if (sorted == 3)
        Arr[k][i][j] = end--;
}}
//функція, щоо щоразу заповнює масив
void Fill_Vector(int size, int sorted)
{
int end = size, start = 1;
for (int i = 0; i < size; i++) {
    if (sorted == 1)
        Vector[i] = start++;
    if (sorted == 2)
        Vector[i] = rand() % (size);
    if (sorted == 3)

        Vector[i] = end--;
}}
//Функція звільнення пам'яті , виділенної під масив
void FreeArrMemory(int P, int M)
{
    for (int k = 0; k < P; k++)
    {
        for (int i = 0; i < M; i++)
            free(Arr[k][i]);
        free(Arr[k]);
    }
    free(Arr); }
