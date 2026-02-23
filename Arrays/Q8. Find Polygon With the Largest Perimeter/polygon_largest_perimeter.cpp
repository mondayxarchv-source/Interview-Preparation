class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long result = -1, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((cur += nums[i]) > nums[i] * 2) {
                result = cur;
            }
        }
        return result;
    }
};
