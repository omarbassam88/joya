
project(TESTAPP)

add_executable(TEST src/TestApp.cpp)

target_link_libraries(TEST 
PRIVATE 
    joya
)