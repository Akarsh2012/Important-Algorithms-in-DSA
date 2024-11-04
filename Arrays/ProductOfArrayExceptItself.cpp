class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        // 1st approach is ...stand on a index run a loop to get the left multiplication and then another loop to get the right multiplication ..but it will take O(n^2)
        int n=nums.size();
        vector<int> ans(n,1);


        for(int i=1;i<n;i++)
        {
            ans[i]=ans[i-1]*nums[i-1];
        }
        int right=1;
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=ans[i]*right;
            right=right*nums[i];
        }
        return ans;
        
    }
};