// 239. Sliding Window Maximum
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length

//Code :
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if(numsSize == 0 || k == 0){
        *returnSize = 0;
        return NULL;
    }
    int* output = (int*)malloc(sizeof(int)*(numsSize+1-k));
    int* deque = (int*)malloc(sizeof(int)*numsSize);
    int front = 0, rear = -1, idx = 0;
    for(int i = 0; i<numsSize; i++){
        if(front <= rear && (deque[front] < i- k + 1)){
            front++;
        }
        while(front <= rear && (nums[i] > nums[deque[rear]])){
            rear--;
        }
        deque[++rear] = i;
        if(i >= k - 1){
            output[idx++] = nums[deque[front]];
        }
    }
    *returnSize = idx;
    free(deque);
    return output;
}   