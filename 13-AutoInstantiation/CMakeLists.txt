cmake_minimum_required(VERSION 3.12)

set(TARGET_NAME "13-my_extension")
set(MODULE_NAME "my_extension")
set(APP_NAME "13-AutoInstantiation")
set(PY_FILE "py_auto_instance.py")

project(${TARGET_NAME})

Python_add_library(${TARGET_NAME} MODULE ${MODULE_NAME}.cpp)

target_compile_definitions(${TARGET_NAME}
  PRIVATE
    MODULE_NAME=${MODULE_NAME}
    MODULE_NAME_STR="${MODULE_NAME}"
)

target_link_libraries(${TARGET_NAME}
  LINK_PRIVATE
    ${Boost_ALL}
)

set_target_properties(${TARGET_NAME}
  PROPERTIES
    OUTPUT_NAME ${MODULE_NAME}
)

add_executable(${APP_NAME} auto_instance.cpp)

target_compile_definitions(${APP_NAME}
  PRIVATE
    MODULE_NAME="${MODULE_NAME}"
)

target_link_libraries(${APP_NAME}
  LINK_PRIVATE
    Python::Python
    ${Boost_ALL}
)

add_dependencies(${APP_NAME} ${TARGET_NAME})

add_test(NAME ${APP_NAME} COMMAND ${APP_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/py_auto_instance.py)
if (WIN32)
  set_tests_properties(${APP_NAME}
    PROPERTIES
      ENVIRONMENT PYTHONPATH=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>;$ENV{PYTHONPATH}
  )
else()
  set_tests_properties(${APP_NAME}
    PROPERTIES
      ENVIRONMENT PYTHONPATH=${CMAKE_CURRENT_BINARY_DIR}/;$ENV{PYTHONPATH}
  )
endif()


install(TARGETS ${TARGET_NAME} ${APP_NAME} DESTINATION bin)
install(FILES ${PY_FILE} DESTINATION bin)
