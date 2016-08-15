package Cryptography;

import java.util.Arrays;

public class Cryptography {
    
    public long encrypt(int[] numbers) {
        long max = 0;
        
        Arrays.sort(numbers);
        
        max = numbers[0] + 1;
        for (int i = 1 ; i < numbers.length ; i++ ) {
            max *= numbers[i];
        }
        
        return max;
    }

}


