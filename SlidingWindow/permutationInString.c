// 567. Permutation in String
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

//Code

bool checkInclusion(char* s1, char* s2) {
    int arr[26] = {0}, size = 0, left = 0, len,flag[26] = {0};  
        while(*s1){
        arr[*s1-'a']++;
        flag[*s1-'a'] = 1;
        size++;
        s1++;
    }
    for(int right = 0; s2[right]!='\0'; right++){
        if((arr[s2[right]-'a']-1 < 0) && (flag[s2[right]-'a']!=1)){
            while(left!=right){
                arr[s2[left]-'a']++;
                left++;
            }
            left++;
        }
        else if((arr[s2[right]-'a']-1 < 0) && (flag[s2[right]-'a']==1)){
            while(arr[s2[right]-'a']-1 < 0){
                arr[s2[left]-'a']++;
                left++;
            }
            arr[s2[right]-'a']--;
        }
        else{
            arr[s2[right]-'a']--;
            len = right - left + 1;
            if(size == len){
                return true;
            }
        }     
    }
    return false;
}