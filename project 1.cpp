#include <iostream>
#include <cstdlib>
#include <string>
// #include <valarray> // for slice
// #include <openssl/md5.h> doesnt work, chen said to use other
#include "md5.h"
#include "md5.cpp"

using namespace std;

/* TA WROTE THIS!

#include <openssl/md5.h>

int main(){
    result = md5("password");
}
*/
/*
string generate_hash(string salt, string password, string& intermediate) {
    // 
    return intermediate;
}
*/
string bitconverter64(int a, int b) {
    string ascii64 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string str1 = "";
    while (--b >= 0) {
        str1 += ascii64.at(a & 0x3f);
        a >> 6;
    }
    return str1;
}

string bitconverter64_3(string str1, int a, int b, int c) {
    char abc = (
        (str1.at(a) << 16) | 
        (str1.at(b) << 8) |
        (str1.at(c))
    );

    return bitconverter64(abc, 4);
}

string bitconverter64_1(string str1, int a) {
    char abc = str1.at(a);
    return bitconverter64(abc, 2);
}

string next_word (string word) {
    if (word.size() == 8) {
        if (word.at(word.size()-1) != 'z') {
            word.at(word.size()-1) += 1;
            return word;
        }
        else {
            word.at(word.size()-1) = 'a';
            if (word.at(word.size()-2) != 'z') {
                word.at(word.size()-2) += 1;
                return word;
            }
            else {
                word.at(word.size()-2) = 'a';
                if (word.at(word.size()-3) != 'z') {
                    word.at(word.size()-3) += 1;
                    return word;
                }
                else {
                    word.at(word.size()-3) = 'a';
                    if (word.at(word.size()-4) != 'z') {
                        word.at(word.size()-4) += 1;
                        return word;
                    }
                    else {
                        word.at(word.size()-4) = 'a';
                        if (word.at(word.size()-5) != 'z') {
                            word.at(word.size()-5) += 1;
                            return word;
                        }
                        else {
                            word.at(word.size()-5) = 'a';
                            if (word.at(word.size()-6) != 'z') {
                                word.at(word.size()-6) += 1;
                                return word;
                            }
                            else {
                                word.at(word.size()-6) = 'a';
                                if (word.at(word.size()-7) != 'z') {
                                    word.at(word.size()-7) += 1;
                                    return word;
                                }
                                else {
                                    return "";
                                }
                            }
                        }
                    }
                }
            }
        }
        // else if (word.at(word.size() - 2) + 1 != 'z') {
        //     word.at(word.size()-2) += 1;
        //     return word;
        // }
        // else if (word.at(word.size() - 3) + 1 != 'z') {
        //     word.at(word.size()-3) += 1;
        //     return word;
        // }
        // else if (word.at(word.size() - 4) + 1 != 'z') {
        //     word.at(word.size()-4) += 1;
        //     return word;
        // }
        // else if (word.at(word.size() - 5) + 1 != 'z') {
        //     word.at(word.size()-5) += 1;
        //     return word;
        // }
        // else if (word.at(word.size() - 6) + 1 != 'z') {
        //     word.at(word.size()-6) += 1;
        //     return word;
        // }
        // else if (word.at(word.size() - 7) + 1 != 'z') {
        //     word.at(word.size()-7) += 1;
        //     return word;
        // }
        // else if (word.at(word.size() - 8) + 1 != 'z') {
        //     word.at(word.size()-8) += 1;
        //     return word;
        // }
        // else return "";
    }
    else {
        if (word.at(word.size() - 1) != 'z') {
            word.at(word.size() - 1) += 1;
            return word;
        }
        else {
            word.at(word.size() - 1) = 'a';
            word.push_back('a');
            return word;
        }
    }
}

int main() { // welcome to bullshit

    string salt = "hfT7jp2q"; // pull from table but same for everyone
    string password = "reeeeeee"; // base password 
    string target_hash = "yKkGOHLs7BZiNuh03um670"; // given to us
    // to do: actually implement random 8 letter password generator 
    
    /* TA's failed attempt at solving my mid-life crisis
    
    const unsigned char *passwd = "security";
    unsigned char passwd[] = "security";
    unsigned long length = 8;
    unsigned char addr[128];

    MD5(passwd, length, addr);
    */

    string intermediate = ""; // to calculate
    string temp = password + "$1$" + salt;

    // compute alternate sum
    cout << "temp :" << temp << endl;

    intermediate = md5(password + salt + password);
    
    cout << "does primitive hash work? " << intermediate << endl;

    for (int i = password.size(); i > 0; i -= 16) {
        temp += intermediate.substr(0, (i > 16) ? 16 : i);
    }

    cout << "passed first for loop" << endl;

    for (int i = password.size(); i != 0; i >>= 1) {
        if (i & 1)
            temp += "\0";
        else 
            temp += password.at(0);
    }

    cout << "passed second for loop" << endl;

    // compute intermediate sum. probably fucked up here somewhere already
    // intermediate += password + "$1$" + salt + intermediate.size();

    /*
    for int(k = 0; k < password.size() ++k) {
        // do bitwise thing
    }
    */

    // for (int i = 0; i < ) // idk what i was doing here no cap
    
    temp = md5(temp);

    for (int i = 0; i < 1000; ++i) {
        intermediate = "";
        if (i & 1) {
            intermediate += password;
        }
        else {
            intermediate += temp;
        }
        if (i % 3) {
            intermediate += salt;
        }
        if (i % 7) {
            intermediate += password;
        }
        if (i & 1) {
            intermediate += temp;
        }
        else {
            intermediate += password;
        }
        temp = md5(intermediate);
        // intermediate = generate_hash(salt, password, intermediate);
    }

    string checker = bitconverter64_3(temp, 0, 6, 12) +
                     bitconverter64_3(temp, 1, 7, 13) +
                     bitconverter64_3(temp, 2, 8, 14) +
                     bitconverter64_3(temp, 3, 9, 15) +
                     bitconverter64_3(temp, 4, 10, 5) +
                     bitconverter64_1(temp, 11);

    // do the bitwise choosing thing;
    /*
    Pick out the 16 bytes in this order: 11 4 10 5 3 9 15 2 8 14 1 7 13 0 6 12.
    For each group of 6 bits (there are 22 groups), starting with the least significant
    Output the corresponding base64 character with this index
    */

    // compute this nightmare 26x26x26x26x26x26 times reeeeeeeeeeeeeeeeeeeeeee
    if (checker == target_hash) { // just use intermediate XOR target_hash u dumbass
        cout << "success! the password is: " << password; 
        return 0;
    }
    else {
        cout << password << " " << checker;
    }

    // for (int i = 0; i < 128; ++i) {
    //     cout << addr[i];
    // }
    // cout << endl;

    // cout << target_hash.size() << endl;

    return 0;
}