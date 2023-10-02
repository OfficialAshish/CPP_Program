int solve(vector<int>& nums, int start,int end)
    {
        int p1 = nums[start] , curr; 
        int p2 = max(nums[start+1], p1);

        for(int i= start+2; i<=end ; i++)
        {
            curr = max(p1 + nums[i], p2);
            p1 = p2;
            p2 = curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
    
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int mx1 = solve(nums, 0, n-2);
        int mx2 = solve(nums, 1, n-1);

        int ans=max(mx1, mx2);
        return ans;
    }