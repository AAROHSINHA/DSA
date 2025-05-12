#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given an integer array arr[] and an integer k, determine whether there exist two indices i and j such that arr[i] == arr[j] and |i – j| ≤ k. If such a pair exists, return ‘Yes’, otherwise return ‘No’.
*/

// TC - O(N*K)
bool checkDuplicatesWithinK1(vector<int>& arr, int k) {
    // your code
    for(int i = 0; i < arr.size(); i+=1){
        int j = i + 1;
        while(j < arr.size() && j - i <= k){
            if(arr[i] == arr[j]){
                return true;
            }
            j++;
        }
    }
    return false;
}

// T.C - O(N)
// S.C - O(N)
bool checkDuplicatesWithinK(vector<int>& arr, int k) {
    // your code
    unordered_map<int, int> hashmap;
    for(int i = 0; i < arr.size(); i+=1){
        if(hashmap.find(arr[i])!=hashmap.end()){
            if(i - hashmap[arr[i]] <= k){
                return true;
            }
        }
        hashmap[arr[i]] = i;
    }
    return false;
}

int main(){

    return 0;
}