/*
 * Complete the 'partitionArray' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY numbers
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */

// partion array into K subsets of equal lengths such that no subeset contains same numbers

char* partitionArray(int k, int numbers_count, int* numbers) {
    if(numbers_count % k != 0)
        return "No";
    int cnt_n[100005] = {};
    for(int i = 0; i < numbers_count; i++) {
        ++cnt_n[numbers[i]];
        if(cnt_n[numbers[i]] > numbers_count / k)
            return "No";
    }
    return "Yes";
}