#include <iostream>
#include <vector>

using namespace std;

const int BOARD_DIMENSION = 8;
const int EMPTY_INT = 0;
const char EMPTY_CHAR = '-';
const char QUEEN_CHAR = '*';

class Chess {
public:
	Chess() {
		for (int i = 0; i < BOARD_DIMENSION; i++) for (int j = 0; j < BOARD_DIMENSION; j++) {
			board[i][j] = EMPTY_CHAR;
			threated_queen[i][j] = EMPTY_INT;
		}
	}

	void dimension_queen() {
		place_queen_in_row(0);
	}

private:
	void place_queen_in_row(int number_of_placed_queen) {
		if (number_of_placed_queen >= BOARD_DIMENSION) {
			return;
		}

		for (int i = 0; i < BOARD_DIMENSION; i++) {
			if (threated_queen[number_of_placed_queen][i] == EMPTY_INT) {
				can_place_queen(number_of_placed_queen, i, number_of_placed_queen + 1);
			}
		}
	}

	void can_place_queen(int row, int column, int queen_id) {

		place_queen(row, column, queen_id);
		if (queen_id == BOARD_DIMENSION)	print_board();
		place_queen_in_row(queen_id);
		remove_queen(row, column, queen_id);
	}

	void change_elements(int row, int column, int first_element, int second_element) {
		for (int i = 0; i < BOARD_DIMENSION; i++) {
			if (threated_queen[row][i] == first_element) {
				threated_queen[row][i] = second_element;
			}
			if (threated_queen[i][column] == first_element) {
				threated_queen[i][column] = second_element;
			}
			if (row + i < BOARD_DIMENSION) {
				if (column - i > -1 && threated_queen[row + i][column - i] == first_element) {
					threated_queen[row + i][column - i] = second_element;
				}
				if (column + i < BOARD_DIMENSION && threated_queen[row + i][column + i] == first_element) {
					threated_queen[row + i][column + i] = second_element;
				}
			}
		}
	}

	void place_queen(int row, int column, int queen_id) {
		board[row][column] = QUEEN_CHAR;
		change_elements(row, column, 0, queen_id);

	};

	void remove_queen(int row, int column, int queen_id) {
		board[row][column] = EMPTY_CHAR;
		change_elements(row, column, queen_id, EMPTY_INT);
	};

	void print_board() {
		for (int i = 0; i < BOARD_DIMENSION; i++) {
			for (int j = 0; j < BOARD_DIMENSION; j++) {
				cout << board[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "	---		" << endl;
	};

	char board[BOARD_DIMENSION][BOARD_DIMENSION];
	int threated_queen[BOARD_DIMENSION][BOARD_DIMENSION];

};

int main() {
	Chess chess;
	chess.dimension_queen();
	cin.get();
}
