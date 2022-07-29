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