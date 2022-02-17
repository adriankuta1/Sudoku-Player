#include <iostream>
#include <string>
using namespace std;

bool resetCell(int x, int y){

    cout << "Are you sure you want to reset (" << x << "," << y << ")?" << endl;
    cout << "Enter '1' if yes, or '2' if no: ";

    int moveOn = 0;
    cin >> moveOn;

    return (moveOn == 1) ? true : false;
}

int chooseDifficulty(){

    cout << "Please enter the difficulty you would like to play at: ";
    int diff = 0;
    cin >> diff;

    if(diff == 1 || diff == 2 || diff == 3 || diff == 4 || diff == 99){
        return diff;
    }else{
        cout << "That's not an option, try again." << endl;
        chooseDifficulty();
    }

    return -1;
}

int getR(){

    int r = 0;
    cout << "enter row co-ord: ";
    cin >> r;

    if(r < 1 || r > 9){
        cout << "try again" << endl;
        getR();
    }

    return r;
}

int getC(){

    int c = 0;
    cout << "enter col co-ord: ";
    cin >> c;

    if(c < 1 || c > 9){
        cout << "try again" << endl;
        getC();
    }

    return c;
}

vector<vector<char>> putNum(int r, int c, vector<vector<char>> sudoku){

    cout << "Enter a digit (1-9): ";
    int digit = 0;
    cin >> digit;

    if(sudoku[r-1][c-1] != '.'){
        cout << "Woah, you're about to override an existing entry.\nIf you want to change this cell, you'll have to remove its value first." << endl;
       
        if(resetCell(r,c)){
            sudoku[r-1][c-1] = '.';
        return sudoku;
        }else{
            cout << "Ok, continue as you were" << endl;
        return sudoku;
        }
        
    }

    if(digit==0){
        sudoku[r-1][c-1] = '.';
        return sudoku;
    }

    sudoku[r-1][c-1] = digit + '0';

    return sudoku;
}

void displayBoard(vector<vector<char>> sudoku){

    cout << endl;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){

            if(j%3==0){
                cout << " ";
            }
            cout << sudoku[i][j] << "  ";

        }
        cout << endl;
        if((i+1)%3==0){
            cout << endl;
        }
    }
    cout << "\n\n\n";
}

void clearScreen(){
    
    cout << "\n\n";
}

bool boardNotEmpty(vector<vector<char>> sudoku){

    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){

            if(sudoku[i][j] == '.'){
                return true;
            }

        }
    }
    return false;
}

bool checkKeepPlaying(){

    cout << endl;
    cout << "Enter '1' to continue: ";
    int a = 0;
    cin >> a;

    if(a==1){
        return true;
    }else{
        return false;
    }

    cout << endl;
}

int getGameTime(){


}