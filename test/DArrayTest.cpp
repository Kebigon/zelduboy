#include <cgreen/cgreen.h>

#include "../src/utils/DArray.hpp"

using namespace cgreen;

Describe(DArray)
BeforeEach(DArray) {}
AfterEach(DArray) {}

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
  DArray<int> array(10);
  assert_that(array.getSize(), 0);
  assert_that(array.isEmpty(), is_true);
  assert_that(array.add(1), is_true);
  assert_that(array.getSize(), 1);
  assert_that(array.isEmpty(), is_false);

}

TestSuite *darray_tests()
{
	TestSuite *suite = create_test_suite();
	add_test_with_context(suite, DArray, does_not_exceed_max_size);
	return suite;
}
