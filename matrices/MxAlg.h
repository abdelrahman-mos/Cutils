#ifndef MXALG_H
#define MXALG_H

// matrix struct

typedef struct __MATRIX
{
    double** pValues;
    int nRows;
    int nCols;
} Matrix;

// fill type to initialize the matrix
typedef enum __MATFILL {MFT_NONE, MFT_ZEROS, MFT_ONES, MFT_RAND, MFT_IDENTITY} MatFillType;

/*!
 * @param nRows number of rows
 * @param nCols number of columns
 * @param fillType Fill type of the matrix
 * @return A matrix filled with fillType
*/
Matrix* createMatrix(int nRows, int nCols, MatFillType fillType);

/*!
 * @param matrix pointer to matrix to destroy
 * @brief frees memory taken by matrix
*/
void destroyMatrix(Matrix* matrix);

/*!
 * @param matrix Pointer to matrix to print
 * @brief Prints matrix
*/
void printMatrix(Matrix* matrix);

/*!
 * @param mat1 pointer to matrix to add
 * @param mat2 pointer to matrix to add 
 * @return Matrix addition of mat1 + mat2
*/
Matrix* addMat(Matrix* mat1, Matrix* mat2);

/*!
 * @param mat1 pointer to matrix to subtract from
 * @param mat2 pointer to matrix to subtract
 * @return mat1 - mat2
 * @
*/
Matrix* subMat(Matrix* mat1, Matrix* mat2);

#endif // MXALG_H