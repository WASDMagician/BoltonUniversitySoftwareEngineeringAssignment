#include "Test_All.h"


Test_All::Test_All()
{
}


Test_All::~Test_All()
{
}


int Test_All::Run_All_Tests()
{
	std::ofstream f("test.xml");
	UnitTest::XmlTestReporter reporter(f);
	UnitTest::TestRunner runner(reporter);
	return runner.RunTestsIf(UnitTest::Test::GetTestList(), NULL, UnitTest::True(), 0);
}