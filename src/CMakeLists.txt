set(EXECUTABLE_OUTPUT_PATH ..)
file(GLOB fngen_src "*.c" "*.h")
message("test")
message(${fngen_src})
add_executable(fngen ${fngen_src})

