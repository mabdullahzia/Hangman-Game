#ifndef GAME_H
#define GAME_H
#include<string>
#include<vector>
#include<set>
using namespace std;

enum Difficulty{EASY,MEDIUM,HARD};

class Hangman{
private:
    string word;
    string display;
    int attempts;
    set<char> guessed;
public:
    Hangman(string w,int maxAttempts);
    bool guess(char c);
    bool isWon(){return display==word;}
    bool isLost(){return attempts<=0;}
    void show();
    int getAttempts(){return attempts;}
    string getWord(){return word;}
};

string selectWord(Difficulty level);

#endif
