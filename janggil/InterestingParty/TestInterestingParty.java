package InterestingParty;

public class TestInterestingParty {
    
    public static void main(String[] args) {
        InterestingParty ip = new InterestingParty();
        
        test0(ip);
        test1(ip);
        test2(ip);
        test3(ip);
        
    }
    
    private static void test0(InterestingParty ip) {
        
        String[] first  = {"fishing", "gardening", "swimming", "fishing"};
        String[] second = {"hunting", "fishing", "fishing", "biting"};
        int bestInvation = ip.bestInvitation(first, second);
        
        System.out.println(bestInvation);        
    }
    
    private static void test1(InterestingParty ip) {
        String[] first  = {"variety", "diversity", "loquacity", "courtesy"};
        String[] second = {"talking", "speaking", "discussion", "meeting"};
        int bestInvation = ip.bestInvitation(first, second);
        
        System.out.println(bestInvation);        
    }
    
    private static void test2(InterestingParty ip) {
        
        String[] first  = {"snakes", "programming", "cobra", "monty"};
        String[] second = {"python", "python", "anaconda", "python"};
        int bestInvation = ip.bestInvitation(first, second);
        
        System.out.println(bestInvation);        
    }
    
    private static void test3(InterestingParty ip) {
        
        String[] first  = {"t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r", "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i"};
        String[] second = {"n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w", "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y"};
        int bestInvation = ip.bestInvitation(first, second);
        
        System.out.println(bestInvation);        
    }
    
}
