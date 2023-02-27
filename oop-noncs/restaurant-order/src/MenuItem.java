public class MenuItem {
  // TODO: Creating dishName and price without private access-specifier
  //  violates the principle of encapsulation. We will cover it in the next
  //  class I will provide resources for the same.
  String dishName;
  double price;
  public MenuItem(String dishName, double price) {
    this.dishName = dishName;
    this.price = price;
  }
}
