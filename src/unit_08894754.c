/* unit_08894754: 0x08894754-0x08894874 (ULES01213) */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_089CBBE8;
extern s32 func_08816460(s32, u8 **);
extern s32 func_0881629C(s32, u8 **);
extern s32 func_088165FC(s32, u16);

void func_08894754(u8 *arg0, u8 *arg1, s32 arg2) {
    u16 *dst;
    s32 count;
    u8 mode;
    u16 c;

    dst = (u16 *) (arg0 + *(u16 *) (arg0 + 0x160) + 0x22CF8);
    count = 0;
    if (*arg1 != 0) {
        mode = arg2;
        do {
            if (mode == 1) {
                c = func_08816460(D_089CBBE8, &arg1);
            } else {
                c = func_088165FC(D_089CBBE8, func_0881629C(D_089CBBE8, &arg1));
            }
            *dst = c;
            dst++;
            *(u16 *) (arg0 + 0x160) += 2;
            if (*(u16 *) (arg0 + 0x160) >= 0x3000) {
                *(u16 *) (arg0 + 0x160) = 0x2FFE;
                dst = (u16 *) (arg0 + *(u16 *) (arg0 + 0x160) + 0x22CF8);
                count++;
            }
        } while (*arg1 != 0);
    }
    *dst = 0;
    if (count == 0) {
        *(u16 *) (arg0 + 0x160) += 2;
        if (*(u16 *) (arg0 + 0x160) >= 0x3000) {
            *(u16 *) (arg0 + 0x160) = 0x2FFE;
        }
    }
}
