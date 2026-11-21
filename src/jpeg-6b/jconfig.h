/* jconfig.h for this build of the IJG JPEG library, release 6b.
 *
 * Not part of the IJG distribution: written for this project from the
 * options listed in the distribution's jconfig.doc. The values are the ones
 * that make the library's unmodified sources compile to the original code
 * (notes/PROVENANCE.md).
 */

#define HAVE_PROTOTYPES
#define HAVE_UNSIGNED_CHAR
#define HAVE_UNSIGNED_SHORT
#define HAVE_STDDEF_H
#define HAVE_STDLIB_H

/* `boolean` is one byte in the original code (is_decompressor is stored
 * with `sb`, global_state follows at +0x14) */
typedef unsigned char boolean;
#define HAVE_BOOLEAN

/* jinit_memory_mgr does not read the JPEGMEM environment variable in the
 * original code (no call between the pool setup and the return) */
#define NO_GETENV
