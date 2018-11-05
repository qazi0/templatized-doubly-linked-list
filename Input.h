

// Input.h
// Author: Javaria Ghafoor
// Templatized Linked List v4.2φ
// Dated: November 5th, 2018 10:26PM

#include"check.h"

class Input : public LetsCheck
{
public:
	Input(void);
	~Input(void);
	int Int(void);
	float Float(void);
	char Char(void);
	bool Bool(void);
};
