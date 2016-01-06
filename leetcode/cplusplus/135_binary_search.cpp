#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int size = nums.size();
    int low=0;
    int hight = size-1;
    while(low<=hight){
        int middle = (low+hight)/2;
        if(target==nums[middle]){
            return middle;
        }else if(target<nums[middle]){
            hight = middle-1;
        }else {
            low = middle+1;
        }
    }
    return low;
};

int main(){
	vector<int> a(1,1);
	cout<< searchInsert (a,2) <<endl;
}
