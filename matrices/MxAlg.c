#include <stdio.h>
#include <stdlib.h>
#include "MxAlg.h"

// These functions can be used in many applications one of them is ML

Matrix* addMat(Matrix* mat1, Matrix* mat2)
{
    int r, c;
    Matrix* ResMat;
    if (mat1->nRows != mat2->nRows || mat1->nCols != mat2->nCols)
    {
        printf("Matrix error, dmatrices imensions must match!"); exit(0);
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

Matrix* mulMat(Matrix* mat1, Matrix* mat2)
{
    int r, c, i;    // rows, columns, and iterate to multiply
    Matrix* ResMat;

    if (mat1->nCols != mat2->nRows)
    {
        printf("Matrix error, inner matrices dimensions must equal!");
        exit(0);
    }

    ResMat = createMatrix(mat1->nRows, mat2->nCols, MFT_ZEROS);
    // n*m x m*z outputs a matrix of size n*z, we fill it with zeros to make it easier for the multiplication process
    
    for (r = 0; r < ResMat->nRows; r++)
        for (c = 0; c < ResMat->nCols; c++)
            for (i = 0; i < mat1->nCols; i++)
                ResMat->pValues[r][c] +=
                    mat1->pValues[r][i] * mat2->pValues[i][c];

    return ResMat;
}

Matrix* transMat(Matrix* matrix)
{
    int r, c;
    Matrix* ResMat;
    ResMat = createMatrix(matrix->nRows, matrix->nCols, MFT_NONE);
    for (r = 0; r < ResMat->nRows; r++)
        for (c = 0; c < ResMat->nCols; c++)
            ResMat->pValues[r][c] = matrix->pValues[c][r];  // reverse column with row
    return ResMat;
}
