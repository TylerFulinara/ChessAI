//Progam to play chess with a friend on the console

#include <iostream>
#include <string>
#include <cstring>  

using namespace std;

const int BOARD_SIZE = 8;

int turnCount = 0;


// Define the chess pieces as constants
const char EMPTY = ' ';
const char PAWN = 'P';
const char KNIGHT = 'N';
const char BISHOP = 'B';
const char ROOK = 'R';
const char QUEEN = 'Q';
const char KING = 'K';

// Define the player colors as constants
const int WHITE = 0;
const int BLACK = 1;

// Define the chess board as a 2D array of chars
char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the chess board
void initBoard() {
    // Set all squares to empty
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Place the black pieces on the board
    board[0][0] = ROOK; 
    board[0][1] = KNIGHT;
    board[0][2] = BISHOP;
    board[0][3] = QUEEN;
    board[0][4] = KING;
    board[0][5] = BISHOP;
    board[0][6] = KNIGHT;
    board[0][7] = ROOK;

    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = PAWN;
    }

    // Place the white pieces on the board
    board[7][0] = ROOK;
    board[7][1] = KNIGHT;
    board[7][2] = BISHOP;
    board[7][3] = QUEEN;
    board[7][4] = KING;
    board[7][5] = BISHOP;
    board[7][6] = KNIGHT;
    board[7][7] = ROOK;

    for (int i = 0; i < BOARD_SIZE; i++) {
        board[6][i] = PAWN;
    }
}

int movePawn(char beforeMove[], char afterMove[]) {

    //Converting from ASCII to INT
    int horizontalPositonPrevious = beforeMove[0] - 97; //Updates to board location where player is trying to move a piece
    int verticalPositonPrevious = beforeMove[1] - 48; 

    //Converting from ASCII to INT
    int horizontalPositonAfter = afterMove[0] - 97; //Updates to board location where player is trying to move a piece
    int verticalPositonAfter = afterMove[1] - 48; 

    cout << "This is the horizontal position before move: ";
    cout << horizontalPositonPrevious;
    cout << endl;

    cout << "This is the vertical position: ";
    cout << verticalPositonPrevious;
    cout << endl;

    cout << "This is the new horizontal position: ";
    cout << horizontalPositonAfter;
    cout << endl;

    cout << "This is the new vertical position: ";
    cout << verticalPositonAfter;
    cout << endl;


    //board[verticalPositonPrevious][horizontalPositonPrevious] = PAWN; 
    //board[6][0] = EMPTY; 
    
    //Pawn Move Options 

    //Check if Piece is at [x,y] board positon

    if (board[verticalPositonPrevious][horizontalPositonPrevious] == EMPTY) {
        cout << "There is no piece at " << beforeMove[0] << "," << beforeMove[1] << endl ;
        return -1;
    }

    int valueChecker = abs(verticalPositonAfter - verticalPositonPrevious);

    //board[afterMove[1]][afterMove[0]] = PAWN;

    //Check to see if that piece is a pawn 

    //Option 1 - Move Up 1 [Anytime]
    if(horizontalPositonAfter == horizontalPositonPrevious && valueChecker == 1){
        
        if (board[verticalPositonAfter][horizontalPositonAfter] != EMPTY) {
            cout << "Can't move to " << afterMove[0] << "," << afterMove[1] << endl;
            return -1;
        }

        board[verticalPositonAfter][horizontalPositonAfter] = PAWN;
        board[verticalPositonPrevious][horizontalPositonPrevious] = EMPTY;

        cout << "Move up 1" << endl;

        turnCount++;
    }

    //Option 2 - Move Up 2 [First Pawn Usage only]
    if(horizontalPositonAfter == horizontalPositonPrevious && valueChecker == 2){

        //returns error if white pawn is not on line 6

        //returns error if black pawn is not on line 1
        
        if (board[verticalPositonAfter][horizontalPositonAfter] != EMPTY) {
            cout << "Can't move to " << afterMove[0] << "," << afterMove[1] << endl;
            return -1;
        }

        board[verticalPositonAfter][horizontalPositonAfter] = PAWN;
        board[verticalPositonPrevious][horizontalPositonPrevious] = EMPTY;

        cout << "Move up 2" << endl;

        turnCount++;
    }

    //Option 3 - Diagonal Left or Right [Capture Only]

    if(horizontalPositonPrevious != horizontalPositonAfter && abs(verticalPositonAfter - verticalPositonPrevious) == 1){

        //returns error if white pawn is not on line 6

        //returns error if black pawn is not on line 1


        //NOTE - Have an extra check to make sure it is a opposite color piece spefically
        if (board[verticalPositonAfter][horizontalPositonAfter] == EMPTY) {
            cout << "Can't move to " << afterMove[0] << "," << afterMove[1] << endl;
            cout << "There is no piece to capture" << endl;
            return -1;
        }

        board[verticalPositonAfter][horizontalPositonAfter] = PAWN;
        board[verticalPositonPrevious][horizontalPositonPrevious] = EMPTY;

        cout << "Pawn Capture Diagonal Left/Right" << endl;

        turnCount++;
    }

    //Option 4 - Diagonal Right [Capture Only]

    //Option 5 - En Passant [Capture Only + Oppoent's Pawn First Usage]

}

// Function to print the chess board to the console
void printBoard() {
    cout << "TURN COUNT: " << turnCount << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << "------";
        }
        cout << endl;

        cout << i << "|";
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << "  " << board[i][j] << "  |";
        }
        cout << endl;
    }

    cout << " ";
    for (int j = 0; j < BOARD_SIZE; j++) {
        cout << "------";
    }
    cout << endl;

    cout << "   ";
    for (int j = 0; j < BOARD_SIZE; j++) {
        cout << char(j + 'a') << "    ";
    }
    cout << endl;
}


int main() {
    // Initialize the chess board
    initBoard();

    // Print the chess board
    printBoard();

    char beforeMove[10];
    char afterMove[10];

    cout << "What Piece would you like to move: ";
    cin >> beforeMove;
    cout << endl;

    cout << "Where do you want to move that Piece: ";
    cin >> afterMove;
    cout << endl;

    movePawn(beforeMove, afterMove);

    cout << " ------------------ ";

    // Print the chess board
    printBoard();

    return 0;
}