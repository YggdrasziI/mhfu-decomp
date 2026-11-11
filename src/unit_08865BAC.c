/* unit_08865BAC: 0x08865BAC-0x08865BD0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;

s32 func_08865BAC(char *arg0) {
    return *(u16 *)(arg0 + 0x29A) == *(u16 *)(D_089CC438 + 0x6AF0E);
}
