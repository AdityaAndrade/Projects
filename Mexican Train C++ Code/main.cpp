#include <iostream>
using namespace std;

//define a vector deck to store deck of dominos
//nested for loops to populate deck
//randomly shuffle deck
//declare community train
//
//

int main() {
  std::vector<Domino> deck;
  for (int i = 0; i <= 12; i++) {
    for (int j = 0; j <= 12; j++) {
      new Domino d (i, j);
      deck.push_back(d);
    }
  }

  deck.random_shuffle();



  return 0;
}
