#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define no  cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define int long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i =a; i< n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";

bool help(vector<int> & arr, int h){

    int valOR = 0;
    vector<int> bitFreq(21, 0);
    int j = 0;

    lp(0, h){
        valOR |= arr[i];
        for (int k = 0; k < 21; k++)
        {
            if((arr[i] >> k) & 1){
                bitFreq[k]++;
            }
        }
    }

    for(int i = h; i < arr.size(); i++){

        //include in bitFreq
        int num = arr[i];
        for (int k = 0; k < 21; k++)
        {
            if((num >> k) & 1){
                bitFreq[k]++;
            }
        } 

        //remove the j th bit from bit freq
        num = arr[j];
        for (int k = 0; k < 21; k++)
        {
            if((num >> k) & 1){
                bitFreq[k]--;
            }
        } 
        
        //get current OR
        int currOR = 0;
        for (int i = 0; i < 21; i++)
        {
            if(bitFreq[i]){
                currOR |= (1 << i);
            }
        }

        if(currOR != valOR){
            return false;
        }

        j++;
    }

    return true;
}


void solve(){
    int n; cin >> n;
    vector<int> arr(n);

    lp(0, n){
        cin >> arr[i];
    }

    int lo = 1, hi = n, mid;
    int mini = INT_MAX;
	while(lo<=hi){
		mid = (lo+hi)/2; 

        if(help(arr,mid)){
			hi = mid-1;
            mini = min(mini, mid);
		}
		else{
			lo = mid+1;
		}
	} 

    cout << mini << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 1;
    cin >> x;
    while(x--){
        solve();
    }
}