#include <bits/stdc++.h>
using namespace std;
//LCS CODE 
int lcs(char* X, char* Y, int m, int n,vector<vector<int> >& dp)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
 
    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),lcs(X, Y, m - 1, n, dp));
}
// Add Contacts
void addContacts(string names[], int n)
{
    for(int i=0;i<n;i++){
        cout<<"Enter Contact "<<i+1<<": ";
        cin>>names[i];
    }
}
// Search
void Search(string names[], int len)
{
    int i, flag=0;
    string search;
    cout<<"Enter the name to search :  ";
    cin>>search;
    int n = search.length();
    cout<<"Searched Results :\n ";
    for(i=0;i<len;i++){
        int m = names[i].length();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
        if(lcs(&names[i][0], &search[0], m, n, dp) == search.length()){
            cout<<names[i]<<"\n";
            flag=1;
        }
    }
    if(!flag){
        cout<<"No Contact Found";
    }
}
// Driver CODE
int main()
{
    int n;
    cout<<"enter number of contacts : ";
    cin>>n;
    string names[n];
    addContacts(names,n);
    Search(names,n);
    return 0;
}