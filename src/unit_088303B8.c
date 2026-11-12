/* unit_088303B8: 0x088303B8-0x088303E8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char D_0893AACC;

u16 func_088303B8(s32 arg0, s32 arg1, s32 arg2) {
    return *(u16 *)((((arg1 & 0xFFFF) * 2) + (&D_0893AACC + ((arg2 & 0xFF) * 0x70))));
}
