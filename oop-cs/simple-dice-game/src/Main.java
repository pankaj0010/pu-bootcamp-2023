public class Main {
  public static void main(String[] args) {


    int numPlayers = 6;
    // Change this to SimpleDiceGameWithRandomness to test
    SnakeAndLadderGame game = new SnakeAndLadderGame(numPlayers);

    while (true) {
      int currP = game.getNextPlayer();
      game.playMove(currP);
      if (game.hasPlayerWon(currP)) {
        System.out.println(currP + " has won the game");
        break;
      }
    }
  }
}







  /*

https://meet.google.com/wgo-rvds-mev






    int numberOfPlayers = 6;
    SimpleDiceGameWithSix game = new SimpleDiceGameWithSix(numberOfPlayers);

    while(true) {
      int player = game.getNextPlayer();
      game.playMove(player);
      if (game.hasPlayerWon(player)) {
        System.out.println("Player 0 has won");
        break;
      }
    }
  }
}





















*/