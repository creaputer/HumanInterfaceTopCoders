package ThePalindrome;

public class TestThePalindrome {

    public static void main(String[] args) {
        ThePalindrome tp = new ThePalindrome();
        
        test("abab", tp);
        test("abacaba", tp);
        test("qwerty", tp);
        test("abdfhdyrbdbsdfghjkllkjhgfds", tp);
        test("abcccc", tp);
        test("abccccc", tp);
        

    }
    
    public static void test (String input, ThePalindrome tp) {    
        int minLength = tp.find(input);
        System.out.println("input string is " + input + "(" + input.length() + ") and result is " + minLength);
       
    }
    
}
