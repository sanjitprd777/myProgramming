// C++ program for implementation of KMP pattern searching algorithm TIME COMPLEXITY O(n).
#include<bits/stdc++.h>
using namespace std;
void computeLPSArray(string pat,vector <int> &lps);
void KMPSearch(string pat,string txt)
{
    int M = pat.length();
    int N = txt.length();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    vector <int> lps(M);

    // Preprocess the pattern (calculate lps[] array for pat string)
    computeLPSArray(pat,lps);

    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N)
    {
        if (txt[i]==pat[j]){
            j++;   i++;
        }
        if (j == M){
            printf("Found pattern at index %d \n", i-j);
            j = lps[j-1];
        }
        // mismatch after j matches
        else if (i < N && txt[i]!=pat[j]){
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                ++i;
        }
    }
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(string pat, vector <int> &lps)
{
    int M=pat.length();
    // length of the previous longest prefix suffix
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string txt,pat;
        cin>>txt;
        cin>>pat;
        KMPSearch(pat, txt);
        cout<<endl;
    }
    return 0;
}
