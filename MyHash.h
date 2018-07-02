//
// Created by mute on 02.07.18.
//

#ifndef BLOCKCHAINFORDUMBS_MYHASH_H
#define BLOCKCHAINFORDUMBS_MYHASH_H

#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;

class MyHash{
    int nonce;
    string lastHash;
    string massage;
    hash<string> hash_fn;
    size_t str_hash;
public:
    MyHash() : str_hash(0000),nonce(0),massage(""), lastHash("0000"){}
    MyHash( string str, string last): nonce(0){
        while(true){
            massage = str;
            lastHash = last;
            str_hash = hash_fn(str + to_string(nonce) + last );
            if(str_hash%10000 == 0){
                break;
            }
            nonce++;
        }
    }
    size_t get(){
        return str_hash;
    }
    void printBlock(){
        cout<<massage<< " + ("<<nonce<<") + "<< lastHash << " ----> "<<str_hash<<endl;
    }
};


#endif //BLOCKCHAINFORDUMBS_MYHASH_H
