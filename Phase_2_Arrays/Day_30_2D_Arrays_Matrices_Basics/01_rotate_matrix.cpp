/*
PROBLEM: Rotate Matrix 90 Degrees
Rotate n x n matrix 90 degrees clockwise in-place.

Example: [[1,2,3],[4,5,6],[7,8,9]] -> [[7,4,1],[8,5,2],[9,6,3]]

KEY INSIGHT:
- Transpose matrix (swap matrix[i][j] with matrix[j][i])
- Reverse each row
- Alternative: Rotate layer by layer
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Step 1: Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);
    
    cout << "Rotated matrix:\n";
    for (auto& row : matrix) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}

/*
TIME: O(n^2)
SPACE: O(1)

DRY RUN:
Original:        Transpose:       Reverse rows:
1 2 3            1 4 7            7 4 1
4 5 6     ->     2 5 8      ->    8 5 2
7 8 9            3 6 9            9 6 3
*/
