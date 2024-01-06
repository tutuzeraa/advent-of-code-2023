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

    line.erase(remove(line.begin(), line.end(), ':'), line.end());
    line.erase(remove(line.begin(), line.end(), ','), line.end());
    line.erase(remove(line.begin(), line.end(), ';'), line.end());
    
    //cout << line << endl;
    stringstream ss(line);
    deque<string> words;
    string word;
      
    while(getline(ss, word, ' ')){
        words.push_back(word);    
    }
    
    id = stoi(words[1]);
    words.erase(words.begin(),words.begin()+2);

    //cout << "game with id " << id << endl;

    for(int i=0; i< words.size(); i+=2){

        int number = stoi(words[i]); 
        string color = words[i+1];

        cout << "number: " << number << " color: " << color << endl;
        
        if (((color == "red") && (number > 12)) ||
            ((color == "green") && (number > 13)) ||
            ((color == "blue") && (number > 14))){
      //      cout << "IMpossible!" << endl;
            return 0;
        }
            
    }


    return id;
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
