/*
Please finish the function allocArray

This function will allocate a 2-D array with size m * n, then point the array using pointer p.

void allocArray(int ***p, int m, int n)
{
}

int main()
{
  int **array, *a;
  int j, k;
  allocArray(&array, 5, 10);
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      array[j][k] = j * 10 + k;
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      printf("%p ", &(array[j][k]));
}

如果你能成功的配置一個二維陣列，你就能得到80分

如果你能配置出連續的空間，你就可以得到100分

You will get 80 point if you can successfully allocate a 2-D array.

You will get 100 point if you can allocate consecutive memory for this 2-D array.

這題的期限到 2021/10/12

This assignment due to 2021/10/12
*/
#include <iostream>

void allocArray(int ***p, int m, int n)
{   
    int *q = new int[m*n];
    *p = new int*[m];
    for(int i=0; i<m; i++){
        (*p)[i] = &q[i*n];
    }
}

int main()
{
  int **array, *a;
  int j, k;
  allocArray(&array, 5, 10);
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      array[j][k] = j * 10 + k;
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      printf("%p ", &(array[j][k]));
      
    return 0;
}