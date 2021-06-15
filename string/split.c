#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 该分割函数，不能分割 separator 个数为0的情况
vector<string> split(const string& s, const char& separator) {
    vector<string> res;
    int beginPos = 0;
    int desPos = s.npos;
    while ((desPos = s.find(separator, beginPos)) 
            && desPos != s.npos) {
        res.push_back(s.substr(beginPos, desPos-beginPos));
        beginPos = desPos + 1;
    }
    res.push_back(s.substr(beginPos, desPos-beginPos));
    return res;
}

int main() {
    string test("sfsg.sfsf.hgt.rhrha.sdeyet.eeyrtj.dghd");
    //test = "sfsg";
    //test = "";
    auto splitRes = split(test, '.');
    for (const string& s: splitRes) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
