//  Serial Number : 51
//
//  Author : Johannes Schneemann

//  Due Date : 11/7/2018
//  Programming Assignment Number 6
//
//  Fall 2018 - CS 3358 - 002
//
//  Instructor: Husain Gholoom.
//
//  This program accepts a positive integer (n) from the keyboard,
//  creates an integer array of size n, and populates the array with random
//  generated integers between 1 - 1000. It then performs 7 individual
//  function calls in which the program sorts the array with various sorting algorithms.

#include <iostream>
#include <chrono>
#include <algorithm>
#include <thread>

using namespace std;

// display the program's functions
void display_actions();

// 1. display the first 20 elements
void display_array(int [], int);

// 2. use recursion to search for element
int sequential_search (int [], int n, int key);

// 3. bubble sort
int bubble_sort(int [], int SIZE, int count);

// 4. insertion sort
int insertion_sort(int [], int SIZE, int count);

// 5. quick sort with middle value as pivot value
int quick_sort_middle(int [], int left, int right, int SIZE, int count);

// 6. quick sort with first value as pivot value
int quick_sort_first(int [], int, int, int);
int partition_quick_sort_first(int [], int, int);

// 7. quick sort with last value as pivot value
int quick_sort_last(int [], int, int, int);
int partition_quick_sort_last(int [], int, int);

int main() {
    
    // random number seed
    srand(unsigned(time(NULL)));
    
    // display the program's functions
    display_actions();
    
    // get the array size from the user
    int SIZE;
    cout << "Enter the size of the array : ";
    cin >> SIZE;
    cout << "\n";

    // if array size is > 1, then execute functions 1 - 7
    // instruction don't specify this but since we compare algorithms,
    // the arrys need to be at least of size 2
    if(SIZE > 1) {
        
        // create an empty array of size n
        int original_array[SIZE];
    
        // populate an array with random numbers between 1 and 1000
        for(int i = 0; i < SIZE; i++) {
            original_array[i] = (rand() % 1000) + 1;
        }
        
        // 1. display the first 20 elements
        display_array(original_array, SIZE);
        
        // 2. use recursion to do sequential search for an element (search number: 125)
        // to keep the exact same array throughout the program
        // copy the original array into a new array for every function without using library functions
        int sequential_search_array[SIZE];
        for(int i = 0; i < SIZE; i++) {
            sequential_search_array[i] = original_array[i];
        }
        int KEY = 125;
        int n = 0;
        auto start2 = std::chrono::system_clock::now();
        int index = sequential_search(sequential_search_array, n, KEY);
        auto end2 = std::chrono::system_clock::now();
        std::time_t start_time2 = std::chrono::system_clock::to_time_t(start2);
        std::time_t end_time2 = std::chrono::system_clock::to_time_t(end2);
        std::chrono::duration<double> duration2 = end2 - start2;
        cout << "Sequential Search \n\n";
        cout << "Searching for " << KEY << " \n\n";
        if (index == -1) {
            cout << KEY << "  Was Not found.\n";
            cout << "Start Time :     " << std::ctime(&start_time2);
            cout << "End Time   :     " << std::ctime(&end_time2);
            cout << "Actual CPU Clock time :   " << fixed << duration2.count() << "s\n";
            cout << "Total Number of Comparisons :     " << SIZE * 2 << "\n\n\n";
        } else {
            cout <<  KEY << "   Was found at index: " << index << " \n";
            cout << "Start Time :     " << std::ctime(&start_time2);
            cout << "End Time   :     " << std::ctime(&end_time2);
            cout << "Actual CPU Clock time :   " << fixed << duration2.count() << "s\n\n";
            cout << "Total Number of Comparisons :     " << SIZE * 2 << "\n\n\n";
        }
        
        // 3. bubble sort
        // copy the original array into a new array for bubble sort
        int bubble_sort_counter = 0;
        int bubble_sort_array[SIZE];
        for(int i = 0; i < SIZE; i++) {
            bubble_sort_array[i] = original_array[i];
        }
        auto start3 = std::chrono::system_clock::now();
        int total_bubble_sort_swaps = bubble_sort(bubble_sort_array, SIZE, bubble_sort_counter);
        auto end3 = std::chrono::system_clock::now();
        std::time_t start_time3 = std::chrono::system_clock::to_time_t(start3);
        std::time_t end_time3 = std::chrono::system_clock::to_time_t(end3);
        std::chrono::duration<double> duration3 = end3 - start3;
        cout << "Start Time :     " << std::ctime(&start_time3);
        cout << "End Time   :     " << std::ctime(&end_time3);
        cout << "Actual CPU Clock time :   " << fixed << duration3.count() << "s\n";
        cout << "Total Number of Swaps :      " << total_bubble_sort_swaps << " \n\n\n";
        
        // 4. insertion sort
        // copy the original array into a new array for insertion sort
        int insertion_sort_counter = 0;
        int insertion_sort_array[SIZE];
        for(int i = 0; i < SIZE; i++) {
            insertion_sort_array[i] = original_array[i];
        }
        auto start4 = std::chrono::system_clock::now();
        int total_insertion_sort_swaps = insertion_sort(insertion_sort_array, SIZE, insertion_sort_counter);
        auto end4 = std::chrono::system_clock::now();
        std::time_t start_time4 = std::chrono::system_clock::to_time_t(start4);
        std::time_t end_time4 = std::chrono::system_clock::to_time_t(end4);
        std::chrono::duration<double> duration4 = end4 - start4;
        cout << "Start Time :     " << std::ctime(&start_time4);
        cout << "End Time   :     " << std::ctime(&end_time4);
        cout << "Actual CPU Clock time :   " << fixed << duration4.count() << "s\n";
        cout << "Total Number of Comparisons :     " << total_insertion_sort_swaps << " \n\n\n";
        
        // 5. quick sort with middle value as pivot value - I don't get this to work, so I used a previous function
        // copy the original array into a new array for quick sort with next to middle as pivot
        int left = 0;
        int right = 0;
        int quick_sort_middle_counter = 0;
        int quick_sort_middle_array[SIZE];
        for(int i = 0; i < SIZE; i++) {
            quick_sort_middle_array[i] = original_array[i];
        }
        auto start5 = std::chrono::system_clock::now();
        int total_quick_sort_middle_swaps = quick_sort_middle(quick_sort_middle_array, left, right, SIZE, quick_sort_middle_counter);
        auto end5 = std::chrono::system_clock::now();
        std::time_t start_time5 = std::chrono::system_clock::to_time_t(start5);
        std::time_t end_time5 = std::chrono::system_clock::to_time_t(end5);
        std::chrono::duration<double> duration5 = end5 - start5;
        cout << "Start Time :     " << std::ctime(&start_time5);
        cout << "End Time   :     " << std::ctime(&end_time5);
        cout << "Actual CPU Clock time :   " << fixed << duration5.count() << "s\n";
        cout << "Total Number of Recursive Calls :     " << total_quick_sort_middle_swaps << " \n\n\n";
        
       // display_array(quick_sort_middle_array, SIZE);
        
        // 6. quick sort with first value as pivot value
        // copy the original array into a new array for quick sort with first value as pivot
        int quick_sort_first_counter = 0;
        int quick_sort_first_array[SIZE];
        for(int i = 0; i < SIZE; i++) {
            quick_sort_first_array[i] = original_array[i];
        }
        auto start6 = std::chrono::system_clock::now();
        int total_quick_sort_first_swaps = quick_sort_first(quick_sort_first_array, 0, SIZE-1, quick_sort_first_counter);
        auto end6 = std::chrono::system_clock::now();
        std::time_t start_time6 = std::chrono::system_clock::to_time_t(start6);
        std::time_t end_time6 = std::chrono::system_clock::to_time_t(end6);
        std::chrono::duration<double> duration6 = end6 - start6;
        cout << "Quick Sort - First element as a pivot : \n\n";
        cout << "Start Time :     " << std::ctime(&start_time6);
        cout << "End Time   :     " << std::ctime(&end_time6);
        cout << "Actual CPU Clock time :   " << fixed << duration6.count() << "s\n";
        cout << "Total Number of Recursive Calls :     " << total_quick_sort_first_swaps << " \n\n\n";
        
        //display_array(quick_sort_first_array, SIZE);
        
        // 7. quick sort with last value as pivot value
        // copy the original array into a new array for quick sort with last value as pivot
        int quick_sort_last_counter = 0;
        int quick_sort_last_array[SIZE];
        for(int i = 0; i < SIZE; i++) {
            quick_sort_last_array[i] = original_array[i];
        }
        auto start7 = std::chrono::system_clock::now();
        int total_quick_sort_last_swaps = quick_sort_last(quick_sort_last_array, 0, SIZE-1, quick_sort_last_counter);
        auto end7 = std::chrono::system_clock::now();
        std::time_t start_time7 = std::chrono::system_clock::to_time_t(start7);
        std::time_t end_time7 = std::chrono::system_clock::to_time_t(end7);
        std::chrono::duration<double> duration7 = end7 - start7;
        cout << "Quick Sort - Last element as a pivot : \n\n";
        cout << "Start Time :     " << std::ctime(&start_time7);
        cout << "End Time   :     " << std::ctime(&end_time7);
        cout << "Actual CPU Clock time :   " << fixed << duration7.count() << "s\n";
        cout << "Total Number of Recursive Calls :     " << total_quick_sort_last_swaps << " \n\n\n";
        
        
        //display_array(quick_sort_last_array, SIZE);
        
    // if condition is false then display this message and terminate the program
    } else {
        cout << "***  Error -  The size of the array must be > 1   ***\n\n\n" << endl;
    }
    cout << "Benchmark Algorithm Implemented by: Johannes , Schneemann\n";
    cout << "12 / 7 / 2018 \n";
    return 0;
}

// This function displays the functions of the program
void display_actions() {
    cout << "Searching / Sorting Benchmark\n\n\n";
    cout << "Using a random number generator, we are creating an array of n\n";
    cout << "elements of type integer then performing the following   :\n\n";
    cout << "  1. Displaying the first 20 numbers.\n\n";
    cout << "  2. Using recursion, Searching for an element in the array using\n";
    cout << "     sequential search and at the end displaying number of comparisons\n";
    cout << "     it makes.\n\n";
    cout << "  3. Sort the original array using bubble Sort and at the end display\n";
    cout << "     the number of swaps it makes.\n\n";
    cout << "  4. Sorting the array using insertion Sort and at the end\n";
    cout << "     displaying the number of comparisons it makes.\n\n";
    cout << "  5. Sorting the array using Quick Sort and at the end displaying\n";
    cout << "     the number of recursion calls it makes. Using the next to the\n";
    cout << "     middle value as a pivot value.\n\n";
    cout << "  6. Sorting the same array using Quick Sort and at the end\n";
    cout << "     displaying the number of recursion calls it makes. Using the\n";
    cout << "     first value as a pivot value.\n\n";
    cout << "  7. Sorting the same array using Quick Sort and at the end\n";
    cout << "     displaying the number of recursion calls it makes. Using the\n";
    cout << "     last value as a pivot value.\n\n";
    cout << "  8. For each of the preceding steps ( 2 thru 5 ), calculating and\n";
    cout << "     printing the CPU time before each step starts and after each\n";
    cout << "     completed step then calculating actual CPU time for the\n";
    cout << "     completion of each step.\n\n\n";
}

// 1. display the first 20 elements if populated array is greater than 20
void display_array(int array[], int SIZE) {
    if(SIZE <= 20) {
        cout << "Array elements are: ";
        for (int n = 0; n < SIZE; n++)
            cout << array[n] << " ";
        cout << "\n\n";
    } else {
        cout << "Array elements are: ";
        for (int n = 0; n < 20; n++)
            cout << array[n] << " ";
        cout << "\n\n";
    }
}

// 2. use recursion to search for element 125
int sequential_search(int sequential_search_array[], int n, int KEY) {
    if(n < 0) {
        return -1;
    }
    if(sequential_search_array[n] == KEY) {
        return n;
    }
    return sequential_search(sequential_search_array, n - 1, KEY);
}

// 3. bubble sort algorithm
int bubble_sort(int bubble_sort_array[], int SIZE, int count) {
    int  temp;
    bool made_a_swap;
    int bubble_sort_swaps = 0;
    do {
        made_a_swap = false;
        for (int count = 0; count < (SIZE - 1); count++) {
            if (bubble_sort_array[count] > bubble_sort_array[count + 1]) {
                temp = bubble_sort_array[count];
                bubble_sort_array[count] = bubble_sort_array[count + 1];
                bubble_sort_array[count + 1] = temp;
                made_a_swap = true;
                bubble_sort_swaps++;
            }
        }
    } while (made_a_swap);
    cout << "Bubble Sort : \n\n";
    return bubble_sort_swaps;
}

// 4. insertion sort algorithm
int insertion_sort(int insertion_sort_array[], int SIZE, int count) {
    int insertion_sort_swaps = 0;
    for (int i = 1; i < SIZE; i++) {
        for (int j = i; j > 0 && insertion_sort_array[j - 1] > insertion_sort_array[j]; j--) {
            int tmp = insertion_sort_array[j];
            insertion_sort_array[j] = insertion_sort_array[j - 1];
            insertion_sort_array[j - 1] = tmp;
            insertion_sort_swaps++;
        }
    }
    cout << "Insertion Sort : \n\n";
    return insertion_sort_swaps;
}

// 5. quick sort with middle value as pivot value
int quick_sort_middle(int quick_sort_middle_array[], int left, int right, int SIZE, int count) {
    int i = left, j = right;
    int quick_sort_middle_swaps = 0;
    int tmp;
    int pivot = quick_sort_middle_array[(left + right) / 2];
    while (i <= j) {
        while (quick_sort_middle_array[i] < pivot)
            i++;
            quick_sort_middle_swaps++;
        while (quick_sort_middle_array[j] > pivot)
            j--;
            quick_sort_middle_swaps++;
        if (i <= j) {
            tmp = quick_sort_middle_array[i];
            quick_sort_middle_array[i] = quick_sort_middle_array[j];
            quick_sort_middle_array[j] = tmp;
            i++;
            j--;
            quick_sort_middle_swaps++;
        }
    };
    if (left < j)
        quick_sort_middle(quick_sort_middle_array, left, j, SIZE, count);
    if (i < right)
        quick_sort_middle(quick_sort_middle_array, i, right, SIZE, count);
    cout << "Quick Sort - Next to the middle element as a pivot : \n\n";
    return quick_sort_middle_swaps;
}

// 6. quick sort with first value as pivot value
int quick_sort_first(int quick_sort_first_array[], int start, int end, int count) {
    int quick_sort_first_swaps = 0;
    quick_sort_first_swaps++;
    if (start < end) {
        // Partition the array and get the pivot point
        int p = partition_quick_sort_first(quick_sort_first_array, start, end);
        
        // Sort the portion before the pivot point
        quick_sort_first_swaps++;
        quick_sort_first(quick_sort_first_array, start, p - 1, count);
        
        // Sort the portion after the pivot point
        quick_sort_first_swaps++;
        quick_sort_first(quick_sort_first_array, p + 1, end, count);
    }
    quick_sort_first_swaps++;
    return quick_sort_first_swaps;
}

// partition rearranges the entries in the array from start to end so all values greater than or equal to the
// pivot are on the right of the pivot and all values less than are on the left of the pivot.
int partition_quick_sort_first(int quick_sort_first_array[], int start, int end) {
    // The pivot element is taken to be the element at
    // the start of the subrange to be partitioned
    int pivotValue = quick_sort_first_array[start];
    int pivotPosition = start;
    // Rearrange the rest of the array elements to
    // partition the subrange from start to end
    for (int pos = start + 1; pos <= end; pos++){
         if (quick_sort_first_array[pos] < pivotValue) {
            // Swap the current item with the item to the
            // right of the pivot element
            swap(quick_sort_first_array[pivotPosition + 1], quick_sort_first_array[pos]);
            // Swap the current item with the pivot element
            swap(quick_sort_first_array[pivotPosition], quick_sort_first_array[pivotPosition + 1]);
            // Adjust the pivot position so it stays with the
            // pivot element
            pivotPosition ++;
        }
    }
    return pivotPosition;
}

// 7. quick sort with last value as pivot value
int quick_sort_last(int quick_sort_last_array[], int start, int end, int count) {
    int quick_sort_last_swaps = 0;
    quick_sort_last_swaps++;
    if (start < end) {
        // Partition the array and get the pivot point
        int p = partition_quick_sort_first(quick_sort_last_array, start, end);
        
        // Sort the portion before the pivot point
        quick_sort_last_swaps++;
        quick_sort_first(quick_sort_last_array, start, p - 1, count);
        
        // Sort the portion after the pivot point
          quick_sort_last_swaps++;
        quick_sort_first(quick_sort_last_array, p + 1, end, count);
    }
    quick_sort_last_swaps++;
    return quick_sort_last_swaps;
}

// partition rearranges the entries in the array arr from start to end so all values greater than or equal to the
// pivot are on the right of the pivot and all values less than are on the left of the pivot.
int partition_quick_sort_last(int quick_sort_last_array[], int start, int end) {
    // The pivot element is taken to be the element at
    // the start of the subrange to be partitioned
    int pivotValue = quick_sort_last_array[end];
    int pivotPosition = end;
    // Rearrange the rest of the array elements to
    // partition the subrange from start to end
    for (int pos = start + 1; pos <= end; pos++) {
        if (quick_sort_last_array[pos] < pivotValue) {
            // arr[scan] is the "current" item.
            // Swap the current item with the item to the
            // right of the pivot element
            swap(quick_sort_last_array[pivotPosition + 1], quick_sort_last_array[pos]);
            // Swap the current item with the pivot element
            swap(quick_sort_last_array[pivotPosition], quick_sort_last_array[pivotPosition + 1]);
            // Adjust the pivot position so it stays with the
            // pivot element
            pivotPosition ++;
        }
    }
    return pivotPosition;
}
