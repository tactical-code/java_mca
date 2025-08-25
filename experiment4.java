public class experiment4 {
  public static void main(String args[]) {
        // Check if correct number of arguments are passed

        // Parse the number and digit from command line
        int number = Integer.parseInt(args[0]);
        int digit = Integer.parseInt(args[1]);

        int count = 0;
        int temp = number;

        // Special case: if number is 0 and digit is 0
        if (temp == 0 && digit == 0) {
            count = 1;
        } else {
            // Count digit occurrence using do-while
            do {
                int lastDigit = temp % 10;
                if (lastDigit == digit) {
                    count++;
                }
                temp /= 10;
            } while (temp > 0);
        }

        System.out.println("Digit " + digit + " occurs " + count + " times in number " + number);
    }
}


