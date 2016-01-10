#include<vector>
#include<iostream>
using namespace std;

void atLevel(vector<vector<int>>& res, int n , int a, int start){
	cout<<"n="<<n<<endl;
    res[a][a] = start+1;
    cout<<"point("<<a<<","<<a<<") = "<<"point("<<a<<","<<a-1<<")+1="<<res[a][a]<<endl;
    if(1==n)
        return;
    for(int i = 1; i <n; i++){
        res[a][a+i] = res[a][a+i-1]+1;
        cout<<"point("<<a<<","<<a+i<<") = "<<"point("<<a<<","<<a+i-1<<")+1="<<res[a][a+i]<<endl;
    }
    for(int i = 1; i <n; i++){
        res[a+i][n+a-1] = res[a+i-1][n+a-1]+1;
        cout<<"point("<<a+i<<","<<n+a-1<<") = "<<"point("<<a+i-1<<","<<n+a-1<<")+1="<<res[a+i][n+a-1]<<endl;
    }      
    for(int i = n-2; i >=0; i--){
        res[n+a-1][i+a] = res[n+a-1][a+i+1]+1;
        cout<<"point("<<n+a-1<<","<<i+a<<") = "<<"point("<<n+a-1<<","<<i+a+1<<")+1="<<res[n+a-1][i+a]<<endl;
    }
    for(int i = n-2; i >0; i--){
        res[i+a][a] = res[a+i+1][a]+1;
        cout<<"point("<<i+a<<","<<a<<") = "<<"point("<<i+1+a<<","<<a<<")+1="<<res[a+i][a]<<endl;
    }

}
vector<vector<int>> generateMatrix(int n) {
    if(0>=n)
        return vector<vector<int>>();
    vector<vector<int>> res(n,vector<int>(n,0));
    atLevel(res,n,0,0);
    for(int a=1;a<=(n-1)/2;a++)
        atLevel(res,n-a*2,a,res[a][a-1]);
    return res;
}

int main(){
	generateMatrix(4);
	return 0;
}
