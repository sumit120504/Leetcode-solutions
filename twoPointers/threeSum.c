// 15. 3Sum

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
 

// Constraints:

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105



//Code

int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 3)
        return NULL;
    int capacity = 100;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int _sum = nums[left] + nums[right] + nums[i];
            if (_sum == 0) {
                if (*returnSize >= capacity) {
                    capacity*=2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (left < right && nums[right] == nums[right - 1])
                    right--;
                while (left < right && nums[left] == nums[left + 1])
                    left++;

                left++;
                right--;
            } else if (_sum > 0) {
                right--;
            } else {
                left++;
            }
        }
    }
    return result;
}