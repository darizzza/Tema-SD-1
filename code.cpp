#include <iostream>
#define N 1000
using namespace std;
int v[N],n,baza;

int MaximVect(int v[], int n)
{int maxim=v[0];
for(int i=1;i<n;i++)
    if(v[i]>maxim)
        maxim=v[i];
return maxim;
}

void CS(int v[],int n,int exp)
{int r[n],i,f[10]={0};
for(i=0;i<n;i++)
    f[(v[i]/exp)%10]++;

for(i=1;i<10;i++)
    f[i]+=f[i-1];

for(i=n-1;i>=0;i--)
    {r[f[(v[i]/exp)%10]-1]=v[i];
    f[(v[i]/exp)%10]--;
    }

for(i=0;i<n;i++)
    v[i]=r[i];
}

void RadixSort(int v[],int n,int baza)
{int maxim=MaximVect(v,n);
for(int exp=1;maxim/exp>0;exp*=baza)
    CS(v,n,exp);
}


void Interclasare(int st,int mij,int dr)
{int b[N],i,j,k;
i=st;j=mij+1;k=0;
while(i<=mij&&j<=dr)
    if(v[i]<v[j]) b[++k]=v[i++];
    else b[++k]=v[j++];
while(i<=mij) b[++k]=v[i++];
while(j<=dr) b[++k]=v[j++];
for(i=0;i<k;i++) v[st+i]=b[i];
}

void MergeSort(int st,int dr)
{int mij=(st+dr)/2;
if(st<dr)
    {MergeSort(st,mij);
    MergeSort(mij+1,dr);
    Interclasare(st,mij,dr);
    }
else if(v[st]>v[dr])swap(v[st],v[dr]);
}

void ShellSort(int v[],int n)
{for(int interval=n/2;interval>0;interval/=2)
    for(int i=interval;i<n;i++)
        {int x=v[i];
        int j;
        for(j=i;j>=interval&&v[j-interval]>x;j-=interval)
            v[j]=v[j-interval];
        v[j]=x;
        }
}


int Pivotare(int st,int dr)
{int i,j,pasi,pasj,aux;
i=st;j=dr;
pasi=0;pasj=1;
while(i<j)
    {if(v[i]>v[j])
        {aux=v[i];v[i]=v[j];v[j]=aux;
        aux=pasi;pasi=pasj;pasj=aux;
        }
    i+=pasi;j-=pasj;
    }
return i;
}

void QuickSort(int st,int dr)
{if(st<dr)
    {int p=Pivotare(st,dr);
    QuickSort(st,p-1);
    QuickSort(p+1,dr);
    }
}

void CountingSort(int v[], int n)
{int maxim=MaximVect(v,n);
int f[maxim+1]={0};
for(int i=0;i<n;i++)f[v[i]]++;
for(int i=1;i<=maxim;i++)f[i]+=f[i-1];
int r[N];
for(int i=0;i<n;i++)
    {r[f[v[i]]-1]=v[i];
    f[v[i]]--;
    }
for(int i=0;i<n;i++)v[i]=r[i];
}

void Afisare(int v[],int n)
{for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
}

int main()
{
    cin>>n;
    cin>>baza;
    for(int i=0;i<n;i++)
        cin>>v[i];
    RadixSort(v,n,baza);
    MergeSort(0,n-1);
    ShellSort(v,n);
    QuickSort(0,n-1);
    CountingSort(v,n);
    Afisare(v,n);
    return 0;
}
