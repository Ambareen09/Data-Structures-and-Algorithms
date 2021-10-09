/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
*/


//Function for the same:

int maxSubArray(vector<int>& nums) {
        int max_so_far=nums[0];
        int max_now=nums[0];
        
      for( int x=1;x<nums.size();x++){
          max_now=max(max_now+nums[x],nums[x]);
          max_so_far=max(max_so_far,max_now);
      }
        
        return max_so_far;
    }
