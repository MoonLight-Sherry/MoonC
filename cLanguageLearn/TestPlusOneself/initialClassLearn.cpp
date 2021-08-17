#include "initialClassLearn.h"
#include <iostream>
#include "Box.h"

using namespace std;

Box MilkBox;
Box &Milk = MilkBox;

Box::Box(int l):length(l){}

void Box::set_length(int l)
{
	length = l;
}

