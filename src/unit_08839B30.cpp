/* unit_08839B30: 0x08839B30-0x08839F64 (ULES01213)
 *
 * C++: flag test keeps its `sltu` (bool). The 0x80110321 test jumps into the
 * 0x80110322 branch with a goto: an `||` of the two consecutive codes becomes
 * a range check (`addu; sltiu 2`).
 */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

extern char *D_089CC438;
extern char *D_089CBBEC;
extern char *D_08A631A0;
extern char *D_09A44C60;
extern s32 D_08A62D8C;
extern char *D_08A62C64;
extern char D_089CBBF0[];
extern char D_0893B398;

extern void func_0881C2E4(char *, u8 *, s32, u8);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088BA760(char *, s32, s32);
extern void func_088BFBEC(char *);
extern s32 func_088BFCF0(char *);
extern void func_088BA860(char *);
extern char *func_08851680(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_088BFEF8(char *, char *);
extern void func_08880760(s32, s32);

s32 func_08839B30(char *arg0, s32 arg1) {
    s32 sel;
    u8 n = 3;
    u8 mode;

    switch (*(s32 *)(arg0 + 0x121C)) {
    case 0:
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1) {
            n--;
        }
        func_0881C2E4(arg0, (u8 *)(arg0 + 0x57F), arg1, n);
        *(s16 *)(arg0 + 0x5FC) = *(u8 *)(arg0 + 0x57F) + 9;
        if (((u16)arg1 & 0x20) || ((u16)arg1 & 0x80)) {
            switch (*(u8 *)(arg0 + 0x57F)) {
            case 0:
                *(s8 *)(arg0 + 0x608) ^= 1;
                *(s8 *)(D_089CC438 + 0x6ADE3) = *(s8 *)(D_089CBBEC + 0x608);
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
                break;
            case 2: {
                s8 v = *(s8 *)(arg0 + 0x609) ^ 1;
                *(s8 *)(arg0 + 0x609) = v;
                *(s8 *)(D_089CC438 + 0x6ADDE) = v;
                if (*(s8 *)(D_089CC438 + 0x6ADDE) != 0) {
                    (*(s32 *)(arg0 + 0x121C))++;
                    func_088BA760(D_09A44C60, 0x80, 0);
                    func_088BFBEC(D_09A44C60);
                }
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
                break;
            case 1:
                if ((u16)arg1 & 0x80) {
                    if (*(s8 *)(arg0 + 0x60A) == 0) {
                        *(s8 *)(arg0 + 0x60A) = 2;
                    } else {
                        *(s8 *)(arg0 + 0x60A) -= 1;
                    }
                } else {
                    if (++*(s8 *)(arg0 + 0x60A) > 2) {
                        *(s8 *)(arg0 + 0x60A) = 0;
                    }
                }
                switch (*(s8 *)(arg0 + 0x60A)) {
                case 0:
                    mode = 1;
                    break;
                case 1:
                    mode = 2;
                    break;
                case 2:
                    mode = 3;
                    break;
                }
                *(s8 *)(D_089CC438 + 0x6ADD9) = mode;
                func_08880760(D_08A62D8C, *(s8 *)(D_089CC438 + 0x6ADD9));
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
                break;
            }
            }
        }
        break;
    case 1: {
        char *p = D_09A44C60;
        s32 err;
        s32 msg;
        if (*(u8 *)(p + 0x970) != 0) {
            break;
        }
        err = *(s32 *)(p + 0x34);
        if (err == 0) {
            if (func_088BFCF0(p) != 0) {
                *(s32 *)(arg0 + 0x121C) = 0;
                func_088BA860(D_09A44C60);
                goto end;
            }
            sel = 0x43;
            msg = 0x40;
        } else if (err == (s32)0x80110321) {
            goto e45;
        } else if (err == (s32)0x80110322) {
        e45:
            sel = 0x45;
            msg = 0x40;
        } else if (err == (s32)0x80110327) {
            sel = 0x46;
            msg = 0x40;
        } else if (err == (s32)0x80110326) {
            sel = 0x43;
            msg = 0x40;
        } else {
            sel = 0;
            msg = 0x40;
        }
        if (sel != 0) {
            char *a = func_08851680(D_089CC438, msg);
            func_0880E8F0(D_089CBBF0, a, func_08851680(D_089CC438, sel));
        } else {
            func_0880E8F0(D_089CBBF0, func_08851680(D_089CC438, msg), &D_0893B398);
        }
        func_088BFEF8(D_09A44C60, D_089CBBF0);
        *(u8 *)(D_08A62C64 + 0x17) = 1;
        *(s8 *)(arg0 + 0x609) = 0;
        *(s8 *)(D_089CC438 + 0x6ADDE) = 0;
        (*(s32 *)(arg0 + 0x121C))++;
        break;
    }
    case 2:
        if (*(u8 *)(D_09A44C60 + 0x971) == 0) {
            *(u8 *)(D_08A62C64 + 0x17) = 0;
            *(s32 *)(arg0 + 0x121C) = 0;
            func_088BA860(D_09A44C60);
        }
        break;
    }
end:
    return arg1;
}

}
