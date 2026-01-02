import java.util.Scanner;

// import static org.junit.jupiter.api.Assertions.assertEquals;

// import org.junit.jupiter.api.Test;

//         1
//       2 3 2
//     3 4 5 4 3
//   4 5 6 7 6 5 4
// 5 6 7 8 9 8 7 6 5

public class Main {
  public static void main(String[] args) {
    System.out.println("Hello world! hii");
    // Scanner sc = new Scanner(System.in);

    // int x = sc.nextInt();
    // System.out.println("x" + x);

    // String str = sc.nextLine();
    // System.out.println("ste" + str);



    for(int i=0; i<5; i++){
      for(int j=0; j<4-i; j++){
        System.out.print(" ");
      }
      for(int k=i+1; k<i+1+i+1; k++){
        System.out.print(k);
      }
      for(int z=i+i; z>i; z--){
        System.out.print(z);
      }
      System.out.println("");
    }
    
 
  }

  // @Test
  // void addition() {
  // assertEquals(2, 1 + 1);
  // }
}