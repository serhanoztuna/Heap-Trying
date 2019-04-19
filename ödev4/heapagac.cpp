#pragma once
#include <fstream>
#include "sayi.h"
#include <iostream>
using namespace std;
struct Dgm
{
    Sayi* unit;
    Dgm *left;
    Dgm *right;
    int tut;
    Dgm( Sayi* yeni,Dgm *L=NULL,Dgm *R=NULL,int tt=0)
    {unit=yeni;left=L;right=R;tut=tt;}
};
class HeapAgac
{
private:
    Dgm *bklt;
    Dgm* add(Dgm *a1,Dgm *a2)
    {
        if(a1 == NULL) return a2;
        if(a2 == NULL) return a1;
        if(a1->unit->getsd() < a2->unit->getsd())return addin(a1,a2);
        else return addin(a2,a1);
    }
    Dgm* addin(Dgm *h1,Dgm *h2)
    {
        if(h1->left == NULL) h1->left = h2;
        else
			{
				h1->right = add(h1->right,h2);
				if(h1->left->tut < h1->right->tut) chnge(h1);
				h1->tut=h1->right->tut+1;
			}
        return h1;
    }
    void chnge(Dgm * &t)
    {
        Dgm* temp = t->left;
        t->left = t->right;
        t->right = temp;
    }
    bool bkltSil()
    {
        if(bklt == NULL) return false;
        Dgm *del = bklt;
        bklt=add(bklt->left,bklt->right);
        delete del;
        return true;
    }
    void empty(Dgm *&sub_bklt)
    {
        if(sub_bklt != NULL)
        {
            empty(sub_bklt->left);
            empty(sub_bklt->right);
            delete sub_bklt;
        }
        sub_bklt = NULL;
    }
public:
    HeapAgac()
    {bklt=NULL;}
    void Ekle( Sayi *yeni)
    {bklt = add(new Dgm(yeni),bklt);}
    void empty()
    {empty(bklt);}
    void wrtfile()
    {
        ofstream outputFile;
        outputFile.open ("sirali.txt");
        int i;
        string lstnmbr;
        while(bklt!=NULL)
        {
            outputFile << bklt->unit->gets() << endl;
            lstnmbr = bklt->unit->gets() ;
            bkltSil();
        }
        outputFile.close();
        lastwrt(lstnmbr);
    }
    void lastwrt(string lstnmbr)
    {
        cout<<lstnmbr;
		system("pause");
    }
};
