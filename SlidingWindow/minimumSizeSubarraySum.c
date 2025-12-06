// 209. Minimum Size Subarray Sum
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0
 

// Constraints:

// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104
 

// Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

//Code
int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0, output  = numsSize+1, sum = 0, len, flag = 0;
    for(int right = 0; right < numsSize; right++){
        sum+=nums[right];
        while(sum>=target){
            sum-=nums[left]; left++;
            flag = 1;
            len = right - left + 2;
        if(len<output) output = len;
        }
    }
    if(flag == 0) return 0;
    return output;
}