class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>res;
        vector<int>current(26);
        vector<int>common(26);
        for(char c: words[0])
        common[c-'a']++;

        for(int i = 1 ; i < words.size() ; i++){
            fill(current.begin(),current.end() , 0);

            for(char c: words[i]){
                current[c- 'a']++;
            }

            for(int j = 0; j < 26 ; j++){
                common[j] = min(common[j], current[j]);
            }
        }
        for (int letter = 0; letter < 26; letter++) {
            for (int commonCount = 0;
                 commonCount < common[letter]; commonCount++) {
                res.push_back(string(1, letter + 'a'));
            }
        }

        return res;

    }
};