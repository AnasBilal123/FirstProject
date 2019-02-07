#ifndef Bit_ARRAY_H
#define BIT_ARRAY_H
class BitArray
{
private:
	int capacity;
	unsigned char*data;
	bool isValidBit(int i) const
	{
		return i >= 0 && i < capacity;
	}
	

public:
	BitArray(int n);
	BitArray(const BitArray &ref);
	void on(int bitNo);
	void of(int bitNo);
	bool checkBitStatus(int bitNo) const;
	void dump()const;
	void invert(int bitNo);
	BitArray operator&(BitArray)const;
	BitArray operator|(BitArray) const;
	void operator<<(int);
	void operator>>(int);
	unsigned long long getUnsignedIntegralValue()const;
	void setIntegralValue(unsigned long long int)const;
	~BitArray();
};
#endif
 