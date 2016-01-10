class Solution {
public:
    int numTrees(int n) {
        if(0==n || 1==n)
            return 1;
        int sum = 0;
        for(int i=0; i<n/2;i++)
            sum +=numTrees(i)*numTrees(n-1-i)*2;
        if(1 ==n%2 ){
            sum +=numTrees(n/2)*numTrees(n/2);
        }
        return sum;
            
    }
};
