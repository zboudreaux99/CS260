#include <iostream>
#include <iomanip>

using namespace std;

long factorial(int n) {
    long result;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

void solve(int howManyNumbers, int numberSelected)
{
    //**  Your code here.
    if (howManyNumbers <= 0 || numberSelected <= 0 || numberSelected > howManyNumbers) {
        cout << "This is not a possible lottery";
        return;
    } else {
        long probability = factorial(howManyNumbers) / (factorial(numberSelected) * factorial(howManyNumbers - numberSelected));
        cout << "Your chances of winning are 1 in " << probability;
    }
}

int main(int argc, char **argv)
{
    int howManyNumbers;
    int numberSelected;

    cout << "How many numbers are printed on the lottery ticket? " << flush;
    cin >> howManyNumbers;
    cout << "How many numbers are selected in the lottery drawing? " << flush;
    cin >> numberSelected;

    cout << endl;

    solve(howManyNumbers, numberSelected);

    return 0;
}
