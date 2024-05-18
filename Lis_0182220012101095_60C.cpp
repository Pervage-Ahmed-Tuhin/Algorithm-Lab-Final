#include<bits/stdc++.h>
using namespace std;

// Defined a custom structure to store information about each element of the array
typedef struct lis {
    int input;      // Value of the element
    int length;     // Length of the LIS ending at this element
    int previous;   // Index of the previous element in the LIS
} custom_type;

// Function to calculate the Longest Increasing Subsequence (LIS) and print it
int LIS(int a[], int n) {
    // Create an array of custom_type to store information about each element
    custom_type Arr[n];

    // Initialize the array of custom_type
    for(int i = 0 ; i < n ; i++) {
        Arr[i].input = a[i];
        Arr[i].length = 1;
        Arr[i].previous = -1; // Initialize previous index as -1
    }

    // this is the main loop that does the main functionality
    for(int i = 1 ; i < n ; i++) {
        for(int j = 0 ; j < i ; j++) {
            // Compare each pair of elements to find the LIS
            if(Arr[i].input > Arr[j].input) {
                // Update the length of LIS if the current element can extend the LIS ending at the previous element
                Arr[i].length = max(Arr[i].length, (1 + Arr[j].length) );
                // Update the previous index if the length of the current LIS is extended
                if(Arr[i].length <= (Arr[j].length + 1)) {
                    Arr[i].previous = j;
                }
            }
        }
    }

    // Finding the maximum length of LIS and its position
    int Max_length = Arr[0].length;
    int Max_position = 0;
    for(int i = 0 ; i < n ; i++) {
        if(Arr[i].length > Max_length) {
            Max_length = Arr[i].length;
            Max_position = i;
        }
    }

    // Backtracking to construct the LIS
    int Lis[Max_length];
    int k  = Max_length - 1;
    int index = Max_position;
    while(index >= 0) {
        Lis[k] = Arr[index].input;
        k--;
        index = Arr[index].previous;
    }

    // Print the LIS
    cout << "LIS is = ";
    for(int i = 0 ; i < Max_length ; i++) {
        cout << Lis[i] << " ";
    }
    cout << endl;

    // Return the length of the LIS
    return Max_length;
}


int main() {
    // Defining an array and its size
    int n = 10;
    int arr[100] = {9 , 2 , 5 , 3 , 7 , 11 , 8 , 10 , 13 , 6};

    // Calling the LIS function to find the length of the LIS
    int result = LIS(arr, n);

    // Printing the length of the LIS
    cout << "LIS length is = " << result << endl;

    return 0;
}

