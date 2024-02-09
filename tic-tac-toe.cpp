#include <iostream>
#include <time.h>

const char PLAYER = 'X';
const char COMPUTER = 'O';

char board[3][3];

void printBoard();
void resetBoard();
void playerMove();
void computerMove();
int checkFreeSpaces();
char checkWinner();
void printWinner(char);

int main() {
    char playAgain;

    do {
        char winner = ' ';

        resetBoard();
        
        while (winner == ' ' && checkFreeSpaces() != 0) {
            printBoard();

            playerMove();
            winner = checkWinner();

            if (winner == ' ' && checkFreeSpaces() != 0) {
                computerMove();
                winner = checkWinner();
            } else break;
        }

        printWinner(winner);

        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

void printBoard() {
    system("cls");
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << std::endl;
}

void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void playerMove() {
    int row, column;

    std::cout << "Enter row (1-3): ";
    std::cin >> row;
    row--;

    std::cout << "Enter column (1-3): ";
    std::cin >> column;
    column--;

    if (board[row][column] == ' ') {
        board[row][column] = PLAYER;
    } else {
        std::cout << "Invalid move!" << std::endl;
        playerMove();
    }
}

void computerMove() {
    int row, column;

    srand(time(0));
    
    do {
        row = rand() % 3;
        column = rand() % 3;
    } while (board[row][column] != ' ');

    board[row][column] = COMPUTER;

}

int checkFreeSpaces() {
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }

    return freeSpaces;
}

char checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}

void printWinner(char winner) {
    printBoard();

    if (winner == PLAYER) {
        std::cout << "Player wins!" << std::endl;
    } else if (winner == COMPUTER) {
        std::cout << "Computer wins!" << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }
}
