class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
    unordered_set<int> seen;

    for (int num : arr) {
        if (seen.find(num * 2) != seen.end()) {
            return true;
        }
        if (num % 2 == 0 && seen.find(num / 2) != seen.end()) {
            return true;
        }
        seen.insert(num);
    }

    return false;
    }
};