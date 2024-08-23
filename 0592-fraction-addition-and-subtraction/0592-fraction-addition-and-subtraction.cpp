class Solution {
public:
    // Efficient GCD calculation using the Euclidean algorithm
    int findGCD(int num1, int num2) {
        while (num2 != 0) {
            int temp = num2;
            num2 = num1 % num2;
            num1 = temp;
        }
        return num1;
    }
    
    string fractionAddition(string s) {
        int LCM = 1;
        int numeratorSum = 0;
        int i = 0;
        
        // Process each fraction in the string
        while (i < s.size()) {
            int sign = 1;
            if (s[i] == '-' || s[i] == '+') {
                sign = (s[i] == '-') ? -1 : 1;
                i++;
            }
            
            // Parse the numerator
            int numerator = 0;
            while (i < s.size() && isdigit(s[i])) {
                numerator = numerator * 10 + (s[i] - '0');
                i++;
            }
            numerator *= sign;
            
            // Skip the '/'
            i++;
            
            // Parse the denominator
            int denominator = 0;
            while (i < s.size() && isdigit(s[i])) {
                denominator = denominator * 10 + (s[i] - '0');
                i++;
            }
            
            // Update the LCM of the denominators
            int currentLCM = LCM * denominator / findGCD(LCM, denominator);
            
            // Adjust the current numeratorSum to the new LCM and add the current numerator
            numeratorSum = numeratorSum * (currentLCM / LCM) + numerator * (currentLCM / denominator);
            LCM = currentLCM;
        }

        // Simplify the result by finding the GCD of the numerator and LCM
        int gcd = findGCD(abs(numeratorSum), LCM);
        numeratorSum /= gcd;
        LCM /= gcd;

        // Special case: if the numerator is 0, return "0/1"
        if (numeratorSum == 0)
            return "0/1";
        
        // Return the simplified fraction as a string
        return to_string(numeratorSum) + '/' + to_string(LCM);
    }
};
