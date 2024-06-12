#include<bits/stdc++.h>
using namespace std;


#define int long long

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define mii map<int, int>
#define msi map<string, int>
#define umap unordered_map
#define pb push_back
#define ppb pop_back
#define fl(i, a, b) for (int i = a; i < b; i++)
#define second ss
#define first ff
#define int long long

const int M = 1e9 + 7;
const double epsilon = 1e-6;
const int ARR = 1e7;
const long long X = 1e12;

template <typename Container>
void printer(const Container &container) {
    for (auto it = std::begin(container); it != std::end(container); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void pairprint(const Container &container) {
    for (auto it = std::begin(container); it != std::end(container); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}

class Sam {
public:
    int binmultiply(int a, int b) {
        int ans = 0;
        while (b > 0) {
            if (b & 1) {
                ans = (ans + a) % M;
            }
            a = (a + a) % M;
            b >>= 1;
        }
        return ans;
    }

    double power(double x, long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = power(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        }
        return x * half * half;
    }

    int fact(int n) {
        int ans = 1;
        fl(i, 1, n + 1) {
            ans = (ans * i) % M;
        }
        return ans;
    }

    double squareroot(int n) {
        double mid, l = 1, r = n;
        while (r - l >= epsilon) {
            mid = l + (r - l) / 2;
            if (mid * mid == n)
                return mid;
            else if (mid * mid < n) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return mid;
    }

    int isprime(long long n) {
        vi v(X, 1);
        v[0] = v[1] = 0;
        fl(i, 2, X) {
            if (v[i] == 1) {
                for (int j = 2 * i; j < X; j += i) {
                    v[j] = 0;
                }
            }
        }
        return v[n];
    }

    unordered_map<int, int> primes(long long n) {
        vi v(n, 1);
        v[0] = v[1] = 0;
        unordered_map<int, int> primefac;
        fl(i, 2, n) {
            if (v[i] == 1) {
                primefac[i] = 1;
                for (int j = 2 * i; j < n; j += i) {
                    v[j] = 0;
                }
            } else {
                primefac[i * i] = 0;
            }
        }
        return primefac;
    }

    int nCr(int n, int r) {
        return fact(n) / (fact(r) * fact(n - r));
    }

    void primefactors(int n) {
        vi v(ARR, 1);
        vi lp(ARR, 0), hp(ARR, 0);
        v[0] = v[1] = 0;
        fl(i, 2, ARR) {
            if (v[i] == 1) {
                lp[i] = hp[i] = i;
                for (int j = 2 * i; j < ARR; j += i) {
                    v[j] = 0;
                    hp[j] = i;
                    if (lp[j] == 0)
                        lp[j] = i;
                }
            }
        }
        vi pfs;
        while (n > 1) {
            int pf = hp[n];
            while (n % pf == 0) {
                n /= pf;
                pfs.pb(pf);
            }
        }
        fl(i, 0, pfs.size()) cout << pfs[i] << " ";
        cout << endl;
    }

    bool isPerfectSquare(long double x) {
        if (x >= 0) {
            long long sr = sqrt(x);
            return (sr * sr == x);
        }
        return false;
    }

    bool parity(int x, int y) {
        return ((x ^ y) & 1) == 0;
    }

    int lenint(int n) {
        return floor(log10(n) + 1);
    }

    template <typename T>
    void remove(std::vector<T> &v, const T &target) {
        v.erase(std::remove(all(v), target), v.end());
    }

    // New Utility Functions

    // Greatest Common Divisor (GCD)
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    // Least Common Multiple (LCM)
    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    // Modular Exponentiation
    int modExp(int x, int y, int p) {
        int res = 1;
        x = x % p;
        while (y > 0) {
            if (y & 1)
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    // Sieve of Eratosthenes
    vector<bool> sieve(int n) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        return is_prime;
    }

    // Prime Factorization
    vector<int> primeFactors(int n) {
        vector<int> factors;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                factors.pb(i);
                n /= i;
            }
        }
        if (n > 1) factors.pb(n);
        return factors;
    }

    // Finding k-th smallest element
    int kthSmallest(vector<int> &arr, int k) {
        nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
        return arr[k - 1];
    }

    // Merge Sort
    void mergeSort(vector<int> &arr) {
        if (arr.size() > 1) {
            int mid = arr.size() / 2;
            vector<int> left(arr.begin(), arr.begin() + mid);
            vector<int> right(arr.begin() + mid, arr.end());
            mergeSort(left);
            mergeSort(right);
            merge(arr, left, right);
        }
    }

private:
    void merge(vector<int> &arr, vector<int> &left, vector<int> &right) {
        auto it = arr.begin();
        auto lit = left.begin(), rit = right.begin();
        while (lit != left.end() && rit != right.end()) {
            *it++ = (*lit <= *rit) ? *lit++ : *rit++;
        }
        while (lit != left.end()) {
            *it++ = *lit++;
        }
        while (rit != right.end()) {
            *it++ = *rit++;
        }
    }
};
