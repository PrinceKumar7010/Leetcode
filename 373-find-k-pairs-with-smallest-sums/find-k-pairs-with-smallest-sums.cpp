vector<int> n1;
vector<int> n2;

class Solution {
public:
    struct NumPair {
        int n1_index;
        int n2_index;
        NumPair(int i, int j) : n1_index(i), n2_index(j) {}
        bool operator>(const NumPair& other) const {
            return n1[n1_index] + n2[n2_index] > n1[other.n1_index] + n2[other.n2_index];
        }
        string getKey() {
            return to_string(n1_index) + "-" + to_string(n2_index);
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        n1 = nums1;
        n2 = nums2;

        vector<vector<int>> result;
        std::priority_queue<NumPair, std::vector<NumPair>, std::greater<NumPair>> minHeap;
        minHeap.push({0, 0});
        unordered_map<string, int> visited;

        while (visited.size() < k) {
            auto pair = minHeap.top();
            minHeap.pop();
            if (visited.find(pair.getKey()) != visited.end()) {
                continue;
            }
            visited[pair.getKey()] = 1;
            result.push_back({nums1[pair.n1_index], nums2[pair.n2_index]});

            if (pair.n1_index < nums1.size() - 1) {
                minHeap.push({pair.n1_index + 1, pair.n2_index});
            }
            if (pair.n2_index < nums2.size() - 1) {
                minHeap.push({pair.n1_index, pair.n2_index + 1});
            }
        }
        
        return result;
    }
};