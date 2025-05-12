#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

// 3Sum Closest
int threeSumClosest(vector<int>& nums, int target) {
    // first sort the array
    sort(nums.begin(), nums.end());
    
    int minDiff = INT_MAX;
    int minNum = -1;
    for(int offset = 0; offset < nums.size(); offset+=1){
        int low = offset + 1;
        int high = nums.size() - 1;
        while(high > low){
            int sum = nums[offset] + nums[low] + nums[high];
            if(sum == target){
                return sum;
            }
            int currDiff = abs(target - sum);
            if(minDiff > currDiff){
                minDiff = currDiff;
                minNum = sum;
            }
            if(sum > target){
                high--;
            }else{
                low++;
            }
        }
    }
    return minNum;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for(int outer = 0; outer < nums.size() - 1; outer++){
        if(outer>0 && nums[outer]==nums[outer - 1]){
            continue;
        }
        for(int inner = outer + 1; inner < nums.size() - 1; inner++){
            if (inner > outer + 1 && nums[inner] == nums[inner - 1]) continue;
            int low = inner + 1;
            int high = nums.size() - 1;
            while(high > low){
                int sum = nums[outer] + nums[inner] + nums[low] + nums[high];
                if(sum == target){
                    res.push_back({nums[outer], nums[inner], nums[low], nums[high]});
                    low++;
                    high--;
                    while(low < high && nums[low] == nums[low - 1]) low++;
                    while(high > low && nums[high] == nums[high + 1]) high--;
                }else if(sum > target){
                    high-=1;
                }else{
                    low+=1;
                }
            }
        }
        
    }
    return res;

}

// REMOVE DUPLICATES FROM SORTED ARRAY
int removeDuplicates1(vector<int>& nums){
    int i = 0;
    int j = 1;
    int count = 1; // as first element is already counted in comparisions
    while(j < nums.size() && i < nums.size()){
        if(nums[i] == nums[j]){
            j++;
        }else{
            nums[i + 1] = nums[j];
            i = i + 1;
            count++;
        }
    }
    return count;
}

// remove all occurance of a given element
int removeElement(vector<int>& nums, int val) {
    int i = 0;
   int j = 1;
   int count = 0;
    for(int num : nums){
       if(num == val) count++;
   }  
   while(j < nums.size() && i < nums.size()){
       if(nums[i] == nums[j]){
           if(nums[i] == val){
               j++;
           }else{
               i++;
               j++;
           }
       }else{
           if(nums[i] == val){
               nums[i] = nums[j];
               nums[j] = val;
               i+=1;
               j+=1;
           }else{
               i++;
               j++;
           }
       }
   }     
  
   return nums.size() - count;
   }

int removeDuplicates2(vector<int>& nums) {
    int originalSize = nums.size();
    map<int, int> hashmap;
    for(int num:nums){
        hashmap[num]++;
    }
    int count = 0;
    nums = {};
    for(auto val : hashmap){
        if(val.second >= 2){
            nums.push_back(val.first);
            count+=1;
        }
        nums.push_back(val.first);
        count+=1;
    }

    while(originalSize > count){
        nums.push_back(-1);
        originalSize-=1;
    }
    return count;

}

int removeDuplicates(vector<int>& nums) {
    // This is very simple
    if(nums.size() < 3) return nums.size();
    int i = 2;
    for(int j = 2; j < nums.size(); j+=1){
        if(nums[j] != nums[i - 2]){
            nums[i] = nums[j];
            i+=1;
        }
    }
    return i;
}

/*
 // version 2
    string current2 = "";
    for(int i = 0; i < version2.size(); i++){
        if(version2[i] == '.'){
            v2.push_back(convertToInt(current2));
            current2 = "";
            continue;
        }
        current2 += version2[i];
    }
*/
/*

    // now take two pointers to compare
    int ptr1 = 0;
    int ptr2 = 0;
    while(ptr1 < v1.size() || ptr2 < v2.size()){
        int d1 = ptr1 < v1.size() ? v1[ptr1] : 0;
        int d2 = ptr2 < v2.size() ? v2[ptr2] : 0;
        
        if(d1 > d2) return 1;
        if(d2 > d1) return -1;

        ptr1++;
        ptr2++;
    }
*/

int convertToInt(string s){
    int number = 0;
    for(char c : s){
        number*=10;
        number += c - '0';
    }
    return number;
}

int compareVersion(string version1, string version2) {
    vector<int> v1;
    vector<int> v2;      
    // version 1
    string current1 = ""; 
    for(int i = 0; i < version1.size(); i++){
        if(version1[i] == '.'){
            v1.push_back(convertToInt(current1));
            current1 = "";
            continue;
        }
        current1 += version1[i];
    }
    v1.push_back(convertToInt(current1));
    // version 2
    string current2 = "";
    for(int i = 0; i < version2.size(); i++){
        if(version2[i] == '.'){
            v2.push_back(convertToInt(current2));
            current2 = "";
            continue;
        }
        current2 += version2[i];
    }

    v2.push_back(convertToInt(current2));
    // for(int a : v2){
    //     cout << a << " ";
    // }
    // now take two pointers to compare
    int ptr1 = 0;
    int ptr2 = 0;
    while(ptr1 < v1.size() || ptr2 < v2.size()){
        int d1 = ptr1 < v1.size() ? v1[ptr1] : 0;
        int d2 = ptr2 < v2.size() ? v2[ptr2] : 0;
            
        if(d1 > d2) return 1;
        if(d2 > d1) return -1;
    
        ptr1++;
        ptr2++;
    }

    return 0;
}

void rotatePart(vector<int>& nums, int low, int high){
    while(high >= low){
        int temp = nums[high];
        nums[high] = nums[low];
        nums[low] = temp;
        low++;
        high--;
    }
}

void rotate(vector<int>& nums, int k) {
    /*
    Here I use the algorith I remember
    -> divide array into two halves, first half and last half. last half has k elements
    -> reverse both of them seperately
    -> Then reverse the entire array once
    */       
    int pivot = nums.size() - k - 1; // first half contains [0, pivot] inclusive
    rotatePart(nums, 0, pivot);
    rotatePart(nums, pivot + 1, nums.size() - 1);
    rotatePart(nums, 0, nums.size() - 1);
}

int main(){
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    rotate(vec, 3);
    for(int v : vec){
        cout << v << " ";
    }
    cout << "\n";
    return 0;
}
