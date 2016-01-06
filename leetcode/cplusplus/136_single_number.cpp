#include <iostream>
#include <vector>
#include <numeric> 	
using namespace  std;
int singleNumber(vector<int>& nums) {
    /*int size =nums.size();
    int restult = 0;
    for(int i=0;i<size;i++) {
       restult ^= nums[i];
    }
    return restult;*/
    return std::accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}

int main()
{
	vector<int> v(1,1); 
    cout<<singleNumber(v)<<endl;
    return 0;
}


