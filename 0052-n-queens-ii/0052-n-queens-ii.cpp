class Solution {
    void totalNQueens(int row, int n, std::vector<int>& cols, std::vector<int>& diag1, std::vector<int>& diag2, int& count) {
        if(row == n) {
            count++;
            return;
        }
        for(int col = 0; col < n; col++) {
            if(cols[col] == 0 && diag1[row+col] == 0 && diag2[row-col+n] == 0) {
                cols[col] = 1;
                diag1[row+col] = 1;
                diag2[row-col+n] = 1;
                totalNQueens(row+1, n, cols, diag1, diag2, count);
                cols[col] = 0;
                diag1[row+col] = 0;
                diag2[row-col+n] = 0;
            }
        }
    }

public:
    int totalNQueens(int n) {
        int count = 0;
        std::vector<int> cols(n, 0), diag1(2*n, 0), diag2(2*n, 0);
        totalNQueens(0, n, cols, diag1, diag2, count);
        return count;
    }
    
};