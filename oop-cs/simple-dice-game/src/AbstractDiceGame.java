import java.util.Random;

public abstract class AbstractDiceGame {
  protected int numberOfPlayers;
  protected Random ran;
  protected int currentPlayer;
  protected int[] positions;
  protected int[] lastDiceNumber;
  public AbstractDiceGame(int numberOfPlayers) {
    this.numberOfPlayers = numberOfPlayers;
    currentPlayer = -1;
    positions = new int[numberOfPlayers];
    lastDiceNumber = new int[numberOfPlayers];
    for (int player = 0; player < numberOfPlayers; player++) {
      positions[player] = 1;
      lastDiceNumber[player] = 0;
    }

    ran = new Random(3);
  }
  // playMove is abstract because it's implementation depends on the
  // game we are playing and each class which extends this must define its
  // own implementation. Similar for getNextPlayer
  abstract void playMove(int player);
  boolean hasPlayerWon(int player) {
    if (positions[player] >= 30) {
      return true;
    }
    else {
      return false;
    }
  }
  abstract int getNextPlayer();
}
