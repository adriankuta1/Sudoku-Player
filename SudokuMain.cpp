#include <iostream>
#include <string>
#include <vector>
#include "functions.cpp"
#include "sudokuBoards.cpp"

using namespace std;

int main(){

    clearScreen();

    cout << "Hi, welcome to my Sudoku game!" << endl;
    cout << "Enter '1' to play: ";

    int play = 0;
    cin >> play;

    clearScreen();

    if(play==1){
        cout << "Okay, let's get started!" << endl;
    }else{
        cout << "Fair enough, see you again soon!" << endl;
        return 0;
    }

    cout << "The rules are simple: " << endl;
    cout << "   1. you can only make entries of digits 1,2,3,4,5,6,7,8, or 9" << endl;
    cout << "   2. Every row, column, and box must contain the numbers 1 through 9 (hint: this means there can be no duplicate numbers in any row, column, or box)" << endl;

    if(checkKeepPlaying() == true){
        cout << "Great, let's move on" << endl;
    }else{
        cout << "Getting scared? No biggy, see you next time" << endl;
        return 0;
    }
    cout << endl;

    cout << "Time to choose your difficulty." << endl;
    cout << "Easy: 1" << endl;
    cout << "Medium: 2" << endl;
    cout << "Hard: 3" << endl;
    cout << "'Actually, I've never played sudoku. I'm not sure if I can even finish a game.'\n  Don't worry, we've got you covered, enter '4' for noob mode!\n" << endl;

    int difficulty = chooseDifficulty();

    switch (difficulty) {
        case 1:
            cout << "Ok, easy it is!" << endl;
        break;

        case 2:
            cout << "Medium sounds good!" << endl;
        break;

        case 3:
            cout << "You're brave... hard it is!" << endl;
        break;
        case 4:
            cout << "We all start somewhere. All the best!" << endl;
        case 99:
            cout << "test mode" << endl;
        break;
        default:
            cout << "That's not valid!" << endl;
    }

    cout << "\nBefore you get started, here's how you navigate the board: " << endl;
    cout << "   1. Rows and columns are 1-indexed, which means you can enter 1 through 9 for row choice and column choice" << endl;
    cout << "   2. If you ever realise an incorrect move, simply enter its coordinates, and enter '0' as the digit." << endl;
    cout << "       (this will restore the cell to its original empty value)" << endl;
    //cout << "   3. If you are stuck and can't proceed, enter 'help' to any prompt and a random spot will be filled on the board.\n" << endl;

    cout << "Enter '1' to continue to your game: ";
    int cont = 0;
    cin >> cont;
    if(cont!=1){
        cout << "Your loss!" << endl;
    }

    clearScreen();

    vector<vector<char>> sudoku(9,vector<char>(9));

    switch (difficulty) {
        case 1:
            sudoku = easySudoku;
            break;

        case 2:
            sudoku = mediumSudoku;
            break;

        case 3:
            sudoku = hardSudoku;
            break;

        case 4:
            sudoku = noobSudoku;
            break;

        case 99:
            sudoku = testSudoku;
            break;

        default:
            cout << "That's not valid!" << endl;
    }

    cout << "Alright! Let the game finally begin! Good luck!" << endl;

    //This loop is where the majority of playtime is spent
    while(boardNotEmpty(sudoku)){

        displayBoard(sudoku);

        int rowCoord = getR();
        int colCoord = getC();

        sudoku = putNum(rowCoord,colCoord,sudoku);

    }

    cout << "That was the last move!" << endl;
    cout << "Here's the board: " << endl;

    displayBoard(sudoku);

    if(sudoku==solutionSudoku){
        cout << "Congratulations, you've filled out the entire board correctly!" << endl;
    }else{
        cout << "Great persistence but there's at least two numbers misplaced" << endl;
    }

    cout << endl;
   //cout << "That game took " getGameTime() << " minutes." << endl;


    cout << "\n That's the end of the game, thanks for playing!\nStayed tuned for new features!" << endl;
}