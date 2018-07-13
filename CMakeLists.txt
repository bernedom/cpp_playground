CMAKE_MINIMUM_REQUIRED(VERSION 3.5 )

set(SOURCE_DIR source)
file(GLOB SOURCE_FILES src/*.cc)


foreach(CC_FILE ${SOURCE_FILES} )

  get_filename_component(SOURCE_BASENAME ${CC_FILE} NAME)
  string (REPLACE ".cc" "" EXE_NAME ${SOURCE_BASENAME})
  add_executable(${EXE_NAME} ${CC_FILE})
  if (${CMAKE_VERSION} GREATER 3.8)
    set_target_properties(${EXE_NAME} PROPERTIES
     CXX_STANDARD 17
     CXX_STANDARD_REQUIRED YES
    )
  else()
  target_compile_options(${EXE_NAME} PUBLIC
    -std=c++17
  )
  endif()
endforeach(CC_FILE ${SOURCE_FILES} )