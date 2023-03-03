#include <iostream>
#include <vector>
using std::vector;

class Solution{
public:
    int removeElement(vector<int>& nums,int val){
        int slowIndex = 0;
        for (int firstIndex = 0; firstIndex <nums.size(); firstIndex++){
            if (nums[firstIndex] != val){
                nums[slowIndex++] = nums[firstIndex];

            }
        }
        return slowIndex;

    }

};

int main(){

    vector<int> nums{0,1,2,2,3,0,4,2};
    int val = 2;
    Solution mysolution;
    int len = mysolution.removeElement(nums,val);
    std::cout << len << std::endl;
    for (int i=0;i < len; i++){
        std::cout << nums[i] << std::endl;
    }
    return 0;
}