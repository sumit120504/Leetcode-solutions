// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

 

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]
 

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1
 

// Follow up: Could you minimize the total number of operations done?

//Code 

void moveZeroes(int* nums, int numsSize) {
    int p1 = 0, p2 = 0;
    while(p2<numsSize){
        if(nums[p2]==0){
            p2++;
        }
        else{
            int temp = nums[p1];
            nums[p1] = nums[p2];
            nums[p2] = temp;
            p1++; p2++;
        }
    }
    printf("[");
    for(int i = 0; i < numsSize; i++){
        if(i != numsSize-1) printf("%d,", nums[i]);
        else printf("%d]", nums[i]);
    }
}