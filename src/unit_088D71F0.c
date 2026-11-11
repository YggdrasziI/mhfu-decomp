/* unit_088D71F0: 0x088D71F0-0x088D722C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

s32 func_088147C8(s32);
extern s32 D_089CBBE4;

s32 func_088D71F0(char *arg0) {
    return (*(u16 *)(arg0 + 0x49C) + (func_088147C8(D_089CBBE4) & 0xFFFF)) & 0xFFFF;
}
