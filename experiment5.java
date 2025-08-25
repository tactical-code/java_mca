public class experiment5 {
  public static void main(String[] args) {

        // Convert command line argument (String) to integer
        int rows = Integer.parseInt(args[0]);

        int i = rows;
        do {
            int j = 1;
            do {
                System.out.print("* ");
                j++;
            } while (j <= i);
            
            System.out.println();
            i--;
        } while (i > 0);
    }
  
}

