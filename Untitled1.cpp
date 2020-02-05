#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

char* NameConvert(string name);

char* NameConvert(string name)
{
    string safe = name;
    int n = safe.length();
    char converted[n+1];
    strcpy(converted, safe.c_str());
    return converted;
}

int main()
{
    string whichteam = "testing.txt";
    ofstream outfile(NameConvert(whichteam));
    outfile << "hey it works!!!" << endl;
    outfile.close();

    return 0;
}
