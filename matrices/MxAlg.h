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
 * @brief mat1 and mat2 must be of same size
 * @return Matrix addition of mat1 + mat2
*/
Matrix* addMat(Matrix* mat1, Matrix* mat2);

/*!
 * @param mat1 pointer to matrix to subtract from
 * @param mat2 pointer to matrix to subtract
 * @brief mat1 and mat2 must be of same size
 * @return mat1 - mat2
*/
Matrix* subMat(Matrix* mat1, Matrix* mat2);

/*!
 * @param mat1 pointer to matrix to be multiplied
 * @param mat2 pointer to matrix to be multiplied
 * @brief if mat1 is of size n*m, then mat2 must be of size m*y, where n and y can be any numbers, but inner dimensions must equal
 * @return multiplication of mat1*mat2
*/
Matrix* mulMat(Matrix* mat1, Matrix* mat2);

/*!
 * @param matrix pointer to matrix that we need to transpose
 * @return the transpose of the input matrix
*/
Matrix* transMat(Matrix* matrix);

/*!
 * @param matrix pointer to matrix to which we want to calculate the determinant
 * @brief Calculates the determinant of any n*n matrix (dimensions must match)
 * @return The determinant of the input matrix
*/
double detMat(Matrix* matrix);

#endif // MXALG_H