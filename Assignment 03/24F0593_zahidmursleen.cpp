#include <iostream>   
#include <cstdlib>    
#include <ctime>      

using namespace std;  
class Player {
private:
    // Position tracking
    int x, y;            

    // Visual representation
    char symbol;        
    int goldCoins;       // Gold coins (each worth 10 points )
    int silverCoins;     // Silver coins (each worth 5 points)
    int points;          // used for buying items

    int swordUses;       // Remaining sword uses (counter)
    bool hasShield;      // Shield possession flag
    bool hasWater;       // Water possession flag
    bool hasKey;         // Key possession flag

 
    bool isBlocked;      // Whether player is currently blocked
    int blockedTurns;    // Turns remaining blocked (-1 = permanent)
    bool reachedCenter;  // Whether player reached the center

public:
    Player(int x = 0, int y = 0, char sym = 'P', int gold = 5, int silver = 10)
        : x(x), y(y), symbol(sym), goldCoins(gold), silverCoins(silver), points(0),
        swordUses(0), hasShield(false), hasWater(false), hasKey(false),
        isBlocked(false), blockedTurns(0), reachedCenter(false) {
    }

    int getX() const { return x; }             // Current x-coordinate
    int getY() const { return y; }             // Current y-coordinate
    char getSymbol() const { return symbol; }  // Board representation
    int getGold() const { return goldCoins; }  // Gold coin count
    int getSilver() const { return silverCoins; } // Silver coin count
    int getPoints() const { return points; }   // Current points
    int getSwordUses() const { return swordUses; } // Remaining sword uses
    bool getHasShield() const { return hasShield; } // Shield status
    bool getHasWater() const { return hasWater; }   // Water status
    bool getHasKey() const { return hasKey; }     // Key status
    bool getIsBlocked() const { return isBlocked; } // Blocked status
    int getBlockedTurns() const { return blockedTurns; } // Turns remaining blocked
    bool hasReachedCenter() const { return reachedCenter; } // Center status

    void setPosition(int newX, int newY) {  // Update player position
        x = newX;
        y = newY;
    }

    void setReachedCenter(bool value) {     // Set center reached flag
        reachedCenter = value;
    }

    /*
     * buyPoints() - Convert coins to points through menu interface
     *
     * Flow:
     * 1. Present conversion options
     * 2. Get user choice and amount
     * 3. Validate sufficient resources
     * 4. Convert and provide feedback
     */
    void buyPoints() {
        int choice, amount;
        cout << "\nBuy Points:\n1. Use Gold (1 Gold = 10 Points)\n2. Use Silver (1 Silver = 5 Points)\nChoose: ";
        cin >> choice;

        if (choice == 1) {  // Gold conversion
            cout << "How many Gold coins to spend? ";
            cin >> amount;
            if (amount <= goldCoins) {
                goldCoins -= amount;
                points += amount * 10;
                cout << "Bought " << amount * 10 << " points using " << amount << " gold.\n";
            }
            else cout << "Not enough gold!\n";
        }
        else if (choice == 2) {  // Silver conversion
            cout << "How many Silver coins to spend? ";
            cin >> amount;
            if (amount <= silverCoins) {
                silverCoins -= amount;
                points += amount * 5;
                cout << "Bought " << amount * 5 << " points using " << amount << " silver.\n";
            }
            else cout << "Not enough silver!\n";
        }
        else {
            cout << "Invalid option.\n";
        }
    }

    /*
     * buyHelperItems() - Purchase special items using points
     */

    void buyHelperItems() {
        int choice;
        cout << "\nBuy Helper Items:\n";
        cout << "1. Sword - 40 Points (Kill snake/lion, 2 uses)\n";
        cout << "2. Shield - 30 Points (Protect against ghost, 1 use)\n";
        cout << "3. Water - 50 Points (Protect against fire, 1 use)\n";
        cout << "4. Key - 70 Points (Open locked cell, 1 use)\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:  // Sword purchase
            if (points >= 40) {
                points -= 40;
                swordUses = 2;  // Initialize with 2 uses
                cout << "Sword purchased! Can be used twice.\n";
            }
            else cout << "Not enough points!\n";
            break;
        case 2:  // Shield purchase
            if (points >= 30) {
                points -= 30;
                hasShield = true;
                cout << "Shield purchased! Can protect against ghost once.\n";
            }
            else cout << "Not enough points!\n";
            break;
        case 3:  // Water purchase
            if (points >= 50) {
                points -= 50;
                hasWater = true;
                cout << "Water purchased! Can protect against fire once.\n";
            }
            else cout << "Not enough points!\n";
            break;
        case 4:  // Key purchase
            if (points >= 70) {
                points -= 70;
                hasKey = true;
                cout << "Key purchased! Can open locked cell once.\n";
            }
            else cout << "Not enough points!\n";
            break;
        default:
            cout << "Invalid option.\n";
        }
    }

    /*
     * Resource Spending Methods - Deduct resources with validation
     *
     * Each method follows the same pattern:
     * 1. Check if player has enough resource
     * 2. If yes, deduct and return true
     * 3. If no, show message and return false
     */
    bool spendPoints(int cost) {
        if (points >= cost) {
            points -= cost;
            return true;
        }
        cout << "Not enough points!\n";
        return false;
    }

    bool spendGold(int cost) {
        if (goldCoins >= cost) {
            goldCoins -= cost;
            return true;
        }
        cout << "Not enough gold!\n";
        return false;
    }

    bool spendSilver(int cost) {
        if (silverCoins >= cost) {
            silverCoins -= cost;
            return true;
        }
        cout << "Not enough silver!\n";
        return false;
    }

    // Add collected coins to inventory
    void addCoins(int gold, int silver) {
        goldCoins += gold;
        silverCoins += silver;
    }

    // Block the player for specified turns (-1 = permanent)
    void blockPlayer(int turns) {
        isBlocked = true;
        blockedTurns = turns;
    }

    // Remove all block conditions
    void unblockPlayer() {
        isBlocked = false;
        blockedTurns = 0;
    }

    /*
     * Item Usage Methods - Activate special items
     *
     * Each method:
     * 1. Checks if item is available
     * 2. Uses it if available (decrementing uses)
     * 3. Returns success status
     */
    bool useSword() {
        if (swordUses > 0) {
            swordUses--;
            return true;
        }
        return false;
    }

    bool useShield() {
        if (hasShield) {
            hasShield = false;  // Shield is single-use
            return true;
        }
        return false;
    }

    bool useWater() {
        if (hasWater) {
            hasWater = false;    // Water is single-use
            return true;
        }
        return false;
    }

    bool useKey() {
        if (hasKey) {
            hasKey = false;      // Key is single-use
            return true;
        }
        return false;
    }
};
class Board {
private:
    // Board representation
    char** map;          // 2D array for visual display
    int** coins;         // 2D array tracking coin positions

    // Game configuration
    int size;            // Board dimensions
    Player* p1;          // Pointer to Player 1
    Player* p2;          // Pointer to Player 2
    int gameStage;       // Current stage (1-3)

public:
    Board(int size, Player* player1, Player* player2, int stage) {
        this->size = size;
        this->p1 = player1;
        this->p2 = player2;
        this->gameStage = stage;

        // Allocate memory for 2D arrays
        map = new char* [size];
        coins = new int* [size];
        for (int i = 0; i < size; i++) {
            map[i] = new char[size];
            coins[i] = new int[size];

            // Initialize with empty spaces and no coins
            for (int j = 0; j < size; j++) {
                map[i][j] = ' ';    // Empty space
                coins[i][j] = 0;    // 0 = no coin
            }
        }

        placeRandomCoins();  // Distribute coins randomly
    }

    void placeRandomCoins() {
        srand(time(0));  // Seed random number generator
        int goldCount = 0, silverCount = 0;
        int targetGold, targetSilver;

        // Set targets based on stage
        if (gameStage == 1) {
            targetGold = 4;
            targetSilver = 4;
        }
        else if (gameStage == 2) {
            targetGold = 6;
            targetSilver = 6;
        }
        else {
            targetGold = 10;
            targetSilver = 10;
        }

        // Place gold coins
        while (goldCount < targetGold) {
            int x = rand() % size;
            int y = rand() % size;
            // Only place if empty and not on player
            if (coins[x][y] == 0 && !isPlayerPosition(x, y)) {
                coins[x][y] = 1;  // 1 = gold
                goldCount++;
            }
        }

        // Place silver coins
        while (silverCount < targetSilver) {
            int x = rand() % size;
            int y = rand() % size;
            if (coins[x][y] == 0 && !isPlayerPosition(x, y)) {
                coins[x][y] = 2;  // 2 = silver
                silverCount++;
            }
        }
    }

    /*
     * isPlayerPosition() - Checks if coordinates contain a player
     *
     * Used to prevent coin placement on players
     */
    bool isPlayerPosition(int x, int y) {
        return (x == p1->getX() && y == p1->getY()) ||
            (x == p2->getX() && y == p2->getY());
    }

    // Reset all map positions to empty
    void clear() {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                map[i][j] = '-';
    }

    /*
     * updateBoard() - Refreshes the board state
     *
     * 1. Clears the board
     * 2. Marks the center
     * 3. Places players who haven't reached center
     * 4. Checks for coin collection
     */
    void updateBoard() {
        clear();
        int center = size / 2;

        // Mark center with 'C'
        map[center][center] = 'C';

        // Only show players who haven't reached center
        if (!p1->hasReachedCenter()) {
            map[p1->getX()][p1->getY()] = p1->getSymbol();
        }
        if (!p2->hasReachedCenter()) {
            map[p2->getX()][p2->getY()] = p2->getSymbol();
        }

        // Check for coin collection
        checkCoins(p1);
        checkCoins(p2);
    }

    /*
     * checkCoins() - Handles coin collection for a player
     *
     * If player is on a coin:
     * 1. Add to inventory
     * 2. Remove coin from board
     * 3. Show message
     */
    void checkCoins(Player* player) {
        if (player->hasReachedCenter()) return; 

        int x = player->getX();
        int y = player->getY();

        if (coins[x][y] == 1) {  // Gold coin
            player->addCoins(1, 0);
            cout << "\nPlayer " << player->getSymbol() << " found a gold coin!\n";
            coins[x][y] = 0;
        }
        else if (coins[x][y] == 2) {  // Silver coin
            player->addCoins(0, 1);
            cout << "\nPlayer " << player->getSymbol() << " found a silver coin!\n";
            coins[x][y] = 0;
        }
    }

    // Display the current board state
    void display() {
        cout << "\nGame Board:\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                cout << map[i][j] << ' ';
            cout << endl;
        }
    }

    void showStatus() {
        // Player 1 status
        cout << "\nPlayer 1 (" << p1->getSymbol() << "): ";
        cout << "Gold: " << p1->getGold() << " | Silver: " << p1->getSilver()
            << " | Points: " << p1->getPoints();

        if (p1->getIsBlocked()) {
            if (p1->getBlockedTurns() == -1)
                cout << " | Status: Permanently Locked";
            else
                cout << " | Status: Blocked for " << p1->getBlockedTurns() << " more turns";
        }
        if (p1->hasReachedCenter())
            cout << " | Status: Reached Center";
        cout << endl;

        // Player 2 status
        cout << "Player 2 (" << p2->getSymbol() << "): ";
        cout << "Gold: " << p2->getGold() << " | Silver: " << p2->getSilver()
            << " | Points: " << p2->getPoints();

        if (p2->getIsBlocked()) {
            if (p2->getBlockedTurns() == -1)
                cout << " | Status: Permanently Locked";
            else
                cout << " | Status: Blocked for " << p2->getBlockedTurns() << " more turns";
        }
        if (p2->hasReachedCenter())
            cout << " | Status: Reached Center";
        cout << endl;
    }

    /*
     * showHelperItems() - Displays player's special items
     */
    void showHelperItems(Player* player) {
        cout << "\nHelper Items for Player " << player->getSymbol() << ":\n";
        cout << "Sword uses left: " << player->getSwordUses() << endl;
        cout << "Shield: " << (player->getHasShield() ? "Yes" : "No") << endl;
        cout << "Water: " << (player->getHasWater() ? "Yes" : "No") << endl;
        cout << "Key: " << (player->getHasKey() ? "Yes" : "No") << endl;
    }

    void applyHurdle(int currentPlayer) {
        Player* user = (currentPlayer == 1) ? p1 : p2;
        Player* opponent = (currentPlayer == 1) ? p2 : p1;

        // Can't hurdle someone who reached center
        if (opponent->hasReachedCenter()) {
            cout << "Cannot apply hurdle - opponent already reached center!\n";
            return;
        }

        cout << "\nChoose a hurdle to use on your opponent:\n";
        cout << "1. Fire (50 Points): Block 2 turns\n";
        cout << "2. Snake (30 Points): Block 3 turns + send back\n";
        cout << "3. Ghost (20 Points): Block 1 turn\n";
        cout << "4. Lion (2 Gold): Block 4 turns\n";
        cout << "5. Lock (3 Silver): Block permanently\n";
        cout << "Enter your choice: ";
        int hurdle;
        cin >> hurdle;

        bool success = false;
        switch (hurdle) {
        case 1:  // Fire
            if (opponent->getHasWater()) {
                cout << "Opponent used water to protect against fire!\n";
                opponent->useWater();
                success = true;
            }
            else {
                success = user->spendPoints(50);
                if (success) opponent->blockPlayer(2);
            }
            break;
        case 2:  // Snake
            if (opponent->useSword()) {
                cout << "Opponent used sword to kill the snake!\n";
                success = true;
            }
            else {
                success = user->spendPoints(30);
                if (success) {
                    opponent->blockPlayer(3);
                    // Move back 3 spaces (but not off board)
                    int newY = (opponent->getY() - 3 < 0) ? 0 : opponent->getY() - 3;
                    opponent->setPosition(opponent->getX(), newY);
                    cout << "Opponent sent back 3 cells.\n";
                }
            }
            break;
        case 3:  // Ghost
            if (opponent->getHasShield()) {
                cout << "Opponent used shield to protect against ghost!\n";
                opponent->useShield();
                success = true;
            }
            else {
                success = user->spendPoints(20);
                if (success) opponent->blockPlayer(1);
            }
            break;
        case 4:  // Lion
            if (opponent->useSword()) {
                cout << "Opponent used sword to kill the lion!\n";
                success = true;
            }
            else {
                success = user->spendGold(2);
                if (success) opponent->blockPlayer(4);
            }
            break;
        case 5:  // Lock
            if (opponent->getHasKey()) {
                cout << "Opponent used key to unlock!\n";
                opponent->useKey();
                success = true;
            }
            else {
                success = user->spendSilver(3);
                if (success) opponent->blockPlayer(-1);  // -1 = permanent
            }
            break;
        default:
            cout << "Invalid hurdle.\n";
            return;
        }

        if (success)
            cout << "Hurdle applied successfully.\n";
        else
            cout << "Failed to apply hurdle.\n";
    }

    /*
     * checkWinCondition() - Determines if game is over
     *
     * Win condition: Both players reached center
     *
     * Returns true if game should end, along with:
     * - Final score calculation (including coin conversion)
     * - Winner declaration or tie
     */
    bool checkWinCondition() {
        int center = size / 2;
        bool p1AtCenter = p1->hasReachedCenter();
        bool p2AtCenter = p2->hasReachedCenter();

        // Game ends when both reach center
        if (p1AtCenter && p2AtCenter) {
            // Calculate total points (coins converted to points)
            int p1Total = p1->getPoints() + (p1->getGold() * 10) + (p1->getSilver() * 5);
            int p2Total = p2->getPoints() + (p2->getGold() * 10) + (p2->getSilver() * 5);

            cout << "\n\nGAME OVER\n";
            cout << "Both players reached the center!\n";

            // Display final scores
            cout << "Player 1 total points: " << p1Total << endl;
            cout << "Player 2 total points: " << p2Total << endl;

            // Determine winner
            if (p1Total > p2Total) {
                cout << "Player 1 wins!\n";
            }
            else if (p2Total > p1Total) {
                cout << "Player 2 wins!\n";
            }
            else {
                cout << "It's a tie!\n";
            }
            return true;
        }
        return false;
    }

    /*
     * isValidMove() - Validates a potential move
     *
     * Checks:
     * 1. Move stays within board boundaries
     * 2. Doesn't land on opponent (except center)
     */
    bool isValidMove(int x, int y, Player* movingPlayer) {
        // Boundary check
        if (x < 0 || x >= size || y < 0 || y >= size) {
            cout << "Cannot move outside the board!\n";
            return false;
        }

        int center = size / 2;
        Player* otherPlayer = (movingPlayer == p1) ? p2 : p1;

        // Special case: Both can be at center simultaneously
        if (x == otherPlayer->getX() && y == otherPlayer->getY() &&
            !(x == center && y == center)) {
            cout << "Cannot move to opponent's position!\n";
            return false;
        }

        return true;
    }

    /*
     * movePlayer() - Executes player movement
     */

    void movePlayer(Player* player, char direction) {
        if (player->hasReachedCenter()) return;  // Can't move after reaching center

        int newX = player->getX();
        int newY = player->getY();
        int center = size / 2;

        // Update coordinates based on input
        switch (direction) {
        case 'w': newX--; break;  // Up
        case 's': newX++; break;  // Down
        case 'a': newY--; break;  // Left
        case 'd': newY++; break;  // Right
        case 'q': newX--; newY--; break;  // Up-left
        case 'e': newX--; newY++; break;  // Up-right
        case 'z': newX++; newY--; break;  // Down-left
        case 'c': newX++; newY++; break;  // Down-right
        case 'x': break;  // Skip move
        default: cout << "Invalid direction!\n"; return;
        }

        if (direction != 'x') {
            if (isValidMove(newX, newY, player)) {
                player->setPosition(newX, newY);

                // Check for center arrival
                if (newX == center && newY == center) {
                    player->setReachedCenter(true);
                    cout << "\nPlayer " << player->getSymbol() << " reached the center!\n";
                }
            }
        }
    }

    /*
     * DESTRUCTOR
     */
    ~Board() {
        // Delete each row first 
        for (int i = 0; i < size; i++) {
            delete[] map[i];
            delete[] coins[i];
        }
        // Then delete the arrays of pointers
        delete[] map;
        delete[] coins;
    }
};

/*
 * Flow:
 * 1. Sets up board and players
 * 2. Runs main game loop
 * 3. Handles turn-based gameplay
 */
void playGame(int stage) {
    // Determine board size based on stage
    int size;
    if (stage == 1) size = 5;
    else if (stage == 2) size = 7;
    else size = 11;

    Player p1(0, 0, '1');               // Top-left
    Player p2(size - 1, size - 1, '2'); // Bottom-right

    Board board(size, &p1, &p2, stage);
    int turn = 1;  // Start with Player 1

    cout << "\n STAGE " << stage << " (" << size << "x" << size << " board) ===\n";

    // Control game loop
    while (true) {
        board.updateBoard();
        board.display();
        board.showStatus();

        // Check for win condition
        if (board.checkWinCondition()) {
            break;
        }

        Player* current = (turn == 1) ? &p1 : &p2;

        // Skip turn if player reached center
        if (current->hasReachedCenter()) {
            cout << "\nPlayer " << turn << " has already reached the center!\n";
            turn = (turn == 1) ? 2 : 1;  // Switch turns
            continue;
        }

        cout << "\n--- Turn of Player " << turn << " ---\n";
        board.showHelperItems(current);

        // Present options
        int choice;
        cout << "\n1. Buy Points\n2. Buy Helper Items\n3. Continue\nChoose: ";
        cin >> choice;
        if (choice == 1) {
            current->buyPoints();
        }
        else if (choice == 2) {
            current->buyHelperItems();
        }

        if (!current->getIsBlocked()) {
            // Option to use hurdle
            int useHurdle;
            cout << "Use a hurdle? (1 = Yes / 0 = No): ";
            cin >> useHurdle;
            if (useHurdle == 1) {
                board.applyHurdle(turn);
            }

            // Movement interface
            cout << "Movement options:\n";
            cout << "q w e\n";
            cout << "a   d\n";
            cout << "z x c\n";
            cout << "(x to skip move)\n";

            char dir;
            cout << "Move: ";
            cin >> dir;

            board.movePlayer(current, dir);
        }
        else {
            // Handle blocked status
            if (current->getBlockedTurns() > 0) {
                cout << "Player is blocked for " << current->getBlockedTurns() << " more turns.\n";
                current->blockPlayer(current->getBlockedTurns() - 1);  // Decrement counter
            }
            else if (current->getBlockedTurns() == -1) {
                cout << "Player is permanently locked.\n";
            }
        }

        // Switch turns
        turn = (turn == 1) ? 2 : 1;
        cout << "\n--- End of Turn ---\n";
    }
}
//main
int main() {
    srand(time(0));

    // Play through all stages
    for (int stage = 1; stage <= 3; stage++) {
        playGame(stage);

        // Pause between stages (except after last)
        if (stage < 3) {
            cout << "\nPress enter to continue to the next stage...";
            cin.ignore();  // Clear input buffer
            cin.get();     // Wait for Enter
        }
    }
    cout << "\nGame completed! Thanks for playing!\n";
    return 0;
}