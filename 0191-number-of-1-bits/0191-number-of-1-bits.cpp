class Solution {
public:
    int hammingWeight(uint32_t n) {
        std::string str = std::bitset<32>(n).to_string();
        int count = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '1') { // Compare to the character '1'
                count++;
            }
        }
        return count;
    }
};