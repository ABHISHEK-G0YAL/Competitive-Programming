You must have staticaly allocated the 3d array. You need to dynamically allocate it.
Many people don't understand the pointer arithmatic in static and dynamic array. A static array is always only a single integer pointer whether you make it 2d or 3d or 1d it doesnt matter. It always allocates a single continuous piece of memory and dereferences it according to the indexes.
While a dynamic array is triple pointer to integer if 3d, double if 2d and single if 1d array. it allocates 1d chunks of memory and stores there pointers is arrays.
```
    //  static array
    int arr[X][Y][Z];     //  creates a single continuous array of size X x Y x Z.
    cout << arr[2][3][5] << endl;    //  equivalent to cout << *(arr + (2 * X + 3 * Y + Z)) << endl;
    //  Notice how its dereferenced only once. Also this is the reason Functions need to know the first n - 1 
    //  dimensions of a n-d array beacuse they need this information in dereferencing it.
    
    // dynamic array
    int ***arr = new int **[X];
    for(int i = 0; i < X; i++) {
        arr[i] = new int *[Y];
        for(int j = 0; j < Y; j++) {
            arr[i][j] = new int[Z];
        }
    }
    cout << arr[2][3][5] << endl;    //  equivalent to cout << *((*((*(arr + 2)) + 3)) + 5) << endl;
    //  Notice how its dereferenced 3 times. Also this is the reason Functions doesn't need to know the first n - 1 
    //  dimensions of a dynamic array beacuse they don't need this information in dereferencing it.
```