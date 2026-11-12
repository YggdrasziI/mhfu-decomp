/* unit_0885E244: 0x0885E244-0x0885E270 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct { char b[12]; } E12;

extern s32 D_089CC438;

s32 func_0885E244(s32 arg0, s16 arg1) {
    return *(u8 *)((E12 *)((char *)D_089CC438 + 0x549))[arg1].b == 6;
}
