class Solution(object):
    # TLE in Python
    # def isValid(self, board, ch, r, c):
    #     for i in range(len(board)):
    #         boxR = (r//3) * 3 + (i//3)
    #         boxC = (c//3) * 3 + (i%3)

    #         if (board[r][i]==ch or board[i][c]==ch or board[boxR][boxC]==ch):
    #             return False

    #     return True


    # def backtrack(self, board):
    #     for i in range(len(board)):
    #         for j in range(len(board[0])):
    #             if (board[i][j]=='.'):
    #                 for ch in '123456789':
    #                     if (self.isValid(board,ch,i,j)):
    #                         board[i][j]=ch
    #                         if (self.backtrack(board)):
    #                             return True
    #                         board[i][j]='.'
    #                 return False
    #     return True
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        # self.backtrack(board)
        r = [set() for x in range(9)]
        c = [set() for x in range(9)]
        b = [set() for x in range(9)]
        empty = []

        #initialize sets + empties
        for i in range(9):
            for j in range(9):
                if board[i][j]!='.':
                    ch=board[i][j]
                    r[i].add(ch)
                    c[j].add(ch)
                    b[(i//3)*3+(j//3)].add(ch)
                else:
                    empty.append((i,j))

        def backtrack(idx=0):
            if idx == len(empty):
                return True
            
            i,j = empty[idx]
            k = (i//3) * 3 + (j//3)

            for ch in '123456789':
                if ch not in r[i] and ch not in c[j] and ch not in b[k]:
                    board[i][j]=ch
                    r[i].add(ch)
                    c[j].add(ch)
                    b[k].add(ch)

                    if (backtrack(idx+1)):
                        return True

                    board[i][j]='.'
                    r[i].remove(ch)
                    c[j].remove(ch)
                    b[k].remove(ch)
            return False

        backtrack()
