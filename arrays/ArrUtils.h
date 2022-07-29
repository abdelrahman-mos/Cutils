#ifndef ARRUTILS_H
#define ARRUTILS_H

/*!
 * @param arr input array
 * @param len length of input array
 * @return A copy of input array
*/
int* copy(const int* arr, int len);

/*!
 * @param arr1 first array
 * @param len1 length of first array
 * @param arr2 second array
 * @param len2 length of second array
 * @return An array which contains arr1 concatenated to arr2
*/
int* concat(const int* arr1, int len1, const int* arr2, int len2);

/*!
 * @param arr array to be spliced
 * @param index index from which we cut the array
 * @param len length of input array
 * @param outlen length of output array
 * @return The array that was spliced
*/
int* splice(int* arr, int index, int len, int* outlen);

/*!
 * @param arr array to be reversed
 * @param len length of input array
 * @brief reverses an array
*/
void reverse(int* arr, int len);

#endif // !ARRUTILS_H