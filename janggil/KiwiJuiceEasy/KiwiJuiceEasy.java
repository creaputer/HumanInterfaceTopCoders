package KiwiJuiceEasy;

public class KiwiJuiceEasy {

    public int[] toPouring2(int[] capacities, int[] bottles, int[] fromId, int[] toId) {
        
        //   Input parameter validation check.
        // (capacities.length == bottles.length)
        // (fromId.length == toId.length)
        // (capacities.length >= fromId.length)
        
        int[] results = bottles.clone();
        
        for (int i = 0; i < fromId.length ; i++) {
            
            int from = fromId[i];
            int to   = toId[i];
            
            int emptyAmount = capacities[to] - results[to];
            
            if (emptyAmount >= results[from]) {
                results[to] += results[from];
                results[from] = 0;
            } else {// if (emptyAmount < results[from]) {
                results[to] += emptyAmount;
                results[from] -= emptyAmount;
            }
        }
        
        
        return results;
    }
    
    
    public int[] toPouring(int[] capacities, int[] bottles, int[] fromId, int[] toId) {
        
        //   Input parameter validation check.
        // (capacities.length == bottles.length)
        // (fromId.length == toId.length)
        // (capacities.length >= fromId.length)
        
        int[] results = bottles.clone();
        
        for (int i = 0; i < fromId.length ; i++) {
            
           int from = fromId[i];
           int to   = toId[i];
           
           int sum      = results[from] + results[to];
           results[to]  = Math.min(capacities[to], results[from] + results[to]);
           results[from]= sum - results[to];
           
        }
        
        
        return results;
    }
    
}
