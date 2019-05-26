file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")
add_executable(${ViewingTableTest} ${srcs} ${hdrs})
target_link_libraries(${ViewingTableTest} ${ViewingTableLib} gtest)