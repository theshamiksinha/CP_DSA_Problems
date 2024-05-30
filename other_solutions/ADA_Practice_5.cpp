#include<bits/stdc++.h>
using namespace std;
#define print(x) for(auto i: x) { cout << i << " "; }

vector<vector<int>> dp;


int recursive(vector<char> &arr, int i, int j, vector<vector<int>> &dp){

    if(i==j){
        return arr[i] == 'F' ? 0 : 1;
    }

    int ans = 0;
    for(int k = i; k <j; k+=2){

        int temp1 = recursive(arr, i, k, dp);  
        int temp2 = recursive(arr, k+1, j, dp);

        int temp;

        if(arr[k] == '&'){
            temp = temp1 && temp2;
        }else if(arr[k] == '|'){
            temp = temp1 || temp2;
        }else{
            temp = temp1^temp2;
        }
        ans = ans || temp;
    }
    return ans;
}

int tabular(vector<int> &hotels, int n, int index, int dist, vector<vector<int>> &dp){
    

}

int main() {

    int n; cin >> n;

    vector<char> arr(n);

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i = 0; i < n; i++){

        cin >> arr[i];

    }

    int ans = recursive(arr,1,n-1, dp);

    // int ans = tabular(hotels, n, 0, 0, dp);
    
    cout << ans << endl;
    

    return 0;
}