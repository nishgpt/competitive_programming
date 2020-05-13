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
#define MAX 41
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (1L<<62)
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

inline void inp( int &n ) { 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

inline void inp1( LL &n ) { 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

int get_bits(LL n) {
	if(n == 0) return 0;
	return log2(n) + 1; 
}

void convert_to_binary(LL num, vector<int> &v) {
	queue<int> q;
	while(num) {
		q.push(num&1);
		num>>=1;
	}
	
	for(int i=MAX-1;i>=0;i--) {
		if(q.empty()) break;
		else {
			v[i] = q.front();
			q.pop();
		}
	}
}

LL convert_to_decimal(vector<int> &bin) {
	LL x = 1;
	LL decimal = 0; 
	for(int i=MAX-1;i>=0;i--) {
		decimal = decimal + bin[i] * x;
		x<<=1;
	}
	
	return decimal;
}

void compute_sums(LL n, vector<LL> &s) {
	vector<int> v(MAX, 0);
	convert_to_binary(n, v);
	
	LL prev = 0, fix = 1L;
	for(int i=0;i<MAX;i++) {
		s[i] =  prev;
		if(v[i]) s[i] += (fix << (MAX-i-1));
		prev = s[i];
	}
}

int main() {
	int t;
	LL one = 1L;
	LL z, temp;
	LL x, y, l, r;
	LL kuch;
	int kuchb;
	inp(t);
	
	while(t--) {
		inp1(x);inp1(y);inp1(l);inp1(r);
		
		//only solving first subtask
		if(l == 0 && r > 2*max(x, y)) {
			z = (x|y);
			if(min(x,y) == 0) z = 0;
			cout<<z<<endl;
		} 
		
		else {
			if(min(x, y) == 0) {
				cout<<l<<endl;
				continue;
			}
			int rbits = get_bits(r);
			int lbits = get_bits(l);
			vector<LL> sums(MAX, 0);
			compute_sums(l, sums);
						
			LL xory = x|y;
			LL prod = -1;
			LL ans_final = -1;
			LL cmp = ~l;
			
			//check with l first
			z = (l & xory);
			kuch = (z & cmp);
			if(kuch > 0) {
				kuchb = get_bits(kuch);
				z = z | sums[MAX-kuchb-1];
			} else {
				z = z | l;
			}
			if(z >= l && z<= r) {
				temp = (z&x) * (z&y);
				if(prod < temp) {
					prod = temp;
					ans_final = z;
				} else if(prod == temp) {
					ans_final = min(ans_final, z);
				}
			}
			
			//~===========================================================
			
			//check for bits from lbits to rbits-1
			for(int i=lbits;i<rbits;i++) {
				z = (one<<i) - 1;
				z = (z & xory);
				
				kuch = (z & cmp);
				if(kuch > 0) {
					kuchb = get_bits(kuch);
					z = z | sums[MAX-kuchb-1];
				} else {
					z = z | l;
				}
				
				temp = (z&x) * (z&y);
				if(prod < temp) {
					prod = temp;
					ans_final = z;
				} else if(prod == temp) {
					ans_final = min(ans_final, z);
				}
			}
			
			//now for bits already in r
			vector<int> rbin(MAX, 0);
			convert_to_binary(r, rbin);
			
			int o = 0;
			LL left = 0;
			for(int i=0;i<MAX;i++) {
				if(rbin[i] == 0) continue;
				++o;
				
				if(o == 1) {
					left = left + (one << (MAX-i-1));
					continue;
				}
				
				//start from second set most significant bit
				//try to unset it and set remaining all bits after
				LL add = left + (one << (MAX-i-1)) - 1;
				z = (add & xory);
				kuch = z & cmp;
				if(kuch > 0) {
					kuchb = get_bits(kuch);
					z = z | sums[MAX-kuchb-1];
				} else {
					z = z | l;
				}
				
				if(z >= l && z<= r) {
					temp = (z&x) * (z&y);
					if(prod < temp) {
						prod = temp;
						ans_final = z;
					} else if(prod == temp) {
						ans_final = min(ans_final, z);
					}
				}
				//include this 1 in left now
				left = add + 1;
			}
			
			z = (r & xory);
			kuch = (z & cmp);
			if(kuch > 0) {
				kuchb = get_bits(kuch);
				z = z | sums[MAX-kuchb-1];
			} else {
				z = z | l;
			}
			if(z >= l && z<= r) {
				temp = (z&x) * (z&y);
				if(prod < temp) {
					prod = temp;
					ans_final = z;
				} else if(prod == temp) {
					ans_final = min(ans_final, z);
				}
			}
			
			cout<<ans_final<<endl;
		}
	}
    return 0;
}

