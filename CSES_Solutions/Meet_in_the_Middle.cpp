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


void solve(){
    int n, sum; cin >> n >> sum;

    vector<int> arr(n);

    lp(0, n){
        cin >> arr[i];
    }

    int split = n/2;

    vector<int> arr1, arr2;

    for (int i = 0; i < split; i++){
        arr1.push_back(arr[i]);
    }

    for (int i = n/2; i < n; i++){
        arr2.push_back(arr[i]);
    }

    vector<int> sums1, sums2; // storing all the possible combinations of subset sums

    int n1 = arr1.size();
    int n2 = arr2.size();

    int range1 = pow(2, n1)-1;
    int range2 = pow(2, n2)-1;
 
    for(int i = 0; i <= range1; i++){ //calculating all possible subsets using bit masks
        int check = i;

        if(i == 0){
            sums1.push_back(0);
            sums2.push_back(0);
            continue;
        }

        int temp1 = 0;
        int temp2 = 0;
        for(int j = n1-1; j >= 0; j--){
            if(check & 1){
                temp1 += arr1[j];
                temp2 += arr2[j];
            }
            check>>=1;
        }

        sums1.push_back(temp1);
        sums2.push_back(temp2);
    }

 

    sort(sums2.begin(), sums2.end()); //sorting to use binary search to look for desired elements in logN time instead of N^2 time

    unordered_map<int, int> countSums2;
    lp(0, sums2.size()){
        countSums2[sums2[i]]++;
    }

    int countAns = 0;

    for(int i = 0; i < sums1.size(); i++) {
        int needed = sum - sums1[i];

        int ind = lower_bound(sums2.begin(), sums2.end(), needed) - sums2.begin();

        int found = sums2[ind];

        if(found == needed){
            int times = countSums2[found];
            countAns += times;
        }
    }

    cout << countAns << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 1;
    // cin >> x;
    while(x--){
        solve();
    }
}