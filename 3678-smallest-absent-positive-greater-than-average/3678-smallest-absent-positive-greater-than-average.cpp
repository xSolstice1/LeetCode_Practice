class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int avg = sum/n;

        vector<bool> exist(102,false);

        for (int x:nums) {
            if (x>0) {
                exist[x]=true;
            }
        }

        return distance(exist.begin(),find(exist.begin()+max(1,avg+1),exist.end(),false));
    }
};
