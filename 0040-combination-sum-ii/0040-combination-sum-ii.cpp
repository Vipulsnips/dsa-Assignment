class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, vector<int> rn, int curr, int sum, int target) {
        if (sum == target) {
            ans.push_back(rn);
            return;
        }
        for (int i = curr; i < candidates.size(); i++) {
            if (i > curr && candidates[i] == candidates[i-1]) {
                continue;
            }
            if (sum + candidates[i] > target) {
                break;
            }
            rn.push_back(candidates[i]);
            solve(candidates, rn, i + 1, sum + candidates[i], target);
            rn.pop_back(); 
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, {}, 0, 0, target);
        return ans;
    }
};