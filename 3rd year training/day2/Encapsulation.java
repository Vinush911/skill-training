package day2;

class EncapsulatedMember{
    private String id,name;
    private double fine;

    public EncapsulatedMember(String id,String name){//,double fine){
        this.id=id;
        this.name=name;
        this.fine=0.0;
    }

    public double getfine(){
        return this.fine;
    }

    public void setfine(double newfine){
        if(newfine>0){
            this.fine=newfine;
        }
        else{
            System.out.println(" error fine cannot be negative ");
        }
    }
}


public class Encapsulation {
    public static void main(String[] args) {
        EncapsulatedMember m1=new EncapsulatedMember("101", "vinush");
        m1.setfine(10000);
        System.out.println("current fine is"+m1.getfine());
        m1.setfine(-1000);
        System.out.println("current fine is"+m1.getfine());
    }
}
