/* unit_0885E270: 0x0885E270-0x0885E2E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885E270: returns 0xFF when func_0885E244 refuses entry arg1, else
 * whether the u16 flags of 12-byte entry arg1 (table at D_089CC438 + 0x54C)
 * share a bit with arg2.
 * Needs #pragma opt_rebuildconditionals off (bnezl into the body, b to the
 * shared 0xFF); the loaded flags go in their own local first (and order).
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 h[6];
} E12;

extern char *D_089CC438;

extern s32 func_0885E244(s32 arg0, s16 arg1);

#pragma opt_rebuildconditionals off

u8 func_0885E270(s32 arg0, s16 arg1, s32 arg2) {
    char *p = D_089CC438 + 0x4A0;
    u16 v;

    if (!(u8)func_0885E244(arg0, arg1)) {
        return 0xFF;
    }
    v = ((E12 *)(p + 0xAC))[arg1].h[0];
    return (v & arg2) != 0;
}
