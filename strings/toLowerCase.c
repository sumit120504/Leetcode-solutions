// Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

 

// Example 1:

// Input: s = "Hello"
// Output: "hello"
// Example 2:

// Input: s = "here"
// Output: "here"
// Example 3:

// Input: s = "LOVELY"
// Output: "lovely"
 

// Constraints:

// 1 <= s.length <= 100
// s consists of printable ASCII characters.

//Code
char* toLowerCase(char* s) {
    int n = strlen(s);
    for(int i = 0; i<n; i++){
        if(65<=(int)s[i] && (int)s[i]<=90){
            s[i] = (char)((int)s[i]+32);
        }
    }
    return s;
}