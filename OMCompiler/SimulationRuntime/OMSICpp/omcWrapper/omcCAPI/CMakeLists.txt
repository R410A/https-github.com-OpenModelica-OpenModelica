

PROJECT(${OMCCAPIName})

#name of omc c api wrapper dll


OPTION(ENABLE_CAPI_TESTS "enable tests for c api calls" OFF)

#check if path to OpenModelica was set
IF(NOT OMC_PATH)
 MESSAGE(FATAL_ERROR "OpenModelica path is not set")
ENDIF(NOT OMC_PATH)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#path to OpenModelica libs
IF(WIN32) # Check if we are on Windows
  IF(MSVC)
   SET(OMC_LIB_PATH "${OMC_PATH}/lib/omc/msvc")
  ELSE(MSVC)
   SET(OMC_LIB_PATH "${OMC_PATH}/${LIB_OMC}")
   set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,33554432")
   SET(CMAKE_FIND_LIBRARY_SUFFIXES ".dll.a" ".dll" ".a")
  ENDIF(MSVC)
ELSEIF(UNIX)
  SET(OMC_LIB_PATH "${OMC_PATH}/${LIBINSTALLEXT}/../")
ELSE(WIN32)
  MESSAGE(SEND_ERROR "You are on an unsupported platform! (Not Win32 or Unix)")
ENDIF(WIN32)

MESSAGE(STATUS "using omc paths")
MESSAGE(STATUS ${OMC_PATH})
MESSAGE(STATUS ${OMC_LIB_PATH})



INCLUDE_DIRECTORIES(./include)
#search for ModelicaExtrenal C library
FIND_LIBRARY(MODELICAEX_LIB NAMES libModelicaExternalC.a ModelicaExternalC.lib NO_DEFAULT_PATH NO_SYSTEM_ENVIRONMENT_PATH PATHS ${OMC_LIB_PATH})
IF(NOT MODELICAEX_LIB)
  MESSAGE(FATAL_ERROR "Could not find ModelicaExternalC library!")
ENDIF(NOT MODELICAEX_LIB)

#search for OpenModelica C Runtime library
FIND_LIBRARY(OMCRUNTIME_LIB "OpenModelicaRuntimeC" NO_DEFAULT_PATH NO_SYSTEM_ENVIRONMENT_PATH PATHS ${OMC_LIB_PATH})
IF(NOT OMCRUNTIME_LIB)
  MESSAGE(FATAL_ERROR "Could not find OpenModelicaRuntimeC library!")
ENDIF(NOT OMCRUNTIME_LIB)

#search for OpenModelica Compiler dll
FIND_LIBRARY(OMC_LIB "OpenModelicaCompiler" NO_DEFAULT_PATH NO_SYSTEM_ENVIRONMENT_PATH PATHS ${OMC_LIB_PATH})
IF(NOT OMC_LIB)
  MESSAGE(FATAL_ERROR "Could not find OpenModelicaCompiler library!")
ENDIF(NOT OMC_LIB)

#search for FMILib
FIND_LIBRARY(FMI_LIB "fmilib" NO_DEFAULT_PATH NO_SYSTEM_ENVIRONMENT_PATH PATHS ${OMC_LIB_PATH})
IF(NOT FMI_LIB)
  MESSAGE(FATAL_ERROR "Could not find fmilib library!")
ENDIF(NOT FMI_LIB)

FIND_LIBRARY(OMCGC_LIB "omcgc" NO_DEFAULT_PATH NO_SYSTEM_ENVIRONMENT_PATH PATHS ${OMC_LIB_PATH})
IF(NOT OMCGC_LIB)
  MESSAGE(FATAL_ERROR "Could not find omcgc library!")
ENDIF(NOT OMCGC_LIB)


#add necessary definitions
ADD_DEFINITIONS(-DIMPORT_INTO=1)
ADD_DEFINITIONS(-DBUILDING_OMC_DLL)



ADD_LIBRARY(${OMCCAPIName} SHARED src/OMC.cpp)
TARGET_LINK_LIBRARIES(${OMCCAPIName} ${MODELICAEX_LIB} ${OMCRUNTIME_LIB} ${OMC_LIB} ${FMI_LIB} ${OMCGC_LIB})


INSTALL(TARGETS ${OMCCAPIName} DESTINATION lib)
#INSTALL(FILES 
#    include/OMC.h 
#    include/OMCAPI.h 
#    include/OMCFunctions.h DESTINATION include)



