#include <vector>
#include <unordered_set>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    // 查找速度是 O(1)
    unordered_set<int> window;

    for (int j = 0 ; j < nums.size() ; j++){
        if (window.find(nums[j]) != window.end()){
            return true;
        }

        window.insert(nums[j]);

        if (window.size() > k){
            window.erase(nums[j-k]);
        }

    }
    return false;
}