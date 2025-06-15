#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cctype>
using namespace std;

int validate(string s){

    vector<string> msg;

    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        msg.push_back(word);
    }
    
    if(msg.size()!=7)
        return 0;

    if(msg[0]!="CU")
        return 0;

    if(msg[1].length() != 3 || msg[4].length() != 3)
        return 0;
    
    for(char c : msg[1]){
        if(isupper(c))
            return 1;
    }

    for(char c : msg[4]){
        if(isupper(c))
            return 1;
    }


    // if(!stoi(msg[3]) || !stoi(msg[6]))
    //     return 0;

    if(stoi(msg[3]) - stoi(msg[6]) < 2)
        return 0;

    return 1;
}

int main(){

    string s = "CU CTG 216754 2018 CTG 234323 2016";

    cout<<validate(s);
    return 0;

}
