#include <stdio.h>
#include <stdlib.h>
#include "MxAlg.h"

Matrix* createMatrix(int nRows, int nCols, MatFillType fillType) {
    int r, c; // row, column
    Matrix* ResMat; // result matrix
    ResMat = (Matrix*)malloc(sizeof(Matrix));
    ResMat->nCols = nCols;
    ResMat->nRows = nRows;
    ResMat->pValues = (double**)calloc(nRows, sizeof(double*)); // allocating memory for the matrix
    for (r = 0; r < nRows; r++)
        ResMat->pValues[r] = (double*)calloc(nCols, sizeof(double)); // allocating memory for each element in the array
    
    if (fillType != MFT_NONE) // we fill the array woth fill type
    {
        for (r = 0; r < nRows; r++) 
        {
            for (c = 0; c < nCols; c++)
            {
                switch (fillType)
                {
                case MFT_ZEROS: // fill with zeros
                    ResMat->pValues[r][c] = 0;
                    break;
                case MFT_ONES:  // fill with ones
                    ResMat->pValues[r][c] = 1;
                    break;
                case MFT_RAND:  // fill with a random number
                    ResMat->pValues[r][c] = (rand()%100)/100.0; // random number bet 0 and 1
                    break;
                case MFT_IDENTITY: // fill identity
                    ResMat->pValues[r][c] = (r == c) ? 1 : 0;   // 1 if r == c, 0 else
                    break;
                default:
                    return ResMat;
                }
            }
        }
    }
    return ResMat;
}

void destroyMatrix(Matrix* matrix) 
{
    int r;
    for (r = 0; r < matrix->nRows; r++) 
        free(matrix->pValues[r]);       // free each row
    free(matrix->pValues);              // free the matrix
    free(matrix);                       // free the struct
}

void printMatrix(Matrix* matrix)
{
    int r, c;
    for (r = 0; r < matrix->nRows; r++) 
    {
        for (c = 0; c < matrix->nCols; c++) 
        {
            printf("%5.2lf\t", matrix->pValues[r][c]);
        }
        printf("\n");
    }
}

Matrix* addMat(Matrix* mat1, Matrix* mat2)
{
    int r, c;
    Matrix* ResMat;
    if (mat1->nRows != mat2->nRows || mat1->nCols != mat2->nCols)
    {
        printf("Matrix error!"); exit(0);
    }

    ResMat = createMatrix(mat1->nRows, mat1->nCols, MFT_NONE);  // create ResMat and leave it unfilled

    for (r = 0; r < ResMat->nRows; r++)
        for (c = 0; c < ResMat->nCols; c++)
            ResMat->pValues[r][c] = mat1->pValues[r][c] + mat2->pValues[r][c];
    
    return ResMat;
}

Matrix* subMat(Matrix* mat1, Matrix* mat2)
{
    int r, c;
    Matrix* ResMat;
    if (mat1->nRows != mat2->nRows || mat1->nCols != mat2->nCols)
    {
        printf("Matrix error!"); exit(0);
    }

    ResMat = createMatrix(mat1->nRows, mat1->nCols, MFT_NONE);  // create ResMat and leave it unfilled

    for (r = 0; r < ResMat->nRows; r++)
        for (c = 0; c < ResMat->nCols; c++)
            ResMat->pValues[r][c] = mat1->pValues[r][c] - mat2->pValues[r][c];
    
    return ResMat;
}
