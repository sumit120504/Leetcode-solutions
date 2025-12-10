// 20. Valid Parentheses
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

// Example 5:

// Input: s = "([)]"

// Output: false

 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

//Code:
bool isValid(char* s) {
    unsigned stack[10001] = {0};
    int top = -1;
    for(int i = 0; s[i]!='\0'; i++){
        if(top == -1){
            top = 0;
            stack[top] = s[i] ;
        }
        else if((stack[top]=='(' && s[i]==')') || (stack[top]=='[' && s[i]==']') || (stack[top]=='{' && s[i]=='}')){
            top--;
        }
        else{
            top++;
            stack[top] = s[i];
        }
    }  
    return (top==-1?true:false);
}