set(WEBDAV_SRC
	webdav.c
)

add_backend(webdav SHARED ${WEBDAV_SRC})
