import java.util.Arrays;

public class SuccessfulPairs {
    
    public static int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int m = potions.length;
        int[] result = new int[n];
        
        // Sort the potions array for binary search.
        Arrays.sort(potions);
        
        for (int i = 0; i < n; i++) {
            int spell = spells[i];
            
            // Compute the minimum potion strength required.
            // Use ceiling division to account for non-integer division.
            long minPotionRequired = (success + spell - 1) / spell;
            
            // Find the first index in potions that has value >= minPotionRequired.
            int index = lowerBound(potions, minPotionRequired);
            
            // If index is within bounds, then count successful potions.
            result[i] = (index == m) ? 0 : m - index;
        }
        
        return result;
    }
    
    // Helper method: lowerBound returns the first index at which potions[index] >= target.
    public static int lowerBound(int[] potions, long target) {
        int lo = 0, hi = potions.length;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (potions[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
    
    public static void main(String[] args) {
        int[] spells = {5, 1, 3};
        int[] potions = {1, 2, 3, 4, 5};
        long success = 7;
        
        int[] pairs = successfulPairs(spells, potions, success);
        System.out.println("Successful pairs: " + Arrays.toString(pairs));
    }
}
