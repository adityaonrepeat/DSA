// https://leetcode.com/problems/properties-graph/
class Solution {
public:
    bool isConnected(unordered_map<int, unordered_set<int>>& mp, int k, int i, int j){
        for(auto t: mp[i]) k -= (mp[j].find(t) != mp[j].end())?1:0;
        return (k <= 0);
    }

    int find(int node, vector<int>& par){
        return par[node] = ((par[node] == node)?node: find(par[node], par));
    }

    int add(int a, int b, vector<int>& par){
        int pa = find(a, par), pb = find(b, par);
        par[pb] = pa;
        return (pa != pb) ? 1 : 0; 
    }

    int numberOfComponents(vector<vector<int>>& p, int k) {
        int count = p.size();
        vector<int> par(p.size(), -1);
        unordered_map<int, unordered_set<int>> mp;
        for(int i = 0; i < par.size(); ++i) par[i] = i;

        for(int i = 0; i < p.size(); ++i){           // create the lookup map 
            for(int j = 0; j < p[i].size(); ++j) mp[i].insert(p[i][j]);
        }

        for(int i = 0; i < p.size(); ++i){           
            for(int j = i+1; j < p.size(); ++j){
                if(isConnected(mp, k, i, j)) count -= add(i, j, par);  
                
            }
        }
        return count;
    }
};
