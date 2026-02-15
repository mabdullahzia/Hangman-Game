#include<iostream>
#include"Game.h"
using namespace std;
#include"Game.cpp"

void viewRules(){
    cout<<"---Hangman Rules---\nGuess letters to complete the word.\n";
    cout<<"Incorrect guesses reduce attempts.\nWin by guessing word before attempts run out.\n";
}

int main(){
    int choice;
    do{
        cout<<"1.Start New Game 2.View Rules 0.Exit:";cin>>choice;
        switch(choice){
            case 1:{
                int lvl;cout<<"Select Difficulty(0-Easy 1-Medium 2-Hard):";cin>>lvl;
                string w=selectWord(static_cast<Difficulty>(lvl));
                Hangman g(w,6);
                char c;
                while(!g.isWon() && !g.isLost()){
                    g.show();
                    cout<<"Guess:";cin>>c;
                    if(!isalpha(c)){cout<<"Enter alphabet only\n";continue;}
                    if(!g.guess(c)) cout<<"Already guessed or wrong\n";
                }
                if(g.isWon()) cout<<"You won! Word:"<<g.getWord()<<"\n";
                else cout<<"Game Over! Word:"<<g.getWord()<<"\n";
                break;
            }
            case 2:viewRules();break;
        }
    }while(choice!=0);
}
