class Solution {

public:

    vector<string> generateParenthesis(int n) {

        vector<string> res;

        if(0==n)

            return res;

        generateParenthesisHelper(res,n,"",0,0);

        return res;

    }

    

    void generateParenthesisHelper(vector<string>& res,int n, string s, int left, int right){

        if(left == n && right == n){

            res.push_back(s);

            return;

        }

        if(left<n) generateParenthesisHelper(res, n, s+"(",left+1, right);

        if(left>right) generateParenthesisHelper(res, n, s+")",left, right+1);

    }

};
