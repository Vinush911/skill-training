package day2;
public class AltCharecter {
        String str;
        String vit;
        String agi;
        String dex;
        String crit;

        public AltCharecter(String str,String vit,String agi,String dex,String crit){
            this.str=str;
            this.vit=vit;
            this.agi=agi;
            this.dex=dex;
            this.crit=crit;
        }
        public void printStats(){
            System.out.println("the stats of charecter is ");
            System.out.println("Strength "+this.str);
            System.out.println("Vitality "+this.vit);
            System.out.println("Agility "+this.agi);
            System.out.println("Dexterity "+this.dex);
            System.out.println("Critical "+this.crit);

        }
    
    public static void main(String[] args) {
        AltCharecter sniper=new AltCharecter("400","150","1","408","411");
        sniper.printStats();
    }
}
