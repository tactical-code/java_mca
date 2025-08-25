import java.util.Scanner;

public class hourpattern {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of rows: ");
        int n = sc.nextInt();
        sc.close();
        int i = 0;

        do {
            int stars, spaces;

            if (i < n / 2) { // top half
                stars = n - 2 * i;
                spaces = i;
            } else { // bottom half
                int j = n - i - 1;
                stars = n - 2 * j;
                spaces = j;
            }

            // Print spaces
            int s = 0;
            do {
                if (s >= spaces) break;
                System.out.print(" ");
                s++;
            } while (true);

            // Print stars
            int st = 0;
            do {
                if (st >= stars) break;
                System.out.print("*");
                st++;
            } while (true);

            System.out.println();
            i++;
        } while (i < n);
    }
}
