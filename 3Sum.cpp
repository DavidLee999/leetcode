class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int> > res;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < length; ++i)
        {
            int target = -nums[i];
            int front = i + i;
            int rear = length - 1;
            
            while (front < rear)
            {
                int two_sum = nums[front] + nums[rear];
                
                if (two_sum < )
                    
            }
            
            for (int j = i + 1; j < length - 1; ++j)
            {
                for (int k = j + 1; k < length; ++k)
                {
                    if (nums[j] + nums[k] == target)
                    {
                        res.push_back(vector<int> { nums[i], nums[j], nums[k] });
                    }
                    
                    while (nums[k + 1] == nums[k])
                        ++k;
                }
                
                while (nums[j + 1] == nums[j])
                    ++j;
            }
            
            while (nums[i + 1] == nums[i])
                ++i;
        }
        
        return res;
    }
};
