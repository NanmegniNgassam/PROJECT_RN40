cmake_minimum_required(VERSION 3.20)

project(Population)

set(CMAKE_CXX_STANDARD 18)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../EXECUTABLE")

set(CMAKE_OBJECT_PATH_MAX 300)

add_executable( Population
  ../CODE_C/main.c
  ../CODE_C/Individu/Individu.h    ../CODE_C/Individu/Individu.c
  ../CODE_C/Population/Population.h    ../CODE_C/Population/Population.c 
  ../CODE_C/Others/Autres.h    ../CODE_C/Others/Autres.c    
)