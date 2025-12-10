// https://leetcode.com/problems/create-maximum-number
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(); int m = nums2.size(); 
        int removal = n + m - k; vector<int> ans;
        for(int r1 = 0; r1 <= min(removal, n) ; r1 ++){
            // how many i am removing from rem1
            // i remove using monotonic stack 
            int rem1 = r1;
            stack<int> h;
            stack<int> o;
            int rem2 = removal - rem1;
            if(rem2 > m) continue;
            for(int a : nums1){
                while(!h.empty() && rem1 && h.top() < a){
                    h.pop(); rem1 --;
                }
                h.push(a);
            }
            while(rem1){
                h.pop(); rem1 --;
            }
            for(int a : nums2){
                while(!o.empty() && rem2 && o.top() < a){
                    o.pop(); rem2 --;
                }
                o.push(a);
            }
            while(rem2){
                o.pop(); rem2 --;
            }
            vector<int> d1; vector<int> d2;
            while(!h.empty()){
                d1.push_back(h.top()); h.pop();
            }
            while(!o.empty()){
                d2.push_back(o.top()); o.pop();
            }
            reverse(d1.begin(),d1.end()); reverse(d2.begin(),d2.end());
            int p1 = 0;
            int p2 = 0;
            vector<int> current;
            if(d1 < d2) swap(d1,d2);
            while(p1 < d1.size() && p2 < d2.size()){
                if(d1[p1] > d2[p2]){
                    current.push_back(d1[p1]); p1 ++;
                }
                else if(d1[p1] == d2[p2]){
                    int y1 = p1; int y2 = p2;
                    while(y1 < d1.size() && y2 < d2.size() && d1[y1] == d2[y2]){
                        y1 ++; y2 ++;
                    }
                    if(y1 == d1.size()){
                        current.push_back(d2[p2]);
                        p2 ++;
                    }
                    else if(y2 == d2.size()){
                        current.push_back(d1[p1]);
                        p1 ++;
                    }
                    else{
                        if(d1[y1] > d2[y2]){
                            current.push_back(d1[p1]);
                            p1 ++;
                        }
                        else{
                            current.push_back(d2[p2]);
                            p2 ++;
                        }
                    }
                }
                else{
                    current.push_back(d2[p2]); p2 ++;
                }
            }
            while(p1 < d1.size()){
                current.push_back(d1[p1]); p1 ++;
            }
            while(p2 < d2.size()){
                current.push_back(d2[p2]); p2 ++;
            }
            if(ans.size() == 0) ans = current;
            ans = max(ans, current);
        }
        return ans;
    }
};
