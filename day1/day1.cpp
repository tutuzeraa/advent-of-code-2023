#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    ifstream input ("input.txt");
    int ans{};
    string line{};

    if(input.is_open()){
        while(getline(input, line)){
            cout << line << endl;
            string digits = "";
            for(char c: line){
                if (isdigit(c)) digits += c;
            }
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


