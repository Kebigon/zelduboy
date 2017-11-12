#include <cgreen/cgreen.h>

#include "../src/Location.hpp"

#define MIN_COORDINATE 0
#define MAX_COORDINATE 4080

using namespace cgreen;

Describe(Location)
BeforeEach(Location) {}
AfterEach(Location) {}

Ensure(Location, test_works_with_normal_coordinates)
{
	Location *loc = new Location(nullptr, 1234, 567);
	assert_that(loc->getX(), is_equal_to(1234));
	assert_that(loc->getY(), is_equal_to(567));
	assert_that(loc->getTileX(), is_equal_to(1234 / 16));
	assert_that(loc->getTileY(), is_equal_to(567 / 16));
	free(loc);
}

Ensure(Location,  works_with_min_coordinates)
{
	Location *locMin = new Location(nullptr, MIN_COORDINATE, MIN_COORDINATE);
	assert_that(locMin->getX(), is_equal_to(MIN_COORDINATE));
	assert_that(locMin->getY(), is_equal_to(MIN_COORDINATE));
	assert_that(locMin->getTileX(), is_equal_to(MIN_COORDINATE / 16));
	assert_that(locMin->getTileY(), is_equal_to(MIN_COORDINATE / 16));
	free(locMin);
}

Ensure(Location, works_with_max_coordinates)
{
	Location *locMax = new Location(nullptr, MAX_COORDINATE, MAX_COORDINATE);
	assert_that(locMax->getX(), is_equal_to(MAX_COORDINATE));
	assert_that(locMax->getY(), is_equal_to(MAX_COORDINATE));
	assert_that(locMax->getTileX(), is_equal_to(MAX_COORDINATE / 16));
	assert_that(locMax->getTileY(), is_equal_to(MAX_COORDINATE / 16));
	free(locMax);
}

TestSuite *location_tests()
{
	TestSuite *suite = create_test_suite();
	add_test_with_context(suite, Location, test_works_with_normal_coordinates);
	add_test_with_context(suite, Location, works_with_min_coordinates);
	add_test_with_context(suite, Location, works_with_max_coordinates);
	return suite;
}
