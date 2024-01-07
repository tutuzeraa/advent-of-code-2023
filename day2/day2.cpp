#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <deque>

using namespace std;

int solve(string line){
    // return the id of the game if is possible
    // else returns 0;
    
    int id{};

    int maxRed{}, maxGreen{}, maxBlue{};

    line.erase(remove(line.begin(), line.end(), ':'), line.end());
    line.erase(remove(line.begin(), line.end(), ','), line.end());
    line.erase(remove(line.begin(), line.end(), ';'), line.end());
    
    stringstream ss(line);
    deque<string> words;
    string word;
      
    while(getline(ss, word, ' ')){
        words.push_back(word);    
    }
    
    id = stoi(words[1]);
    words.erase(words.begin(),words.begin()+2);

    for(int i=0; i< words.size(); i+=2){
        int number = stoi(words[i]); 
        string color = words[i+1];

        cout << "number: " << number << " color: " << color << endl;
        
        if ((color == "red") && (number > maxRed))
           maxRed = number;
        else if ((color == "green") && (number > maxGreen))
            maxGreen = number;
        else if ((color == "blue") && (number > maxBlue))
            maxBlue = number;
    }

    return maxRed * maxGreen * maxBlue;
}

int main(){
    ifstream input ("input.txt");
    int ans{};    
    string line{};

    if(input.is_open()){
        while(getline(input, line)){
            ans += solve(line);          
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
