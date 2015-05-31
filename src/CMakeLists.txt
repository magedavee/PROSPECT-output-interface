#----------------------------------------------------------------------------
# Compile command, from inside build directory:
# cmake ../
# make -j4

#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(Evt)
#include_directories(/home/mage/DataAnalysis-QuickStart/CalTech)
add_compile_options(-std=c++11)

#----------------------------------------------------------------------------
#For Mac OS X Use @rpath on OS X
if(APPLE) 
  if(POLICY CMP0042)
      CMAKE_POLICY(SET CMP0042 NEW)
   endif()
endif()
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc )
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh )
#-------------------------------
# ROOT dependencies
#-------------------------------

set(PG_LIB $ENV{PG4_LIB_DIR})
set(PG_INC "$ENV{PG4_CODE}/include/Output")
######## locate ROOT install, headers, includes
include(FindROOT.cmake)
include_directories(${ROOT_INCLUDE_DIR} ${PG_INC} "./include")
link_directories(${ROOT_LIBRARY_DIR}${PG_LIB})
MESSAGE( STATUS "CMAKE_INCLUDE_PATH: " ${PG_INC} )
MESSAGE( STATUS "soources: " ${sources} )
#################
# Executables
#################
set(EVT_SRC "./src" )
set(EVT_INC "./include" )
set(PRIM "${EVT_SRC}/PrimEvt.cc")
MESSAGE( STATUS "Prim " ${PRIM})
set(IONI "${EVT_SRC}/IoniEvt.cc")
set(IONIH "${PROJECT_SOURCE_DIR}/include/IoniEvt.hh")
MESSAGE( STATUS "Ioni " ${IONI})
set(SEC "${EVT_SRC}/SecParticleEvt.cc")
set(SECH "${PROJECT_SOURCE_DIR}/include/SecParticleEvt.hh")
MESSAGE( STATUS "SEC " ${SEC})


#set(SB_G4_LINKDEF_E ${PG_INC}/Output/EventLinkDef.h)
#set(SB_G4_DICTIONARY_E ${CMAKE_CURRENT_BINARY_DIR}/EventLib_Dict.cxx)
#MESSAGE("Generating dictionary ${SB_G4_DICTIONARY_E}")
#set(DICTFILES_E "${PG_INC}/Output/Event.hh")
#ROOT_GENERATE_DICTIONARY("${DICTFILES_E}" "${SB_G4_LINKDEF_E}""${SB_G4_DICTIONARY_E}" "")
#LIST(APPEND SEC ${SB_G4_DICTIONARY_E})

set(SB_G4_LINKDEF ${PROJECT_SOURCE_DIR}/include/SecLinkDef.h)
set(SB_G4_DICTIONARY ${CMAKE_CURRENT_BINARY_DIR}/SecParticleEvtLib_Dict.cxx)
MESSAGE("Generating dictionary ${SB_G4_DICTIONARY}")
set(DICTFILES ${PROJECT_SOURCE_DIR}/include/SecParticleEvt.hh)
MESSAGE( STATUS "DIC " ${DICTFILES})
ROOT_GENERATE_DICTIONARY("${DICTFILES}" "${SB_G4_LINKDEF}" "${SB_G4_DICTIONARY}" "")
LIST(APPEND SEC ${SB_G4_DICTIONARY})

set(SB_G4_LINKDEF_I ${PROJECT_SOURCE_DIR}/include/IoniLinkDef.h)
set(SB_G4_DICTIONARY_I ${CMAKE_CURRENT_BINARY_DIR}/IoniEvtLib_Dict.cxx)
MESSAGE("Generating dictionary ${SB_G4_DICTIONARY_I}")
set(DICTFILES ${PROJECT_SOURCE_DIR}/include/IoniEvt.hh)
MESSAGE( STATUS "DIC " ${DICTFILES})
ROOT_GENERATE_DICTIONARY("${DICTFILES}" "${SB_G4_LINKDEF_I}" "${SB_G4_DICTIONARY_I}" "")
LIST(APPEND IONI ${SB_G4_DICTIONARY_I})

add_library(PrimEvt_static STATIC ${PRIM})
add_library(PrimEvt SHARED ${PRIM})
target_link_libraries(PrimEvt ${ROOT_LIBRARIES})
#add_library(IoniEvt_static STATIC ${IONI})
add_library(IoniEvt SHARED ${IONI} ${IONIH})
target_link_libraries(IoniEvt ${ROOT_LIBRARIES})

#add_library(SecParticleEvt_static STATIC ${SEC})
add_library(SecParticleEvt SHARED ${SEC} ${SECH})
target_link_libraries(SecParticleEvt ${ROOT_LIBRARIES})

#Uncomment this next two lines if you want and example program buit with your code

#add_executable(example example.cpp) 
#target_link_libraries(example ${ROOT_LIBRARIES} RawData)


#################
# Build settings
#################

#set(CMAKE_BUILD_TYPE release)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O3 -Wextra -Wpedantic")

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()
