class Solution {
public:
    int compress(vector<char>& chars) {
       int index = 0;
       int i= 0;
       while(i<chars.size()){
           int j = i+1;
           while(j< chars.size()&& chars[i]== chars[j]){
               j++;
           }
           chars[index++]=chars[i];
           int count = j-i;
           
           if(count>1){
               string ch=to_string(count);
               for(char ch1:ch){
                chars[index++]= ch1;
           }
           }
         i=j;  
       }
       return index;
    }
};