#include <time.h>
#include <string.h>
#include <iostream>
#include <algorithm>

typedef unsigned long int ul_int;

////////////////////////////////////////////////////////////////////////////////
// QuickSort functions
////////////////////////////////////////////////////////////////////////////////
ul_int partition(ul_int *A, ul_int lo, ul_int hi) {
    ul_int left, right;
    ul_int pivot;
    pivot = A[lo];
    pivot = left = lo;
    right = hi;
    while(left<right){
        while (A[left] <= pivot) left++;
        while (A[right] > pivot) right--;
        if(left<right){
            ul_int temp = A[left];
            A[left] = A[right];
            A[right] = temp;
        }
    }
    A[lo] = A[right];
    A[right] = pivot;
    return right;
}

void r_quicksort(ul_int *A, ul_int lo, ul_int hi) {
    if (hi <= lo) return;
    ul_int p = partition(A, lo, hi);
    // avoid negative indices because indices are unsigned int
    if (p > 0) r_quicksort(A, lo, p-1);
    r_quicksort(A, p+1, hi);
}

void quicksort(ul_int *A, ul_int n) {
    // shuffle the array
    std::random_shuffle(A, A+n);
    // call recursive quicksort
    r_quicksort(A, 0, n-1);
}

////////////////////////////////////////////////////////////////////////////////
// HeapSort functions
////////////////////////////////////////////////////////////////////////////////
void downheap(ul_int *A, ul_int n, ul_int i) {
    ul_int largest = i;
    ul_int left = 2 * i + 1;
    ul_int right = 2 * i + 2;
    if (left < n && A[left] > A[largest]) largest = left;
    if (right < n && A[right] > A[largest]) largest = right;
    if (largest != i) {
        std::swap(A[i], A[largest]);
        downheap(A, n, largest);
    }
}

void buildheap(ul_int *A, ul_int n) {
    for (long int i = n/2-1 ; i >= 0 ; i--)
        downheap(A, n, i);
}

// array A contains the elements to be sorted from index 0 to index n-1
void heapsort(ul_int *A, ul_int n) {
    // apply buildheap to input array A
    buildheap(A, n);
    // sorting begins
    for (long int i = n-1 ; i >= 0 ; i--) {
        std::swap(A[0], A[i]);
        downheap(A, i, 0);
    }
}

////////////////////////////////////////////////////////////////////////////////
// Quadratic algorithms
////////////////////////////////////////////////////////////////////////////////
void insertionsort(ul_int *A, ul_int n) {
    ul_int temp, i, j;
    // grows the left part (sorted)
    for (i = 0 ; i < n ; i ++) {
        temp = A[i];
        // inserts A[j] into the right place in sorted part
        for (j = i ; j > 0 && A[j-1] > temp ; j --) {
            A[j] = A[j-1];
        }
        A[j] = temp;
    }
}

void selectionsort(ul_int *A, ul_int n) {
    ul_int i, j, min, temp;
    // grows the left part (sorted)
    for (i = 0 ; i < n ; i ++) {
        min = i;
        // find min in unsorted part
        for (j = i+1 ; j < n ; j ++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        // swap A[i] and A[min]
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

////////////////////////////////////////////////////////////////////////////////
// Auxiliary functions
////////////////////////////////////////////////////////////////////////////////
void time_func(void (*f_ptr)(ul_int *, ul_int), ul_int *array, ul_int n, const char *name) {
    clock_t tic = clock();
    // run the sorting algorithm using a function pointer
    (*f_ptr)(array, n);
    clock_t toc = clock();

    // print the running time of the algorithm
    printf("%s:\t%f seconds\n", name, (double)(toc-tic)/CLOCKS_PER_SEC);
}

int is_sorted(ul_int *A, ul_int n) {
    ul_int *B = new ul_int[n];
    for (ul_int i = 0 ; i < n ; i ++)
        B[i] = A[i];
    std::sort(B, B+n);
    for (ul_int i = 0 ; i < n ; i ++)
        if (A[i] != B[i])
            return 0;
    delete [] B;
    return 1;
}

void print_array(ul_int *array, char *name, int n) {
    std::cout << name << ": ";
    for (int i = 0 ; i < n ; i ++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

////////////////////////////////////////////////////////////////////////////////
// Main function
////////////////////////////////////////////////////////////////////////////////
int main() {
    // number of algorithms to test
    const int n_algo = 4;
    // array of function names
    const char * fun_names[n_algo] = {"InsertionSort", "SelectionSort", "HeapSort", "QuickSort"};
    // array of pointers to functions
    void (*fun_ptrs[n_algo])(ul_int *, ul_int) = {&insertionsort, &selectionsort, &heapsort, &quicksort};

    // read first number from standard input
    ul_int n, i;
    std::cin >> n;

    // allocate space for array
    ul_int *array = new ul_int[n];
    // allocate space for saving a copy of the array
    ul_int *arr_copy = new ul_int[n];

    // read the sequence
    std::cout << "Reading input sequence of size " << n << " ...\n";
    for (i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    // apply ALL sorting algorithms
    std::cout << "Applying sorting algorithms ...\n";
    for (int i = 0 ; i < n_algo ; i ++) {
        // make a copy
        memcpy(arr_copy, array, n*sizeof(ul_int));
        // apply algorithm and measure time
        time_func(fun_ptrs[i], arr_copy, n, fun_names[i]);
        // this step should be unnecessary but perhaps we want to check for correctness ...
        if (! is_sorted(arr_copy,n)) std::cout << "Incorrect !!!\n";
    }

    // free memory
    delete [] array;
    delete [] arr_copy;
}