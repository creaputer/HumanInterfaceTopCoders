package FriendScore;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.function.Predicate;

public class FriendScore {

    private static final boolean isDebug = false;
    
    private static final char CHAR_FRIEND = 'Y';
    
    
    public int highestScore(String[] friends) {
        int highestScore = 0;        
        
        printFriends(friends);
        
        for (int i = 0 ; i < friends.length ; i++) {
            ArrayList<Integer> tFriendsList = findFriends(friends, i, 1); 
            
            printArrayList(tFriendsList);
          
            // remove self index.
            tFriendsList.removeIf(new FriendPredicate<Integer>(i));
            
            printArrayList(tFriendsList);
            
            // remove duplication
            Set<Integer> tFriendsSet = new HashSet<Integer>(tFriendsList);
            
            printArrayList(new ArrayList<Integer>(tFriendsSet));
           
            if (highestScore < tFriendsSet.size()) {
                highestScore = tFriendsSet.size();
            }
        }
        
        return highestScore;
    }
    
     
    /**
     * Find friend index list recursively until level is 0.
     * @param friends   friends list
     * @param index     current row index
     * @param level     recursive level (when level is 0 then stop)
     * @return
     */
    private ArrayList<Integer> findFriends(String[] friends, int index, int level) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        
        String row = friends[index];
        for (int i = 0 ; i < row.length() ; i++) {
            
            if (i == index) continue;
            
            if (row.charAt(i) == CHAR_FRIEND) {
                list.add(i);
                if (level > 0) 
                    list.addAll(findFriends(friends, i, level-1));
            }
            
        }
        
        return list;
    }
    
    
    /**
     * Using for ArrayList.removeIf()
     * @author creaputer
     *
     * @param <T>
     */
    class FriendPredicate<T> implements Predicate<T>{  
        T varc1;
        
        public FriendPredicate(T t) {
            super();
            varc1 = t;
        }
        
        @Override
        public boolean test(T varc){  
            if(varc1.equals(varc)){  
                return true;  
            }  
            return false;  
        }  
    } 
    
    
    /**************************************************************************
     * DEBUG METHODS SECTION                                                  *
     **************************************************************************/
    
    
    /**
     * Print(sysout) input friends list for Debugging.
     * @param friends
     */
    private void printFriends(String[] friends) {
        if (isDebug) {
            for (String str : friends) {
                System.out.println(str);
            }
            System.out.println();
        }
    }
    
    
    /**
     * Print(sysout) ArrayList for Debugging.
     * @param list
     */
    private void printArrayList(ArrayList<Integer> list) {
        if (isDebug) {
            if ((list == null) || (list.size() < 1) ){
                System.out.println("[]");
                return ;
            }
            
            System.out.print("[");
            int i = 0;
            for (i = 0 ; i < list.size() - 1 ; i++) {
                System.out.print(list.get(i) + ", ");
            }
            System.out.println(list.get(i) + "]");
        }
    }
    
}
