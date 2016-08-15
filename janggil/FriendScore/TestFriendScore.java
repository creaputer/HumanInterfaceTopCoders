package FriendScore;

public class TestFriendScore {
    
    private static final String SUCC = "SUCCESS";
    private static final String FAIL = "FAIL";


    public static void main(String[] args) {
        
        String[] friends0
            = { "NNN", 
                "NNN", 
                "NNN"
            };
        int answer0 = 0;
        
        String[] friends1
            = { "NYY",
                "YNY",
                "YYN" 
            };
        int answer1 = 2;
        
        String[] friends2 
            = { "NYNNN",
                "YNYNN",
                "NYNYN",
                "NNYNY",
                "NNNYN"
            };
        int answer2 = 4;
        
        String[] friends3
            = { "NNNNYNNNNN",
                "NNNNYNYYNN",
                "NNNYYYNNNN",
                "NNYNNNNNNN",
                "YYYNNNNNNY",
                "NNYNNNNNYN",
                "NYNNNNNYNN",
                "NYNNNNYNNN",
                "NNNNNNYNNN",
                "NNNNNYNNNN"
            };
        int answer3 = 8;
        
        String[] friends4 
            = { "NNNNNNNNNNNNNNY",
                "NNNNNNNNNNNNNNN",
                "NNNNNNNYNNNNNNN",
                "NNNNNNNYNNNNNNY",
                "NNNNNNNNNNNNNNY",
                "NNNNNNNNYNNNNNN",
                "NNNNNNNNNNNNNNN",
                "NNYYNNNNNNNNNNN",
                "NNNNNYNNNNNYNNN",
                "NNNNNNNNNNNNNNY",
                "NNNNNNNNNNNNNNN",
                "NNNNNNNNYNNNNNN",
                "NNNNNNNNNNNNNNN",
                "NNNNNNNNNNNNNNN",
                "YNNYYNNNNYNNNNN"
            };
        int answer4 = 6;
        
        TestFriendScore.test(friends0, answer0);
        TestFriendScore.test(friends1, answer1);
        TestFriendScore.test(friends2, answer2);
        TestFriendScore.test(friends3, answer3);
        TestFriendScore.test(friends4, answer4);
  
     }
    
    
    
    public static void test(String[] friends, int answer) {        
        FriendScore fs = new FriendScore();
        int highestScore = fs.highestScore(friends);
        
        if (answer == highestScore) 
            System.out.println(SUCC);
        else 
            System.out.println(FAIL + " ::: " + "high: " + highestScore + ", answer: " + answer);
        
        System.out.println("---------------------------------------");
  
    }

}
