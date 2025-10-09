// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

// Constraints:

// 1 <= haystack.length, needle.length <= 104
// haystack and needle consist of only lowercase English characters.

//Code 

int strStr(char* haystack, char* needle) {
    int ptr1 = 0;
    int ptr2 = 0;
    int flag = 0;
    int nl = strlen(needle);
    int hl = strlen(haystack);
    while(ptr1 != hl){
        if(haystack[ptr1] == needle[ptr2]){
            if(ptr2 == nl-1) return ptr1 - (nl-1);
            ptr1++; ptr2++;
        }
        else{
            ptr2 = 0;
            ptr1 = ++flag;
        }
    }
    return -1;
}