//
class Solution {
public:
    int flipLights(int n, int presses) {
        if(n>=5 &&presses==1)return 4;
        if(presses==1 && n>3)return n;
        if(presses==1)return n+1;
        if(presses==0)return 1;
        
       if(n==1)return 2;
       if(n==2 && presses==1)return 3;
       if(n==2 || presses==1)return 4;
       if(presses==2)return 7;
       

        return 8;
    }
};
