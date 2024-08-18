class Solution {
public:
    bool isPrime(int num){
        if(num <= 1)
            return false;
        if(num == 2 || num == 3)
            return true;
        if(num % 2 == 0 || num % 3 == 0)
            return false;

        for(int i = 5; i * i <= num; i += 6){
            if(num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }

    bool isValid(int num){
        for(int i = 2; i <= num; i++){
            if(num % i == 0){
                if(isPrime(i)){
                    if(i != 2 && i != 3 && i != 5)
                        return false;
                }
            }
        }
        return true;
    }

    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;

        int i = 2;
        int count = 1; // 1 is already counted as the first ugly number

        while(n > count){
            if(isValid(i)){
                count++;
            }
            i++;
        }

        return i - 1; // Because the loop increments i before checking the condition
    }
};
