#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


    
string findDigits(const string &line){
    // find all digits and its locations
    string digits = "";
    
    for(int i = 0; i < line.length(); i++){
        char c = line[i];
        if (isdigit(c)) digits += c;
        else{
            switch (c){
                size_t pos;
                case 'o':
                    pos = line.find("one", i);
                    if((pos != string::npos) and (pos == i))
                        digits += '1';
                    break;

                case 'e':
                    pos = line.find("eight", i);
                    if((pos != string::npos) and (pos == i))
                        digits += '8';
                    break;
                
                case 'n':
                    pos = line.find("nine", i);
                    if((pos != string::npos) and (pos == i))
                        digits += '9';
                    break;
                
                case 't':
                    pos = line.find("two", i);
                    if((pos != string::npos) and (pos == i))
                        digits += '2';
                    pos = line.find("three", i);
                    if((pos != string::npos) and (pos == i))
                        digits += '3';
                    break;
            
                case 'f':
                    pos = line.find("four", i);
                    if((pos != string::npos) and (pos == i))
                        digits += '4';
                    pos = line.find("five", i);
                    if((pos != string::npos) and (pos == i))
                        digits += '5';
                    break;
            
                case 's':
                    pos = line.find("six", i);
                    if((pos != string::npos) and (pos == i))
                        digits += '6';
                    pos = line.find("seven", i);
                    if((pos != string::npos) and (pos == i))
                        digits += '7';
                    break;
            }
        }
    }
    return digits;
}

int main(){

    ifstream input ("input.txt");
    int ans{};
    string line{};

    if(input.is_open()){
        while(getline(input, line)){
            cout << line << endl;
            string digits = findDigits(line);
            //cout << digits[0] << " "
            //     << digits[digits.length()-1] << endl;
            char resp[2];
            resp[0] = digits[0];
            resp[1] = digits[digits.length()-1];
            
            int num = stoi(resp);
            //cout << resp << endl;
            ans += num;
        }
    }

    cout << ans << endl;

    return 0;
}


