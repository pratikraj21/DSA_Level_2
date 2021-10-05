#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main()
{
    string str;
    cin>>str;
    
    // row (vertically down) stores the startIndex of substring
    // col (horizontal) stores the endIndex of substring
    //Eg- dp[1][6] => substring starting from INDEX-1 and ending at INDEX-6
    int dp[str.size()][str.size()];
    
    // gap betweeen the startIndex and endIndex of the substring
    for(int gap = 0; gap < str.size(); gap++){
        
        // traverse diagonally in the upper half diagonals by doing this -
        // for each gap - starting row: 0  starting col: gap  and go till last col in dp
        for(int i = 0, j = gap; j < str.size(); i++, j++){
            
            // gap == 0  =>  startIndex and endIndex are same => 1 character
            if(gap == 0){
                // single char is a palindome already
                dp[i][j] = 1;
            }
            
            // gap == 1  =>  startIndex and endIndex differ by 1 in length => 2 characters
            else if(gap == 1){
                // if startIndex and endIndex have same char (Eg- aa)
                if(str[i] == str[j]){
                    dp[i][j] = 2;
                }
                else{
                    dp[i][j] = 1;
                }
            }
            
            // gap = 2 .... str.size()
            else{
                if(str[i] == str[j]){
                    // a bcd a => 2 + move to b (i+1) + move to d (j-1)
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else{
                    // a bcd e => max( lps(abcd), lps(bcde) )
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
            
        }
        
    }
    
    // gap of str.size() at top right corner
    cout<<dp[0][str.size() - 1];
    
    return 0;
}