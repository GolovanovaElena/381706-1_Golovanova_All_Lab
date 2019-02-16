cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME All_Labs) 
project(${PROJECT_NAME}) 

set(Exception Exception)


set(List List)
set(ListLib ListLib)
set(ListTest ListTest)



set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ExceptionLib)
add_subdirectory(Exception)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(List)
add_subdirectory(ListLib)
add_subdirectory(ListTest)






