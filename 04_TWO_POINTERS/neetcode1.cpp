#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

// given a sentence. ignoring the whitespace check if it is a palindrome
bool alphanumeric(char c){
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c  >= 48 && c <= 57)){
        return true;
    }
    return false;
}

bool isPalindrome(string s) {
    int low = 0;
    int high = s.length() - 1;
    while(high >= low){
        if(s[low] == ' ' || !alphanumeric(s[low])){
            low++;
            continue;
        }
        if(s[high] == ' ' || !alphanumeric(s[high])){
            high--;
            continue;
        }
        if(tolower(s[low]) != tolower(s[high])){
            return false;
        }
        low++;
        high--;
    }
    return true;
}

// CONTAINER WITH MOST WATER
int maxArea(vector<int>& heights){
        // prefix
        vector<int> prefixHeight = {-1};
        vector<int> prefixIndex = {-1};
        for(int i = 1; i < heights.size(); i+=1){
            if(prefixHeight[i - 1] < heights[i - 1]){
                prefixHeight.push_back(heights[i - 1]);
                prefixIndex.push_back(i - 1);
            }else{
                prefixHeight.push_back(prefixHeight[i - 1]);
                prefixIndex.push_back(prefixIndex[i - 1]);
            }
        }
        // get from prefix
        int areaMax = 0;
        for(int i = 0; i < heights.size(); i+=1){
            areaMax = max(areaMax, min(heights[i], prefixHeight[i])*abs(i - prefixIndex[i]));
        }

        // suffix
        vector<int> suffixMax(heights.size(), -1);
        vector<int> suffixIndex(heights.size(), -1);
        for(int i = heights.size() - 2; i >= 0; i-=1){
            if(suffixMax[i + 1] < heights[i + 1]){
                suffixMax[i] = heights[i + 1];
                suffixIndex[i] = i + 1;
            }else{
                suffixMax[i] = suffixMax[i + 1];
                suffixIndex[i] = suffixIndex[i + 1];
            }
        }
        for(int i = 0; i < heights.size(); i+=1){
            areaMax = max(areaMax, min(heights[i], suffixMax[i])*abs(i - suffixIndex[i]));
        }


        // for(int a : suffixIndex){
        //     cout << a << " ";
        // }
        // cout << "\n";

        return areaMax;
}

// NEETCODE - ENCODE AND DECODE STRING
string encode(vector<string>& strs) {
    string res = "";
    for(int i = 0; i < strs.size(); i+=1){
        res += strs[i];
        if(i < strs.size() - 1){
            res += " ";
        }
    }
    return res;
}

vector<string> decode(string s) {
    // there is one white space after every word
    // using that
    vector<string> res;
    string word = "";
    for(int i = 0; i < s.length(); i+=1){
        if(s[i] == ' '){
            res.push_back(word);
            word = "";
            continue;
        }
        word += s[i];
    }
    if(word.length() > 0){
        res.push_back(word);
    }
    return res;
}

int longestConsecutive(vector<int>& nums) {
    set<int> hashSet;
    for(int num : nums) hashSet.insert(num);
    int maxCons = -1;
    set<int>::iterator it;
    nums = {};
    for(it = hashSet.begin(); it != hashSet.end(); it++){
        nums.push_back(*it);
    }

    // now check
    int currCount = 1;
    bool found = false;
    for(int i = 1; i < nums.size(); i+=1){
        if(nums[i] - nums[i - 1] != 1){
            maxCons = max(maxCons, currCount);
            currCount = 1;
            continue;
        }
        found = true;
        currCount++;

    }
    maxCons = max(currCount, maxCons);
    if(!found) return 0;
    return maxCons;
}

// longest palindromic substrings
/*
    BRUTE FORCE APPROACH
--> Expand around centers
*/
bool checkPalindrome(string str, int low, int high){
    if(low < 0 || high >= str.length()) return false;
    while(high >= low){
        if(str[low] != str[high]){
            return false;
        }
        low++;
        high--;
    }
    return true;
}

// string longestPalindrome(string s) {
//     string longest = "";
//     int start = 0;
//     int end = 0;
//     int maxLen = 1;
//     for(int i = 1; i < s.length() - 1; i++){
//         int low = i - 1;
//         int high = i + 1;
//         while(checkPalindrome(s, low, high)){
//             if(high - low + 1 > maxLen){
//                 maxLen = high - low + 1;
//                 start = low;
//                 end = high;
//             }
//             low--;
//             high++;
//         }
//         if(maxLen == 1){
//             if(checkPalindrome(s, i - 1, i)){
//                 start = i - 1;
//                 end = i;
//                 maxLen = 2;
//             }
//         }
//     }    
//     for(int i = start; i <= end; i+=1){
//         longest += s[i];
//     }
//     return longest;   
// }

string longestPalindrome(string s) {
     
}

int main(){
    string s = "bababd";
    cout << longestPalindrome(s) << "\n";
    return 0;
}