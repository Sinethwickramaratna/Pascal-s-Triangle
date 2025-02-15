#include <iostream>
#include <vector>

using namespace std;

// Recursive function to generate Pascal's Triangle
void pascalsTriangle(int N, int n, vector<int> arr) {
    int size = arr.size(); // Get the size of the current row

    // Base case: Stop recursion when N rows have been printed
    if (N == n) {
        return;
    }

    // Print the current row
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    // Generate the next row of Pascal's Triangle
    vector<int> new_arr = {1}; // First element is always 1

    // Compute the intermediate elements of the next row
    for (int i = 0; i < size - 1; i++) {
        new_arr.push_back(arr[i] + arr[i + 1]); // Sum adjacent elements
    }

    new_arr.push_back(1); // Last element is always 1

    // Recursive call with the new row
    pascalsTriangle(N, n + 1, new_arr);
}

int main() {
    int N; // Variable to store the number of rows

    cin >> N; // Take input from the user

    // Start the recursion with the first row containing only '1'
    pascalsTriangle(N, 0, {1});
}
