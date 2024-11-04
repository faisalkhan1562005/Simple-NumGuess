#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    char playAgain;

    do
    {
        int maxNumber, maxAttempts;
        cout << "*** Choose level: ***\n1. Easy (1-10)\n2. Medium (1-50)\n3. Hard (1-100)\n";

        int difficulty;
        while (true)
        {
            cin >> difficulty;

            // Input validation for difficulty level
            if (cin.fail() || difficulty < 1 || difficulty > 3)
            {
                cout << "Invalid choice. Please choose 1, 2, or 3: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else
            {
                break;
            }
        }


        // Set parameters based on difficulty level
        switch (difficulty) {
        case 1:
            maxNumber = 10;
            maxAttempts = 5;
            break;
        case 2:
            maxNumber = 50;
            maxAttempts = 7;
            break;
        case 3:
            maxNumber = 100;
            maxAttempts = 10;
            break;
        }


        int number = rand() % maxNumber + 1;
        int guess, attempts = 0;

        cout << "Guess the number (between 1 and " << maxNumber << "): ";


        while (attempts < maxAttempts)
        {
            cin >> guess;

            // Input validation for the guess
            if (cin.fail() || guess < 1 || guess > maxNumber)
            {
                cout << "Please enter a valid number between 1 and " << maxNumber << ".\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            attempts++;

            if (guess == number)
            {
                cout << "** Congratulations ** You guessed the number in " << attempts << " attempts.\n";
                break; // Exit the guessing loop
            }
            else
            {
                cout << (guess > number ? "Too high!" : "Too low!") << " ";
                cout << "You have " << (maxAttempts - attempts) << " attempts left.\n";
            }
        }


        if (attempts == maxAttempts)
        {
            cout << "Sorry, you've run out of attempts. The number was " << number << ".\n";
        }

        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;

        // Clear input for play again
        cin.ignore(10000, '\n');

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "** Thank you for playing **\n";
    return 0;
}
