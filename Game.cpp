#include"Game.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

Hangman::Hangman(string w,int maxAttempts){
    word=w;
    display=string(w.size(),'_');
    attempts=maxAttempts;
    guessed.clear();
}

bool Hangman::guess(char c){
    c=tolower(c);
    if(guessed.count(c)) return false; //already guessed
    guessed.insert(c);
    bool found=false;
    for(int i=0;i<word.size();i++){
        if(tolower(word[i])==c){display[i]=word[i];found=true;}
    }
    if(!found) attempts--;
    return found;
}

void Hangman::show(){
    cout<<"Word: ";
    for(char ch:display) cout<<ch<<" ";
    cout<<" Attempts:"<<attempts<<"\nGuessed:";
    for(char ch:guessed) cout<<ch<<" ";
    cout<<"\n";
}

string selectWord(Difficulty level){
    vector<string> easy={"cat","dog","sun","pen"};
    vector<string> medium={"apple","house","green","table"};
    vector<string> hard={"elephant","computer","hangman","difficult"};
    srand(time(0));
    if(level==EASY) return easy[rand()%easy.size()];
    else if(level==MEDIUM) return medium[rand()%medium.size()];
    else return hard[rand()%hard.size()];
}
