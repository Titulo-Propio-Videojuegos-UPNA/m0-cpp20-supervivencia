cmake_minimum_required(VERSION 3.16)
project(m0_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

# Los ejercicios M0 verifican las invariantes con assert(<cassert>).
# Desactivamos NDEBUG en configuraciones Release/RelWithDebInfo/MinSizeRel
# para que ctest nunca dé falsos positivos en generadores multi-config (MSVC/Ninja).
foreach(cfg RELEASE RELWITHDEBINFO MINSIZEREL)
  if(DEFINED CMAKE_CXX_FLAGS_${cfg})
    string(REGEX REPLACE "[-/]DNDEBUG" "" CMAKE_CXX_FLAGS_${cfg} "${CMAKE_CXX_FLAGS_${cfg}}")
  endif()
endforeach()

function(m0_test name)
  add_executable(${name} ${ARGN})
  target_compile_options(${name} PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/UNDEBUG>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-UNDEBUG>
  )
  add_test(NAME ${name} COMMAND ${name})
endfunction()

m0_test(01_const 01_const.cpp)
m0_test(02_referencias 02_referencias.cpp)
m0_test(03_punteros 03_punteros.cpp)
m0_test(04_raii 04_raii.cpp)
m0_test(05_clase 05_clase.cpp)
m0_test(06_virtual 06_virtual.cpp)
m0_test(07_plantillas 07_plantillas.cpp)
m0_test(08_archivos 08_archivos/vec2.cpp 08_archivos/main.cpp)
target_include_directories(08_archivos PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/08_archivos)

option(M0_SOLUCIONES "Compila las soluciones de referencia (equipo docente)" OFF)
if(M0_SOLUCIONES)
  m0_test(sol_01_const soluciones/01_const.cpp)
  m0_test(sol_02_referencias soluciones/02_referencias.cpp)
  m0_test(sol_03_punteros soluciones/03_punteros.cpp)
  m0_test(sol_04_raii soluciones/04_raii.cpp)
  m0_test(sol_05_clase soluciones/05_clase.cpp)
  m0_test(sol_06_virtual soluciones/06_virtual.cpp)
  m0_test(sol_07_plantillas soluciones/07_plantillas.cpp)
  m0_test(sol_08_archivos soluciones/08_archivos/vec2.cpp soluciones/08_archivos/main.cpp)
  target_include_directories(sol_08_archivos PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/soluciones/08_archivos)
endif()
