class Solution {
public:
    int monkeyMove(int n) {
    long long mod = 1e9 + 7;
    long long res = 1;
    long long base = 2;
    
    // Modular Exponentiation: O(log n) time
    while (n > 0) {
        if (n % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        n /= 2;
    }
    
    // Safely subtract 2 and ensure the result is positive
    return (res - 2 + mod) % mod;
}

};