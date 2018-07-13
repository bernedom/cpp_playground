set(SOURCE_DIR source)
file(GLOB SOURCE_FILES *.cc)


foreach(CC_FILE ${SOURCE_FILES} )

  get_filename_component(SOURCE_BASENAME ${CC_FILE} NAME)
  string (REPLACE ".cc" "" EXE_NAME ${SOURCE_BASENAME})
  add_executable(${EXE_NAME} ${CC_FILE})
  set_target_properties(${EXE_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
  )
endforeach(CC_FILE ${SOURCE_FILES} )