#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N];
void in(int a[])
{
    for (int i = 0; i < N; i++)
        a[i] = rand();
}
void userInput(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    //    in(a);
    int n, k;
    cout << "enter n:";
    cin >> n;
    cout << "nth element is :" << fib(n - 1) << endl;

    // iterative fib
    // sc:o(n) if storing in array
    // tc:o(n);
    int fibo[n];
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == 1)
            fibo[i] = i;
        else
            fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    //    print(fibo,n);
    // recursive
    // tc:o(2^n), sc:o(n)
    cout << "nth element is :" << fibo[n - 1] << endl;
}
