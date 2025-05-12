#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

// Find majority element by Moore's algorithm
int findMajorityElement(vector<int> arr){
    int candidate = -1;
    int count = 0;
    for(int i = 0; i < arr.size(); i+=1){
        if(count == 0){
            candidate = arr[i];
            count = 1;
            continue;
        }

        if(arr[i] == candidate) count++;
        else count--;
    }

    // now check for the candidate
    int candidateCount = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == candidate) candidateCount++;
    }

    return (candidateCount > arr.size()/2) ? candidate : -1;
}

// majority element 2
vector<int> findMajority(vector<int>& arr){
    // note that there can be atmost two majority elements in the array
    vector<int> res;
    int candidate1 = -1;
    int count1 = 0;
    int candidate2 = -1;
    int count2 = 0;
    for(int i = 0; i < arr.size(); i+=1){
        if(count1 == 0){
            candidate1 = arr[i];
            count1 = 1;
            continue;
        }
        if(count2 == 0 && count1!=0){
            candidate2 = arr[i];
            count2 = 1;
            continue;
        }
        if(arr[i] == candidate1){
            count1++;
        }else{
            if(arr[i] == candidate2){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
    }

    // now check for both candidate 1 and candidate 2
    int c1, c2 = 0;
    for(int i = 0; i < arr.size(); i+=1){
        if(arr[i] == candidate1) c1++;
        if(arr[i] == candidate2) c2++;
    }
    if(c1 > arr.size()/3) res.push_back(candidate1);
    if(c2 > arr.size()/3) res.push_back(candidate2);
    return res;
}

// Stock buy and sell - Multiple transaction allowed
// int maximumProfit(vector<int> &prices) {
//     int currIndex = 0;
//     int sellIndex = currIndex + 1;
//     int maxProfit = 0;
//     int currMax = prices[currIndex];
//     while(sellIndex < prices.size() && currIndex < prices.size()){
//         if(prices[sellIndex] > currMax){
//             currMax = prices[sellIndex];
//         }else if(prices[sellIndex] < prices[currIndex]){
//             cout << prices[currIndex] << " - " << prices[sellIndex] << "\n";
//             maxProfit += currMax - prices[currIndex];
//             currIndex = sellIndex;
//             currMax = prices[currIndex];
//         }
//         sellIndex++;
//     }
//     if(currIndex < prices.size() && prices[prices.size() - 1] > prices[currIndex]){
//         maxProfit += prices[prices.size() - 1] - prices[currIndex];
//     }
//     cout << currIndex << "\n";
//     return maxProfit;
// }
int maximumProfit(vector<int>& prices){
    int profits = 0;
    for(int i = 1; i < prices.size(); i+=1){
        if(prices[i] > prices[i - 1]){
            profits+=prices[i] - prices[i-1];
        }
    }
    return profits;
}

int maxSubarraySum(vector<int> &arr) {
    int currSum = 0;
    int maxSum = arr[0];
    for(int i = 0; i < arr.size(); i+=1){
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if(currSum < 0) currSum = 0;
    }
    return maxSum;
}

int maxProduct(vector<int> &arr) {
    int currProduct = 1;
    int maxProduct = arr[0];
    for(int i = 0; i < arr.size(); i+=1){
        currProduct*=arr[i];
        maxProduct = max(currProduct, maxProduct);
        if(arr[i] > maxProduct){
            maxProduct = arr[i];
            currProduct = arr[i];
        }
    }       
    return maxProduct;
}

// Maximise number of 1s
int maxOnes1(vector<int>& arr, int k) {
    // maximum betweens
    int first = -1;
    int maxCount = 0;
    for(int i = 0; i < arr.size(); i+=1){
        if(arr[i] == 1){
            first = i;
            break;
        }
    }
    // condition if the first is somewhere beteen then atmost ones
    if(first!=0){
        if(first <= k){
            maxCount = first + 1;
        }else{
            maxCount = k + 1;
        }
    }
    int second = first+1;
    while(second < arr.size() && first < arr.size()){
        if(arr[second] == 0){
            second++;
        }else{
            // arr[second] = 1
            int betweenZeros = second - first - 1;
            int count = 0;
            if(betweenZeros <= k){
                count = second - first + 1;
            }else{
                count = k + 1;
            }
            maxCount = max(count, maxCount);
            first = second;
            second++;
        }
    }
    return maxCount;
}

int maxOnes5(vector<int>& arr, int k) {
    // code here
    int numFlips = k;
    int maxSize = 0;
    int subStartIndex = 0;
    int size = 0;
    int lastOne = 0;
    while(subStartIndex < arr.size()){
        if(arr[subStartIndex] == 0){
            numFlips-=1;
            subStartIndex++;
        }else{
            lastOne = subStartIndex;
            subStartIndex++;
        }
        if(numFlips == 0){
            maxSize = max(size, maxSize);
            numFlips = k;
            subStartIndex = lastOne;
            size = 0;
        }
        size++;
    }
    return maxSize;
}

// NEXT PERMUTATION
/*
1. Find the first element from right lesser than its next element - pivot element
2. THen find the rightmost (RiGhTmOsT - first element from right) just greter than pivot element
3. Swap these
4. Then reverse the subarray after pivot index
*/
void nextPermutation(vector<int>& arr) {
    // 1. Find the pivot element index (as we will swap it in future)
    int pivotIndex = -1;
    for(int i = arr.size() - 2; i >= 0; i--){
        if(arr[i] < arr[i  + 1]){
            pivotIndex = i;
            break;
        }
    }
    if(pivotIndex == -1){
        int low = 0;
        int high = arr.size() - 1;
        while(high >= low){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
        return;
    }
    
    // 2. Now find the RiGhTmOsT element just greater than the element at the pivot index
    int rightMostIndex = -1;
    for(int i = arr.size() - 1; i>= 0; i--){
        if(arr[i] > arr[pivotIndex]){
            rightMostIndex = i;
            break;
        }
    }

    if(pivotIndex == -1){
        int low = 0;
        int high = arr.size() - 1;
        while(high >= low){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
        return;
    }
    // if not found then what????????
    if(rightMostIndex == -1) return;
    // 3. Now swap them
    int temp = arr[rightMostIndex];
    arr[rightMostIndex] = arr[pivotIndex];
    arr[pivotIndex] = temp;

    // 4. Now reverse the array after the pivotIndex
    int low = pivotIndex + 1;
    int high = arr.size() - 1;
    while(high >= low){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

void printArray(vector<int>& arr){
    for(int a : arr) cout << a << " ";
    cout << "\n";
}

// MINIMIZE HEIGHTS
vector<int> findSplit(vector<int>& arr) {
        bool foundIteration = false;
        vector<int> res = {-1, -1};
        // first find whole sum
        int wholeSum = 0;
        for(int a : arr){
            wholeSum += a;
        }
        int iSum = 0;
        int midSum = 0;
        int jSum = arr[arr.size() - 1];

        for(int i = 0; i < arr.size() - 1; i++){
            foundIteration = false;
            iSum += arr[i];
            for(int j = arr.size() - 2; j > i; j-=1){
                midSum = wholeSum - iSum - jSum;
                cout << iSum << " " << midSum << " " << jSum << "\n";
                if(midSum == iSum && midSum == jSum){
                    res[0] = i;
                    res[1] = j;
                    foundIteration = true;
                }
                jSum += arr[j];
            }
            if(foundIteration) break;
            jSum = arr[arr.size() - 1];
        }
        return res;
}

// maximize number of ones
int maxOnes(vector<int>& arr, int k) {
        int size = 0;
        int maxSize = 0;
        int numFlips = k;
        int currPtr = 0;
        while(currPtr < arr.size()){
            if(arr[currPtr] == 1){
                size++;
                maxSize = max(size, maxSize);
                currPtr++;
            }else{
                // arr[i] == 0
                if(numFlips > 0){
                    size++;
                    maxSize = max(size, maxSize);
                    numFlips-=1;
                    currPtr++;
                }else{
                    maxSize = max(size, maxSize);
                    currPtr-=1;
                    while(arr[currPtr] == 1 && currPtr >= 0){
                        currPtr-=1;
                    }
                    currPtr++;
                    size = 0;
                    numFlips = k;
                }
            }
        }
        maxSize = max(size, maxSize);
        return maxSize;
}

// // MAXIMUM PRODUCT SUBARRAY
// int maxProduct(vector<int> &arr) {
//     int n = arr.size();
//     int currMax = arr[0];
//     int currMin = arr[0];
//     int maxProd = arr[0];
//     for (int i = 1; i < n; i++) {
//         int temp = max( arr[i], max(arr[i] * currMax, arr[i] * currMin) );
//       	currMin = min( arr[i], min(arr[i] * currMax, arr[i] * currMin) );
//         currMax = temp;
//         maxProd = max(maxProd, currMax);
//     }
//     return maxProd;
// }

// Subarray product less than k
long long countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
    long long product = 1;
    long long start = 0;
    long long end = 0;
    long long res = 0;
    while(end < n){
        product *= arr[end];
        while(start < end && product >= k){
            product/=arr[start];
            start++;
        }
        if(product < k){
            int len = end - start + 1;
            res += len;
        }
        end++;
    }
    return res;
}

bool doesIntersect(vector<int> a, vector<int> b) {
    // Check if intervals a and b do not intersect
    if(a[1] == b[0] || a[0] == b[1]) return true;
    if (b[0] >= a[1] || a[0] >= b[1]) {
        return false;  // No intersection
    } 
    return true;  // Intersecting
}

vector<vector<int>> findIntersection(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> res;
    
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (doesIntersect(a[i], b[j])) {
                // Calculate intersection range: [max(a[i][0], b[j][0]), min(a[i][1], b[j][1])]
                res.push_back({max(a[i][0], b[j][0]), min(a[i][1], b[j][1])});
            }
            // No need for break here, as we want to continue checking other intervals in b
        }
    }
    return res;
}

/*
SEARCH IN ROTATED SORTED ARRAY
// */
// int search(vector<int>& nums, int target) {
//     int low = 0;
//     int high = nums.size() - 1;
//     int mid = low + (high - low)/2;
//     while(high >= low){
//         mid = low + (high - low)/2;
//         if(nums[mid] == target){
//             return mid;
//         }else{
//             // check if left half sorted
//             if(nums[low] < nums[mid]){
//                 // if yes check if element is in the sorted half
//                 if(target >= nums[low] && target <= nums[mid]){
//                     // then we need to go to the left part by - 
//                     high = mid - 1;
//                 }else{
//                     // means traget is in the unsorted half. go there and repeat the same
//                     low = mid + 1;
//                 }
//             }
//             // else condition means right half is sorted.
//             // check if element in the sorted half (right)
//             else{
//                 if(target >= nums[mid] && target <= nums[high]){
//                     low = mid + 1;
//                 }else{
//                     // means target is in the left unsorted half
//                     high = mid - 1;
//                 }
//             }
//         }
//     }

//     return -1;
// }

int search(vector<int>& nums, int target){
    int low = 0;
int high = nums.size() - 1;

while (high >= low) {
    int mid = low + (high - low) / 2;

    // If target is found, return the index
    if (nums[mid] == target) {
        return mid;
    }

    // Check if the left half is sorted
    if (nums[low] <= nums[mid]) {
        // If yes, check if the target is in the sorted half
        if (target >= nums[low] && target <= nums[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    // Else, the right half must be sorted
    else {
        // If yes, check if the target is in the sorted half
        if (target >= nums[mid] && target <= nums[high]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
}

return -1; // Target not found

}

// find first and last occurance of an element - (lower npund and upper npund)
// 1 - lower bound
int lowerBound(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    int mid = low + (high - low)/2;
    while(high >= low){
        mid = low + (high - low)/2;
        if(nums[mid] == target){
            if(mid > 0 && nums[mid - 1] == target){
                high = mid - 1;
            }else{
                return mid;
            }
        }else if(nums[mid] > target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int upperBound(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    int mid = low + (high - low)/2;
    while(high >= low){
        mid = low + (high - low)/2;
        if(nums[mid] == target){
            if(mid < nums.size() - 1 && nums[mid + 1] == target){
                low = mid  + 1;
            }else{
                return mid;
            }
        }else if(nums[mid] > target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int firstMissingPositive(vector<int>& nums) {
    int smallest = INT_MAX;
    int largest = INT_MIN;
    for(int num : nums){
        smallest = min(num, smallest);
        largest = max(num, largest);
    }
    if(smallest > 1){
        return 1;
    }
    int size = nums.size() + 1;
    int div = (smallest <= 0) ? 1 : smallest;
    vector<int> res(size, -1);
    for(int i = 0; i < nums.size(); i+=1){
        if(nums[i] <= 0){
            res[0] = 1;
            continue;
        }
        if(div!=1){
        res[nums[i]%div] = 1;
    }else{
        res[nums[i]] = 1;
    }
}

    int ind = -1;
    for(int i = 1; i < res.size(); i+=1){
        if(res[i] == -1){
            ind = i;
            break;
        }
    }
    if(ind == -1) return largest + 1;
    return (div <= 1 ? 0 : div) + ind;
}

int trap(vector<int>& height) {
    // prefixMax
    vector<int> prefixMax;
    prefixMax.push_back(height[0]);
    for(int i = 1; i < height.size(); i++){
        prefixMax.push_back(max(prefixMax[i - 1], height[i]));
    }       
    // suffixMax
    vector<int> suffixMax(height.size(), 0);
    suffixMax[height.size() - 1] = height[height.size() - 1];
    for(int i = height.size() - 2; i >= 0; i-=1){
        suffixMax[i] = max(suffixMax[i + 1], height[i]);
    }

    int waterCount = 0;
    for(int i = 0; i < height.size(); i++){
        if(height[i] < prefixMax[i] && height[i] < suffixMax[i]){
            waterCount += min(prefixMax[i], suffixMax[i]) - height[i];
        }
    }

    return waterCount;

}

int jump(vector<int>& nums) {
    int i = 0;
    int j = i + 1;
    int count = 0;
    int currTurns = nums[i];
    int cMax = nums[j];
    int cInd = j;
    while(j < nums.size() && i < nums.size()){
        if(nums[i] == 0) return count;
        if(j + currTurns >= nums.size()){
            count++;
            return count;
        }
        if(currTurns > 0){
            if(nums[j] > cMax){
                cMax = nums[j];
                cInd = j;
            }
            currTurns -= 1;
        }else{
            i = cInd;
            j = i + 1;
            currTurns = nums[i];
            count++;
        }
    }
    return count;
}

void rotate(vector<vector<int>>& matrix) {
    vector<vector<int>> matrix2;
    for(int col = 0; col < matrix[0].size(); col++){
        vector<int> vec(matrix[0].size(), 0);
        for(int row = 0; row < matrix.size(); row++){
            vec[vec.size() - 1 - row] = matrix[row][col];
        }
        matrix2.push_back(vec);
    }        

    // now put them in matrix1 in reverse
    matrix = matrix2;
}

/*
vector<vector<int>> cols;
    int col1 = 1;
    int col2 = matrix.size() - 1;

    int start = 0;
    int end = matrix[0].size() - 1;

    bool positive  = false;
    while(col2 >= col1){
        vector<int> currVec;
        if(positive){
            cout << start << "\n";
            for(int i = col2; i>= col1; i-=1){
                currVec.push_back(matrix[i][start]);
            }
            int temp = col1;
            col1 = col2 + 1;
            col2 = col1;
            start++;
            // col1++;
            positive = false;
        }else{
            // something
            int i = col1;
            for(int i = col1; i <= col2; i+=1){
                currVec.push_back(matrix[i][end]);
            }
            int temp = col1;
            col1 = col2 - 1;
            col2 = temp;
            // end--;
            end--;
            positive = true;
        }
        cols.push_back(currVec);
    }
    return cols;
*/

// SPIRAL MATRIX
vector<vector<int>> spiralOrder_Rows(vector<vector<int>>& matrix) {
    vector<vector<int>> rows;
    int col1 = 0;
    int col2 = matrix.size() - 1;
    bool positive = true;
    int n = matrix[0].size();
    
    int start = 0;
    int end = n - 1;

    while(col1 <= col2){
        vector<int> currVec;
        if(positive){
            // something
            for(int i = start; i <= end; i++){
                currVec.push_back(matrix[col1][i]);
            }
            // new end = current start + 1
            // new start = current end -1
            int temp = start;
            start = end - 1;
            end = temp;
            col1++;
            positive = false;
        }else{
            // something
            for(int i = start; i>= end; i--){
                currVec.push_back(matrix[col2][i]);
            }
            int temp = start;
            start = end + 1;
            end = temp;
            col2--;
            positive = true;
        }
        rows.push_back(currVec);
    }
    return rows;
}

vector<vector<int>> spiralOrder_Cols(vector<vector<int>>& matrix){
    vector<vector<int>> cols;
    int start = 0;
    int end = matrix[0].size() - 1;
    int countPasses = 0;
    int col1 = 1;
    int col2 = matrix.size() - 1;
    bool positive = false;
    while(col2 >= col1){
        vector<int> currVec;
        if(positive){
            // something
            for(int i = col2; i >= col1; i--){
                currVec.push_back(matrix[i][start]);
            }
            col1++;
            positive = false;
        }else{
            // something
            for(int i = col1; i <= col2; i+=1){
                currVec.push_back(matrix[i][end]);
            }
            col2--;
            positive = true;
        }
        // if(col1 == col2 && countPasses == 1) break; // making mushkil haina
        countPasses++;
        if(countPasses == 2){
            countPasses = 0;
            start++;
            end--;
            // col1++;
            // col2--;
        }

        cols.push_back(currVec);

    }   
    return cols;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<vector<int>> rows = spiralOrder_Rows(matrix);
    vector<vector<int>> cols = spiralOrder_Cols(matrix);
    vector<int> finalAns;
    bool rowsAdd = true;
    int rowPtr = 0;
    int colPtr = 0;
    while(rowPtr < rows.size() || colPtr < cols.size()){
        if(rowsAdd){
            // something
            if(rowPtr < rows.size()){
                for(int row : rows[rowPtr]){
                    finalAns.push_back(row);
                }
            }
            rowPtr++;
            rowsAdd = false;
        }else{
            // something
            if(colPtr < cols.size()){
                for(int col : cols[colPtr]){
                    finalAns.push_back(col);
                }
            }
            colPtr++;
            rowsAdd = true;
        }
    }


    return finalAns;
}

    // bool compareString(string str1, string str2) {
    //     if (str1.size() != str2.size()) return false;
    //     unordered_map<char, int> hashmap;
    //     for (char ch : str1) {
    //         hashmap[ch]++;
    //     }
    //     for (char ch : str2) {
    //         if (hashmap[ch] == 0) return false;
    //         hashmap[ch]--;
    //     }
    //     return true;
    // }

    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     unordered_map<int, int> hashmap;
    //     vector<vector<string>> vec;
    //     for(int i = 0; i < strs.size(); i+=1){
    //         if(hashmap[i] > 0) continue;
    //         vector<string> currVec = {strs[i]};
    //         for(int j = i + 1; j < strs.size(); j++){
    //             if(compareString(currVec[0], strs[j])){
    //                 hashmap[j]++;
    //                 currVec.push_back(strs[j]);
    //             }
    //         }
    //         vec.push_back(currVec);
    //     }
    //     return vec;
    // }

// vector<vector<string>> groupAnagrams(vector<string>& strs){
//     unordered_map<string, vector<string>> hashmap;
//     for(int i = 0; i < strs.size(); i+=1){
//         string curr = strs[i];
//         sort(curr.begin(), curr.end());
//         if(hashmap.find(curr) != hashmap.end()){
//             vector<string> cv = hashmap[curr];
//             cv.push_back(strs[i]);
//             hashmap[curr] = cv;
//             continue;
//         }
//         hashmap[curr] = {strs[i]};
//     }

//     vector<vector<string>> vec;
//     for(auto val : hashmap){
//         vec.push_back(val.second);
//     }
//     return vec;
// }

vector<vector<int>> merge(vector<vector<int>> intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0]; // Compare start times
    });

    stack<vector<int>> st;
    st.push(intervals[0]);
    int i = 1;
    while(i < intervals.size()){
        // if somehow st is empty put intervals[i] (edge case--although wont be)
        vector<int> currVec = st.top();
        vector<int> thisVec = intervals[i];
        if(currVec[0] > currVec[1]) currVec = {currVec[1], currVec[0]};
        if(thisVec[0] > thisVec[1]) thisVec = {thisVec[1], thisVec[0]};
        if(currVec[1] >= thisVec[0] && currVec[0] <= thisVec[1]){
            vector<int> newVec = {min(currVec[0], intervals[i][0]), max(currVec[1], intervals[i][1])};
            st.pop();
            st.push(newVec);
        }else{
            st.push(intervals[i]);
        }
        i++;
    }   
    vector<vector<int>> v(st.size(), {0, 0});
    int ind = v.size() - 1;
    while(!st.empty()){
        v[ind--] = st.top();
        st.pop();
    }
    return v;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hashmap;
    for(int i = 0; i < strs.size(); i++){
        string curr = strs[i];
        sort(curr.begin(), curr.end());
        if(hashmap.find(curr) != hashmap.end()){
            vector<string> cv = hashmap[curr];
            cv.push_back(strs[i]);
            hashmap[curr] = cv;
        }else{
            hashmap[curr] = {strs[i]};
        }
    }

    vector<vector<string>> vec;
    for(auto val : hashmap){
        vec.push_back(val.second);
    }
    return vec;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> vec;
    vector<vector<int>> curr;
    unordered_map<int, int> hashmap;
    for(int n : nums){
        hashmap[n]++;
    }
    for(auto val : hashmap){
        curr.push_back({val.first, val.second});
    }

    // now we need to sort on the basis of second
    sort(curr.begin(), curr.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] > b[1];
    });
    // now get k elements
    for(int i = 0; i < k; i+=1){
        vec.push_back(curr[i][0]);
    }
    return vec;
}

int main(){
    vector<int> merg = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 1, 3, 3};
    vector<int> a = topKFrequent(merg, 2);
    for(int v : a){
        cout << v << " ";
    }
    cout << "\n";
    return 0;
}
