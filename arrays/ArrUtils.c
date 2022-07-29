#include <stdlib.h>
#include "ArrUtils.h"

int* copy(const int* arr, int len)
{
    int* res = (int*)calloc(len, sizeof(int));
    int i;
    for (i = 0; i < len; i++)
        res[i] = arr[i];
    return res;
}

int* concat(const int* arr1, int len1, const int* arr2, int len2)
{
    int* res = (int*)calloc(len1+len2, sizeof(int));
    int i;
    for (i = 0; i < len1; i++)
        res[i] = arr1[i];
    for (;i < len1 + len2; i++)
        res[i] = arr2[i-len1];

    return res;
}

int* splice(int* arr, int index, int len, int* outlen)
{
    int i;
    *outlen = len - index;
    int* res = (int*)calloc(*outlen, sizeof(int));
    int* tmp = (int*)calloc(index+1, sizeof(int));

    for (i = index; i < len; i++) 
        res[i-index] = arr[i];
    for (i = 0; i < index+1; i++)
        tmp[i] = arr[i];
    
    free(arr);
    arr = tmp;
    return res;
}

void reverse(int* arr, int len)
{
    int i, j, temp;
    for (i = 0, j = len-1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
