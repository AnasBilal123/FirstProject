#include<iostream>
#include"BitArray.h"
using namespace std;
void main()
{
	BitArray ba(20);
	//ba.on(15);
	//ba.on(0);
	ba.on(2);
	ba.on(0);
	//ba.on(19);
//	ba.on(5);
	//ba.on(6);
	//ba.on(9);
	//ba.on(10);
	//ba.dump();
	//ba.of(10);
	//ba.dump();
	//ba.invert(10);
	//ba.dump();
	//ba.on(7);
	//ba.of(1);
	cout << ba.getUnsignedIntegralValue() << endl;
	//ba.invert(2);
	//ba.invert(1);
	
	BitArray one(20);
	one.on(2);
	one.on(3);
	one.on(8);
	one.on(17);
	cout << one.getUnsignedIntegralValue() << "\n";
	one.dump();
	//ba.of(1);
	//ba.shiftLeft(2);
	ba.dump();
	ba.setIntegralValue(23);
	ba.dump();
	ba << 3;
	ba << 3;
	ba.dump();
	//ba.shiftRight(2);
	//BitArray OR(20);
	//BitArray And=ba&(one);
	//And.dump();
	//OR = ba|one;
	
	
	


}
