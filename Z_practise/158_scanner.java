import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter an integer: ");
        int x = sc.nextInt();

        System.out.print("Enter a double: ");
        double d = sc.nextDouble();

        System.out.print("Enter a word: ");
        String word = sc.next();

        sc.nextLine(); // consume leftover newline

        System.out.print("Enter a full sentence: ");
        String line = sc.nextLine();

        System.out.println("Integer: " + x);
        System.out.println("Double: " + d);
        System.out.println("Word: " + word);
        System.out.println("Line: " + line);

        sc.close();
    }
}
