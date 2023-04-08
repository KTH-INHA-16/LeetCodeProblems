class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, vector<int> &arr, int target, vector<int> &temp, int &sum) {
        if(idx==arr.size()) {
            return;
        }
        if(sum>target) return;
        if(sum == target){
            ans.push_back(temp);
            return;
        }

        sum += arr[idx];
        temp.push_back(arr[idx]);

        //take
        solve(idx, arr, target, temp, sum);

        //notTake
        sum -= arr[idx];
        temp.pop_back();
        solve(idx+1, arr, target, temp, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int sum=0;
        solve(0, candidates, target, temp, sum);

        return ans;
    }
};
