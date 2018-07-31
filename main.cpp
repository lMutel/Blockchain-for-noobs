#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "MyHash.h"

using namespace std;


/*
 * Simple console application to show how blockchain is working from the inside
 * To find out information about this example, use the link:
 * https://prometheus.ru/samoe-prostoe-obyasnenie-blokchejna/
 */



int main() {
    vector<MyHash> newChain;

    string str, lastHash = "0000";
    cout<<"type exit() to quit "<<endl;
    cout<<"Please, put here new note... "<<endl;


    while (true){
        getline(cin,str);
        if(str == "exit()"){
            break;
        }else {
            MyHash newBlock(str, lastHash);
            lastHash = to_string(newBlock.get());

            newChain.push_back(newBlock);
        }

    }

    for_each(newChain.begin(), newChain.end(), MyHash::display);


    return 0;
}