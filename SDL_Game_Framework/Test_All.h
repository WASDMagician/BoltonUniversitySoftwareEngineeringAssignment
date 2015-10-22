#ifndef _TEST_ALL_H_
#define _TEST_ALL_H_

#include "UnitTest++\src\UnitTest++.h"
#include <fstream>
#include "UnitTest++\src\XmlTestReporter.h"

class Test_All
{
public:
	Test_All();
	~Test_All();
	int Run_All_Tests();
};
#endif //_TEST_ALL_H_
