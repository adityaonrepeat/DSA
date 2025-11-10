// https://leetcode.com/problems/maximum-swap
class Solution {
public:
    int maximumSwap(int num)
    {

        int i;
        string number=to_string(num);

        unordered_map<char,int> ump;
        priority_queue<pair<char,int>> maxheap;

        for(i=0;i<number.size();i++)
            ump[number[i]]=i;

        for(i=0;i<number.size();i++)
            maxheap.push({number[i],i});

        for(i=0;i<number.size();i++)
        {
            if(number[i]==maxheap.top().first)
                maxheap.pop();
    
            else
            {
                int swapIdx=ump[maxheap.top().first];

                swap(number[i],number[swapIdx]);
            
                break;
            }
        }
        
        return stoi(number);
    }
};
