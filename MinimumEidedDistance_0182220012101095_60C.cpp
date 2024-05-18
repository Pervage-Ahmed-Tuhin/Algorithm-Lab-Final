#include<bits/stdc++.h>
using namespace std;

// this is the function to calculate the minimum edit distance between two strings
int Min_Edit_Distance(string s1, string s2, int n, int m) {
    // Created a 2D array to store the edit distances
    int EDIT_DISTANCE[n + 1][m + 1];

    // Initializing the first row and column of the array
    for (int i = 0; i <= n; i++) {
        EDIT_DISTANCE[i][0] = i; // Filling the first column with values from 0 to n
    }
    for (int j = 0; j <= m; j++) {
        EDIT_DISTANCE[0][j] = j; // Filling the first row with values from 0 to m
    }

    // Calculating the edit distances for each cell of the array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                EDIT_DISTANCE[i][j] = EDIT_DISTANCE[i - 1][j - 1]; // If characters are equal, no edit needed
            } else {
                // else take the minimum of three operations: insertion, deletion, and substitution
                EDIT_DISTANCE[i][j] = 1 + min(EDIT_DISTANCE[i - 1][j], min(EDIT_DISTANCE[i - 1][j - 1], EDIT_DISTANCE[i][j - 1]));
            }
        }
    }

    // Backtrack to find the sequence of operations
    int i = n;
    int j = m;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            i--;
            j--;
        } else {
            // Determining the operation with the minimum edit distance and update i and j accordingly
            if (EDIT_DISTANCE[i - 1][j] <= EDIT_DISTANCE[i - 1][j - 1] && EDIT_DISTANCE[i - 1][j] <= EDIT_DISTANCE[i][j - 1]) {
                cout << s1[i - 1] << " removed from string 1" << endl;
                i--;
            } else if (EDIT_DISTANCE[i - 1][j - 1] <= EDIT_DISTANCE[i - 1][j] && EDIT_DISTANCE[i - 1][j - 1] <= EDIT_DISTANCE[i][j - 1]) {
                cout << "string 1's " << s1[i - 1] << " is replaced with " << s2[j - 1] << endl;
                i--;
                j--;
            } else {
                cout << s2[j - 1] << " inserted into string 1" << endl;
                j--;
            }
        }
    }

    // Return the minimum edit distance
    return EDIT_DISTANCE[n][m];
}

int main() {
    string str1 = "abcdef";
    string str2 = "ayced";

    int n = str1.size();
    int m = str2.size();

    // Calling the Min_Edit_Distance function and store the result
    int result = Min_Edit_Distance(str1, str2, n, m);

    // Printing the minimum edit distance
    cout << "Minimum Edit Distance = " << result << endl;

    return 0;
}

