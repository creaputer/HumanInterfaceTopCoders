package ThePalindrome;

public class ThePalindrome {
    
    public int find(String s) {
        int minLength = s.length();
        
        int mid = minLength / 2;
        
        for (int i = 0, lastIdx = s.length() - 1 ; i < lastIdx ; i++) {
            if (s.charAt(i) != s.charAt(lastIdx)) {
                minLength++;
            } else {
                lastIdx--;
            }
        }
        
        return minLength;
    }
}
