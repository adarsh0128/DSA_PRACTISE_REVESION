class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Hashmap to store the frequency of prefix sums
        unordered_map<int, int> mpp;
        mpp[0] = 1; // Initialize with 0 sum to handle case when subarray starts from index 0

        int n = nums.size();
        int sum = 0; // To keep track of the cumulative sum
        int ans = 0; // To count number of subarrays with sum = k

        for (int i = 0; i < n; i++) {
            sum += nums[i]; // Update cumulative sum

            // Check if there is a prefix sum that when subtracted from current sum gives k
            // i.e., (sum - k) must be a previously seen prefix sum
            if (mpp.find(sum - k) != mpp.end()) {
                ans += mpp[sum - k]; // Add the frequency of that prefix sum
            }

            // Update the frequency of current cumulative sum in map
            mpp[sum]++;
        }

        return ans;
    }
};



// ✅ Time Complexity (TC):
// O(n), where n is the number of elements in the input vector nums.

// ✅ Space Complexity (SC):
// O(n) in the worst case for the unordered_map, which can hold up to n unique prefix sums.