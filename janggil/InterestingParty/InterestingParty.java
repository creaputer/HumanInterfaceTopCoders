package InterestingParty;

import java.util.Collections;
import java.util.HashMap;

public class InterestingParty {

   
    //// 
    // Restriction
    // first  : 1 <= length <= 50
    // second : same length with first array
    // first, second : each elements has 1~15 characters, 
    //                 only lowercase alphabet,
    //                 first[i].equal(second[i]) is always false. 
    public int bestInvitation(String[] first, String[] second) {
        int bestInvitation = 0;
        
        HashMap<String, Integer> interestMap = new HashMap<String, Integer>();
        
        for (int i = 0 ; i < first.length ; i++) {
            // first
            Integer vote = interestMap.get(first[i]);
            if (vote == null) vote = new Integer(0);
            interestMap.put(first[i], vote.intValue()+1);
            
            // second
            vote = interestMap.get(second[i]);
            if (vote == null) vote = new Integer(0);
            interestMap.put(second[i], vote.intValue()+1);
        }
        
        bestInvitation = Collections.max(interestMap.values());
        
        return bestInvitation;
    }
}
