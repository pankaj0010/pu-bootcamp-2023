import java.util.Random;

public class SimpleDiceGame extends AbstractDiceGame {

  public SimpleDiceGame(int numberOfPlayers) {
    super(numberOfPlayers);
  }

  public void playMove(int player) {
    System.out.println("Player " + player + " is playing.");
    int diceNumber = ran.nextInt(6); // 0 to 5
    System.out.println("Dice roll: " + diceNumber);
    positions[player] += diceNumber;
    System.out.println("Player " + player + " is at " + positions[player]);
    currentPlayer = player;
  }

  public int getNextPlayer() {
    return (currentPlayer + 1) % numberOfPlayers;
  }


}
