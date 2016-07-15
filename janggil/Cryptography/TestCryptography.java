package Cryptography;


public class TestCryptography {

    public static void main(String[] args) {
        Cryptography cg = new Cryptography();
        
        int[] numbers0 = {1, 2, 3};
        long max = cg.encrypt(numbers0);
        System.out.println(max);
        System.out.println(max == 12);
        
        int[] numbers1 = {1, 3, 2, 1, 1, 3};
        max = cg.encrypt(numbers1);
        System.out.println(max);
        System.out.println(max == 36);
        
        int[] numbers2 = {1000, 999, 998, 997, 996, 995};
        max = cg.encrypt(numbers2);
        System.out.println(max);
        System.out.println(max == 986074810223904000L);
        
        int[] numbers3 = {1, 1, 1, 1};
        max = cg.encrypt(numbers3);
        System.out.println(max);
        System.out.println(max == 2);
        
        
    }
    
    

}
