// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000

//Code

#define TABLE_SIZE 1001

typedef struct Node{
    int val;
    struct Node* next;
}Node;

int hash(int key){
    if(key<0) key = -key;
    return key%1001;
}

void insert(Node** table, int key){
    int idx = hash(key);
    Node* curr = table[idx];
    while(curr){
        if(curr->val == key){
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = key;
    newNode->next = table[idx];
    table[idx] = newNode;
}

bool contains(Node** table, int key){
    int idx = hash(key);
    Node* curr = table[idx];
    while(curr){
        if(curr->val == key){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    Node* table[TABLE_SIZE] = {0};
    int* result = (int*)malloc(sizeof(int)* (nums1Size<nums2Size?nums1Size:nums2Size));
    *returnSize = 0;
    for(int i = 0; i<nums1Size; i++){
        insert(table, nums1[i]);
    }
    for(int i = 0; i<nums2Size; i++){
        if(contains(table, nums2[i]) && !contains(table, -nums2[i]-1)){
            result[(*returnSize)++] = nums2[i];
            insert(table, -nums2[i]-1);
        }
    }
    return result;
}