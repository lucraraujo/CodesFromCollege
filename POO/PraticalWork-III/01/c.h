#ifndef _c_h_
#define _c_h_
#include "A.h"
#include "B.h"

class c : public A
{
	B atrib;
public:
	c();
	virtual ~c();
};

#endif