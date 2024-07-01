#include <iostream>
#include <vector>

using namespace std;

class Cell
{
private:
    char symbol;

public:
    Cell() : symbol(' ') {}

    bool isEmpty() const
    {
        return symbol == ' ';
    }

    char getSymbol() const
    {
        return symbol;
    }

    void setSymbol(char sym)
    {
        symbol = sym;
    }
};

class Board
{
private:
    vector<vector<Cell>> grid;

public:
    Board() : grid(3, vector<Cell>(3)) {}

    void initialize()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                grid[i][j].setSymbol(' ');
            }
        }
    }

    void display() const
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << grid[i][j].getSymbol();
                if (j < 2)
                    cout << " | ";
            }
            cout << endl;
            if (i < 2)
                cout << "---------" << endl;
        }
    }

    bool updateCell(int row, int col, char symbol)
    {
        if (isCellEmpty(row, col))
        {
            grid[row][col].setSymbol(symbol);
            return true;
        }
        return false;
    }

    bool isCellEmpty(int row, int col) const
    {
        return grid[row][col].isEmpty();
    }

    bool checkWin() const
    {
        // Check rows
        for (int i = 0; i < 3; ++i)
        {
            if (grid[i][0].getSymbol() != ' ' && grid[i][0].getSymbol() == grid[i][1].getSymbol() && grid[i][1].getSymbol() == grid[i][2].getSymbol())
            {
                return true;
            }
        }
        // Check columns
        for (int i = 0; i < 3; ++i)
        {
            if (grid[0][i].getSymbol() != ' ' && grid[0][i].getSymbol() == grid[1][i].getSymbol() && grid[1][i].getSymbol() == grid[2][i].getSymbol())
            {
                return true;
            }
        }
        // Check diagonals
        if (grid[0][0].getSymbol() != ' ' && grid[0][0].getSymbol() == grid[1][1].getSymbol() && grid[1][1].getSymbol() == grid[2][2].getSymbol())
        {
            return true;
        }
        if (grid[0][2].getSymbol() != ' ' && grid[0][2].getSymbol() == grid[1][1].getSymbol() && grid[1][1].getSymbol() == grid[2][0].getSymbol())
        {
            return true;
        }
        return false;
    }

    bool checkDraw() const
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (grid[i][j].isEmpty())
                {
                    return false;
                }
            }
        }
        return true;
    }
};

class Player
{
private:
    string name;
    char symbol;

public:
    Player(string name, char symbol) : name(name), symbol(symbol) {}

    string getName() const
    {
        return name;
    }

    char getSymbol() const
    {
        return symbol;
    }

    bool makeMove(Board &board, int row, int col) const
    {
        return board.updateCell(row, col, symbol);
    }
};

class Game
{
private:
    Board board;
    Player *currentPlayer;
    Player playerX;
    Player playerO;

public:
    Game(string nameX, string nameO) : playerX(nameX, 'X'), playerO(nameO, 'O'), currentPlayer(&playerX)
    {
        board.initialize();
    }

    void start()
    {
        while (!isGameOver())
        {
            board.display();
            int row, col;
            cout << currentPlayer->getName() << " (" << currentPlayer->getSymbol() << "), enter your move (row and column): ";
            cin >> row >> col;

            if (currentPlayer->makeMove(board, row, col))
            {
                if (board.checkWin())
                {
                    board.display();
                    cout << currentPlayer->getName() << " wins!" << endl;
                    return;
                }
                if (board.checkDraw())
                {
                    board.display();
                    cout << "The game is a draw!" << endl;
                    return;
                }
                switchPlayer();
            }
            else
            {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }

    void switchPlayer()
    {
        if (currentPlayer == &playerX)
        {
            currentPlayer = &playerO;
        }
        else
        {
            currentPlayer = &playerX;
        }
    }

    bool isGameOver() const
    {
        return board.checkWin() || board.checkDraw();
    }

    Player *getWinner() const
    {
        if (board.checkWin())
        {
            return currentPlayer;
        }
        return nullptr;
    }
};

int main()
{
    string nameX, nameO;
    cout << "Enter player X's name: ";
    cin >> nameX;
    cout << "Enter player O's name: ";
    cin >> nameO;

    Game game(nameX, nameO);
    game.start();

    return 0;
}
