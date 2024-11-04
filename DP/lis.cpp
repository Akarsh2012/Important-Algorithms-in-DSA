#include<bits/stdc++.h>
using namespace std;
int memo(vector<int> & nums,int n,vector<vector<int>> & dp,int i,int prev)
{
    if(i==n) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];   //prev+1 because coordinate shifting
    int len=memo(nums,n,dp,i+1,prev);  //  not picking up the element at index i
    if(prev==-1 || nums[i]>nums[prev]) len=max(len,1+memo(nums,n,dp,i+1,i));  // picking the element at index i only when it greater than the previus picked element
     return dp[i][prev+1]=len;
}
int lis(vector<int> & nums,int n)
{
    // memoization
    vector<vector<int>> dp(n,vector<int>(n+1,-1));  // for shiftion the coordinates for the prev index   i.e 0 represents prev=-1 1 represents 0  .... n represents n-1
    // return memo(nums,n,dp,0,-1);

     // tabulation
     vector<vector<int>> dp(n+1,vector<int>(n+1,0));

     for(int i=n-1;i>=0;i--)
     {
        for(int prev=i-1;prev>=-1;prev--)  // here is the catch i.e prevshould start 1 index before i.. it is so because we cannot pick the index beyonf i that would not be a previous one
        {
            int len=dp[i+1][prev+1];
            if( prev==-1 || nums[i]>nums[prev]) len=max(len,1+dp[i+1][i+1]);
            dp[i][prev+1]=len;
        }
     }
    // return dp[0][0];


     // tabulation but with 1d dp it is a different approach 
     // dp[i] gives the length of lis till index i
       int len=1;
     vector<int> dp(n,1);
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<i;j++)
        {
            if(nums[i]>nums[j])
            {
                dp[i]=max(1+dp[j],dp[i]);
                
            }
            len=max(len,dp[i]);
        }
     }
    // return len;


    // using binary search
     vector<int> temp;
       temp.push_back(nums[0]);
        int length=1;
       for(int i=1;i<n;i++)
       {
         if(nums[i]>temp.back())
         {
            temp.push_back(nums[i]);
            length++;
         }
         else
         {
            int index=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[index]=nums[i];
         }
       }
       return temp.size();
}
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>> nums[i];
    }
    cout<<lis(nums,n)<<endl;
    return 0;
}