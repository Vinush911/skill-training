package day2;

class Student {
    String name;
    String rollno;
    String usn;

    //method
    Student(String name,String rollno,String usn){
        this.name= name;
        this.rollno=rollno;
        this.usn=usn;
    }
}

public class StudentMain {
    public static void main(String[] args) {
        //datatype name=new datatype();
        // Student s1= new Student(); //object creation
        // //s1.name="Vinush";
        // System.out.println(s1.name);

        Student s2=new Student("vinush","059","061");
        System.out.println(s2.name);

    }
    
}






