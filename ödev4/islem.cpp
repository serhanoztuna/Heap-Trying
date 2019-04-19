#include <iostream>
#include "sayi.h"
#include "heapAgac.cpp"

using namespace std;
void readfile()
{
    HeapAgac *heapAgac = new HeapAgac();
    string line;
    ifstream dsya ("sayilar.txt");
    if (dsya.is_open())
    {
			while ( getline (dsya,line) )
				{
					Sayi *a = new Sayi;
					a->nadd(line);
					heapAgac->Ekle(a);
				}
        heapAgac->wrtfile();
        delete heapAgac;
        dsya.close();
    }
}
int main(){readfile();return 0;}
