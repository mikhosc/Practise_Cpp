#include <iostream>
using namespace std;

const int N=205;

int n;
bool C[N][N];
bool Gorna[N], Dolna[N];
int Partner[N];
bool Vis[N];

bool DFS(int i)
{
    for (int j=i+1; j<n; j++)
      if (C[i][j] && Dolna[j] && !Vis[j] && Partner[i]!=j)
      {
         Vis[j] = true;
         if (Partner[j]==-1)
         {
             Partner[j] = i; Partner[i]=j;
             return true;
         }
         else {
             int gornaSkojarzona = Partner[j];
             if (DFS(gornaSkojarzona))
             {
                  Partner[j] = i; Partner[i]=j;
                  return true;
             }
         }
      }
    return false;
}

int main()
{
    cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) C[i][j] = false;
        Gorna[i] = false;
        Dolna[i] = false;
        Partner[i] = -1;
    }
    int liczbaSkojarzen = 0;

    int ile, nr;
    for (int i=0; i<n-1; i++) {
        cin>>ile;
        for (int j=0; j<ile; j++) {
          cin>>nr;
          C[i][nr-1] = true;
        }
    }

    for (int i=0; i<n; i++) {
      Gorna[i]= C[0][i];
      Dolna[i] = C[i][n-1];
    }

    for (int i=0; i<n; i++)
       for (int k=0; k<n; k++)
           if (C[i][k])
              for (int j=0; j<n; j++)
                    if (C[k][j]) C[i][j] = true;

    while (true) {

        bool postep = false;
        for (int i=0; i<n; i++) Vis[i] = false;

        for (int i=1; i<n-1; i++)
           if (Gorna[i] && Partner[i]==-1 && DFS(i)) {
               postep=true; liczbaSkojarzen++;
               }

        if (!postep) break;
    }

    cout<<liczbaSkojarzen;

    return 0;
}
