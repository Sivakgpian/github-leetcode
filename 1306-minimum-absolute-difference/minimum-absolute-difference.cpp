class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int mindiff = INT_MAX;

        // First pass: find minimum difference
        for (int i = 0; i < n - 1; i++) {
            mindiff = min(mindiff, arr[i + 1] - arr[i]);
        }

        vector<vector<int>> result;

        // Second pass: collect pairs with minimum difference
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] == mindiff) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }

        return result;
    }
};
