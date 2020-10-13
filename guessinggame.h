#ifndef GUESSINGGAME_H
#define GUESSINGGAME_H

#include <QList>


class GuessingGame
{
public:
    //default constructor
    GuessingGame();
    //constructor - n is number of random numbers to gen, fn is from  Num starting num, tn is toNum end number
    GuessingGame(int n, int fn, int tn);
    //getter for n
    int getNum();
    //getter for fn
    int getFromNum();
    //getter for tn
    int getToNum();
    //generate unique/non-unique random numbers
    QList<int> generateNumbers(bool unique);
    //return number of correct guesses by user
    int score(QList<int> input, QList<int> correct);

private:
    int num;
    int fromNum;
    int toNum;
};

#endif // GUESSINGGAME_H
