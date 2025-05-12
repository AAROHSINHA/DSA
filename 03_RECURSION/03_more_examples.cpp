#include <iostream>
#include <vector>
using namespace std;

// 1. Get sum of an array in C++
int arraySum(vector<int>& arr) {
    if(arr.size() == 0){
        return 0;
    }
    int lastElem = arr.back();
    arr.pop_back();
    return lastElem + arraySum(arr);
}

// 2. Reverse of a string in cpp
string reverse(string str){
    if(str.empty()){
        return "";
    }
    char curr = str.back();
    str.pop_back();
    return curr + reverse(str);
} 

// 3. Get length of string C
/*
int recLen(string str){
   if(str.length() == 0){
    return 0;
   }
   str.pop_back();
   return 1 + recLen(str);
}
*/
// This is also a good one
/*
Every iteration the str.substr returns the string with the first character removed
ABC -> BC -> C -> _
*/
int recLen(string str)
{
    // Base case: If the string is empty
    if (str == "")
        return 0;
    return 1 + recLen(str.substr(1));
}

// 4. Sum of array using tail recursion
int arrSum(vector<int> &arr, int n, int sum = 0)
{
    if(n == 0){
        return sum;
    }
    return arrSum(arr, n - 1, sum + arr[n - 1]);
}

// 5. Check Palindrome in Cpp string[s...e]
bool isPalRec(string str, int s, int e){
    if(s > e){
        return true;
    }
    if(str[s] == str[e]){
        return isPalRec(str, s+1, e-1);
    }
    return false;
}





int main(){
    string str = "racecar";
    string ans = isPalRec(str, 0, str.length() - 1) ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}
