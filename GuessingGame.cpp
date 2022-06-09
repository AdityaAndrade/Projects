#include <iostream>
using namespace std;

class Player {
public:
  virtual int getGuess(int l, int h) {return 0;}
};

class HumanPlayer : public Player {
public:
  int getGuess(int l, int h) {
    int ans;
    cout << "Enter a number" << endl;
    cin >> ans;
    return ans;
  }
};
class ComputerPlayer : public Player {
public:
  int getGuess(int l, int h) {
    return l + rand() % h;}
};

void play(Player &player1, Player &player2);
bool checkForWin (int guess, int answer);

int main() {
  HumanPlayer p1;
  HumanPlayer p2;
  ComputerPlayer c1;
  ComputerPlayer c2;

  play(p1, p2);
  play(p1, p2);
  play(p1, c1);
  play(c1, c2);
  play(c1, c2);

  return 0;
}


bool checkForWin (int guess, int answer, int& l, int& h) {
  if (answer == guess) {
    cout << "You're right! You win!" << endl;
    return true;
  }

  else if (answer < guess) {
    cout << "Your guess is too high." << endl;
    h = guess - 1;
  }

  else {
    cout << "Your guess is too low." << endl;
    l = guess + 1;
  }

  return false;
}

void play(Player &player1, Player &player2) {
  int answer = 0, guess = 0;
  answer = rand() % 100;
  bool win = false;
  int low = 0, high = 100;

  while (!win) {
    cout << "Player 1's turn to guess." << endl;
    guess = player1.getGuess(low, high);
    win = checkForWin(guess, answer, low, high);
    if (win) {return;}

    cout << "Player 2's turn to guess." << endl;
    guess = player2.getGuess(low, high);
    win = checkForWin(guess, answer, low, high);
  }
}
