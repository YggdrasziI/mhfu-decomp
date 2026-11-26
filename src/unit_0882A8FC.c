/* unit_0882A8FC: 0x0882A8FC-0x0882A988 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern char *D_08A631A0;
extern char *D_089CC438;

s32 func_0882A8FC(char *p) {
    if ((s32)((*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) == 0) {
        if ((s32)(*(u8 *)(*(char **)(p + 0x530) + 0x1E0) != 0) == 1) {
            return -1;
        }
    } else {
        if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0) {
            return -1;
        }
    }
    *(u8 *)(p + 0x57E) = 0;
    *(u8 *)(p + 0x57F) = 0;
    *(u8 *)(p + 0x580) = 0;
    *(s16 *)(p + 0x5FC) = 12;
    return 0;
}
