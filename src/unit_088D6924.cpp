/* unit_088D6924: 0x088D6924-0x088D69F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088D66F4 (still in assembly)
 * and unit_088D69F0.
 *
 * Copies the 24 pairs at +0x43C8 of the global object to the pairs returned
 * by func_08856884 and, for the object whose id is the global one, to its
 * own pairs at +0x568.
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

void func_088D6924(char *arg0) {
    s32 i;
    char *rec;
    char *own;

    i = 0;
    own = arg0;
    rec = D_089CC438 + 0x4A0;
    for (; i < 0x18; i++, rec += 4, own += 4) {
        func_08856884(D_089CC438, i)->unk0 = *(u16 *)(rec + 0x3F28);
        func_08856884(D_089CC438, i)->unk2 = *(s16 *)(rec + 0x3F2A);
        if (is_own(arg0) == 1) {
            *(u16 *)(own + 0x568) = *(u16 *)(rec + 0x3F28);
            *(s16 *)(own + 0x56A) = *(s16 *)(rec + 0x3F2A);
        }
    }
}

}
