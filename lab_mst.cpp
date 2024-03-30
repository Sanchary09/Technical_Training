#include <iostream>
#include <unordered_set>

using namespace std;

int isValidSudoku(char board[9][9]) {
    unordered_set<char> rows[9];
    unordered_set<char> cols[9];
    unordered_set<char> subs[3][3];

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char cell = board[i][j];
            if (cell == '.') continue;
            if (rows[i].count(cell))
                return 1;
            if (cols[j].count(cell))
                return 2; 
            if (subs[i / 3][j / 3].count(cell))
                return 3; 
            rows[i].insert(cell);
            cols[j].insert(cell);
            subs[i / 3][j / 3].insert(cell);
        }
    }

    return 0; // Valid Sudoku
}

int main() {
    char board[9][9] = {
        {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '9', '9', '1'}, 
        {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
    };

    int validity = isValidSudoku(board);
    if (validity == 0)
        cout << "The given Sudoku puzzle is a correct solution." << endl;
    else {
        if (validity == 1)
            cout << "The given Sudoku puzzle is NOT a correct solution. Duplicate in the same row." << endl;
        else if (validity == 2)
            cout << "The given Sudoku puzzle is NOT a correct solution. Duplicate in the same column." << endl;
        else if (validity == 3)
            cout << "The given Sudoku puzzle is NOT a correct solution. Duplicate in the same subgrid." << endl;
    }

    return 0;
}