#include <iostream>
#include <vector>
using namespace std;

int circularSubarraySum(vector<int> &arr) {
    int currSum = 0;
    int maxSum = 0;
    int dist = 0;
    int currentMaxSum = 0;
    for(int j = 0; j < arr.size()*2; j+=1){
        int i = j%arr.size();
        if(dist == arr.size()){
            currentMaxSum = max(currentMaxSum, maxSum);
            currSum = 0;
            continue;
        }

        currSum += arr[i];
        if(currSum < 0) dist = 0;
        if(currSum < arr[i]) currSum = arr[i];
        maxSum = max(currSum, maxSum);
        dist++;
    }
    return maxSum;
}

// SMALLEST POSITIVE MISSING ELEMENT
/*
Here approach is to use array indices
create array of size maxElem + 1
negative numbers - incremenet 0th index
positive numbers - incremenet the number th index
then iterate and find at which index the value is 0 and return

Only thing in my mind is at worst case an vector of 10^6 size will form
but let's see
*/
int missingNumber(vector<int> &arr) {
    int maxElem = 1;
    for(int a : arr) maxElem = max(maxElem , a);
    vector<int> vec(maxElem + 1, 0);
    for(int i = 0; i < arr.size(); i+=1){
        if(arr[i] <= 0){
            vec[0]+=1;
        }else{
            vec[arr[i]]++;
        }
    }

    // get the maxIndex
    for(int i = 1; i < vec.size(); i+=1){
        if(vec[i] == 0) return i;
    }
    return maxElem+1;
} // works just fine

// minJumps
int minJumps(vector<int>& arr) {
    // code here
    if(arr[0] == 0) return -1;
    int jumpCount = 0;
    int i = 0;
    while(i < arr.size()){
        if(arr[i] == 0) return -1;
        if(arr[i] == 1){
            jumpCount++;
            i++;
        }
        else{
            int possibles = arr[i];
            if(i + possibles >= arr.size() - 1){
                jumpCount++;
                break;
            };
            
            int j = i + 1;
            int max = -1;
            int maxPtr = 0;
            while(j < arr.size() && possibles > 0){
                if(arr[j] > max){
                    maxPtr = j;
                    max = arr[j];
                }else if(arr[j] + j > maxPtr + max){
                    maxPtr = j;
                    max = arr[j];
                }
                j++;
                possibles--;
            }
            i = maxPtr;
            jumpCount+=1;
        }
    }
    return jumpCount;
}

int main(){
    vector<int> inp = {1, 4, 3, 2, 6, 7};
    cout << minJumps(inp) << "\n";
    return 0;
}



/*
#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t > 0){
        string name;
        getline(cin, name);
        
        string shortName = "";
        for(int i = 1; i < name.length(); i+=1){
            if(name[i - 1] == ' '){
                shortName += name[i] + "";
            }
        }
        cout << shortName << "\n";
        
        t-=1;
    }
    return 0;
}
*/