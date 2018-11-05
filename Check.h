

// Check.h
// Author: Javaria Ghafoor
// Templatized Linked List v4.2φ
// Dated: November 5th, 2018 10:26PM

#pragma once

class LetsCheck
{
protected:
	void block(void);
	int Check(int, int, int&);
	float Check(float, float, int&);
	char Check(char, char, int&);
	bool Check(bool, bool, int&);
	LetsCheck();
	~LetsCheck();
public:
	template<typename Generic>
	inline friend Generic check(Generic, Generic);
};
