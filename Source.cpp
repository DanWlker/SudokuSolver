#include <iostream>
#include <vector>

class SudokuSolver
{
	private:
		std::vector< std::vector<int> > blanks;
		std::vector< std::vector<int> > sudoku;

		bool solver(int curr_blank)
		{
			if (curr_blank == blanks.size())
				return true;

			for (int i = 1; i <= 9; ++i)
			{
				if (checkCorrect(i, blanks[curr_blank][0], blanks[curr_blank][1]))
				{
					sudoku[blanks[curr_blank][0]][blanks[curr_blank][1]] = i;

					if (solver(curr_blank + 1))
						return true;
				}
			}

			sudoku[blanks[curr_blank][0]][blanks[curr_blank][1]] = 0;

			return false;
		}

		bool checkCorrect(int val, int pos_i, int pos_j)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (sudoku[pos_i][j] == val)
					return false;
			}

			for (int i = 0; i < 9; ++i)
			{
				if (sudoku[i][pos_j] == val)
					return false;
			}

			int quadrant_i = pos_i / 3;
			int quadrant_j = pos_j / 3;
			int check_from_i = quadrant_i * 3;
			int check_from_j = quadrant_j * 3;

			for (int i = check_from_i; i <= check_from_i + 2; ++i)
			{
				for (int j = check_from_j; j <= check_from_j + 2; ++j)
				{
					if (sudoku[i][j] == val) 
						return false;
				}
			}

			return true;
		}

	public:
		void printSudoku(std::vector< std::vector<int> >& passed_sudoku)
		{
			for (int i = 0; i < 9; ++i)
			{
				for (int j = 0; j < 9; ++j)
				{
					if (passed_sudoku[i][j] == 0)
						std::cout << "_ ";
					else
						std::cout << passed_sudoku[i][j] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}

		void solveSudoku(std::vector< std::vector<int> >& passed_sudoku)
		{
			sudoku = passed_sudoku;

			for (int i = 0; i < 9; ++i)
			{
				for (int j = 0; j < 9; ++j)
				{
					if (sudoku[i][j] == 0)
						blanks.push_back({ i, j });
				}
			}

			if (solver(0))
				printSudoku(sudoku);
			else
				std::cout <<std::endl << "No solution" <<std::endl;
		}
};

int main()
{
	SudokuSolver machine;

	std::vector< std::vector<int> >sudoku =
	{
		{8, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 3, 6, 0, 0, 0, 0, 0},
		{0, 7, 0, 0, 9, 0, 2, 0, 0},
		{0, 5, 0, 0, 0, 7, 0, 0, 0},
		{0, 0, 0, 0, 4, 5, 7, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 3, 0},
		{0, 0, 1, 0, 0, 0, 0, 6, 8},
		{0, 0, 8, 5, 0, 0, 0, 1, 0},
		{0, 9, 0, 0, 0, 0, 4, 0, 0},
	};

	machine.printSudoku(sudoku);

	machine.solveSudoku(sudoku);

	return 0;
}