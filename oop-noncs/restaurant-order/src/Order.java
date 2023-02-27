public class Order {
  // TODO: Creating dish and qty without private access-specifier
  //  violates the principle of encapsulation. We will cover it in the next
  //  class I will provide resources for the same.
  MenuItem[] dish;
  int[] qty;

  public Order(MenuItem[] dish, int[] qty) {
    this.dish = dish;
    this.qty = qty;
  }

  public double getInvoice() {
    double totalInvoice = 0;
    for (int i = 0; i < dish.length; i++) {
      totalInvoice = totalInvoice + (dish[i].price * qty[i]);
    }
    double gst = 0.05 * totalInvoice;
    return totalInvoice + gst;
  }

  public void printDetails() {
    for (int i = 0; i < dish.length; i++) {
      System.out.println("Dish name: " +  dish[i].dishName);
      System.out.println("Qty: " +  qty[i]);
      System.out.println("Total Price " +  dish[i].price * qty[i]);
      System.out.println();
    }
  }
}
