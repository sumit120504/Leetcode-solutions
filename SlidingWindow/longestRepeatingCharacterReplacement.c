// 424. Longest Repeating Character Replacement
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length
 
//Code : 

int characterReplacement(char* s, int k) {
    int left = 0, output = 0, len, occ, maxFreq = 0;
    int arr[26] = {0};
    for(int right = 0; s[right]!='\0'; right++){
        occ = ++arr[s[right]-65];
        if(occ > maxFreq) maxFreq = occ;
        len = right - left + 1;
        if(maxFreq + k < len){
            arr[s[left]-65]--;
            left++;
            len = right - left + 1;
        }
        if(len>output)output = len;
    }
    return output;    
}