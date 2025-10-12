// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.
 

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

//Code

typedef struct Node{
    char key;
    int freq;
    struct Node* next;
}Node;

int hash(char key){
    return (key - 97) % 26;
}

void insert(char key, Node** table, int flag){
    int idx = hash(key);
    Node* curr = table[idx];
    while(curr){
        if(curr->key == key){
            curr->freq += flag;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->freq = flag;
    newNode->next = table[idx];
    table[idx] = newNode;
}

bool allZero(Node** table){
    for(int i = 0; i<26; i++){
        Node* curr = table[i];
        while(curr){
            if(curr->freq != 0) return false;
             curr = curr->next;
        }
    }
    return true;
}

bool isAnagram(char* s, char* t) {
    if(strlen(s) != strlen(t)) return false;

    Node* table[26] = {0};

    for(int i = 0; i < strlen(s); i++){
        insert(s[i], table, 1);
        insert(t[i], table, -1);
    }
    bool result = allZero(table);
    for (int i = 0; i < 26; i++) {
        Node* curr = table[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    return result;
}

//Second Approach

// bool isAnagram(char* s, char* t) {
//     int a[256] = {0};
//     for(int i = 0; s[i]!='\0'; i++){
//         a[(unsigned char)s[i]]++; 
//     }
//     for(int i = 0; t[i]!='\0'; i++){
//         a[(unsigned char)t[i]]--; 
//     }
//     for(int i = 0; i<256; i++){
//         if(a[i]!=0) return false;
//     }
//     return true;    
// }