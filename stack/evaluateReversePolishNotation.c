// 150. Evaluate Reverse Polish Notation
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
// Example 3:

// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22
 

// Constraints:

// 1 <= tokens.length <= 104
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

//Code :
int evalRPN(char** tokens, int tokensSize) {
    int* stack = (int*)malloc(sizeof(int)*tokensSize);
    int top = -1;
    for(int i = 0; i < tokensSize; i++){
        if(tokens[i][0] == '+'){
            stack[--top] = stack[top - 1] + stack[top]; 
        }
        else if(*tokens[i] == '-' && tokens[i][1] == '\0'){
            stack[--top] = stack[top - 1] - stack[top]; 
        }
        else if(*tokens[i] == '*'){
            stack[--top] = stack[top - 1] * stack[top]; 
        }
        else if(*tokens[i] == '/'){
            stack[--top] = stack[top - 1] / stack[top]; 
        }
        else{
            stack[++top] = atoi(tokens[i]);
        }
    }
    int result = stack[0];
    free(stack);
    return result;
}