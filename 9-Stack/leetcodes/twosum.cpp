#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using std::cout;
using std::vector;
using std::unordered_map;
class Solution{
    public:
    vector<int> twoSum(vector<int> nums, int target){
        int complement;
         unordered_map<int, int> seen;
        
        for (int i = 0; i<nums.size(); ++i){
            complement = target-nums[i];
            auto it = seen.find(complement);
            if (it != seen.end()){
                int index_of_second = it->second;
                return vector<int>{index_of_second, i};
            }
            seen[nums[i]] = i;
            
        }
        return {};
    }
};
int main(){
    vector<int> arr = {2,4,3,4,5,5,64,3,3,2,3};
    Solution soln;
    auto ans = soln.twoSum(arr, 10);
    for (int j:ans){
        cout<<j<<" ";
    }

    return 0;
}