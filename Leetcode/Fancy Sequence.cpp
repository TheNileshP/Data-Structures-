class Fancy {
public:
    const int MOD = 1e9 + 7;
    struct Item {
        int val, factor, sum;
    };
    int factor, sum;
    vector <Item> sequence;
    Fancy() {
        factor = 1, sum = 0;
    }
    int binpow(int b, int exp) {
        int ans = 1;
        while (exp) {
            if (exp & 1) {
                ans = 1ll * ans * b % MOD;
            }
            b = 1ll * b * b % MOD;
            exp >>= 1;
        }
        return ans;
    }
    void append(int val) {
        sequence.push_back({val, factor, sum});
    }
    
    void addAll(int inc) {
        sum = (0ll + sum + inc) % MOD;
    }
    
    void multAll(int m) {
        factor = 1ll * factor * m % MOD;
        sum = 1ll * sum * m % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= sequence.size()) {
            return -1;
        }
        int actualFactor = 1ll * factor * binpow(sequence[idx].factor, MOD - 2) % MOD;
        int actualSum = (0ll + sum - (1ll * actualFactor * sequence[idx].sum) % MOD + MOD) % MOD;
        return (1ll * actualFactor * sequence[idx].val + actualSum) % MOD;
    }
};
