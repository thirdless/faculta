public class Problema2 {
    static int binaryToDecimal(String binaryString) throws NumberFormatException{
        return Integer.parseInt(binaryString, 2);
    }

    public static void main(String[] arg){
        try{
            System.out.println(binaryToDecimal("1010101010"));
            System.out.println(binaryToDecimal("11a0"));
        } catch(NumberFormatException e){
            System.out.println("Wrong binary number");
        }
    }
}
