#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;

    while (t--)
    {
        string word;
        int insIdx = 0;
        cin >> word;
        char dchar;

        if(word[0] == 'z')
            dchar = 'y';
        else
            dchar = word[0]+1; 
            
        for (int i=0; i < word.length(); i++)
        {
            if(i != 0)
                if(word[i-1] == word[i]) {
                    insIdx = i;
                    if(word[i] == 'z')
                        dchar = 'y';
                    else
                        dchar = word[i]+1; 
                    break;
                }

        }
        word.insert(word.begin()+insIdx, dchar);
        cout << word << endl;
    }
    

    return 0;
}
