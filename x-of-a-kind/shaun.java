class Solution {
    //shaun java code, beats 13%
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer,Integer> m = new HashMap<>();
        for (int i = 0; i < deck.length; i++) {
            if (!m.containsKey(deck[i])) {
                m.put(deck[i], 1);
            } else {
                m.put(deck[i], m.get(deck[i])+1);
            }
            
        }
        
        //use examples to figure out the gcd
        int X  = 0;
        for (int number: m.keySet()){
            int count = m.get(number);
            //X = GCD(count, X);
            X = egcd(count, X);
        }
        return X >= 2;
        
    }
    
    private int GCD(int a, int b) {
        if (b == 0) return a;
        return GCD(b, a%b);
    }
    
    //Euclidean algorithm for calculating the GCD...
    public int egcd(int a, int b) {
        //if (a == 0)
        //    return b;

        while (b != 0) {
            if (a > b)
                a = a - b;
            else //a <= b
                b = b - a;
        }

        return a;
    

    }
}
