#include <iostream>
#include <limits>
#include <string>
#include <bitset>
using namespace std;

struct game{
    bitset<26> chars;
    bitset<26> solved;
    bitset<26> guessed;
};

int main()
{
    string target;
    struct game roundcase;
    int round(0);
    string guessstring;
    int stroke(7);
    while (cin >> round)
    {
        if (round == -1)
            break;

        roundcase.chars.reset();
        roundcase.solved.reset();
        roundcase.guessed.reset();

        cin >> target;
        for(string::iterator iter = target.begin();iter < target.end();iter++)
            roundcase.chars.set(*iter-'a',true);

        stroke = 7;

        cin >> guessstring;

        for(string::iterator guess = guessstring.begin();guess < guessstring.end() && stroke > 0;guess++)
        {
            if (roundcase.guessed.test(*guess-'a') == false)
            {
                if (roundcase.chars.test(*guess-'a') == true)
                    roundcase.solved.set(*guess-'a',true);
                else
                    stroke--;
            }
            roundcase.guessed.set(*guess-'a',true);
        }

        cout << "Round " << round << endl;

        if (roundcase.solved.count() == roundcase.chars.count())
            cout << "You win." << endl;
        else if (stroke == 0)
            cout << "You lose." << endl;
        else
            cout << "You chickened out." << endl;
    }
    return 0;
}