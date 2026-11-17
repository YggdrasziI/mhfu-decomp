/* unit_08834D3C: 0x08834D3C-0x08835098 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_08834D04 and unit_08835098.
 * Its jump table (0x08930F74-0x08930FA8) is linked from this unit.
 *
 * C++: flag tests keep their `sltu` (bool).
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

extern char *D_089CC438;
extern char *D_08A631A0;
extern s32 D_09A4F0C4;

extern s32 func_088DCEBC(s32, u8);
extern void func_088D897C(s32);
extern void func_088277DC(char *, s32);
extern s32 func_0881C884(char *arg0);
extern s32 func_0881C944(char *arg0);
extern s32 func_0881CA34(s32 arg0);
extern int func_0881CAC8(char *p);
extern int func_0881CB0C(char *o);
extern s32 func_0881E8F8(char *arg0);
extern s32 func_08838AB4(s32, u8, u8);

s32 func_08834D3C(char *arg0, u8 arg1) {
    s32 obj = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    s32 ret = 1;

    switch (arg1) {
    case 0:
        ret = func_0881C884(arg0);
        break;
    case 1:
        func_088D897C(obj);
        ret = func_0881C944(arg0);
        break;
    case 9:
        func_088D897C(obj);
        ret = func_0881E8F8(arg0);
        break;
    case 2:
        ret = func_0881CA34((s32) arg0);
        break;
    case 7:
        func_088277DC(arg0, obj);
        ret = func_0881CAC8(arg0);
        break;
    case 8:
        func_088D897C(obj);
        ret = func_0881CB0C(arg0);
        break;
    case 5:
        *(s32 *)(arg0 + 0x5E8) |= 4;
        ret = 0;
        *(u16 *)(arg0 + 0x5FC) = 0xE;
        arg0[0x57E] = 0;
        arg0[0x57F] = 0;
        break;
    case 6:
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1) {
            s32 count;
            u32 i;
            char *rec;

            *(s32 *)(arg0 + 0x5E8) |= 4;
            arg0[0x57E] = 0;
            arg0[0x57F] = 0;
            *(char **)(arg0 + 0x118C) = D_089CC438 + 0x69BEC;
            count = 0;
            rec = D_089CC438;
            for (i = 0; i < 13; i++) {
                if (*(s8 *)(rec + 0x69BEC) != 0) {
                    count++;
                }
                rec += 0x70;
            }
            if ((u8) count != 0) {
                *(u16 *)(arg0 + 0x5FC) = *(u8 *)(arg0 + 0x57F) + 0x12;
            } else {
                *(u16 *)(arg0 + 0x5FC) = 0x15;
            }
            ret = 0;
        }
        break;
    case 10: {
        s8 v;

        arg0[0x609] = *(s8 *)(D_089CC438 + 0x6ADDE);
        v = *(s8 *)(D_089CC438 + 0x6ADD9);
        switch (v) {
        case 1:
            arg0[0x60A] = 0;
            break;
        case 2:
            arg0[0x60A] = 1;
            break;
        case 3:
            arg0[0x60A] = 2;
            break;
        }
        *(s32 *)(arg0 + 0x5E8) |= 4;
        arg0[0x5FE] = 3;
        *(u16 *)(arg0 + 0x5FC) = 9;
        arg0[0x57F] = 0;
        ret = 0;
        break;
    }
    case 4:
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1) {
            arg0[0x57E] = 0;
            arg0[0x57F] = 0;
            arg0[0x580] = 0;
            ret = 0;
        }
        break;
    case 12:
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1) {
            if ((u8) func_08838AB4((s32) arg0, *(u8 *)(obj + 0x298), *(u8 *)(obj + 0x299)) == 0) {
                if ((bool) (*(s32 *)(*(char **)(arg0 + 0x530) + 0x614) & 8) == 0) {
                    arg0[0x57E] = 0;
                    arg0[0x57F] = 0;
                    arg0[0x580] = 0;
                    ret = 0;
                }
            }
        }
        break;
    case 3:
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1) {
            arg0[0x57E] = 0;
            arg0[0x57F] = 0;
            arg0[0x580] = 0;
            arg0[0x5FE] = 0;
            ret = 0;
            *(u16 *)(arg0 + 0x5FC) = 0xC;
        }
        break;
    case 11:
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1) {
            ret = 0;
        }
        break;
    }
    return ret;
}

}
