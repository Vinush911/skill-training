import java.util.Scanner;
public class Inputs {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the age");
        int age= sc.nextInt();
        if(age<0||age>105){
            System.out.println("invalid age");
            return;
        }
        else if(age>=18){
            System.out.println("you can vote");
        }
        else {
            System.out.println("you cannot vote");
        }
    }
}
