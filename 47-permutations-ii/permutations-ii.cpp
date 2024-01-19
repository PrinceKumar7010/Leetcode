class Solution {
    vector<vector<int>> res;
    void generate(int idx, vector<int>& arr) {
        if (idx == arr.size()) {  // if swapping of elements reach till end then store it 
            res.push_back(arr);
            return;
        }
        int i = idx, curr = INT_MIN;
        while (i < arr.size()) {
            if (arr[i] != curr) { // if arr[i]!=curr that means new element found and find its permutation
                curr = arr[i];
                vector<int> temp = arr;
                swap(arr[idx], arr[i]); // first swap curr idx element with ith ele
                int key = arr[i];
                int j = i - 1;
                /* Move elements greater than key to one position ahead of their
                current position as swapped element swapped at ith pos which is not sorted acc to 
                curr ele ex:- 1 2 3 1 , swap(1,3) 3 is placed for permutation but 1 is placed after
                2 which is not in sorted manner and we want permutation in sorted order */
                while (j > idx && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
                generate(idx + 1, arr); // generate permution for elements after idx
                arr = temp; // backtrack by replacing the arr with not updated arr;
            }
            i++;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // sort initially so that we can detect duplicate in o(n) time
        generate(0,nums);
        return res;
    }
};
