#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Card {
    public:
        string rank;
        int value;
    Card(string r, int v){
        rank = r;
        value = v;
    }
    string getRank() {
        return rank;
    }
    int getValue() {
        return value;
    }
};

vector<Card> shuf(vector<Card> deck) {
        random_device rd;
        mt19937 gen(rd());
        shuffle(deck.begin(), deck.end(), gen);
        return deck;
} 

int main()
{
    
    vector<Card> myDeck = {Card("ONE",1),Card("ONE",1),Card("TWO",2),Card("TWO",2),Card("THREE",3),Card("THREE",3),Card("FOUR",4),Card("FOUR",4),Card("FIVE",5),Card("FIVE",5),Card("SIX",6),Card("SIX",6)};
    vector<Card> yourDeck = {Card("ONE",1),Card("ONE",1),Card("TWO",2),Card("TWO",2),Card("THREE",3),Card("THREE",3),Card("FOUR",4),Card("FOUR",4),Card("FIVE",5),Card("FIVE",5),Card("SIX",6),Card("SIX",6)};
    
    int myHand = 0;
    int yourHand = 0;
    
    string answer = "A";
    Card temp = Card("JOKER",0);
    
    myDeck = shuf(myDeck);
    yourDeck = shuf(yourDeck);
    
    cout << "Are you ready to play?: ";
    cin >> answer;
    
    while (true) {
        //Flip Cards
        cout << "Flipping Cards...\n---\n";
        myHand = 0;
        cout << "Computer: " << myDeck[myHand].getRank() << endl;
        yourHand = 0;
        cout << "You: " << yourDeck[yourHand].getRank() << endl;
        
        srand(time(0));
        
        //Cards Equal, War
        if (myDeck[myHand].getValue() == yourDeck[yourHand].getValue()) {
            cout << "IT'S WAR!!!\n";
            cout << "Choose a card to flip over (1, 2, 3):\n🂠🂠🂠\n";
            while (true) {
                cin >> answer;
                if (answer == "1") {
                    yourHand = 0;
                    break;
                }
                else if (answer == "2") {
                    yourHand = 1;
                    break;
                }
                else if (answer == "3") {
                    yourHand = 2;
                    break;
                }
                else {
                    cout << "No card selected.\n";
                }
            }
            myHand = rand() % 3;
            cout << "Computer: " << myDeck[myHand].getRank() << endl;
            cout << "You: " << yourDeck[yourHand].getRank() << endl;
            
            //Opponent Victory (WAR)
            if (myDeck[myHand].getRank() > yourDeck[yourHand].getRank()) {
                cout << "I win!!\n";
                myDeck.insert(myDeck.end(),Card(yourDeck[0].getRank(),yourDeck[0].getValue()));
                yourDeck.erase(yourDeck.begin());
                myDeck.insert(myDeck.end(),Card(yourDeck[0].getRank(),yourDeck[0].getValue()));
                yourDeck.erase(yourDeck.begin());
                myDeck.insert(myDeck.end(),Card(yourDeck[0].getRank(),yourDeck[0].getValue()));
                yourDeck.erase(yourDeck.begin());
            }
            else if (myDeck[myHand].getRank() < yourDeck[yourHand].getRank()) {
                cout << "I win!!\n";
                yourDeck.insert(yourDeck.end(),Card(myDeck[0].getRank(),myDeck[0].getValue()));
                myDeck.erase(myDeck.begin());
                yourDeck.insert(yourDeck.end(),Card(myDeck[0].getRank(),myDeck[0].getValue()));
                myDeck.erase(myDeck.begin());
                yourDeck.insert(yourDeck.end(),Card(myDeck[0].getRank(),myDeck[0].getValue()));
                myDeck.erase(myDeck.begin());
            }
            else {
                cout << "Draw, both decks are shuffled.";
                myDeck = shuf(myDeck);
                yourDeck = shuf(yourDeck);
            }
        }
        //Opponent Victory
        else if (myDeck[myHand].getValue() > yourDeck[yourHand].getValue()) {
            cout << "I win!\n";
            myDeck.insert(myDeck.end(),Card(yourDeck[yourHand].getRank(),yourDeck[yourHand].getValue()));
            yourDeck.erase(yourDeck.begin());
        }
        //Player Victory
        else {
            cout << "You win!\n";
            yourDeck.insert(yourDeck.end(),Card(myDeck[myHand].getRank(),myDeck[myHand].getValue()));
            myDeck.erase(myDeck.begin());
        }
        
        //Player Wins (Opponent has less than 3 cards)
        if (myDeck.size()<3) {
            cout << "I don't have enough cards, you win!!!";
            break;
        }
        
        //Opponent Wins (Player has less than 3 cards)
        if (yourDeck.size()<3) {
            cout << "You don't have enough cards, I win!!!";
            break;
        }
        
        cout << "Ready?: ";
        cin >> answer;
        
    }
    

    return 0;
}