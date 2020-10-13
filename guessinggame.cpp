#include "guessinggame.h"
#include <QDateTime>

//default constructor
GuessingGame::GuessingGame()
{
    //empty
}

//constructor - n is number of random numbers to gen, fn is from  Num starting num, tn is toNum end number
GuessingGame::GuessingGame(int n, int fn, int tn)
{
    num = n;
    fromNum = fn;
    toNum = tn;
}

//getter for n
int GuessingGame::getNum()
{
    return num;
}
//getter for fn
int GuessingGame::getFromNum()
{
    return fromNum;
}
//getter for tn
int GuessingGame::getToNum()
{
    return toNum;
}

//generate unique/non-unique random numbers
QList<int> GuessingGame::generateNumbers(bool unique)
{
    QList<int> lottoList;
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    for(int i = 0; i < getNum(); i++)
    {
        int tempNum = qrand() % ((getToNum() + 1) - getFromNum()) + getFromNum();
        if(unique)
        {
            while(lottoList.contains(tempNum))
            {
                tempNum = qrand() % ((getToNum() + 1) - getFromNum()) + getFromNum();
            }
        }
        lottoList.append(tempNum);
    }

    return lottoList;
}

//return number of correct guesses by user
int GuessingGame::score(const QList<int> input, const QList<int> correct)
{
    int s = 0;
    if(!input.isEmpty() && !correct.isEmpty())
    {
        for(int i = 0; i < input.length(); i++)
        {
            if(correct.contains(input.at(i)))
            {
                s++;
            }
        }
    }

    return s;
}
