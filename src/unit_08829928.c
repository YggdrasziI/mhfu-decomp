/* unit_08829928: 0x08829928-0x08829A48 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef short s16;

extern char *D_08A631A0;
extern char *D_089CC438;
extern u8 D_0899D19A[][24];
extern u8 D_0899D19B[][24];
extern s16 func_08826734(char *, u8);

s32 func_08829928(char *arg0) {
    char *g;

    if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0) {
        return 0;
    }
    if (D_0899D19A[func_08826734(arg0, *(u8 *)(arg0 + 0x586))][0] >= 3) {
        return 0;
    }
    if (D_0899D19B[func_08826734(arg0, *(u8 *)(arg0 + 0x586))][0] == 0xFF) {
        return 0;
    }
    g = D_089CC438;
    if ((s32)((*(s32 *)(g + 0x6AF14) & 1) != 0) != 0) {
        if (*(u16 *)(g + 0x6AF0E) != 0x55) {
            return 0;
        }
    } else if ((s32)(*(u8 *)(*(char **)(arg0 + 0x530) + 0x1E0) != 0) == 1) {
        return 0;
    }
    return 1;
}
