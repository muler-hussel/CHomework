class PrintNum {
  public static void main(String[] args) {
    String[] num = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };

    for (String ss : num) {
      if (ss.contains("i") && ss.contains("e")) {
        ss += " yipes";
      } else if (ss.contains("i")) {
        ss += " yip";
      } else if (ss.contains("e")) {
        ss += " yep";
      }
      System.out.println(ss);
    }
  }
}