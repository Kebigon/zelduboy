#include <cgreen/cgreen.h>

#include "../src/utils/DArray.hpp"
#include <string>

using namespace cgreen;

Describe(DArray)
BeforeEach(DArray) {}
AfterEach(DArray) {}

class A
{
public:
	virtual std::string getName() = 0;
};

class B : public A
{
public:
	virtual std::string getName()
	{
		return "B";
	}
};

Ensure(DArray, does_not_exceed_max_size)
{
	DArray<int> array(3);
	assert_that(array.add(1), is_true);
	assert_that(array.add(2), is_true);
	assert_that(array.add(3), is_true);
	assert_that(array.add(4), is_false);
}

Ensure(DArray, increments_and_decrements_size_correctly)
{
	DArray<double> array(10);
	assert_that(array.getSize(), is_equal_to(0));
	assert_that(array.isEmpty(), is_true);

	assert_that(array.add(1.0), is_true);
	assert_that(array.getSize(), is_equal_to(1));
	assert_that(array.isEmpty(), is_false);

	assert_that(array.add(2.0), is_true);
	assert_that(array.getSize(), is_equal_to(2));
	assert_that(array.isEmpty(), is_false);

	assert_that(array.removeAt(1), is_true);
	assert_that(array.getSize(), is_equal_to(1));
	assert_that(array.isEmpty(), is_false);

	assert_that(array.remove(1.0), is_true);
	assert_that(array.getSize(), is_equal_to(0));
	assert_that(array.isEmpty(), is_true);
}

Ensure(DArray, test_3)
{
	DArray<double> array(10);
	assert_that(array.add(1.0), is_true);
	assert_that(array.get(0), is_equal_to_double(1.0));

	DArray<std::string *> array2(10);
	std::string str = "test";
	assert_that(array2.add(&str), is_true);
	assert_that(array2.get(0), is_equal_to(&str));
}

Ensure(DArray, handles_polymorphism)
{
	DArray<A *> array(10);
	array.add(new B());
	assert_that(array.get(0)->getName(), is_equal_to_string("B"));
}

TestSuite *darray_tests()
{
	TestSuite *suite = create_test_suite();
	add_test_with_context(suite, DArray, does_not_exceed_max_size);
	add_test_with_context(suite, DArray, increments_and_decrements_size_correctly);
	add_test_with_context(suite, DArray, test_3);
	add_test_with_context(suite, DArray, handles_polymorphism);
	return suite;
}
