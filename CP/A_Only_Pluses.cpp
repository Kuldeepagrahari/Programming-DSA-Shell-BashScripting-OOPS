#include <bits/stdc++.h>
using namespace std;

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

#define LL long long
const int Mod = 1e9 + 7;
const double Epsilon = 1e-6;
const int MaxArraySize = 1e7;
const int MaxPrimeLimit = 1e9;

template <typename Container>
void samPrinter(const Container &samContainer)
{
    for (auto samIt = begin(samContainer); samIt != end(samContainer); ++samIt)
    {
        cout << *samIt << " ";
    }
    cout << endl;
}

template <typename Container>
void samPairPrinter(const Container &samContainer)
{
    for (auto samIt = begin(samContainer); samIt != end(samContainer); ++samIt)
    {
        cout << "(" << samIt->first << ", " << samIt->second << ") ";
    }
    cout << endl;
}

template <typename Container>
void samSetPrinter(const Container &samContainer)
{
    for (auto samIt = begin(samContainer); samIt != end(samContainer); samIt++)
    {
        cout << *samIt << " ";
    }
    cout << endl;
}

class samGraph
{
public:
    int samVertices;
    vector<vector<int>> samAdjacencyList;

    samGraph(int samVertices)
    {
        this->samVertices = samVertices;
        samAdjacencyList.resize(samVertices);
    }

    void samAddEdge(int samVertex1, int samVertex2)
    {
        samAdjacencyList[samVertex1].pb(samVertex2);
        samAdjacencyList[samVertex2].pb(samVertex1); // Assuming undirected graph
    }

    void samBFS(int samStartVertex)
    {
        vector<bool> samVisited(samVertices, false);
        queue<int> samQueue;
        samVisited[samStartVertex] = true;
        samQueue.push(samStartVertex);

        while (!samQueue.empty())
        {
            int samCurrentVertex = samQueue.front();
            cout << samCurrentVertex << " ";
            samQueue.pop();

            for (auto samAdjacentVertex : samAdjacencyList[samCurrentVertex])
            {
                if (!samVisited[samAdjacentVertex])
                {
                    samVisited[samAdjacentVertex] = true;
                    samQueue.push(samAdjacentVertex);
                }
            }
        }
        cout << endl;
    }

    void samDFSUtil(int samVertex, vector<bool> &samVisited)
    {
        samVisited[samVertex] = true;
        cout << samVertex << " ";

        for (auto samAdjacentVertex : samAdjacencyList[samVertex])
        {
            if (!samVisited[samAdjacentVertex])
            {
                samDFSUtil(samAdjacentVertex, samVisited);
            }
        }
    }

    void samDFS(int samStartVertex)
    {
        vector<bool> samVisited(samVertices, false);
        samDFSUtil(samStartVertex, samVisited);
        cout << endl;
    }
};

class samMaths
{
public:
    int samBinMultiply(int samA, int samB)
    {
        int samResult = 0;
        while (samB > 0)
        {
            if (samB & 1)
            {
                samResult = (samResult + samA) % Mod;
            }
            samA = (samA + samA) % Mod;
            samB >>= 1;
        }
        return samResult;
    }

    double samPower(double samBase, long samExponent)
    {
        if (samExponent == 0)
        {
            return 1.0;
        }
        double samHalf = samPower(samBase, samExponent / 2);
        if (samExponent % 2 == 0)
        {
            return samHalf * samHalf;
        }
        return samBase * samHalf * samHalf;
    }

    int samFactorial(int samN)
    {
        int samResult = 1;
        fl(i, 1, samN + 1)
        {
            samResult = (samResult * i) % Mod;
        }
        return samResult;
    }

    double samSquareRoot(int samN)
    {
        double samMid, samLeft = 1, samRight = samN;
        while (samRight - samLeft >= Epsilon)
        {
            samMid = samLeft + (samRight - samLeft) / 2;
            if (samMid * samMid == samN)
                return samMid;
            else if (samMid * samMid < samN)
            {
                samLeft = samMid;
            }
            else
            {
                samRight = samMid;
            }
        }
        return samMid;
    }

    int samIsPrime(int samN)
    {
        vi samPrimeStatus(MaxPrimeLimit, 1);
        samPrimeStatus[0] = samPrimeStatus[1] = 0;
        fl(i, 2, MaxPrimeLimit)
        {
            if (samPrimeStatus[i] == 1)
            {
                for (int j = 2 * i; j < MaxPrimeLimit; j += i)
                {
                    samPrimeStatus[j] = 0;
                }
            }
        }
        return samPrimeStatus[samN];
    }

    mii samAllPrimes(int samN)
    {
        vi samPrimeStatus(samN, 1);
        samPrimeStatus[0] = 0;
        samPrimeStatus[1] = 0;
        map<int, int> samPrimeFactors;
        for (int i = 2; i * i < samN; i++)
        {
            if (samPrimeStatus[i] == 1)
            {
                samPrimeFactors[i] = 1;
                for (int j = 2 * i; j < samN; j += i)
                {
                    samPrimeStatus[j] = 0;
                }
            }
            // else
            // {
            //     samPrimeFactors[i * i] = 0;
            // }
        }
        return samPrimeFactors;
    }

    vi samAllPrimes2(int samN)
    {
        vi samPrimer(samN, 1);
        samPrimer[0] = samPrimer[1] = 0;

        for (int i = 0; i * i <= samN; i++)
        {
            if (samPrimer[i] == 1)
            {
                for (int j = 2 * i; j < samN; j += i)
                {
                    samPrimer[j] = 0;
                }
            }
        }

        return samPrimer;
    }

    int samCalculateNcR(int n, int r)
    {
        int maxi = max(r, n - r);
        int mini = min(r, n - r);

        LL num = 1;
        for (int i = n; i >= 1 + maxi; i--)
        {
            num *= i;
        }

        LL deno = 1;
        for (int i = 1; i <= mini; i++)
        {
            deno *= i;
        }

        return num / deno;
    }

    void samFindPrimeFactors(int samN)
    {
        vi samPrimeStatus(MaxArraySize, 1);
        vi samLowestPrime(MaxArraySize, 0), samHighestPrime(MaxArraySize, 0);
        samPrimeStatus[0] = samPrimeStatus[1] = 0;
        fl(i, 2, MaxArraySize)
        {
            if (samPrimeStatus[i] == 1)
            {
                samLowestPrime[i] = samHighestPrime[i] = i;
                for (int j = 2 * i; j < MaxArraySize; j += i)
                {
                    samPrimeStatus[j] = 0;
                    samHighestPrime[j] = i;
                    if (samLowestPrime[j] == 0)
                        samLowestPrime[j] = i;
                }
            }
        }
        vi samPrimeFactorsList;
        while (samN > 1)
        {
            int samPrimeFactor = samHighestPrime[samN];
            while (samN % samPrimeFactor == 0)
            {
                samN /= samPrimeFactor;
                samPrimeFactorsList.pb(samPrimeFactor);
            }
        }
        fl(i, 0, samPrimeFactorsList.size()) cout << samPrimeFactorsList[i] << " ";
        cout << endl;
    }

    bool samIsPerfectSquare(long double samX)
    {
        if (samX >= 0)
        {
            long long samSqrtValue = sqrt(samX);
            return (samSqrtValue * samSqrtValue == samX);
        }
        return false;
    }

    bool samHasSameParity(int samX, int samY)
    {
        return ((samX ^ samY) & 1) == 0;
    }

    int samGetIntegerLength(int samN)
    {
        return floor(log10(samN) + 1);
    }

    template <typename T>
    void samRemoveElement(vector<T> &samV, const T &samTarget)
    {
        samV.erase(remove(all(samV), samTarget), samV.end());
    }

    // Additional Utility Functions

    int samCalculateGCD(int samA, int samB)
    {
        while (samB)
        {
            samA %= samB;
            swap(samA, samB);
        }
        return samA;
    }

    int samCalculateLCM(int samA, int samB)
    {
        return (samA / samCalculateGCD(samA, samB)) * samB;
    }

    int samModularExponentiation(int samBase, int samExponent, int samMod)
    {
        int samResult = 1;
        samBase = samBase % samMod;
        while (samExponent > 0)
        {
            if (samExponent & 1)
                samResult = (samResult * samBase) % samMod;
            samExponent = samExponent >> 1;
            samBase = (samBase * samBase) % samMod;
        }
        return samResult;
    }

    vector<bool> samSieveOfEratosthenes(int samN)
    {
        vector<bool> samIsPrime(samN + 1, true);
        samIsPrime[0] = samIsPrime[1] = false;
        for (int i = 2; i * i <= samN; i++)
        {
            if (samIsPrime[i])
            {
                for (int j = i * i; j <= samN; j += i)
                {
                    samIsPrime[j] = false;
                }
            }
        }
        return samIsPrime;
    }

    vector<int> samGetPrimeFactors(int samN)
    {
        vector<int> samPrimeFactors;
        while (samN % 2 == 0)
        {
            samPrimeFactors.pb(2);
            samN = samN / 2;
        }
        for (int i = 3; i <= sqrt(samN); i += 2)
        {
            while (samN % i == 0)
            {
                samPrimeFactors.pb(i);
                samN = samN / i;
            }
        }
        if (samN > 2)
        {
            samPrimeFactors.pb(samN);
        }
        return samPrimeFactors;
    }
};

class samBinarySearch
{
public:
    int justLessThanOrEqual(vector<LL> &v, int l, int r, int tar)
    {
        int ans = -1;
        while (r >= l)
        {
            int mid = l + (r - l) / 2;

            if (v[mid] > tar)
            {
                r = mid - 1;
            }
            else if (v[mid] == tar)
                return mid;
            else
            {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
};
class comp
{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.first != p2.first)
            return p1.first < p2.first;
        return p1.second > p2.second;
    }
};

class samProblemSolver
{
private:
    samGraph G();
    samMaths ramanujan;
    samBinarySearch aryabhatt;

public:
    void solve()
    {
        int t;
        cin >> t;

        //    vi primer = ramanujan.samAllPrimes2(1e6);
        //    vi primes (1e6);

        //    for ( int i = 1e6-1; i >= 0; i-- ){
        //        if ( primer[i] == 1 ){
        //         primes[i] = i;
        //        }
        //        else primes[i] = primes[i+1];
        //    }

             // us value se just bada / vo khud prime h ya nhi

        //    samPrinter(primes);
        while (t--)
        {
            int n, k, m;
            cin >> n >> k >> m;
            int v[3] ;
            v[0] = n, v[1] = k, v[2] = m;
            int ans;

            sort(v, v+3);

            int c1 = v[2] - v[1] + v[2] - v[0];
            if(c1 <= 5){
                v[0] = v[2];
                v[1] = v[2];
                int t = 5 - c1;
                v[0] +=  t / 3;
                t -= t/3;
                v[1] += t/2;
                t -= t/2;
                v[2] += t;

                ans = v[0] * v[1] * v[2];
                
            }else{
                int c2 = v[1] - v[0];
                if(c2 <= 5){
                    int t = 5 - c2;
                    v[0] = v[1];
                    
                    v[0] += t /2;
                    t -= t/2;
                    v[1] += t;
                    ans = v[0] * v[1] * v[2];
                }else{
                    ans = (v[0] + 5) * v[1] * v[2];
                }
            }


            



            
            
            cout << ans << endl;
            // samPrinter(ans);
        }
    }
};
int main()
{

    samProblemSolver god;

    god.solve();
}
