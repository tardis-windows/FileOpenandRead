#include <iostream>
#include <windows.h>
#include <fstream>
#include <new>
#include <string>

using namespace std;

int main()
{

    string filename= "LittleLamb.mpx";
    ifstream fin(filename);

    if(!fin.is_open())
    {
        cerr<< filename << "not found\n";
        exit(0);
    }

    int N;
    int* duration, *frequency;

    fin >>N;
    frequency = new(nothrow)int [N];  //should not throw an exception in failure, should return a null pointer instead.
    duration = new(nothrow) int[N];

    if (frequency == nullptr || duration == nullptr)
    {
        cerr << "memory allocation problem\n";
    }

    for( int i=0; i<N; i++)
    {
         fin >> frequency[i] >> duration [i];
    }

    for(int i=0; i<N; i++)
        cout << frequency[i] << ',' << duration[i]<< endl;

    delete[]duration;
    delete[]frequency;

fin.close();

return 0;
}
