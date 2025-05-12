#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(int k, vector<int>& nums){
    int n = nums.size();
    if(k > n) return {};
    vector<int> ans;
    ans.push_back(nums[0]);
    for(int i = 1; i < n; i++){
        while(!ans.empty() && nums[i]>ans.back() && ans.size()-1+n-i >= k){
            ans.pop_back();
        }
    }
    while(ans.size() > k){
        ans.pop_back();
    }
    return ans;
}
void merge()

int main(){

}

