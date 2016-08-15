package KiwiJuiceEasy;

public class TestKiwiJuiceEasy {
    
    static int[][] correctAnswers = {    {0, 13}
                                , {3, 10}
                                , {10, 10, 0}
                                , {0, 14, 65, 35, 25, 35}
                                , {0, 156956, 900000, 856956}
    };
    
    public static void main(String[] args) {
        test0();
        test1();
        test2();
        test3();
        test4();
        
        
        
        
        
    }
    
    private static boolean answerCheck(int[] result, int[] answer) {
        
        for (int i = 0 ; i < result.length ; i++ ) {
            if (result[i] != answer[i]) return false;
        }
        
        return true;
    }
    
    
    private static void test0() {
        int[] capacities = {20, 20};
        int[] bottles    = {5, 8};
        int[] fromId     = {0};
        int[] toId       = {1};
        
        int[] Returns = null;
        
        KiwiJuiceEasy kje = new KiwiJuiceEasy();
        
        Returns = kje.toPouring(capacities, bottles, fromId, toId);
        
        TestKiwiJuiceEasy.printArray(Returns);
        
        System.out.println(TestKiwiJuiceEasy.answerCheck(Returns, correctAnswers[0]));
        
    }
    
    private static void test1() {
        int[] capacities = {10, 10};
        int[] bottles    = {5, 8};
        int[] fromId     = {0};
        int[] toId       = {1};
        
        int[] Returns = null;
        
        KiwiJuiceEasy kje = new KiwiJuiceEasy();
        
        Returns = kje.toPouring(capacities, bottles, fromId, toId);
        
        TestKiwiJuiceEasy.printArray(Returns);
        System.out.println(TestKiwiJuiceEasy.answerCheck(Returns, correctAnswers[1]));
    }
    
    private static void test2() {
        int[] capacities = {30, 20, 10};
        int[] bottles    = {10, 5, 5};
        int[] fromId     = {0, 1, 2};
        int[] toId       = {1, 2, 0};
        
        int[] Returns = null;
        
        KiwiJuiceEasy kje = new KiwiJuiceEasy();
        
        Returns = kje.toPouring(capacities, bottles, fromId, toId);
        
        TestKiwiJuiceEasy.printArray(Returns);
        System.out.println(TestKiwiJuiceEasy.answerCheck(Returns, correctAnswers[2]));
    }
    
    private static void test3() {
        int[] capacities = {14, 35, 86, 58, 25, 62};
        int[] bottles    = {6, 34, 27, 38, 9, 60};
        int[] fromId     = {1, 2, 4, 5, 3, 3, 1, 0};
        int[] toId       = {0, 1, 2, 4, 2, 5, 3, 1};
        
        int[] Returns = null;
        
        KiwiJuiceEasy kje = new KiwiJuiceEasy();
        
        Returns = kje.toPouring(capacities, bottles, fromId, toId);
        
        TestKiwiJuiceEasy.printArray(Returns);
        System.out.println(TestKiwiJuiceEasy.answerCheck(Returns, correctAnswers[3]));
    }
    
    private static void test4() {
        int[] capacities = {700000, 800000, 900000, 1000000};
        int[] bottles    = {478478, 478478, 478478, 478478};
        int[] fromId     = {2, 3, 2, 0, 1};
        int[] toId       = {0, 1, 1, 3, 2};
        
        int[] Returns = null;
        
        KiwiJuiceEasy kje = new KiwiJuiceEasy();
        
        Returns = kje.toPouring(capacities, bottles, fromId, toId);
        
        TestKiwiJuiceEasy.printArray(Returns);
        System.out.println(TestKiwiJuiceEasy.answerCheck(Returns, correctAnswers[4]));
    }

    
    private static void printArray(int[] array) {
        if (array != null) {
            System.out.print("{");
            for (int i = 0; i < array.length ; i++) {
                if (i != 0) {
                    System.out.print(", ");
                }
                
                System.out.print(array[i]);
            }
            System.out.println("}");
        }
    }
}
