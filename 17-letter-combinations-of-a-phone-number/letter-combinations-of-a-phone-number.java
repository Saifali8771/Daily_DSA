import java.util.ArrayList;
import java.util.List;

public class Solution {
    // Fixed mapping of digits to telephone letters
    private static final String[] KEYPAD = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        
        // Edge case: if input is empty, return empty list
        if (digits == null || digits.isEmpty()) {
            return result;
        }
        
        // Start the backtracking process from index 0
        backtrack(result, digits, new StringBuilder(), 0);
        return result;
    }

    private void backtrack(List<String> result, String digits, StringBuilder current, int index) {
        // Base case: if the current combination matches the length of digits, save it
        if (index == digits.length()) {
            result.add(current.toString());
            return;
        }

        // Get the letters corresponding to the current digit
        char digit = digits.charAt(index);
        String letters = KEYPAD[digit - '0'];

        // Loop through all letters mapped to this digit
        for (int i = 0; i < letters.length(); i++) {
            current.append(letters.charAt(i));       // Choose the letter
            backtrack(result, digits, current, index + 1); // Explore next digit
            current.deleteCharAt(current.length() - 1); // Backtrack (undo the choice)
        }
    }
}