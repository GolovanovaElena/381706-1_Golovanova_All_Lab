file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${ScanTabLib} STATIC ${srcs} ${hdrs}) 
