#include <iostream>
#include <cstring>
#include <cstdlib>
#define ll long long
using namespace std;

ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

ll modulo(ll base, ll ex, ll mod)
{
    ll x = 1;
    ll y = base;
    while (ex > 0)
    {
        if (ex % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        ex = ex / 2;
    }
    return x % mod;
}

bool Miller(ll p,int a)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    ll s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < a; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a = 5;
    ll num;

    int n;
    cin>>n;

    for (int i=0;i<n;i++)
    {
        cin>>num;
        if (Miller(num, a))
            cout<<"TAK"<<endl;
        else
            cout<<"NIE"<<endl;
    }
    return 0;
}
