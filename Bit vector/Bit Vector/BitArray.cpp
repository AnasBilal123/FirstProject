#include<iostream>
#include"BitArray.h"
using namespace std;
BitArray::BitArray(int n)
{
	if (n > 8)
	{
		capacity = n;
	}
	else
	{
		capacity = 8;
	}
	int s = (int)ceil((float)n / 8);
	data = new unsigned char[s];
	for (int i = 0; i < s; i = i + 1)
	{
		data[i] = (data[i] & 0);
	}

}
BitArray::BitArray(const BitArray &ref)
{
	if (ref.data == 0)
	{
		data = 0;
	}
	else
	{
		capacity = ref.capacity;
		int s = (int)ceil((float)capacity / 8);
		data = new unsigned char[s];
		for (int i = 0; i < s; i = i + 1)
		{
			data[i] = ref.data[i];
		}
	}
	
}
void BitArray::on(int bitNo)
{
	int s = bitNo / 8;
	int rem = bitNo % 8;
	data[s] = (data[s] | 1 << rem);
}
void BitArray::of(int bitNo)
{
	int s = bitNo / 8;
	int rem = bitNo % 8;
	char data2 = 0;
	data2 = data2 | 1 << rem;
	data2 = ~data2;
	if (data[s] == (data[s] | 1<<rem))
	{
		data[s] = data[s] &data2;
	}
}

bool BitArray::checkBitStatus(int bitNo) const
{
	int s = bitNo / 8;
	int rem = bitNo % 8;
	if (data[s] == (data[s] | 1<<rem))
	{
		return true;
	}
	else
	{
		return false;
	}
}


void BitArray::dump()const
{

	for (int j = capacity; j >= 0; j = j - 1)
	{
		if (checkBitStatus(j)==true)
		{
			cout << "1";
		}
		if (checkBitStatus(j) == false)
		{
			cout << "0";
		}
		if (j % 8 == 0)
		{
			cout << " ";
		}

	}
	cout << endl;

}

void BitArray::invert(int bitNo)
{
	if (checkBitStatus(bitNo)==true)
	{
		of(bitNo);
	}
	else
	{
		on(bitNo);
	}
}

BitArray BitArray::operator&(BitArray a) const
{
	BitArray d(capacity);
	for (int i = 0; i <= a.capacity / 8; i = i + 1)
	{
		d.data[i] = (data[i] & a.data[i]);
	}
	return d;
}

BitArray BitArray::operator|(BitArray a) const
{
	BitArray d(capacity);
	for (int i = 0; i <= a.capacity/8; i = i + 1)
	{
		d.data[i] = (data[i] | a.data[i]);
	}
	return d;
}

void BitArray::operator<<(int n)
{
	for (int i = 0; i < n; i = i + 1)
	{
		for (int j = (capacity/8); j >=0; j = j - 1)
		{
			data[j] = data[j] << 1;
			if (data[j-1] == (data[j-1] | 1<<7))
			{
				if (j != 0)
				{
					data[j] = (data[j] | 1 << 0);
				}
			}
		}
	}
}

void BitArray::operator>>(int n)
{

	for (int i = 0; i < n; i = i + 1)
	{
		for (int j =0 ; j <= (capacity / 8); j = j + 1)
		{
			data[j] = data[j] >> 1;
			if (data[j + 1] == (data[j + 1] | 1<<0))
			{

				data[j] = (data[j] | 1 << 7);

			}
		}
	}

}
unsigned long long BitArray::getUnsignedIntegralValue() const
{
	long long int a = 0;
	for (int i = 0; i < capacity; i = i + 1)
	{
		if (checkBitStatus(i)==true)
			a = a | 1<<i;
	}
	return a;

}

void BitArray::setIntegralValue(unsigned long long int a) const
{
	//int s = (int)ceil((float)capacity / 8);
	//for (int i = 0; i < 2; i + 1)
	//{
		data[0] = 0;
		data[1] = 0;
		data[2] = 0;
	//}
	*data =unsigned char (a);
}

BitArray::~BitArray()
{
	if (data!=nullptr)
	{
		delete[]data;
		data = nullptr;
	}
	capacity = 0;

}