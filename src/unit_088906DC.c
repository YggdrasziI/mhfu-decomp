/* unit_088906DC: 0x088906DC-0x08890718 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

typedef int s32;
typedef unsigned char u8;

extern char *D_089CC434;

void func_088906DC(char *arg0) {
    *(s32 *) (arg0 + 0xF7A57C) &= ~1;
    *(u8 *) (D_089CC434 + 0x2FBDC) = 1;
}
