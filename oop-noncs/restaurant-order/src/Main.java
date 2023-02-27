public class Main {
  public static void main(String[] args) {

    // TODO: Ideally this has to be done inside a separate function like
    //  createMenu. The main class should only support creating an order,
    //  printing it and getting invoice.
    MenuItem dosa = new MenuItem("Dosa", 70);
    MenuItem maggi = new MenuItem("Maggi", 30);

    MenuItem[] dishes;
    dishes = new MenuItem[]{dosa, maggi};
    int[] qty;
    qty = new int[]{1, 2};

    Order order = new Order(dishes, qty);
    order.printDetails();
    double totalBill = order.getInvoice();
    System.out.println(totalBill);
  }
}