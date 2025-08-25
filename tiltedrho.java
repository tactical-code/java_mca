import java.util.Scanner;

public class tiltedrho {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of rows: ");
        int n = sc.nextInt();
        sc.close();
        int i = 0;

        do {
            int spaces, stars;

            if (n % 2 == 1) { // odd rows
                int mid = n / 2;
                stars = n - 2 * Math.abs(i - mid);
                spaces = (n - stars) / 2;
            } else { // even rows
                int mid1 = n / 2 - 1;
                int mid2 = n / 2;
                int dist = Math.min(Math.abs(i - mid1), Math.abs(i - mid2));
                stars = n - 2 * dist;
                spaces = (n - stars) / 2;
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
