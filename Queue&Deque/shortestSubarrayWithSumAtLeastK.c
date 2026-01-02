// 862. Shortest Subarray with Sum at Least K
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [1], k = 1
// Output: 1
// Example 2:

// Input: nums = [1,2], k = 4
// Output: -1
// Example 3:

// Input: nums = [2,-1,2], k = 3
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 105
// -105 <= nums[i] <= 105
// 1 <= k <= 109

//Code :

#include <limits.h>

int shortestSubarray(int* nums, int numsSize, int k) {
    long long* prefix = (long long*)malloc(sizeof(long long)*(numsSize + 1));
    int* deque = (int*)malloc(sizeof(int)*(numsSize + 1));

    prefix[0] = 0;
    for(int i = 0; i < numsSize; i++){
        prefix[i+1] = prefix[i] + nums[i];
    }

    int front = 0, rear = -1, result = INT_MAX;
    for(int i = 0; i <= numsSize; i++){
        while(front <= rear && prefix[i] - prefix[deque[front]] >= k){
            int len = i - deque[front];
            if(len < result) result = len;
            front++;
        }

        while(front <= rear && prefix[i] <= prefix[deque[rear]]){
            rear--;
        }

        deque[++rear] = i;
    }
    free(prefix);
    free(deque);
    return (result == INT_MAX) ? -1 : result;
}