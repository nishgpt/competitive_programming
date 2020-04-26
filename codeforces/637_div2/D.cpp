/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 1000000007
#define INF 1000000

using namespace std;

//WRONG ANSWER - System Tests
string num[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011","1101111", "1010010", "1111111", "1111011" };

int sticks_to_convert(string s, string t) {
	int sticks = 0, i;
	for(i=0;i<7;i++) {
		if(s[i] == '1' && t[i] == '0') {
			return INF;
		}
		if(s[i] == '0' && t[i] == '1') sticks++;
	}
	return sticks;
} 

int mini_to_convert(string s) {
	//int target = -1;
	int mini = INF;
	int i;
	for(i=0;i<10;i++) {
		int sticks_required = sticks_to_convert(s, num[i]);
		
		if(sticks_required != INF) {
			if(mini > sticks_required){
				mini = sticks_required;
			}
		}
	}
	
	return mini;
}

pair<int, string> convert_to_max_possible(string s, int max_sticks) {
	int i;
	for(i=9;i>=0;i--) {
		int sticks = sticks_to_convert(s, num[i]);
		if(sticks == INF) continue;
		if(sticks > max_sticks) continue;
		
		return make_pair(sticks, num[i]);
	}
	return make_pair(INF, "");
}

pair<int, string> max_sticks_to_convert(string s, int max_sticks) {
	int i;
	int maxi = -1;
	int digit = -1;
	for(i=9;i>=0;i--) {
		int sticks = sticks_to_convert(s, num[i]);
		if(sticks == INF) continue;
		if(sticks > max_sticks) continue;
		
		if(maxi < sticks) {
			maxi = sticks;
			digit = i;
		}
	}
	
	if(maxi == -1) return make_pair(INF, "");
	return make_pair(maxi, num[digit]);
}

int main() {
	int n, k;
	cin>>n>>k;
	
	string digits[n];
	int i, j;
	for(i=0;i<n;i++) {
		cin>>digits[i];
	}
	
	int steps[n];
	int total = 0;
	for(i=0;i<n;i++) {
		steps[i] = mini_to_convert(digits[i]);
		total+=steps[i];
	}
	
	if(total > k) {
		cout<<"-1"<<endl;
		return 0;
	} 
	
	//cout<<total<<endl;
	int left = k - total;
	string target[n];
	for(i=0;i<n;i++) {
		//try converting this to maximum number possible
		pair<int, string> result = convert_to_max_possible(digits[i], left + steps[i]);
		left = left + steps[i] - result.first;
		target[i] = result.second;
		steps[i] = result.first;
	}
	
	for(i=0;i<n;i++) {
		for(j=0;j<10;j++) {
			if(num[j].compare(target[i]) == 0) {
				cout<<j;
				break;
			}
		}
	}
	
	cout<<left<<endl;
	
	if(left > 0) {
		for(i=n-1;i>=0;i--) {
			pair<int, string> result = max_sticks_to_convert(digits[i], left+steps[i]);
			left = left + steps[i] - result.first;
			target[i] = result.second;
			
			if(left == 0) break;
		}
	}
	
	if(left > 0) {cout<<"-1"<<endl; return 0;}
	for(i=0;i<n;i++) {
		for(j=0;j<10;j++) {
			if(num[j].compare(target[i]) == 0) {
				cout<<j;
				break;
			}
		}
	}
	cout<<endl;
    return 0;
}

