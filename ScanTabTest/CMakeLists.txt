file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 


add_executable(${ScanTabTest} ${srcs} ${hdrs}) 
target_link_libraries(${ScanTabTest} ${ScanTabLib} gtest )