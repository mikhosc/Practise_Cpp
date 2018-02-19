#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int tab[1000009];
long long tabsuf[1000009];
const int INF=1000000009;

long long bins(int l, int p, long long x)
{
  long long sr;
  while(l<=p)
  {
    sr = (l + p)/2;

    if ((x>=tabsuf[sr])&&(x<tabsuf[sr+1]))
        return sr;

    if(tabsuf[sr]==x)
      return sr;

    if(tabsuf[sr]>x)
      p=sr-1;
    else
      l=sr+1;
}

  return -1;
}

int main()
{
    int B,q;
    scanf("%d%d", &B, &q);
    long long suma=0,ile=0;
    for (int i=0;i<B;i++)
    {
        scanf("%d", &tab[i]);
        suma+=tab[i]*i;
        ile+=tab[i];
    }

    long long podz=B-1;
    lldiv_t p = div(suma, podz);

    if (p.rem!=0)
    {
        tab[p.rem]--;
        suma-=tab[p.rem]; ile--;
    }

    for (int i=0;i<=B;i++)
    {
        tabsuf[i+1]=tabsuf[i]+tab[i];
        //cout<<tabsuf[i]<<" ";
    }

    for (int t=0;t<q;t++)
    {
        long long k;
        scanf("%lld", &k);

        if (k>ile)
        printf("-1\n");
        else
        {
            long long pozycja = bins(0,B-1,k);
            printf("%lld\n", pozycja);
        }
    }

    return 0;
}
