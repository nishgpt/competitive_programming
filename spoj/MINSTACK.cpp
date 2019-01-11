/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 1000005
#define MOD 1000000007
#define getcx getchar_unlocked

using namespace std;

string ip() {
    string i="";
    int temp=getchar_unlocked();
    while(temp<'A'||temp>'Z')
        temp=getchar_unlocked();
    while(temp>='A'&&temp<='Z')
    {
        i+=(char)temp;
        temp=getchar_unlocked();
    }
    return i;
}

inline void inp( int &n )
{
    n=0;    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
    while(  ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}

int a[MAX][2];
int main() {
    int n, v, cnt=-1;
    string s;

    scanf("%d", &n);
    
    while(n--) {
        s = ip();
        if(s[1] == 'U') {
            scanf("%d", &v);

            if(cnt == -1) {
                ++cnt;
                a[cnt][0] = v;
                a[cnt][1] = v;
            } 
            else {
                ++cnt;
                a[cnt][0] = v;
                a[cnt][1] = min(a[cnt-1][1], v);
            }
        }
        else if(s[1] == 'O') {
            if(cnt == -1) {
                printf("EMPTY\n");
                continue;
            }
            cnt--;
        }
        else {
            if(cnt == -1) {
                printf("EMPTY\n");
                continue;
            }
            printf("%d\n", a[cnt][1]);
        }
    }
    return 0;
}

