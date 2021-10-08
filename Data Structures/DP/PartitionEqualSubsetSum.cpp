/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


*/


int dp[209][99009];
    bool canPartition(vector<int>& nums){
        
        memset(dp,-1,sizeof(dp));
        int i=0;
        int j=nums.size();
        int sum=0;
        for(i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        i=0;
        if(sum%2!=0)
            return 0;
        return ans(nums,sum,0,i);
    }
    
    bool ans(vector<int>nums,int sum,int total,int i)
    {
        
        if(i>=nums.size())
            return 0;
        if(total==sum/2)
            return 1;
        if(total>sum/2)
            return 0;
        if(dp[i][total]!=-1)
            return dp[i][total];
        
        
        return dp[i][total]=(ans(nums,sum,total+nums[i],i+1) || ans(nums,sum,total,i+1));
    }
