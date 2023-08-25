#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string createBWT(const string text)
{
    vector<string> ans;
    string bwt;
    for(int i=text.length()-1;i>0;i--)
    {
        string currentString ;
        int currentPos = i;
        while(text[currentPos] != '\0')
        {
            currentString += text[currentPos++];
        }
        currentPos = 0;
        while(currentPos<i)
        {
            currentString += text[currentPos++];
        }
        ans.push_back(currentString);
    }
    ans.push_back(text);
    std::sort(ans.begin(), ans.end());
    int bwtLoc = text.length()-1;
    for(auto & an : ans)
    {
        bwt += an[bwtLoc];
    }
    return bwt;
}

string BWT(const string& text) {
  string bwt = createBWT(text);
  return bwt;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}