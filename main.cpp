#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;

void sleep(int seconds)
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
    int numberOfPersons;
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
        cout << "****************************************" << endl << endl;

        if (numberOfPersons > 30)
        {
            cout << "Wrong Input ..." << endl;
            cout << "Please Enter a vaild number!" << endl;
            sleep(1);
            clearScreen();
        }
    } while (numberOfPersons > 30);

    return numberOfPersons;
}

stPersonInfo readPersonalData()
{
    stPersonInfo personInfo;

    cout << "****************************************" << endl;
    cout << "Enter The Name: ";
    getline(cin, personInfo.personalData.name);

    cout << "\nEnter The Age: ";
    cin >> personInfo.personalData.age;
    cin.ignore();

    cout << "\nEnter The Email: ";
    getline(cin, personInfo.personalData.email);

    cout << "\nEnter The Phone Number: ";
    cin >> personInfo.personalData.phoneNumber;

    cout << "\nEnter The Favorite Color (blue = 1, yellow = 2, green = 3, rose = 4, red = 5): ";
    int fC = 0;
    cin >> fC;
    personInfo.personalData.favoriteColor = (enFavoriteColor)fC;

    return personInfo;
}

stPersonInfo StartGame()
{
    stPersonInfo personInfo;

    personInfo.numberOfPersons = readNumberOfPersons();
    personInfo = readPersonalData();
}

void RunApp()
{
    stPersonInfo personInfo;

    personInfo = StartGame();    
}

int main()
{
    RunApp();

    return 0;
}