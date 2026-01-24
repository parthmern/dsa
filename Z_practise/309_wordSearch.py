class Solution:

    def __init__(self):
        self.isVisited = []
        self.ans = False

    def canTravel(self, board, word, index, i, j):
        # R U D L

        

        if index == len(word):
            print("got ans", i, j)
            self.ans = True
            return
            

        #print("finding", word[index], "and", word[index-1] , "got at", i, j)
        #print("that time board looks liel", self.isVisited)
        
        if j+1 < len(board[0]) and board[i][j+1] == word[index] and self.isVisited[i][j+1] == False:
            self.isVisited[i][j+1] = True
            self.canTravel(board, word, index+1, i, j+1)
            self.isVisited[i][j+1] = False
        if i-1 >= 0 and board[i-1][j] == word[index] and self.isVisited[i-1][j] == False:
            self.isVisited[i-1][j] = True
            self.canTravel(board, word, index+1, i-1, j)
            self.isVisited[i-1][j] = False
        if i+1 < len(board) and board[i+1][j] == word[index] and self.isVisited[i+1][j] == False:
            self.isVisited[i+1][j] = True
            self.canTravel(board, word, index+1, i+1, j)
            self.isVisited[i+1][j] = False
        if j-1 >=0 and board[i][j-1] == word[index] and self.isVisited[i][j-1] == False:
            self.isVisited[i][j-1] = True
            self.canTravel(board, word, index+1, i, j-1)
            self.isVisited[i][j-1] = False
        
        

    def exist(self, board: List[List[str]], word: str) -> bool:

        for i in range(len(board)):
            lst = []
            for j in range(len(board[0])):
                lst.append(False)
            self.isVisited.append(lst)

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    self.isVisited[i][j] = True
                    self.canTravel(board, word, 1, i, j)
                    if self.ans == True:
                        return True
                    self.isVisited[i][j] = False
        return False
        