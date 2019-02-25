cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME AllLabi) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(Exception Exception)

set(Stack Stack)
set(StackLib Stacklib)
set(StackTest StackTest)

set(Queue Queue)
set(QueueLib Queuelib)
set(QueueTest QueueTest)

set(Polish Polish)
set(PolishLib PolishLib)
set(PolishTest PolishTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Exception)
add_subdirectory(Exception)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
add_subdirectory(Stack)
add_subdirectory(StackLib)
add_subdirectory(StackTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
add_subdirectory(Queue)
add_subdirectory(QueueLib)
add_subdirectory(QueueTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolishLib)
add_subdirectory(Polish)
add_subdirectory(PolishLib)
add_subdirectory(PolishTest)