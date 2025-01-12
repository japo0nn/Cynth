#ifndef SAFEFREE_H
#define SAFEFREE_H

#define SAFE_FREE(p) \
	do {             \
		free(p);     \
		(p) = NULL;  \
	} while (0)

#endif
