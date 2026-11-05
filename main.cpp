#include <iostream>
using namespace std;

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
};

struct stPersonInfo
{
    stPersonalData personalData;
    enFavoriteColor favoriteColor;
};

int main()
{
    stPersonInfo personInfo;

    return 0;
}