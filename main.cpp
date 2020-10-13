#include "guessinggame.h"
#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QStringList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //initialise game
    GuessingGame g1(6, 1, 39);
    int replay = 0;

    QList<int> lottoRun = g1.generateNumbers(true);

    QList<int> playerNumList;

    do{
        //clear number list
        if(!playerNumList.isEmpty())
        {
            playerNumList.clear();
        }

        bool ok;
        //dialog box for start of game.
        QString playerNums = QInputDialog::getText(0, "Play the Lotto!", "Enter your 6 numbers between 1 and 39 with a space between each:",
                                                   QLineEdit::Normal, "", &ok);
        if(ok)
        {
            //check for ok click
            QStringList listOfNumbers = playerNums.split(" ");
            //qDebug() << "size is " << listOfNumbers.length();
            int numberOfDuplicates = listOfNumbers.removeDuplicates();
            bool allOk(true);
            if(numberOfDuplicates <= 0 && listOfNumbers.size() == g1.getNum())
            {
                for(int i = 0; i < listOfNumbers.size(); i++)
                {
                    QString StringNumber = listOfNumbers.at(i);
                    playerNumList.append(StringNumber.toInt(&allOk,10));
                }
                if(allOk)
                {
                    int correctGuesses = g1.score(playerNumList, lottoRun);
                    QString response = QString ("You got %1 numbers correct. Do you want to play again?").arg(correctGuesses);
                    replay = QMessageBox::question(0, "Play again?", response, QMessageBox::Yes | QMessageBox::No);
                }
            }
            //check user input error
            else if(!allOk || numberOfDuplicates > 0 || listOfNumbers.size() != g1.getNum())
            {
                QString errorMessage = "You entered an incorrect number, try again?";
                replay = QMessageBox::question(0, "", errorMessage, QMessageBox::Yes | QMessageBox::No);
            }
            else
            {
                replay = QMessageBox::No;
            }
        }
    }
    while(replay == QMessageBox::Yes);

    return 0;
}
