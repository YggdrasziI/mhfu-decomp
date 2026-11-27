/* unit_088165FC: 0x088165FC-0x08816638 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088165FC: table lookup, 0x3F when the entry is zero. */

typedef int s32;
typedef unsigned short u16;

extern u16 D_08910968[];

u16 func_088165FC(s32 arg0, s32 arg1) {
    u16 r;

    if (arg1 == 0) {
        return 0;
    }
    r = D_08910968[(u16)arg1];
    if (r == 0) {
        return 0x3F;
    }
    return r;
}
