macro(add_backend n)
	add_library(${n} ${ARGN})
	set_target_properties(${n} PROPERTIES PREFIX "" OUTPUT_NAME "backend_${n}")
endmacro()

add_subdirectory(webdav)
