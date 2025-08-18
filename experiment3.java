public class experiment3 {

    // Method to reverse a number
    public static int reverseNumber(int num) {
        System.out.println("Original Number: " + num);
        int rev = 0;
        while (num != 0) {
            int digit = num % 10;
            rev = rev * 10 + digit;
            num /= 10;
        }
        System.out.println("Reversed Number: " + rev);
        return rev;
    }

    // Method to count digits
    public static int countDigits(int num) {
        System.out.println("Number: " + num);
        int count = 0;
        if (num == 0) return 1; // Special case for 0
        while (num != 0) {
            num /= 10;
            count++;
        }
        System.out.println("Number of Digits: " + count);
        return count;
    }

    // Method to find HCF (GCD) of two numbers
public static int findHCF(int a, int b) {
    System.out.println("Numbers: " + a + " and " + b);
    int originalA = a, originalB = b;
    int hcf = 1;
    int min = Math.min(a, b); // 12 18 

    for (int i = min; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            hcf = i;
            break; // Found the highest, no need to check further
        }
    }

    System.out.println("HCF of " + originalA + " and " + originalB + " is: " + hcf);
    return hcf;
}

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Usage:");
            System.out.println("java NumberOperations <choice> <num1> [num2]");
            System.out.println("Choices: 1=Reverse, 2=Count Digits, 3=Find HCF");
            return;
        }

        int choice = Integer.parseInt(args[0]);

        switch (choice) {
            case 1:
                int num1 = Integer.parseInt(args[1]);
                reverseNumber(num1);
                break;

            case 2:
                num1 = Integer.parseInt(args[1]);
                countDigits(num1);
                break;

            case 3:
                if (args.length < 3) {
                    System.out.println("Please provide two numbers for HCF.");
                } else {
                    num1 = Integer.parseInt(args[1]);
                    int num2 = Integer.parseInt(args[2]);
                    findHCF(num1, num2);
                }
                break;

            default:
                System.out.println("Invalid choice!");
        }
    }
}
