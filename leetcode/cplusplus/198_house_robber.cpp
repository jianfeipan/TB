#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums) {
    int a = 0;
    int b = 0;

    for (int i=0; i<nums.size(); i++)
    {
        if (i%2==0)
        {
            a = max(a+nums[i], b);            
        }
        else
        {
            b = max(a, b+nums[i]);
            
        }
        cout<<"b"<<b<<"  a"<<a<<endl;
    }
    return b;
}

int main(){
	vector<int> v={2,1,1,2};
	cout<< rob(v)<<endl;
	return 0;
}
