public class Solution {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();
        
        // A valid parentheses string must have an even length
        if (n % 2 != 0) {
            return false;
        }

        // Pass 1: Left to Right
        // Ensure there are enough '(' or unlocked positions to match ')'
        int openCount = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(' || locked.charAt(i) == '0') {
                openCount++;
            } else {
                openCount--;
            }
            // Too many fixed ')' brackets
            if (openCount < 0) {
                return false;
            }
        }

        // Pass 2: Right to Left
        // Ensure there are enough ')' or unlocked positions to match '('
        int closeCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == ')' || locked.charAt(i) == '0') {
                closeCount++;
            } else {
                closeCount--;
            }
            // Too many fixed '(' brackets
            if (closeCount < 0) {
                return false;
            }
        }

        return true;
    }
}