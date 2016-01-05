/*
int maxProfitFrom(vector<int>& prices,int start,int end){
    if(start >= end){
        return 0;
    }
    int i=start;
    while(i<=end-1){
        if(prices[i] > prices[i+1])
            break;
        i++;
    }
    return prices[i]-prices[start]+maxProfitFrom(prices,i+1,end);
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        return maxProfitFrom(prices,0,prices.size()-1);
    }
};*/

int maxProfit(int[] prices) {
        if (prices.length < 2) return 0;
        int max = 0;
        for (int i = 1; i < prices.length; i++) 
            max += Math.max(0, prices[i] - prices[i-1]);
        return max;
}
