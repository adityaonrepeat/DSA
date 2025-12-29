// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks
class Solution {
public:
// The logic is simple we do the task according to the order of minimum-actual means we do that task first which has more diff. We are doing this bcz the task with more diff requires more energy to finish take an example as [16,18],[2,16] if we did 1st task then we can't do 2nd but if 2nd done then we can do 1st with energy as 20
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort according to diff
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b){
            return a[1] - a[0] > b[1] - b[0];
        });
        // Binary search on answer 
        int l = 0, h = 1e9, ans = 0;
        while(l <= h){
            int m = l + (h - l) / 2;
            int e = m;
            bool ok = 1;
            for(auto& t : tasks){
                if(e < t[1]){
                    ok = 0;
                    break;
                }
                e -= t[0];
            }
            // if possible means we can do it in more less energy 
            if(ok){
                ans = m;
                h = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
};
