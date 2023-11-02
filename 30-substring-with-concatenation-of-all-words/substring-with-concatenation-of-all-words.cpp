class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if (s.empty() || words.empty()) {
        return result;
    }

    int word_length = words[0].length();
    int total_length = word_length * words.size();
    unordered_map<string, int> word_count;

    for (const string& word : words) {
        if (word_count.find(word) != word_count.end()) {
            word_count[word]++;
        } else {
            word_count[word] = 1;
        }
    }

    for (int i = 0; i < word_length; i++) {
        int left = i;
        int right = i;
        unordered_map<string, int> current_count;

        while (right + word_length <= s.length()) {
            string word = s.substr(right, word_length);
            right += word_length;

            if (word_count.find(word) != word_count.end()) {
                if (current_count.find(word) != current_count.end()) {
                    current_count[word]++;
                } else {
                    current_count[word] = 1;
                }

                while (current_count[word] > word_count[word]) {
                    string left_word = s.substr(left, word_length);
                    left += word_length;
                    current_count[left_word]--;
                }

                if (current_count == word_count) {
                    result.push_back(left);
                }
            } else {
                current_count.clear();
                left = right;
            }
        }
    }

    return result;
    }
};