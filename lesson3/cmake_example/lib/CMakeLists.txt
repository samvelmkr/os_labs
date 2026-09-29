add_library(printer SHARED printer.cpp)

target_include_directories(printer 
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR})
