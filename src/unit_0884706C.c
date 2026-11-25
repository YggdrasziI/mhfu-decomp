/* unit_0884706C: 0x0884706C-0x0884711C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884706C: counts the slots among 24 whose entry has a positive
 * count, a non-zero id and a func_0885C580 record whose byte 0x1 is 1. */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    /* 0x0 */ u16 id;
    /* 0x2 */ s16 count;
} Pair;

extern char *D_089CC438;
extern char *D_08A62C50;
extern Pair *func_08856884(char *, s32);
extern u8 *func_0885C580(char *, s32);

s16 func_0884706C(void) {
    s16 i;
    s16 n;

    i = 0;
    n = 0;
    for (; i < 24; i++) {
        if (func_08856884(D_089CC438, i)->count > 0) {
            if (func_08856884(D_089CC438, i)->id != 0) {
                if (func_0885C580(D_08A62C50, i)[1] == 1) {
                    n++;
                }
            }
        }
    }
    return n;
}
