public class Problema3 {
    static int hexToDecimal(String hexString) throws NumberFormatException{
        return Integer.parseInt(hexString, 16);
    }

    public static void main(String[] arg){
        try{
            System.out.println(hexToDecimal("00ff00"));
            System.out.println(hexToDecimal("11A0"));
            System.out.println(hexToDecimal("11p0"));
        } catch(NumberFormatException e){
            System.out.println("Wrong hex number");
        }
    }
}
