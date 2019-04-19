#pragma once
#include "stdio.h"
#include <sstream>
#include <string>
#include <fstream>
#include "sayi.h"
#include <iostream>
using namespace std;
Sayi::Sayi(){nmbrclm="";}
void  Sayi::nadd(string s){nmbrclm = s;}
double Sayi::getsd(){double dSayi = 0;dSayi = stod(nmbrclm);return dSayi;}
string Sayi::gets(){return nmbrclm;}
