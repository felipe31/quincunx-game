add_test( HelloTest.BasicAssertions /home/felipe/game/build/tests [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties( HelloTest.BasicAssertions PROPERTIES WORKING_DIRECTORY /home/felipe/game/build)
set( tests_TESTS HelloTest.BasicAssertions)
