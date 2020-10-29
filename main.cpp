#include <iostream>
using namespace std;

#define PLAYER1       1
#define PLAYER2       2

class Board {
  private:
    char *charAtPos;

  public:
    void initBoard()
    {
        for(int i = 0; i < 9; i++) charAtPos[i] = ' ';
    }

    void drawBoard(char userInp, int position)
    {
        charAtPos[position] = userInp;
        cout << "****** TicTacToe Board ******" << endl;
        cout << " ___ ___ ___" << endl;
        cout << "| " << charAtPos[0] << " | " << charAtPos[1] << " | "<< charAtPos[2] << " |" << endl;
        cout << " ___ ___ ___" << endl;
        cout << "| " << charAtPos[3] << " | " << charAtPos[4] << " | "<< charAtPos[5] << " |" << endl;
        cout << " ___ ___ ___" << endl;
        cout << "| " << charAtPos[6] << " | " << charAtPos[7] << " | "<< charAtPos[8] << " |" << endl;
        cout << " ___ ___ ___" << endl;
    }

    char getCharAtPos(int pos)
    {
        if(pos >= 0 && pos < 9)
          return charAtPos[pos];
        else
          throw std::runtime_error("Wrong position used! Try from 0 to 8\n");
    }
};

void playTurn(int player, Board b)
{
    char character;
    if (player == 1) character = 'X';
    else if (player == 2) character = 'O';

    int positionOnBoard;
    cout << "Player " << player << ", please choose the position on the board:\n";
    do {
        cin >> positionOnBoard;
        if(positionOnBoard < 0 || positionOnBoard > 9)
          throw std::runtime_error("Wrong position entered! Try from 0 to 8\n");
        if(b.getCharAtPos(positionOnBoard) == 'X' || b.getCharAtPos(positionOnBoard) == 'O')
          cout << "This place is occupied. Please select another slot.\n";

    } while(b.getCharAtPos(positionOnBoard) == 'X' || b.getCharAtPos(positionOnBoard) == 'O');
    
    b.drawBoard(character, positionOnBoard);
}

bool checkWinner(Board b)
{

    if ((b.getCharAtPos(0) == 'X' && b.getCharAtPos(1) == 'X' && b.getCharAtPos(2) == 'X') ||
        (b.getCharAtPos(3) == 'X' && b.getCharAtPos(4) == 'X' && b.getCharAtPos(5) == 'X') ||
        (b.getCharAtPos(6) == 'X' && b.getCharAtPos(7) == 'X' && b.getCharAtPos(8) == 'X') ||
        (b.getCharAtPos(0) == 'X' && b.getCharAtPos(3) == 'X' && b.getCharAtPos(6) == 'X') ||
        (b.getCharAtPos(1) == 'X' && b.getCharAtPos(4) == 'X' && b.getCharAtPos(7) == 'X') ||
        (b.getCharAtPos(2) == 'X' && b.getCharAtPos(5) == 'X' && b.getCharAtPos(8) == 'X') ||
        (b.getCharAtPos(0) == 'X' && b.getCharAtPos(4) == 'X' && b.getCharAtPos(8) == 'X') ||
        (b.getCharAtPos(2) == 'X' && b.getCharAtPos(4) == 'X' && b.getCharAtPos(6) == 'X') ||

        (b.getCharAtPos(0) == 'O' && b.getCharAtPos(1) == 'O' && b.getCharAtPos(2) == 'O') ||
        (b.getCharAtPos(3) == 'O' && b.getCharAtPos(4) == 'O' && b.getCharAtPos(5) == 'O') ||
        (b.getCharAtPos(6) == 'O' && b.getCharAtPos(7) == 'O' && b.getCharAtPos(8) == 'O') ||
        (b.getCharAtPos(0) == 'O' && b.getCharAtPos(3) == 'O' && b.getCharAtPos(6) == 'O') ||
        (b.getCharAtPos(1) == 'O' && b.getCharAtPos(4) == 'O' && b.getCharAtPos(7) == 'O') ||
        (b.getCharAtPos(2) == 'O' && b.getCharAtPos(5) == 'O' && b.getCharAtPos(8) == 'O') ||
        (b.getCharAtPos(0) == 'O' && b.getCharAtPos(4) == 'O' && b.getCharAtPos(8) == 'O') ||
        (b.getCharAtPos(2) == 'O' && b.getCharAtPos(4) == 'O' && b.getCharAtPos(6) == 'O'))

        return true;


    return false;
}

int main()
{
    bool winnerFound = false;
    uint8_t currPlayer = PLAYER1;
    Board board;
    board.initBoard();

    cout << "\nStarting the TicTacToe Game!!!\n\n";
    while(!winnerFound)
    {
        playTurn(currPlayer, board);
        winnerFound = checkWinner(board);
        if(winnerFound) break;
        if(currPlayer == PLAYER1)
            currPlayer = PLAYER2;
        else
            currPlayer = PLAYER1;
    }

    cout << "Congratulations Player " << (int)currPlayer << ". You've won! Game over.\n\n";
    return 0;
}
