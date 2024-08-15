class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0, count10 = 0, count20 = 0;

        for(int i : bills){
            if(i == 5)
            count5++; 

            else if(i == 10){
                if(count5 < 1){
                    return false;
                }
                else{
                    count5--;
                }
                count10++;
            }

            else{
                count20++;
                if(count10 < 1 && count5 < 3)
                return false;

                else{
                    if(count10 >= 1 && count5 >= 1){
                        count10--;
                        count5--;
                    }
                    else if(count10 < 1 && count5 >=3)
                    count5 -= 3;

                    else
                    return false;
                }
            }
        }
        return true;
    }
};