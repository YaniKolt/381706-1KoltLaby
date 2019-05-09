file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")
add_library(${ViewingTableLib} STATIC ${srcs} ${hdrs})


