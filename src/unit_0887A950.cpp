/* unit_0887A950: 0x0887A950-0x0887AFB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_0887A838 and text_0887AFB8). Its jump table (0x089318CC-0x089318F0)
 * is linked from this unit.
 *
 * C++: the `(bool) (x & 1) != 0` test keeps its `sltu`. The two tables at
 * D_089CC438 + 0x6397C / + 0x55ECA are indexed as arrays. Optimized for speed: the
 * divisions by 60 are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {

extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_09A0B544;
extern s32 D_08A62C6C;
extern s32 D_08A62D8C;

extern s32 func_0884FB6C(s32);
extern s32 func_0884FC0C(char *, s32);
extern void func_088854A0(s32, s32, s32);
extern int func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_08876574(char *);
extern void memcpy(void *, void *, s32);

s32 func_0887A950(char *arg0) {
    char *src;
    s32 idx;
    s32 val;

    if (*(s16 *)(arg0 + 0xAA) > 0) {
        (*(s16 *)(arg0 + 0xAA))--;
    }
    switch (*(s16 *)(arg0 + 0xA4)) {
    case 0:
        if (--*(s16 *)(arg0 + 0xA8) <= 0) {
            (*(s16 *)(arg0 + 0xA4))++;
            *(s16 *)(arg0 + 0xA8) = 10;
            func_08883988(D_08A62D8C, 0, 0x10, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 1:
        if (--*(s16 *)(arg0 + 0xA8) <= 0) {
            (*(s16 *)(arg0 + 0xA4))++;
            if (*(s32 *)(arg0 + 0xB0) > *(s32 *)(arg0 + 0xB4)) {
                *(s16 *)(arg0 + 0xA8) = *(s32 *)(arg0 + 0xB0) / 60;
            } else {
                *(s16 *)(arg0 + 0xA8) = *(s32 *)(arg0 + 0xB4) / 60;
            }
            func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
            *(s16 *)(arg0 + 0xAE) = 0;
        }
        break;
    case 2:
        if (*(s32 *)(arg0 + 0xB8) >= *(s32 *)(arg0 + 0xB0) && *(s32 *)(arg0 + 0xBC) >= *(s32 *)(arg0 + 0xB4)) {
            func_088854A0(D_08A62D8C, *(s32 *)(arg0 + 0xC8), 0);
            (*(s16 *)(arg0 + 0xA4))++;
            *(s16 *)(arg0 + 0xA8) = 10;
            func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
        } else {
            *(s32 *)(arg0 + 0xB8) += *(s16 *)(arg0 + 0xA8);
            if (*(s32 *)(arg0 + 0xB8) > *(s32 *)(arg0 + 0xB0)) {
                *(s32 *)(arg0 + 0xB8) = *(s32 *)(arg0 + 0xB0);
            }
            *(s32 *)(arg0 + 0xBC) += *(s16 *)(arg0 + 0xA8);
            if (*(s32 *)(arg0 + 0xBC) > *(s32 *)(arg0 + 0xB4)) {
                *(s32 *)(arg0 + 0xBC) = *(s32 *)(arg0 + 0xB4);
            }
            if (*(s16 *)(arg0 + 0xAE) == 0) {
                *(s32 *)(arg0 + 0xC8) = func_08883988(D_08A62D8C, 0, 8, 0, 0, 0, 0, 0, 0);
                (*(s16 *)(arg0 + 0xAE))++;
            }
        }
        break;
    case 3:
        if (--*(s16 *)(arg0 + 0xA8) <= 0) {
            (*(s16 *)(arg0 + 0xA4))++;
            *(s16 *)(arg0 + 0xA8) = 10;
            func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 4:
        if (--*(s16 *)(arg0 + 0xA8) <= 0) {
            if (*(s16 *)(arg0 + 0xAC) == 1) {
                (*(s16 *)(arg0 + 0xA4))++;
                *(s16 *)(arg0 + 0xA8) = 0x5A;
                func_08876574(arg0);
                *(s8 *)(arg0 + 0xC1) = 1;
                src = 0;
                if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) {
                    if (*(u8 *)(D_089CC438 + 0x28) == 0) {
                        src = D_09A0B544 + 0xC90;
                    } else {
                        src = D_09A0B544 + 0xBC8;
                    }
                }
                idx = *(u16 *)(D_089CC438 + 0x6AF12);
                val = *(s32 *)(arg0 + 0x120);
                if (val > 999999) {
                    val = 999999;
                }
                ((s32 *)(D_089CC438 + 0x6397C))[idx] = val;
                if (src != 0) {
                    memcpy(D_089CC438 + (idx - 4001) * 18 + 0x6781C, src, 0x12);
                } else {
                    (D_089CC438 + 0x55ECA)[idx * 18] = 0;
                }
            } else {
                *(s16 *)(arg0 + 0xA4) += 2;
                *(s16 *)(arg0 + 0xA8) = 10;
                func_08883988(D_08A62D8C, 0, 0x10, 0, 0, 0, 0, 0, 0);
            }
            *(s16 *)(arg0 + 0xAE) = 0;
        }
        break;
    case 5:
        (*(s16 *)(arg0 + 0xA8))--;
        if (*(s8 *)(arg0 + 0xC1) == 0 && *(s16 *)(arg0 + 0xA8) <= 0) {
            (*(s16 *)(arg0 + 0xA4))++;
            *(s16 *)(arg0 + 0xA8) = 10;
            func_08883988(D_08A62D8C, 0, 0x10, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 6:
        if (*(s32 *)(arg0 + 0x14) != 0) {
            if (*(s16 *)(arg0 + 0xAE) == 0) {
                *(s32 *)(arg0 + 0xC8) = func_08883988(D_08A62D8C, 0, 8, 0, 0, 0, 0, 0, 0);
                (*(s16 *)(arg0 + 0xAE))++;
            }
            if (D_08A62C6C & 0x4000) {
                func_0884FC0C(D_089CC438, *(s32 *)(arg0 + 0x14));
                *(s32 *)(arg0 + 0x14) = 0;
            } else {
                func_0884FC0C(D_089CC438, 1);
                (*(s32 *)(arg0 + 0x14))--;
            }
        } else {
            func_088854A0(D_08A62D8C, *(s32 *)(arg0 + 0xC8), 0);
            (*(s16 *)(arg0 + 0xA4))++;
            func_08883988(D_08A62D8C, 0, 0x19, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 7:
        if (--*(s16 *)(arg0 + 0xA8) <= 0) {
            (*(s16 *)(arg0 + 0xA4))++;
            *(s16 *)(arg0 + 0xA8) = 10;
        }
        break;
    case 8:
        if (*(s16 *)(arg0 + 0xAA) <= 0 || ((u16) func_0884FB6C((s32) D_089CC438) & 0x4000)) {
            (*(s16 *)(arg0 + 0xA4))++;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            return 1;
        }
        break;
    }
    return 0;
}

}