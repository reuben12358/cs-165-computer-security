#include <iostream>
#include <iomanip> // for hex stuff
#include <cstdlib>
#include <string>
// #include <valarray> // for slice
// #include <openssl/md5.h> doesnt work, chen said to use other
#include "md5.h"        // instructor allowed usage  
#include "md5.cpp"      // instructor allowed usage

using namespace std;

// I am team 50

string bitconverter64(int a, int b) {
    string ascii64 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string str1 = "";
    unsigned char abc;
    while (--b >= 0) {
        abc = ascii64.at(a & 0x3f);
        a >>= 6;
        str1 += abc;
    }
    return str1;
}

string bitconverter64_3(string str1, int a, int b, int c) {
    int abc =  
    (
        (unsigned int)(str1.at(a) << 16) | 
        (unsigned short)(str1.at(b) << 8) |
        (unsigned char)(str1.at(c))
    );
    return bitconverter64(abc, 4);
}

string bitconverter64_1(string str1, int a) {
    int abc = str1.at(a);
    return bitconverter64(abc, 2);
}

string next_word (string & word) {
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
        if (word.size() == 1) {
            if (word == "z") {
                word = "aa";
                return word;
            }
            else {
                word.at(0) += 1;
                return word;
            }
        }
        else if (word.size() == 2) {
            if (word == "zz") {
                word = "aaa";
                return word;
            }
            else if (word.at(1) == 'z') {
                word.at(0) += 1;
                word.at(1) = 'a';
                return word;
            } 
            else {
                word.at(1) += 1;
                return word;
            }
        }
        else if (word.size() == 3) {
            if (word == "zzz") {
                word = "aaaa";
                return word;
            }
            else if (word.at(2) == 'z') {
                if (word.at(1) == 'z') {
                    word.at(0) += 1;
                    word.at(1) = 'a';
                    word.at(2) = 'a';    
                }
                else {
                    word.at(1) += 1;
                    word.at(2) = 'a';
                }
                return word;
            } 
            else {
                word.at(2) += 1;
                return word;
            }
        }
        else if (word.size() == 4) {
            if (word.at(3) == 'z') {
                if (word.at(2) == 'z') {
                    if (word.at(1) == 'z') {
                        if (word.at(0) == 'z') {
                            word = "aaaaa";
                        }
                        else {
                            word.at(0) += 1;
                            word.at(1) = 'a';
                            word.at(2) = 'a';
                            word.at(3) = 'a';
                        }
                        return word;
                    }
                    else {
                        word.at(1) += 1;
                        word.at(2) = 'a';
                        word.at(3) = 'a';
                    }
                    return word;
                }
                else {
                    word.at(2) += 1;
                    word.at(3) = 'a';
                }
                return word;
            }
            else {
                word.at(3) += 1;
            }
            return word;
        }
        else if (word.size() == 5) {
            if (word.at(4) == 'z') {
                if (word.at(3) == 'z') {
                    if (word.at(2) == 'z') {
                        if (word.at(1) == 'z') {
                            if (word.at(0) == 'z') {
                                word = "aaaaaa";
                            }
                            else {                
                                word.at(0) += 1;
                                word.at(1) = 'a';
                                word.at(2) = 'a';
                                word.at(3) = 'a';
                                word.at(4) = 'a';
                            }
                            return word;
                        }
                        else {
                            word.at(1) += 1;
                            word.at(2) = 'a';
                            word.at(3) = 'a';
                            word.at(4) = 'a';
                        }
                        return word;
                    }
                    else {
                        word.at(2) += 1;
                        word.at(3) = 'a';
                        word.at(4) = 'a';
                    }
                    return word;
                }
                else {
                    word.at(3) += 1;
                    word.at(4) = 'a';
                }
                return word;
            }
            else {
                word.at(4) += 1;
            }
            return word;
        }
        else {
            if (word.at(5) == 'z') {
                if (word.at(4) == 'z') {
                    if (word.at(3) == 'z') {
                        if (word.at(2) == 'z') {
                            if (word.at(1) == 'z') {
                                if (word.at(0) == 'z') {
                                    return "";
                                }
                                else {
                                word.at(0) += 1;
                                word.at(1) = 'a';
                                word.at(2) = 'a';
                                word.at(3) = 'a';
                                word.at(4) = 'a';
                                word.at(5) = 'a';
                                }
                                return word;
                            }
                            else { 
                                word.at(1) += 1;
                                word.at(2) = 'a';
                                word.at(3) = 'a';
                                word.at(4) = 'a';
                                word.at(5) = 'a';
                            }
                            return word;
                        }
                        else {
                            word.at(2) += 1;
                            word.at(3) = 'a';
                            word.at(4) = 'a';
                            word.at(5) = 'a';
                        }
                        return word;
                    }
                    else {
                        word.at(3) += 1;
                        word.at(4) = 'a';
                        word.at(5) = 'a';
                    }
                    return word;
                }
                else {
                    word.at(4) += 1;
                    word.at(5) = 'a';
                }
                return word;
            }
            else {
                word.at(5) += 1;
            }
            return word;
        }
    }
}

string convert_to_16 (string hex, int size) {
    string xyz = "";

    for (int i = 0; i < size*2; i = i+2) {
        string abc = "0x";
        abc += hex.at(i);
        abc += hex.at(i + 1);
        xyz += stoul(abc, nullptr, 16);
    }

    return xyz;
}

int main() { // welcome to bullshit

    string salt = "hfT7jp2q"; // pull from table but same for everyone
    string password = "zaaaaa"; // base password // change back to a 
    string target_hash = "L1zWXhnkkBA9p8o.wdn511"; // given to us

    string intermediate = ""; // to calculate

    bool iscomplete = false;
    // LOOOP TIME!

    while (!iscomplete) {
    string temp = password + "$1$" + salt;

    // compute alternate sum
    // cout << "temp: " << temp << endl;

    intermediate = md5(password + salt + password);

    // cout << "does primitive hash work?\nintm: " << intermediate << endl;

    // stream << hex << password.size();
    // cout << stream.str() << endl;

    // for (int i = password.size(); i > 0; i -= 16) {
    //     temp += intermediate.substr(0, (i > 16) ? 16 : i);
    // }

    temp += convert_to_16(intermediate, password.size());

    for (int i = password.size(); i != 0; i = i/2) {
        if (i & 1)
            temp += '\0';
        else 
            temp += password.at(0);
    }

    // cout << "passed for loop" << endl;

    // compute intermediate sum. probably fucked up here somewhere already
    // intermediate += password + "$1$" + salt + intermediate.size();

    temp = md5(temp);

    // cout << "temp: " << temp << endl;

    for (int i = 0; i < 1000; ++i) {
        intermediate = "";
        if (i & 1) {
            intermediate += password;
        }
        else {
            intermediate += convert_to_16(temp, 16);
        }
        if (i % 3) {
            intermediate += salt;
        }
        if (i % 7) {
            intermediate += password;
        }
        if (i & 1) {
            intermediate += convert_to_16(temp, 16);
        }
        else {
            intermediate += password;
        }
        temp = md5(intermediate);
        // intermediate = generate_hash(salt, password, intermediate);
    }

    // cout << "passed 1000 for loop thingy\ntemp: " << temp << endl;

    temp = convert_to_16(temp, 16);

    string checker = bitconverter64_3(temp, 0, 6, 12);
    checker += bitconverter64_3(temp, 1, 7, 13);
    checker += bitconverter64_3(temp, 2, 8, 14);
    checker += bitconverter64_3(temp, 3, 9, 15);
    checker += bitconverter64_3(temp, 4, 10, 5);
    checker += bitconverter64_1(temp, 11);

    // do the bitwise choosing thing;
    /*
    Pick out the 16 bytes in this order: 11 4 10 5 3 9 15 2 8 14 1 7 13 0 6 12.
    For each group of 6 bits (there are 22 groups), starting with the least significant
    Output the corresponding base64 character with this index
    */

    // compute this nightmare 26x26x26x26x26x26 times reeeeeeeeeeeeeeeeeeeeeee
    if (checker == target_hash) { // just use intermediate XOR target_hash u dumbass
        cout << "success! the password is: " << password << endl; 
        cout << endl << password << ": " << checker << endl;
        cout << password << ": " << target_hash << endl;
        iscomplete = true;
        return 0;
    }
    else {
        cout << password << endl;
        password = next_word(password);
        // cout << endl << password << ": " << checker << endl;
        // cout << password << ": " << target_hash << endl;
    }

    }
    // for (int i = 0; i < 128; ++i) {
    //     cout << addr[i];
    // }
    // cout << endl;

    // cout << target_hash.size() << endl;

    return 0;
}