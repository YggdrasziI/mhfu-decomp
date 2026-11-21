/* unit_08901814: 0x08901814-0x08901924 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Walks ten 0x1090-byte slots from arg0 + 0x188. A slot whose 6-bit state at
 * +0x10 is neither 0 nor 0x3F has its s16 timer at +0xE decremented; the state
 * is cleared when the timer goes negative or when the 6-byte id at the start
 * of the slot is not found among the 0xC8-byte entries at +0x57C of
 * D_09A0B544 (count: s8 at +0xEE3).
 *
 * #pragma optimize_for_size off: the search loops step their pointers.
 * The three-level inline chain (compare, search, data pointer) is fully
 * inlined only with the build flag `-inline bottomup` (`-inline level=2`
 * leaves a call; notes/COMPILER.md, "Inlining depth").
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_09A0B544;

static inline s32 compare_id(u8 *a, u8 *b) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (a[i] < b[i]) {
            return -1;
        }
        if (b[i] < a[i]) {
            return 1;
        }
    }
    return 0;
}

static inline char *find_entry(u8 *id) {
    char *base = D_09A0B544;
    s32 n = *(s8 *) (base + 0xEE3);
    s32 i;
    for (i = 0; i < n; i++) {
        if (compare_id(id, (u8 *) (base + i * 0xC8 + 0x57C)) == 0) {
            return base + i * 0xC8 + 0x57C;
        }
    }
    return 0;
}

static inline char *find_data(u8 *id) {
    char *e = find_entry(id);
    if (e != 0) {
        return e + 0x20;
    }
    return 0;
}

void func_08901814(char *arg0) {
    char *p = arg0 + 0x188;
    s32 i;
    for (i = 0; i < 10; i++, p += 0x1090) {
        u16 f = *(u16 *) (p + 0x10) & 0x3F;
        if (f == 0) {
            continue;
        }
        if (f == 0x3F) {
            continue;
        }
        if (--*(s16 *) (p + 0xE) < 0 || find_data((u8 *) p) == 0) {
            *(u16 *) (p + 0x10) = 0;
        }
    }
}
