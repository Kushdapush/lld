### Class Diagram

```plaintext
+----------------+
|    Game        |
+----------------+
| - board: Board |
| - currentPlayer: Player |
| - playerX: Player |
| - playerO: Player |
+----------------+
| + start(): void |
| + switchPlayer(): void |
| + isGameOver(): boolean |
| + getWinner(): Player |
+----------------+


+----------------+
|     Board      |
+----------------+
| - grid: Cell[][] |
+----------------+
| + initialize(): void |
| + display(): void |
| + updateCell(row: int, col: int, symbol: char): void |
| + isCellEmpty(row: int, col: int): boolean |
| + checkWin(): boolean |
| + checkDraw(): boolean |
+----------------+


+----------------+
|    Cell        |
+----------------+
| - symbol: char |
+----------------+
| + isEmpty(): boolean |
+----------------+


+----------------+
|    Player      |
+----------------+
| - name: String |
| - symbol: char |
+----------------+
| + makeMove(board: Board, row: int, col: int): boolean |
+----------------+
```

### Description of Classes

1. **Game Class**: 
   - Manages the overall game flow, including starting the game, switching players, checking if the game is over, and determining the winner.
   - Attributes:
     - `board`: An instance of the `Board` class.
     - `currentPlayer`: The player whose turn it is currently.
     - `playerX`: The player using 'X'.
     - `playerO`: The player using 'O'.
   - Methods:
     - `start()`: Initializes the game and starts the main game loop.
     - `switchPlayer()`: Switches the turn to the other player.
     - `isGameOver()`: Checks if the game has ended.
     - `getWinner()`: Returns the winning player if there is one.

2. **Board Class**: 
   - Represents the Tic-Tac-Toe board.
   - Attributes:
     - `grid`: A 2D array of `Cell` objects representing the board.
   - Methods:
     - `initialize()`: Initializes the board.
     - `display()`: Displays the current state of the board.
     - `updateCell(row, col, symbol)`: Updates a cell with a player's symbol.
     - `isCellEmpty(row, col)`: Checks if a specific cell is empty.
     - `checkWin()`: Checks if there is a winning condition on the board.
     - `checkDraw()`: Checks if the game is a draw.

3. **Cell Class**: 
   - Represents an individual cell on the board.
   - Attributes:
     - `symbol`: The symbol in the cell ('X', 'O', or empty).
   - Methods:
     - `isEmpty()`: Checks if the cell is empty.

4. **Player Class**: 
   - Represents a player in the game.
   - Attributes:
     - `name`: The player's name.
     - `symbol`: The player's symbol ('X' or 'O').
   - Methods:
     - `makeMove(board, row, col)`: Allows the player to make a move on the board.