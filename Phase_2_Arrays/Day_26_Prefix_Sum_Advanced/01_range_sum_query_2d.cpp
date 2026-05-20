/*
PROBLEM: Range Sum Query 2D - Immutable
Return sum of rectangle defined by two coordinates.

Example: matrix = [[1,2],[3,4]], sum(0,0,1,1) = 10

KEY INSIGHT:
- Use 2D prefix sum array
- inclusion-exclusion: add opposite corners, subtract overlaps
- Formula: sum = prefix[r2+1][c2+1] - prefix[r1][c2+1] 
                 - prefix[r2+1][c1] + prefix[r1][c1]
*/

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> prefix;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        prefix.assign(m + 1, vector<int>(n + 1, 0));
        
        // Build 2D prefix sum (1-indexed)
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] 
                               - prefix[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2+1][col2+1] - prefix[row1][col2+1] 
               - prefix[row2+1][col1] + prefix[row1][col1];
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    NumMatrix nm(matrix);
    
    cout << "Sum [0,0] to [1,1]: " << nm.sumRegion(0, 0, 1, 1) << " (expected 12: 1+2+4+5)\n";
    cout << "Sum [1,1] to [2,2]: " << nm.sumRegion(1, 1, 2, 2) << " (expected 28: 5+6+8+9)\n";
    cout << "Sum [0,0] to [2,2]: " << nm.sumRegion(0, 0, 2, 2) << " (expected 45: all)\n";
    
    return 0;
}

/*
TIME: Build O(m*n), Query O(1)
SPACE: O(m*n)

FORMULA VISUALIZATION:
    col1  col2
row1  +     -
row2  -     +

Inclusion-Exclusion:
- Start with bottom-right: prefix[r2+1][c2+1]
- Subtract top-right: prefix[r1][c2+1]
- Subtract bottom-left: prefix[r2+1][c1]
- Add top-left (was subtracted twice): prefix[r1][c1]
*/
