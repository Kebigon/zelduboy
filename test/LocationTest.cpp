#include <cgreen/cgreen.h>

#include "../src/Location.hpp"

#define MIN_COORDINATE 0
#define MAX_COORDINATE 4080

using namespace cgreen;

Describe(Location)
BeforeEach(Location) {}
AfterEach(Location) {}

Ensure(Location, test_max_coordinates)
{
	Location *locMax = new Location(nullptr, MAX_COORDINATE, MAX_COORDINATE);
	assert_that(locMax->getX(), is_equal_to(MAX_COORDINATE));
	assert_that(locMax->getY(), is_equal_to(MAX_COORDINATE));
	assert_that(locMax->getTileX(), is_equal_to(MAX_COORDINATE / 16));
	assert_that(locMax->getTileY(), is_equal_to(MAX_COORDINATE / 16));
	free(locMax);
}

Ensure(Location, test_min_coordinates)
{
	Location *locMin = new Location(nullptr, MIN_COORDINATE, MIN_COORDINATE);
	assert_that(locMin->getX(), is_equal_to(MIN_COORDINATE));
	assert_that(locMin->getY(), is_equal_to(MIN_COORDINATE));
	assert_that(locMin->getTileX(), is_equal_to(MIN_COORDINATE / 16));
	assert_that(locMin->getTileY(), is_equal_to(MIN_COORDINATE / 16));
	free(locMin);
}

TestSuite *location_tests()
{
	TestSuite *suite = create_test_suite();
	add_test_with_context(suite, Location, test_max_coordinates);
	add_test_with_context(suite, Location, test_min_coordinates);
	return suite;
}
