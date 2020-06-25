#include "joya.h"

class TestClass : public JY::App
{
private:
public:
    TestClass();
    ~TestClass();
};

TestClass::TestClass()
{
}

TestClass::~TestClass()
{
}

JY::App* JY::CreateApp()
{
    return new TestClass();
}