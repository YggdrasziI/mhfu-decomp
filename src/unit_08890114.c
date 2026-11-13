/* unit_08890114: 0x08890114-0x08890144 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern s32 func_088900C4(s32, s32);

s32 func_08890114(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_088900C4(arg0, 2);
    *(u16 *)(D_089CC438 + 0x44BE) = temp_v0;
    return temp_v0 & 0xFFFF;
}
