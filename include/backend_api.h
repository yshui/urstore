#pragma once
#include <stddef.h>
#include <sys/types.h>
typedef struct backend Backend;
struct backend {
	/* Read a range of a file (optional) */
	int (*read_range)(Backend *, const char *, off_t start, size_t length, char *buf);

	/* Read a whole file (required) */
	int (*read)(Backend *, const char *, void *buf);

	/* Write data into a range of a file, write over the end of the file
	 * is undefined. (optional) */
	int (*write_range)(Backend *, const char *, off_t start, size_t length, const char* buf);

	/* Write data into a range of a file, write over the end of the file
	 * will extend the file. (optional) */
	int (*write_range_extend)(Backend *, const char *, off_t start, size_t length, const char* buf);

	/* Overwrite a file, file length will be set to length. If file doesn't
	 * exist, it will be created (require) */
	int (*write)(Backend *, const char *, size_t length, const char *buf);

	/* Lock and unlock a file (optional) */
	void *(*lock)(Backend *, const char *);
	int (*unlock)(Backend *, const char *);

	/* Required to implement least one of the following two */
	/* Return entries in a directory (optional)
	 *
	 * Return should be a array of string pointers, ends with a
	 * NULL
	 */
	char **(*list_dir)(Backend *, const char *);

	/* Return entries in the entire store (optional)
	 *
	 * Same as list_dir
	 */
	char **(*list_all)(Backend *);
};

typedef Backend *(*backend_init_fn)(const char *uri);
