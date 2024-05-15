# Checks in BUILD_TESTING option is enabled. Allows user to control whether tests should be built alongside the project.
if(BUILD_TESTING)
{
    add_executable(TransferServiceTest.cpp)

    target_link_libraries(transfer_service_test PRIVATE GTest::gtest_main GTest::gmock_main)
    
    # This includes macros and functions provided by Google Test for CMake. This is necessary for test discovery.
    include(GoogleTest)

    # This command tells CMake to automatically discover tests in the test1 executable using Google Test. It 
    # generates CTest tests for each test case found in test1 so that they can be run using CTest or any other 
    # test runner supporting CTest format.
    gtest_discover_tests(test1)
    
}