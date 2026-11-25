/* unit_08849300: 0x08849300-0x088493A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08849300 (ULES01213), 0x08849300-0x088493A4
 *
 * C++: the (bool) flag test keeps `sltu` before the branch.
 */

extern "C" {

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

extern char *D_08A631A0;
extern char *D_089CC438;
extern u8 func_0884FA5C(char *, s32);
extern s32 func_088567C8(char *);
extern u8 func_088567B4(char *);

s32 func_08849300(char *arg0) {
    if ((bool)(*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 0
        && func_0884FA5C(D_089CC438, 0) == 0
        && (func_088567C8(D_089CC438), func_088567B4(D_089CC438) == 1)) {
        *(s32 *)(arg0 + 0x5E8) &= ~4;
        *(s8 *)(arg0 + 0x11AB) = 1;
        return 0;
    }
    return -1;
}

}
