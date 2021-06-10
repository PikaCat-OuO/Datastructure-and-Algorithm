#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, k;
    scanf("%d %d", &n, &m, &k);
    vector<vector<int>> matrix(n, vector<int>(m));
    for (auto& row : matrix) {
        for (auto& col : row) {
            scanf("%d", &col);
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1] + matrix[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m-1; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("%d\n", matrix[i][m-1]);
    }
    return 0;
}
