#include <iostream>
#include <windows.h>
using namespace std;

void mySleep(int seconds)
{
    Sleep(seconds * 1000);
}

void clearScreen()
{
    system("cls");
}

enum enFavoriteColor
{
    blue = 1,
    yellow = 2,
    green = 3,
    rose = 4,
    red = 5
};

struct stPersonalData
{
    string name;
    int age;
    int phoneNumber;
    string email;
    enFavoriteColor favoriteColor;
};

struct stPersonInfo
{
    stPersonalData personalData;
};

int readNumberOfPersons()
{
    int numberOfPersons = 0;

    do
    {
        cout << "****************************************" << endl;
        cout << "Enter Number Of Persons (Max 30) : ";
        cin >> numberOfPersons;
        cout << "****************************************" << endl
             << endl;

        if (numberOfPersons > 30)
        {
            cout << "Wrong Input ..." << endl;
            cout << "Please Enter a vaild number!" << endl;
            mySleep(1);
            clearScreen();
        }
    } while (numberOfPersons > 30);

    cout << "Person(s) will enter now ..." << endl;
    mySleep(1);
    clearScreen();

    return numberOfPersons;
}

stPersonalData readPersonData()
{
    stPersonalData personalData;

    cout << "****************************************" << endl;
    cout << "Enter The Name: ";
    getline(cin, personalData.name);

    cout << "\nEnter The Age: ";
    cin >> personalData.age;

    cout << "\nEnter The Email: ";
    cin >> personalData.email;

    cout << "\nEnter The Phone Number: ";
    cin >> personalData.phoneNumber;

    while (personalData.favoriteColor > 5 || personalData.favoriteColor < 1)
    {
        cout << "\nEnter The Favorite Color (blue = 1, yellow = 2, green = 3, rose = 4, red = 5): ";
        int fC = 0;
        cin >> fC;

        if (fC > 5 || fC < 1)
        {
            cout << "\nWrong Enter!" << endl;
            cout << "Please Enter a valid number" << endl;
            mySleep(2);
            clearScreen();
        }
        

        personalData.favoriteColor = (enFavoriteColor)fC;
    }

    cin.ignore();

    cout << "****************************************" << endl;

    return personalData;
}

string getFavoriteColorText(enFavoriteColor favoriteColor)
{
    switch (favoriteColor)
    {
    case enFavoriteColor::blue:
        return "Blue";
    case enFavoriteColor::yellow:
        return "Yellow";
    case enFavoriteColor::green:
        return "Green";
    case enFavoriteColor::rose:
        return "Rose";
    case enFavoriteColor::red:
        return "Red";
    }
    return "Wrong";
}

void printPersonData(stPersonalData personalData)
{
    cout << "****************************************" << endl;
    cout << "The Full Name: " << personalData.name << endl << endl;
    cout << "The Age: " << personalData.age << endl << endl;
    cout << "The Email: " << personalData.email << endl << endl;
    cout << "The Phone Number: " << personalData.phoneNumber << endl << endl;
    cout << "The Favorite Color: " << getFavoriteColorText(personalData.favoriteColor) << endl;
    cout << "****************************************" << endl << endl;
}

void readPersonsData(stPersonInfo personInfo[], int numberOfPersons, string personText)
{
    for (int i = 0; i < numberOfPersons; i++)
    {
        cout << personText << i + 1 << endl << endl;
        personInfo[i].personalData = readPersonData();
        if (i >= numberOfPersons - 1)
        {
            cout << "Saving ..." << endl;
            mySleep(2);
            clearScreen();
            return;
        }
        cout << "\nThe Next Person will enter Now ..." << endl << endl;
        mySleep(2);
        clearScreen();
    }
}

void printPersonsData(stPersonInfo personInfo[], int numberOfPersons, string personText)
{
    cout << "================================================" << endl << endl;
    for (int i = 0; i < numberOfPersons; i++)
    {
        cout << personText << i + 1 << endl << endl;

        printPersonData(personInfo[i].personalData);
    }
    cout << "================================================" << endl << endl;
}

void StartGame(stPersonInfo personInfo[], int numberOfPersons)
{
    string personText = "Person ";
    
    readPersonsData(personInfo, numberOfPersons, personText);

    printPersonsData(personInfo, numberOfPersons, personText);
}

void RunApp()
{
    int numberOfPersons = readNumberOfPersons();

    cin.ignore();

    stPersonInfo personInfo[numberOfPersons];

    StartGame(personInfo, numberOfPersons);
}

int main()
{
    RunApp();

    return 0;
}