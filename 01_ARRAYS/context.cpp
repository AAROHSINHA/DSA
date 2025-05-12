#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
    bool zero1 = false;
    bool zero2 = false;
    bool found1 = false;
    int countOnes = 0;
    for(int i = 0; i < s.length(); i++){
        if(!found1 && s[i] == '0') zero1 = true;
        if(zero1 && s[i] == '1') found1 = true;
        if(found1 && s[i] == '0') zero2 = true;
        if(s[i] == '1') countOnes++;
    }
    if(countOnes == s.length()) return s.length();
    if(!(found1 && zero1 && zero2)) return 1;
*/
int edgecase(string s) {
    string a = "1" + s + "1";
    bool found = false;
    for (int i = 1; i < a.size() - 1; i++) {
        if (a[i] == '1' && a[i - 1] == '0' && a[i + 1] == '0') {
            found = true; // Found a 1 surrounded by 0s
        }
    }
    if(found == false){
        // convert the zeros beteeen consecutive ones 
        return s.length() - 1;
    }
    int maxLen = -1;
    int i = 0;
    int j = i + 1;
    while(j < s.length() && i < a.length()){
        if(s[j] == '1'){
            maxLen = max(j - i + 1, maxLen);
            i = j;
            j = i + 1;
        }else{
            j++;
        }
    }
    return maxLen;
}

int maxActiveSectionsAfterTrade(string s) {
        // 1. check if one is surrounded by zeros
    bool zero1 = false;
    bool zero2 = false;
    bool found1 = false;
    bool zeroBefore = false;
    bool zeroAfter = false;
    int countOnes = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1') countOnes++;
        if(!found1 && s[i] == '0') zero1 = true;
        if(zero1 && s[i] == '1') found1 = true;
        if(found1 && s[i] == '0') zero2 = true;
        if(s[i] == '1' && !zeroBefore){
            zeroBefore = true;
            continue;
        } 
        if(s[i] == '1' && zeroBefore){
            zeroAfter = true;
            continue;
        }
    }
    if(countOnes == s.length()) return s.length();
    if(countOnes == 0) return 0;
    if(s[0] == '1' && s[s.length() - 1] == '1' && s.length() > 1){
        return edgecase(s);
    }
    if(!(found1 && zero1 && zero2)){
        if(!zeroBefore) return 1;
        if(!zeroAfter) return 1;
    }

    // augment
    string a = "1" + s;
    a += "1";
    int i = 0;
    int j = i + 1;
    int k = j + 1;
    int startK = false;
    int currMax = INT_MIN;
    vector<int> optimal = {-1, -1, -1};
    while(k < a.length() && j < a.length() && i < a.length()){
        if(a[j] == '1'){
            while(k < a.length() && a[k] != '1'){
                k++;
            }
            // now we have i j k
            int thisMax = k - i + 1;
            if(thisMax > currMax){
                currMax = thisMax;
                optimal = {i, j, k};
            }
            i = j;
            j = k;
            k = j + 1;
        }else{
            j++;
            k = j + 1;
        }
    }
    cout << optimal[0] << "\t" << optimal[1] << "\t" << optimal[2] << "\n";
    // now convert in a, optimal[0] to optimal[2] => 1
    for(int i = optimal[0]; i <= optimal[2]; i++){
        if(a[i] == '0'){
            a[i] = '1';
        }
    }

    // now max ones
    int maxOnes = 0;
    if(s[0] == '1' && s[s.length() - 1] == '1') maxOnes-=1;
    int maxCount = -1;
    for(int i = 1; i < a.length() - 1; i++){
        if(a[i] == '1'){
            maxOnes++;
        }else{
            maxCount = max(maxOnes, maxCount);
            maxOnes = 0; 
        }
    }
    return maxCount == -1 ? maxOnes : maxCount;
    }

int main(){
    string s = "1101"; 
    cout << maxActiveSectionsAfterTrade(s) << "\n";
    return 0;
}