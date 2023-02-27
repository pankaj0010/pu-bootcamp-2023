public class Student {
  String id;
  String name;
  String branch;
  double cgpa;

  public Student(String id2, String name2,
                 String branch2, double cgpa2) {
    id = id2;
    name = name2;
    branch = branch2;
    cgpa = cgpa2;
  }

  public String getName() {
    return name;
  }
}
