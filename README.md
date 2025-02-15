# Pascal-s-Triangle

# The Pascal's Triangle Code

This C++ program generates Pascal's Triangle using recursion. Let’s break down each part of the code in detail.

## 1️⃣ Understanding Pascal's Triangle

Pascal’s Triangle is a triangular arrangement of numbers with the following properties:
- The first and last elements of each row are always 1.
- Each middle element is the sum of the two elements directly above it.

### Example for N = 5:

```
     1  
    1 1  
   1 2 1  
  1 3 3 1  
 1 4 6 4 1  
```

Each number is computed as:
```
new_arr[i] = arr[i] + arr[i + 1]
```
This represents the sum of two adjacent numbers from the previous row.

## 2️⃣ Code Walkthrough

### 🔹 Header Files and Namespace

```cpp
#include <iostream>
#include <vector>
using namespace std;
```
- `#include <iostream>` → Allows input/output operations.
- `#include <vector>` → We use `vector<int>` to store and manipulate each row.
- `using namespace std;` → This allows us to omit the `std::` prefix before `cout`, `cin`, etc.

### 🔹 Recursive Function: `pascalsTriangle`

```cpp
void pascalsTriangle(int N, int n, vector<int> arr) {
```
- `N` → The total number of rows to print.
- `n` → The current row number.
- `arr` → A `vector<int>` storing the numbers in the current row.

### 🔹 Base Case (Stopping Condition)

```cpp
if (N == n) {
    return;
}
```
This condition stops the recursion when `n` equals `N`, indicating that we have printed the required number of rows. If this condition is met, the function exits without further recursion.

### 🔹 Printing the Current Row

```cpp
for (int i : arr) {
    cout << i << " ";
}
cout << endl;
```
This loop iterates over the `arr` vector and prints each number, with `cout << endl;` moving to the next line for the subsequent row.

### 🔹 Generating the Next Row

```cpp
vector<int> new_arr = {1}; // The first element is always 1
```
Each row starts with 1, so we initialize `new_arr` with `{1}`.

#### 🔸 Generating the Middle Elements

```cpp
for (int i = 0; i < size - 1; i++) {
    new_arr.push_back(arr[i] + arr[i + 1]); // Sum of two adjacent elements
}
```
This loop runs from `0` to `size - 2` to compute the middle elements, adding adjacent numbers from the previous row (`arr`) and storing the results in `new_arr`.

### Example Calculation:
For the row `{1, 2, 1}`, the next row’s middle elements are calculated as follows:
```
1 + 2 = 3  
2 + 1 = 3  
```
This results in the new row: `{1, 3, 3, 1}`.

#### 🔸 Adding the Last Element

```cpp
new_arr.push_back(1); // The last element is always 1
```
The last element of each row is always 1, so we append 1 to `new_arr`.

### 🔹 Recursive Call

```cpp
pascalsTriangle(N, n + 1, new_arr);
```
This line calls `pascalsTriangle()` with the next row (`new_arr`) and increments `n` by 1. It recursively prints all rows until `N` rows are generated.

## 3️⃣ Main Function

```cpp
int main() {
    int N;
    
    cin >> N; // Read the number of rows from user input
    
    pascalsTriangle(N, 0, {1}); // Start recursion with the first row {1}
}
```
Here, we read `N` from the user for the number of rows and call `pascalsTriangle()` with the initial row `{1}` to start the recursion.

## 4️⃣ Example Walkthrough

Let’s assume `N = 5`. The recursion proceeds as follows:

| n (row index) | arr (Current Row)   | Recursive Call (Next Row) |
|---------------|----------------------|----------------------------|
| 0             | {1}                  | {1, 1}                     |
| 1             | {1, 1}               | {1, 2, 1}                  |
| 2             | {1, 2, 1}            | {1, 3, 3, 1}               |
| 3             | {1, 3, 3, 1}         | {1, 4, 6, 4, 1}            |
| 4             | {1, 4, 6, 4, 1}      | Stops (Base Case)          |

## 5️⃣ Complexity Analysis

- **Time Complexity:** O(N²)  
Each row generation requires looping over the previous row (O(N) operations per row). With `N` rows, the total complexity is O(N²).

- **Space Complexity:** O(N²)  
Each row is stored in a `vector<int>`, which means the total space used is proportional to the total number of elements (approximately N²).

## 6️⃣ Summary

- The program recursively generates Pascal’s Triangle.
- Each row starts and ends with 1, with middle elements calculated from the previous row.
- The recursion halts when all `N` rows are printed.
- The algorithm utilizes O(N²) time and space due to row storage and the calculations involved.

This program offers a straightforward, elegant, and recursive approach to generating Pascal’s Triangle!
