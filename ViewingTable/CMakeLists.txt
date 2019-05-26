file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${ViewingTable} ${srcs} ${hdrs})
target_link_libraries(${ViewingTable} ${ViewingTableLib})