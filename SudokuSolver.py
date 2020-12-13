class SudokuSolver:
    def __init__(self):
        self.__blanks = []
        self.__sudoku = []

    def __solver(self, curr_blank):
        if (curr_blank == len(self.__blanks)):
           return True

        for i in range(1, 10):
            is_correct = self.__checkCorrect(i, self.__blanks[curr_blank][0], self.__blanks[curr_blank][1])
            if (is_correct):
                self.__sudoku[self.__blanks[curr_blank][0]][self.__blanks[curr_blank][1]] = i

                if (self.__solver(curr_blank + 1)):
                    return True

        self.__sudoku[self.__blanks[curr_blank][0]][self.__blanks[curr_blank][1]] = 0

        return False

    def __checkCorrect(self, val, pos_i, pos_j):
        for j in range(9):
            if (self.__sudoku[pos_i][j] == val):
                return False

        for i in range(9):
            if (self.__sudoku[i][pos_j] == val):
                return False

        quadrant_i = int(pos_i / 3)
        quadrant_j = int(pos_j / 3)
        check_from_i = quadrant_i * 3
        check_from_j = quadrant_j * 3

        for i in range(check_from_i, check_from_i + 3):
            for j in range(check_from_j, check_from_j + 3):
                if (self.__sudoku[i][j] == val):
                    return False

        return True;

    def printSudoku(self, passed_sudoku):
        for i in range(9):
            for j in range(9):
                if (passed_sudoku[i][j] == 0):
                    print("_", end = " ")
                else:
                    print(str(passed_sudoku[i][j]), end = " ")

            print("")

        print("")

    def solveSudoku(self, passed_sudoku):
        self.__sudoku = passed_sudoku

        for i in range(9):
            for j in range(9):
                if (self.__sudoku[i][j] == 0):
                    self.__blanks.append([i, j])

        if (self.__solver(0)):
            self.printSudoku(self.__sudoku)
        else:
            print("No solution")

machine = SudokuSolver()

sudoku = [
        [0, 4, 0, 0, 8, 7, 0, 1, 0],
		[1, 9, 7, 0, 5, 0, 0 ,0 ,0],
		[0, 6, 8, 9, 1, 0, 4, 0 ,0],
		[0, 2, 0, 3, 4, 0, 8, 7, 0],
		[0, 0, 1, 7, 2, 0, 3, 4, 0],
		[4, 0, 0, 8, 9, 1, 0, 0, 0],
		[2, 0, 0, 0, 3, 0, 7, 0, 0],
		[6, 0, 5, 4, 0, 0, 1, 3, 0],
		[0, 0, 4, 0, 0, 0, 0, 9, 8],
]

machine.printSudoku(sudoku)
machine.solveSudoku(sudoku)

        
        

                
