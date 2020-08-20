/*
 * Complete the 'sortBinaryNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY bitArrays as parameter.
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */

/* Sort bitArrays and return a array containing possitions of original index after sorting
 * bitArrays is a 2d array where each row represents a number and has positions of the set bits of that number
 * 
 * Example
 * 
 * Input              || Not in Input/Output Just for Explaination
 * 3 2
 * 0 2                -- Represents 5
 * 1 0                -- Represents 3
 * 2 1                -- Represents 6
 * 
 * Output
 * 1 0 2              Positions of rows after sorting
 */

int **gbitArrays, gr;
int cmp_int(const void* p1, const void* p2) {
    int x = *(const int *) p1;
    int y = *(const int *) p2;
    return x - y;
}
int cmp_r(const void* p1, const void* p2) {
    int i = *(const int *) p1;
    int j = *(const int *) p2;
    // printf("%d %d %d\n", i, j, gr);
    return gbitArrays[j][gr] - gbitArrays[i][gr];
    // return j - i;
}
int* sortBinaryNumbers(int bitArrays_rows, int bitArrays_columns, int** bitArrays, int* result_count) {
    gbitArrays = bitArrays;
    int* index_array = malloc(bitArrays_rows * sizeof(int));
    *result_count = bitArrays_rows;
    for(int i = 0; i < bitArrays_rows; i++) {
        index_array[i] = i;
        qsort((void*)bitArrays[i], bitArrays_columns, 4, cmp_int);
    }
    for(int r = 0; r < bitArrays_columns; r++) {
        gr = r;
        qsort((void*)index_array, bitArrays_rows, 4, cmp_r);
    }
    return index_array;
}