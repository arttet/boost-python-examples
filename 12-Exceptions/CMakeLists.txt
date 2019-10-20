cmake_minimum_required(VERSION 3.12)

set(TARGET_NAME "12-Exceptions")
set(MODULE_NAME "my_exceptions")

project(${TARGET_NAME})

Python_add_library(${TARGET_NAME} MODULE ${MODULE_NAME}.cpp)

target_compile_definitions(${TARGET_NAME}
  PRIVATE
    MODULE_NAME=${MODULE_NAME}
)

target_link_libraries(${TARGET_NAME}
  LINK_PRIVATE
    ${Boost_ALL}
)

set_target_properties(${TARGET_NAME}
  PROPERTIES
    OUTPUT_NAME ${MODULE_NAME}
)

add_test(NAME ${TARGET_NAME}
         COMMAND Python::Interpreter ${CMAKE_CURRENT_SOURCE_DIR}/py_${MODULE_NAME}.py)

if (WIN32)
  set_tests_properties(${TARGET_NAME}
    PROPERTIES
      ENVIRONMENT PYTHONPATH=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>;$ENV{PYTHONPATH}
  )
else()
  set_tests_properties(${TARGET_NAME}
    PROPERTIES
      ENVIRONMENT PYTHONPATH=${CMAKE_CURRENT_BINARY_DIR}/;$ENV{PYTHONPATH}
  )
endif()

install(TARGETS ${TARGET_NAME} DESTINATION bin)
install(FILES py_${MODULE_NAME}.py DESTINATION bin)
