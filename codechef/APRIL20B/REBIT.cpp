/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 998244353

using namespace std;

struct data_bag {
	bool is_operator;
	char op;
	LL zz; //where G0=0, G1=0
	LL zo; //where G0=0, G1=1
	LL oz; //where G0=1, G1=0
	LL oo; //where G0=1, G1=1
};

LL power(LL b, LL e, LL ans) {
	if(!e) return ans % MOD;
	if(e&1) ans = (ans * b) % MOD;
	return power((b*b) % MOD, e>>1, ans);
}

data_bag process_and(data_bag left, data_bag right) {
	LL temp = (right.zz + right.zo + right.oz + right.oo) % MOD;
	LL temp1 = (right.zz + right.oz) % MOD;
	LL temp2 = (right.zz + right.zo) % MOD;
	LL temp3 = (right.zo + right.oo) % MOD;
	LL temp4 = (right.oz + right.oo) % MOD;
	
	LL res_zz = ((left.zz * temp) % MOD + (left.zo * temp1) % MOD + (left.oz * temp2) % MOD + (left.oo * right.zz) % MOD) % MOD;
	LL res_zo =  ((left.zo * temp3) % MOD + (left.oo * right.zo) % MOD) % MOD;
	LL res_oz = ((left.oz * temp4) % MOD + (left.oo * right.oz) % MOD) % MOD;
	LL res_oo = (left.oo * right.oo) % MOD;
	
	return (data_bag) {false, '#', res_zz, res_zo, res_oz, res_oo};
}

data_bag process_or(data_bag left, data_bag right) {
	LL temp = (right.zz + right.zo + right.oz + right.oo) % MOD;
	LL temp1 = (right.zz + right.oz) % MOD;
	LL temp2 = (right.zz + right.zo) % MOD;
	LL temp3 = (right.zo + right.oo) % MOD;
	LL temp4 = (right.oz + right.oo) % MOD;
	
	LL res_oo = ((left.zz * right.oo) % MOD + (left.zo * temp4) % MOD + (left.oz * temp3) % MOD + (left.oo * temp) % MOD) % MOD;
	LL res_oz = ((left.zz * right.oz) % MOD + (left.oz * temp1) % MOD) % MOD;
	LL res_zo = ((left.zz * right.zo) % MOD + (left.zo * temp2) % MOD) % MOD;
	LL res_zz = (left.zz * right.zz) % MOD;
	
	return (data_bag) {false, '#', res_zz, res_zo, res_oz, res_oo};
}

data_bag process_xor(data_bag left, data_bag right) {
	LL res_zz = ((left.zz * right.zz) % MOD + (left.zo * right.zo) % MOD + (left.oz * right.oz) % MOD + (left.oo * right.oo) % MOD) % MOD; 
	LL res_zo = ((left.zz * right.zo) % MOD + (left.zo * right.zz) % MOD + (left.oz * right.oo) % MOD + (left.oo * right.oz) % MOD) % MOD;
	LL res_oz = ((left.zz * right.oz) % MOD + (left.zo * right.oo) % MOD + (left.oz * right.zz) % MOD + (left.oo * right.zo) % MOD) % MOD;
	LL res_oo = ((left.zz * right.oo) % MOD + (left.zo * right.oz) % MOD + (left.oz * right.zo) % MOD + (left.oo * right.zz) % MOD) % MOD;
	
	return (data_bag) {false, '#', res_zz, res_zo, res_oz, res_oo};
}

data_bag process(data_bag left, data_bag _operator, data_bag right) {
	if(_operator.op == '&') {
		return process_and(left, right);
	}

	if(_operator.op == '|') {
		return process_or(left, right);
	}

	return process_xor(left, right);
}

data_bag solve(string s) {
	int i, n = s.length();

	data_bag std_hash = {false, '#', 1, 1, 1, 1};
	stack<data_bag> st; 
	for(i=0;i<n;i++) {
		if(s[i] == '(') {
			//ignore
		} else if(s[i] == '#') {
			st.push(std_hash); //standard data bag for #
		} else if(s[i] == ')') {
			data_bag right_operand = st.top();
			st.pop();
			data_bag _operator = st.top();
			st.pop();
			data_bag left_operand = st.top();
			st.pop();
			data_bag result = process(left_operand, _operator, right_operand);
			st.push(result);
		} else {
			//it is some operator
			st.push((data_bag){true, s[i], -1, -1, -1, -1});
		}
	}
	return st.top();
}

LL count_hash(string s) {
	int i, n = s.length();
	LL cnt = 0;
	for(i=0;i<n;i++) {
		if(s[i] == '#') {
			cnt++;
		}
	}
	
	return cnt;
}

int main() {
	int t;
	string s;
	cin>>t;
	while(t--) {
		cin>>s;
		LL cnt_hash = count_hash(s);
		LL q = power(4, cnt_hash, 1); 
		LL q_inverse = power(q, MOD-2, 1);
		data_bag result = solve(s);
		
		//cout<<result.zz<<" "<<result.zo<<" "<<result.oz<<" "<<result.oo<<endl;
		printf("%lld %lld %lld %lld\n", (result.zz * q_inverse) % MOD, (result.oo * q_inverse) % MOD, (result.zo * q_inverse) % MOD, (result.oz * q_inverse) % MOD);
	}
	return 0;
}
