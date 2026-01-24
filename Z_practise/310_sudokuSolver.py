class Solution:

    def isValid(self, board, i, j, ch):
        for k in range(0, 9):
            if board[k][j] == ch:
                return False
            if board[i][k] == ch:
                return False
            if board[3*(i//3) + k//3][3*(j//3) + k%3] == ch:
                return False
        return True

    def helper(self, board):
        for i in range(len(board)):
            for j in range(len(board[0])):

                if board[i][j] == ".":
                    for ch in range(1, 10):
                        if self.isValid(board, i, j, str(ch)):
                            board[i][j] = str(ch)
                            if self.helper(board):
                                return True
                            board[i][j] = "."
                    return False
        return True
            
                    

    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.helper(board)
        
