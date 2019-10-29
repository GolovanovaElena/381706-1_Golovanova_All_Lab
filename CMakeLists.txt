
cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME 381706-1Vlasov_All_Lab) 
project(${PROJECT_NAME}) 


set (ScanTabLib ScanTabLib)
set (ScanTab ScanTab)
set (ScanTabTest ScanTabTest)


set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)



include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ScanTabLib)
add_subdirectory(ScanTab)
add_subdirectory(ScanTabLib)
add_subdirectory(ScanTabTest)
