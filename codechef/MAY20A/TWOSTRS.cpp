/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 100005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

inline void inp( int &n ) {
    n=0;
    int ch=getcx();
    int sign=1;
    while( ch < '0' || ch > '9' ) {
        if(ch=='-')sign=-1;
        ch=getcx();
    }
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}

inline void inp1( LL &n ) {
    n=0;
    LL ch=getcx();
    LL sign=1;
    while( ch < '0' || ch > '9' ) {
        if(ch=='-')sign=-1;
        ch=getcx();
    }
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}

/* 
 * construct apoints[], bpoints[] containing already calculated points
 * i.e apoints[i] contains total points for substring of a with i characters from 0
 * i.e points across all n strings given
 * complexity = O(al * n * (100 + 26)), ~1.2 * 10^6 iterations
*/

void preprocess(string p, int *pie, int m) {
    int q,k=0;
    pie[1]=0;
    rep(q,2,m+1) {
        while(k>0&&p[k]!=p[q-1])
            k=pie[k];
        if(p[k]==p[q-1])
            k++;
        pie[q]=k;
    }
}

int KMP(string s,string p,int *pie,int n,int m) {
    int i,q=0;//q is no. of characters matched
    int occurences = 0;
    rep(i,0,n) {
        while(q>0&&p[q]!=s[i])
            q=pie[q];
        if(p[q]==s[i])q++;
        if(q==m) {
            occurences++;
            q=pie[q];
        }
    }

    return occurences;
}

void compute_subs(string x, string *sub, int l, bool forward) {
    for(int i=0; i<=l; i++) {
        sub[i] = "";
        if(forward) sub[i] = sub[i] + x.substr(0, i);
        else {
            if(i > 0) sub[i] = sub[i] + x.substr(l-i, i);
        }
    }
}

int main() {
    int t, n, i, j;
    string a, b;

    inp(t);
    string ss = "aabb";
    int pp[4];
    preprocess(ss, pp, 4);
    for(i=0;i<4;i++) cout<<pp[i]<<" ";

    while(t--) {
        cin>>a;
        cin>>b;

        inp(n);
        string s[n];
        LL points[n];

        for(i=0; i<n; i++) {
            cin>>s[i];
            cin>>points[i];
        }

        int al = a.length(), bl = b.length();

        string asub[al+1]; //asub[i] is the string with i characters
        string bsub[bl+1];
        LL apoints[al+1], bpoints[bl+1];
        MSV(apoints, 0);
        MSV(bpoints, 0);

        compute_subs(a, asub, al, true);
        compute_subs(b, bsub, bl, false);
        
		for(j=0;j<n;j++) {
			int sl = s[j].length();
			int pie[sl+1];
			preprocess(s[j], pie, sl);
			for(i=1;i<=al;i++) {
				int cnt = KMP(asub[i], s[j], pie, i, sl);
				apoints[i] += (cnt * points[j]);
			}
			
			for(i=1;i<=bl;i++) {
				int cnt = KMP(bsub[i], s[j], pie, i, sl);
				bpoints[i] += (cnt * points[j]);
			}
		}

        LL ans = 0;
        for(i=0; i<=al; i++) {
			for(j=0; j<=bl; j++) {
                if(i+j <= 1) continue;
                LL temp = apoints[i] + bpoints[j];
                
                for(int k=0; k<n; k++) {
					int sl = s[k].length();
					if(sl == 1) continue;
					
					int ti = min(i, sl-1);
					int tj = min(j, sl-1);
					string comb = asub[i].substr(i-ti) + bsub[j].substr(0, tj);
					
					int cl = comb.length();
					if(cl == 0) continue;
					
					int pie[sl+1];
					preprocess(s[k], pie, sl);
					int cnt = KMP(comb, s[k], pie, cl, sl);
					temp += (cnt * points[k]);
				}
                
                ans = max(ans, temp);
            }
        }

        printf("%lld\n", ans);


    }
    return 0;
}

