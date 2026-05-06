

class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        rows = [[0 for i in range(9)] for j in range(9)] # row[i][index]表示board第i行数字index+1出现的次数
        cols = [[0 for i in range(9)] for j in range(9)] # cols[i][index]表示board第j列数字index+1出现的次数
        subboxes = [[[0 for k in range(9)] for j in range(3)] for i in range(3)] # subboxes[i][j][index]表示board(i, j)处的子九宫格中，数字index+1出现的次数
        for i in range(9):
            for j in range(9):
                num_str = board[i][j]
                if num_str != '.':
                    index = int(num_str) - 1
                    rows[i][index] += 1
                    cols[j][index] += 1
                    subboxes[i//3][j//3][index] += 1

                    if rows[i][index]>1 or cols[j][index]>1 or subboxes[i//3][j//3][index]>1:
                        return False
        return True

if __name__=='__main__':
    subboxes = [[[0 for k in range(9)] for j in range(3)] for i in range(3)]
    print(subboxes[0][2][4])