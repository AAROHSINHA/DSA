#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;
// 24 MARCH 2025

int getSecondLargest(vector<int> &arr) {
    // using the one pass algorithm only
    int first_largest = INT_MIN;
    int second_largest = INT_MIN;
    for(int i = 0; i < arr.size(); i+=1){
        if(arr[i] > first_largest){
            second_largest = first_largest;
            first_largest = arr[i];
            continue;
        }
        if(arr[i] >= second_largest && arr[i]!=first_largest){
            second_largest = arr[i];
        }
    }
    return second_largest;
}

 /*
    1. three vars, m1, m2, m3. 
    2. if greater than m1, swap all
    3. if between m1 and m2, swap m2 m3
    4. if only greater than m3, m3 is that
    */
int thirdLargest(vector<int> &arr) {
    int first_largest = -1;
    int second_largest = -1;
    int third_largest = -1;
    for(int i = 0; i < arr.size(); i+=1){
        if(arr[i] > first_largest){
            third_largest = second_largest;
            second_largest = first_largest;
            first_largest = arr[i];
            continue;
        }else if(arr[i] > second_largest && arr[i] <= first_largest){
            third_largest = second_largest;
            second_largest = arr[i];
            continue;
        }else if(arr[i] > third_largest){
            third_largest = arr[i];
        }
    }
    cout << first_largest << "\t" << second_largest << "\t" << third_largest << "\n";
    return third_largest;
}

int maxProduct(vector<int> arr) {
    // repeat the above and multiply
    int first_largest = INT_MIN;
    int second_largest = INT_MIN;
    int third_largest = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > first_largest){
            third_largest = second_largest;
            second_largest = first_largest;
            first_largest = arr[i];
            continue;
        }else if(arr[i] > second_largest && arr[i] <= first_largest){
            third_largest = second_largest;
            second_largest = arr[i];
            continue;
        }else if(arr[i] > third_largest){
            third_largest = arr[i];
        }
    }
    cout << first_largest << "\t" << second_largest << "\t" << third_largest << "\n";

    // what if current product can be more if two negatives present (find least 2)
    int cmax = first_largest*second_largest*third_largest;
    int min1 = 0;
    int min2 = 0;
    for(int i = 0; i < arr.size(); i+=1){
        if(arr[i] < min1){
            min2 = min1;
            min1 = arr[i];
            continue;
        }else if(arr[i] > min1 && arr[i] < min2){
            min2 = arr[i];
        }
    }
    if(first_largest*min1*min2 > cmax){
        cmax = first_largest*min1*min2;
    }

    return cmax;
}

int maxConsecutiveCount(vector<int> &arr) {
    int cons = 1;
    int maxCons = 1;
    for(int i = 1; i < arr.size(); i+=1){
        if(arr[i] == arr[i - 1]){
            cons++;
        }else{
            maxCons = max(cons, maxCons);
            cons = 1;
        }
    }
    maxCons = max(cons, maxCons);
    return maxCons;
}

void pushZerosToEnd(vector<int>& arr) {
    int zeroIndex = -1;
    int i = 0;
    while(i < arr.size()){
        if(arr[i] != 0 && zeroIndex >= 0){
            // swap
            arr[zeroIndex] = arr[i];
            arr[i] = 0;
            zeroIndex++; // Move zeroIndex to the next position
        } else if(arr[i] == 0 && zeroIndex == -1){
            zeroIndex = i; // Set zeroIndex to the first zero encountered
        }
        i++;
    }
    
}

void reverseInGroups(vector<int> &arr, int k) {
    if(k <= 1) return;
    int low = 0;
    int high = (arr.size() <= k) ? arr.size() - 1 : low + k - 1;
    bool rev = false;
    int curr = high;
    while(high < arr.size() && low < arr.size() && !rev){
        // swap
        curr = high;
        while(low <= high){
            int temp = arr[high];
            arr[high] = arr[low];
            arr[low] = temp;
            low++;
            high--;
        }
        low = curr + 1;
        if(low + k - 1 >= arr.size()){
            rev = true;
        }else{
            high = low + k - 1;
        }
    }

    if(rev){
        high = arr.size() - 1;
        while(low <= high){
            int temp = arr[high];
            arr[high] = arr[low];
            arr[low] = temp;
            low++;
            high--;
        }
    }
}

int maximumProfit(vector<int> &prices) {
    // prefixMax array
    vector<int> prefixMax(prices.size(), -1);
    for(int i = prices.size() - 2; i>=0; i-=1){
        prefixMax[i] = max(prefixMax[i + 1], prices[i + 1]);
    }
    // now get the stocks
    int maxSum = 0;
    for(int i = 0; i < prices.size(); i+=1){
        if(prefixMax[i] - prices[i] > maxSum){
            maxSum = prefixMax[i] - prices[i];
        }
    }
    return maxSum;
}

int removeElement(vector<int>& arr, int ele){
    int count = 0;
    int eleIndex = -1;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == ele) count++;
        if(eleIndex == -1 && arr[i] == ele){
            eleIndex = i;
            continue;
        }
        if(eleIndex!=-1 && arr[i] != ele){
            // swap
            arr[eleIndex] = arr[i];
            arr[i] = ele;
            eleIndex++;
        }
    }
    return arr.size() - count;
}

vector<int> duplicateK(vector<int> arr, int k){
    vector<int> ans;
    int low = 0;
    int high = arr.size() - 1;
    while(high >= low){
        if(arr[low] == k){
            if(low == high){
                ans.push_back(k);
            }else{
            ans.push_back(k);
            ans.push_back(k);
            }
            high--;
        }else{
            ans.push_back(arr[low]);
        }
        low++;
    }
    return ans;
}

vector<int> leaders(vector<int>& arr) {
    // use prefix max array and then compare
    vector<int> ans;
    vector<int> prefixMax(arr.size(), -1);
    for(int i = arr.size() - 2; i>=0; i-=1){
        prefixMax[i] = max(prefixMax[i + 1], arr[i + 1]);
    }
    for(int i = 0; i < arr.size(); i+=1){
        if(arr[i] >= prefixMax[i]){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

// TWO SUM
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashmap;
    for(int i = 0; i < nums.size(); i+=1){
        if(hashmap.find(target - nums[i]) != hashmap.end()){
            return {hashmap[target - nums[i]], i};
        }
        hashmap[nums[i]] = i;
    }     
    return {};
}

// CONTAINER WITH MOST WATER
int maxArea(vector<int>& height) {
    // first prefix Max
    vector<int> prefixMax(height.size(), -1);
    vector<int> prefixIndex = {0};
    int lastMaxIndex1 = 0;
    for(int i = 1; i < height.size(); i+=1){
        if(height[i - 1] > prefixMax[i - 1]){
            prefixMax[i] = height[i - 1];
            prefixIndex.push_back(1);
            lastMaxIndex1 = i - 1;
        }else{
            prefixMax[i] = prefixMax[i - 1];
            prefixIndex.push_back(i - lastMaxIndex1);
        }
    }     
    
    int maxWaterHeld = INT_MIN;
    for(int i = 0; i < height.size(); i+=1){
        maxWaterHeld = max(maxWaterHeld, min(prefixMax[i], height[i])*prefixIndex[i]);
    }

    // now suffix Max
    vector<int> suffixMax(height.size(), -1);
    vector<int> suffixIndex(height.size(), 0);
    int lastMaxIndex2 = 0;
    for(int i = height.size() - 2; i >= 0; i-=1){
        if(height[i + 1] > suffixMax[i + 1]){
            suffixMax[i] = height[i + 1];
            suffixIndex[i] = 1;
            lastMaxIndex2 = i + 1;
        }else{
            suffixMax[i] = suffixMax[i + 1];
            suffixIndex[i] = lastMaxIndex2 - i;
        }
    }
    for(int i = 0; i < height.size(); i+=1){
        maxWaterHeld = max(maxWaterHeld, min(suffixMax[i], height[i])*suffixIndex[i]);
    }


    // for(int a : suffixMax){
    //     cout << a << " ";
    // }
    // cout << "\n";
    // for(int b : suffixIndex){
    //     cout << b << " ";
    // }
    // cout << "\n";
    // for(int c : height){
    //     cout << c << " ";
    // }
    // cout << "\n";
    // cout << maxWaterHeld << "\n";
    return maxWaterHeld;
}

// THREE SUM
vector<vector<int>> threeSum(vector<int>& nums) {
     
}

int main(){
    vector<int> vec = {-1,0,1,2,-1,-4};
    vector<vector<int>> rvec = threeSum(vec);
    for(int i = 0; i < rvec.size(); i++){
        cout << rvec[i][0] << " " << rvec[i][1] << " " << rvec[i][2] << "\n";
    }
    return 0;
}

/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array
        std::vector<std::vector<int>> answer;
    std::sort(nums.begin(), nums.end());
    for(int offset = 0; offset < nums.size(); offset+=1){
        if(nums[offset] > 0){
            break;
        }else if(offset > 0 && nums[offset] == nums[offset-1]){
                continue;
            }
        int low = offset + 1;
        int high = nums.size() - 1;
        while(high > low){
            int sum = nums[offset] + nums[low] + nums[high];
            if(sum == 0){
                answer.push_back({nums[offset], nums[low], nums[high]});
                low+=1;
                high-=1;
                while(high > low && nums[low] == nums[low-1]){
                    low++;
                }
                while(high > low && nums[high] == nums[high+1]){
                    high-=1;
                }
            }else if(sum > 0){
                high-=1;
            }else{
                low+=1;
            }
        }
    }
    return answer;
    }
};
*/