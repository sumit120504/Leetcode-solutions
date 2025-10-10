// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

// Example 1:

// Input: nums = [1,2,3,1]

// Output: true

// Explanation:

// The element 1 occurs at the indices 0 and 3.

// Example 2:

// Input: nums = [1,2,3,4]

// Output: false

// Explanation:

// All elements are distinct.

// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]

// Output: true

 

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

//Code
#define TABLE_SIZE 10007

typedef struct Node{
    int val;
    struct Node* next;
}Node;

int hash(int key){
    if (key<0) key = -key;
    return key % 10007;
}

bool insert(Node** table, int key){
    int idx = hash(key);
    Node* curr = table[idx]; 
    while(curr){
        if(curr->val == key) return true;
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = key;
    newNode->next = table[idx];
    table[idx] = newNode;
    return false;
}

bool containsDuplicate(int* nums, int numsSize) {
    Node* table[TABLE_SIZE] = {0};
    for(int i= 0; i<numsSize; i++){
        if(insert(table, nums[i])) return true;
    }
    return false;
}