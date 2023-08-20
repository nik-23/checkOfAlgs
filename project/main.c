#include "out_of_vec.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Головна сторінка (меню)
void menu()
{
    int mode;
    while (1) {
//Вибір прикладу сортування або часу сортування
printf("\nChoose the mode(press '0' to exit):\n");
printf("\n1. Sorting example \n");
        printf("\n2. Time of sorting\n");
         scanf(" %d", &mode);
        switch (mode)
        {
            case(1):
//у випадку обрання прикладів сортування надається вибір між конкретними алгоритмами
                system("clS");

printf("\nChoose the mode(press '0' to exit):\n");
printf("\n1. Selection sort #8 sorting for array (#16)\n");
printf("\n2.  Shell_2  sorting for array (#22)\n");
printf("\n3. Selection sort #1 sorting for array (#23)\n");
printf("\n4. Selection sort #8 sorting for vector (#16)\n");
printf("\n5.  Shell #2 sorting for vector (#22)\n");
printf("\n6.  Selection sort #1 sorting for vector (#23)\n\n");
scanf(" %d", &mode);
                switch (mode)
                {
                    case(1):
                        Sorting(1, 1);
                        break;
                    case(2):
                        Sorting(2, 1);
                        break;
                    case(3):
                        Sorting(3, 1);
                        break;
                    case(4):
                        Sorting(1, 2);
                        break;
                    case(5):
                        Sorting(2, 2);
                        break;
                    case(6):
                        Sorting(3, 2);
                        break;
                    case(0):

                        exit(1);
                    default:
                        printf("Please input correct value!");
                }
                break;
            case(2):
//у випадку обрання виміру часу сортування надається вибір між конкретними алгоритмами
                system("cls");

printf("\nChoose the mode(press '0' to exit):\n");
                printf("\n1. Selection Sort #8 algorithm time for array (#16)\n");
                printf("\n2.  Shell #2 algotithm time for array (#22)\n");
                printf("\n3. Selection Sort #1 algorithm time for array (#23)\n");
                printf("\n4. All algorithms time for array \n");
                printf("\n5. Selection Sort #8 algorithm time for vector (#16)\n");
                printf("\n6. Classic Shell #1 algotithm time for vector (#22)\n");
                printf("\n7. Selection Sort #1 algorithm time for vector (#23)\n");
                printf("\n8. All algorithms time for vector \n");
                scanf(" %d", &mode);
                switch (mode)
                {
                    case(1):
                        Time(1, 1);
                        break;
                    case(2):
                        Time(2, 1);
                        break;
                    case(3):
                        Time(3, 1);
                        break;
                    case(4):
                        Time(4, 1);
                        break;
                    case(5):
                        Time(1, 2);
                        break;
                    case(6):
                        Time(2, 2);
                        break;
                    case(7):
                        Time(3, 2);
                        break;
                    case(8):
                        Time(4, 2);
                        break;
                    case(0):
                        exit(1);
                    default:
                        printf("Please input correct value!");
                }
                break;
            case(0):
                exit(1);
            default:
                printf("Please input correct value!");
        }
        printf("\n\n\n Enter any key to continue...");
        scanf(" %с", &mode);

        system("cls");
    }
}
int main()
{
    menu();
}
