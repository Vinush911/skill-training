public class Operators {
    public static void main(String[] args) {
        int num1 = 10;
        int num2 = 20;
        int sum = num1 + num2;
        int sub = num2 - num1;
        int div = num2 / num1;
        int mul = num1 * num2;
        int remainder = num1 % num2;
        // System.out.println("Sum of num1 & num2 is: " + sum);
        // System.out.println("sub : " + sub);
        // System.out.println("mul : " + mul);
        // System.out.println("div res: " + div);
        // System.out.println("remainder : " + remainder);

        // comparision operators 
        // System.out.println(100 > 10);
        // System.out.println(100 < 10);
        // System.out.println(100 == 100);
        // System.out.println(100 == 3);

        // logical operators 
        System.out.println(true && true);
        System.out.println(true && false);
        System.out.println(false && true);
        System.out.println(false && false);
        boolean num = true;
        boolean res = !num;
        System.out.println(res);
    }
}
