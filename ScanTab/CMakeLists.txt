  
file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 
add_executable(${ScanTab} ${srcs} ${hdrs}) 

target_link_libraries(${ScanTab} ${ScanTabLib})
