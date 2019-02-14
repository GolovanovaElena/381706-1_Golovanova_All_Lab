file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${Stack} ${srcs} ${hdrs})
target_link_libraries(${Stack} ${StackLib})