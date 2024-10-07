#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int element = 0;
    int totalElement = matrix.size() * matrix[0].size();

    int startingRow = 0;
    int endingCol = matrix[0].size() - 1;
    int endingRow = matrix.size() - 1;
    int startingCol = 0;

    while (element < totalElement) {
        // Traverse from left to right across the top row
        for (int i = startingRow; i <= endingCol && element < totalElement; i++) {
            ans.push_back(matrix[startingRow][i]);
            element++;
        }
        startingRow++;

        // Traverse from top to bottom along the rightmost column
        for (int i = startingRow; i <= endingRow && element < totalElement; i++) {
            ans.push_back(matrix[i][endingCol]);
            element++;
        }
        endingCol--;

        // Traverse from right to left across the bottom row
        for (int i = endingCol; i >= startingCol && element < totalElement; i--) {
            ans.push_back(matrix[endingRow][i]);
            element++;
        }
        endingRow--;

        // Traverse from bottom to top along the leftmost column
        for (int i = endingRow; i >= startingRow && element < totalElement; i--) {
            ans.push_back(matrix[i][startingCol]);
            element++;
        }
        startingCol++;
    }

    return ans;
}

int main() {
    vector<vector<int>> v = {{1, 2, 3, 4, 5, 6},
                             {7, 8, 9, 10, 11, 12},
                             {13, 14, 15, 16, 17, 18},
                             {19, 20, 21, 22, 23, 24},
                             {25, 26, 27, 28, 29, 30}};

    vector<int> result = spiralOrder(v);

    // Output the result in spiral order
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
