#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> res(size,1);
    int left = 1;
    int right = 1;
    for(int i=0;i<size;i++){
        res[i] *= left;
        res[size-i-1] *=right;
        std::cout << res[i] << endl;
        std::cout << res[i] << endl;
        left*=nums[i];
        right*=nums[size-1-i];
    }
    return res;
}

int main(){
	vector<int> v(2,0);
	vector<int> res = productExceptSelf(v);
	
	for (std::vector<int>::iterator it = res.begin() ; it != res.end(); ++it)
    	std::cout << ' ' << *it;
    return 0;
}
