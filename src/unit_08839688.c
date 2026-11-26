/* unit_08839688: 0x08839688-0x08839824 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_08A631A0;
extern s32 D_08A62D8C;
extern s32 D_09A5242C;

extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0881C2E4(char *, u8 *, s32, u8);
extern void func_088F0020(s32);
extern s32 func_088F0088(s32, s32, s32);

s32 func_08839688(char *arg0, s32 arg1) {
    switch (*(u8 *)(arg0 + 0x57E)) {
    case 0:
        if ((u16)arg1 & 0x4000) {
            switch (*(u8 *)(arg0 + 0x57F)) {
            case 2:
                if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) != 0) {
                    goto accept;
                }
                func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                break;
            case 0:
            case 1:
            case 3:
            accept:
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                (*(u8 *)(arg0 + 0x57E))++;
                *(s32 *)(arg0 + 0x5E8) &= ~4;
                func_088F0020(D_09A5242C);
                return 0;
            }
        }
        func_0881C2E4(arg0, (u8 *)(arg0 + 0x57F), arg1, 4);
        *(s16 *)(arg0 + 0x5FC) = *(u8 *)(arg0 + 0x57F) + 0xE;
        break;
    case 1:
        arg1 = (u16)func_088F0088(D_09A5242C, arg1, *(u8 *)(arg0 + 0x57F));
        if (arg1 & 0x2000) {
            (*(u8 *)(arg0 + 0x57E))--;
            arg1 = 0;
            *(s32 *)(arg0 + 0x5E8) |= 4;
        }
        break;
    }
    return arg1;
}
