#include <stdio.h>
#include <stdlib.h>
#include "MxAlg.h"

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
