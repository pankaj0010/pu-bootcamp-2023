public class SimpleDiceGameWithRandomness extends AbstractDiceGame {
  public SimpleDiceGameWithRandomness(int numberOfPlayers) {
    super(numberOfPlayers);
  }

  public void playMove(int player) {
    System.out.println("Player " + player + " is playing.");
    int diceNumber = ran.nextInt(6); // 0 to 5
    System.out.println("Dice roll: " + diceNumber);
    positions[player] += diceNumber;
    System.out.println("Player " + player + " is at " + positions[player]);
    currentPlayer = player;
    lastDiceNumber[currentPlayer] = diceNumber;
  }

  public int getNextPlayer() {
    // If no move has been played, return player 0
    if (currentPlayer == -1) {
      return 0;
    }
    return lastDiceNumber[currentPlayer];
  }
}
