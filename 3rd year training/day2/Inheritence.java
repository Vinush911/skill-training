package day2;

class Person{
    String name;
    int age;
    char gender;
    String contact;

    public Person(String name,int age,char gender,String contact){
        this.name=name;
        this.age=age;
        this.gender=gender;
        this.contact=contact;
    }
     public void print() {
        System.out.println("Age is: " + age);
        System.out.println("Contact is: " + contact);
        System.out.println("name is : " + name);
        System.out.println("gender is: " + gender);
    }

}
class Student extends Person {
    String rollNumber;
    String branch;

    public Student(String rollNumber, String branch, String name, int age, char gender, String contact) {
        super(name, age, gender, contact);
        this.rollNumber = rollNumber;
        this.branch = branch;
    }
     public void print() {
        super.print();
        System.out.println("rollNumber : " + rollNumber);
        System.out.println("branch: " + branch);
    }


}
// class Enployee extends Person{

// }

public class Inheritence {
    public static void main(String[] args) {
        Student s1=new Student("9900", "AI", "Vinush", 21, 'M', "1234567890");
        s1.print();
    }
}
