class Solution {
    using BoardT = std::vector<std::string>;
    using ResultT = std::vector<BoardT>;
    ResultT theResult;
    BoardT theBoard;
    void solveNQueens_(int row) {
        int n = theBoard.size();
        if(row == n) {
            theResult.push_back(theBoard);
            return;
        }
        for(int col = 0; col < n; col++) {
            if(isValid(row, col)) {
                theBoard[row][col] = 'Q';
                solveNQueens_(row+1);
                theBoard[row][col] = '.';
            }
        }
    }
    
    bool isValid(int row, int col) noexcept {
        int n = theBoard.size();
        for(int i = 0; i < row; i++) {
            if(theBoard[i][col] == 'Q') {
                return false;
            }
        }
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if(theBoard[i][j] == 'Q') {
                return false;
            }
        }
        for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
            if(theBoard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

public:
     ResultT solveNQueens(int n) {
        theBoard.resize(n);
        std::fill_n(theBoard.begin(), n, std::string(n, '.'));
        solveNQueens_(0);
        return theResult;
    }
};