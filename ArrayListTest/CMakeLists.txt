file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${ArrayListTest} ${srcs} ${hdrs})
target_link_libraries(${ArrayListTest} ${ArrayListLib} gtest)
