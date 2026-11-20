/* unit_088D722C: 0x088D722C-0x088D72A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088D7224 and func_088D72A4,
 * which is still in assembly (text_088D72A4).
 *
 * Tells whether one of the 24 pairs returned by func_08856884 is free (id
 * 0); always 1 for an object whose id is not the global one.
 *
 * C++: bool conversion, an inline test of the object id against the global
 * one.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Pair {
    u16 unk0;
    s16 unk2;
} Pair;

extern "C" {

extern char *D_089CC438;

extern Pair *func_08856884(char *, s32);

static inline bool is_own(char *obj) {
    return *(u16 *)(obj + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

s32 func_088D722C(char *arg0) {
    s32 i;

    if (is_own(arg0) == 0) {
        return 1;
    }
    i = 0;
    do {
        if (func_08856884(D_089CC438, i)->unk0 == 0) {
            return 1;
        }
        i++;
    } while (i < 0x18);
    return 0;
}

}
