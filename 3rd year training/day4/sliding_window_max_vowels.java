class Solution {
    public int maxVowels(String s, int k) {
        int currentVowels = 0;
        int maxVowels = 0;
        
        // 1. Count vowels in the very first window of size k
        for (int i = 0; i < k; i++) {
            if (checkVowel(s.charAt(i))) {
                currentVowels++;
            }
        }
        
        // Save the result of the first window
        maxVowels = currentVowels;
        
        // 2. Slide the window from index k to the end of the string
        for (int i = k; i < s.length(); i++) {
            // Add the new character entering the window on the right
            if (checkVowel(s.charAt(i))) {
                currentVowels++;
            }
            // Remove the old character leaving the window on the left
            if (checkVowel(s.charAt(i - k))) {
                currentVowels--;
            }
            
            // Keep track of the highest number of vowels seen so far
            if (currentVowels > maxVowels) {
                maxVowels = currentVowels;
            }
            
            // Optimization: If maxVowels reaches k, we can't get any higher!
            if (maxVowels == k) {
                return maxVowels;
            }
        }
        
        return maxVowels;
    }

    // Helper method to check if a character is a vowel
    public boolean checkVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
