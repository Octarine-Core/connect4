#include <iostream>
using namespace std;
class ConnectFour{
public:
    int board[7][6];

    ConnectFour() {
        for (int x = 0; x < 7; ++x) {
            for (int y = 0; y < 6; ++y) {
                board[x][y] = 0;
            }
        }
    }

    void printBoard(){
        for (int j = 0; j < 6; ++j) {
            for (int i = 0; i < 7; ++i) {
                cout << board[i][j] << "\t";
            }
            cout << " " << "| " << j << endl;
        }
        for (int i = 0; i < 25; ++i) {
            cout << "_";
        }
        cout << endl;
        for (int i = 0; i < 7; ++i) {
            cout << i << "\t";
        }
        cout << endl;
    }

    int addPiece(int indx, int player){
        if(indx <0 || indx > 6){
            return -1;
        }
        for (int i = 5; i >= 0; --i) {
            if(board[indx][i] == 0){
                board[indx][i] = player;
                return i;
            }
        }
        return -1;
    }

    void gameLoop(){

        bool done = false;
        int turn = 1;

        while(!done){
            int choice;
            printBoard();
            wrong:
            cout << "Player " << turn << "'s turn, " <<"col: ";
            if(!(cin >> choice)){
                goto wrong;
            }
            int addedAtY = addPiece(choice, turn);
            if( addedAtY == -1){
                goto wrong;
            }
            cout << endl;
            if(checkWin(choice , addedAtY, turn)){
                cout << turn << "WIN";
                done = true;
            }
            turn = ((turn == 1)? 2: 1);
        }
    }

    bool checkWin(int x, int y, int player){
        //check vertical
        int m = 0; //count instances of
        for (int j = 0; j < 6; ++j) {
            if(board[x][j] == player){
                m++;
            } else{
                m = 0;
            }
            if (m==4){
                return true;
            }
        }

        //check horizontal
        m = 0;
        for (int i = 0; i < 7; ++i) {
            if(board[i][y] == player){
                m++;
            } else{
                m=0;
            }
            if(m==4){
                return true;
            }
        }

        //check +/+ diagonal
        int b=y-x; // b from the y=ax+b linear equation,  a=1 for this diagonal
        if(b >= -3 && b <= 2){
            m = 0;
            int a=1;
            int i, j;
            if(b>=0){
                i = 0;
                j = b;
            }else{
                i=-b;
                j=0;
            }

            for (; i < 7 && j < 6; ++i, ++j) {
                if(board[i][j] == player){
                    m++;
                } else{
                    m=0;
                }
                if(m==4){
                    return true;
                }
            }
        }

        //check other diagonal
        b = y+x;

        if(b>=3 && b<=8){
            m = 0;
            int i, j;
            if(b<=5){
                i = 0;
                j = b;
            }else{
                i=b-5;
                j=5;
            }

            for (; i < 7 && j >= 0; ++i, --j) {
                if(board[i][j] == player){
                    m++;
                } else{
                    m=0;
                }
                if(m==4){
                    return true;
                }
            }
        }

            return false;

    }


};

int main(void){

    ConnectFour c;
    c.gameLoop();
    return 0;
}

