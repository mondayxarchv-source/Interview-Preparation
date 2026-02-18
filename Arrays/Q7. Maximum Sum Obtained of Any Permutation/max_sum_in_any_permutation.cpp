class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<long long> freq(n+1, 0);

        for(auto &r : requests) {
            freq[r[0]]++;
            freq[r[1]+1]--;
        }

        for(int i=1; i<n; i++) {
            freq[i] = freq[i-1] +freq[i];
        }
        freq.pop_back();

        sort(nums.begin(), nums.end());
        sort(freq.begin(), freq.end());

        long long ans = 0, mod = 1e9 + 7;
        for(int i=0; i<n; i++) {
            ans += nums[i]*freq[i];
        }

        return ans % mod;
    }
};
