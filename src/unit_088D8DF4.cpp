/* unit_088D8DF4: 0x088D8DF4-0x088D92F8 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088D8DA4 and the asm piece
 * text_088D92F8.
 *
 * func_088D8DF4 sums the values of func_0885CF9C for the five items at
 * +0x4E8...+0x524 and of func_0885D1D4 for one key. func_088D8ED4 computes
 * the 16-bit value at +0x420 of the object whose id is the global one (base
 * of func_0885D300, bonuses from pairs, items and states, then factors) and
 * stores it divided by 100 at +0x380.
 *
 * C++: bool conversions, an inline test of the object id against the
 * global one.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern "C" {

extern char *D_089CC438;
extern char *D_08A62C54;

extern s8 func_0885CF9C(char *, char *, s32);
extern s8 func_0885D1D4(char *, char *, s32);
extern s16 func_0885D300(char *, char *, s32, s32);
extern s32 func_088568AC(char *, s32);
extern s32 func_088D6A1C(char *, u8);
extern s32 func_088D6A54(char *, u8);
extern s32 func_088DAE98(char *, s32);

static inline bool is_own(char *obj) {
    return *(u16 *)(obj + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

s8 func_088D8DF4(char *arg0, s32 arg1) {
    s8 sum = 0;

    sum += func_0885CF9C(D_08A62C54, arg0 + 0x500, arg1);
    sum += func_0885CF9C(D_08A62C54, arg0 + 0x518, arg1);
    sum += func_0885CF9C(D_08A62C54, arg0 + 0x524, arg1);
    sum += func_0885CF9C(D_08A62C54, arg0 + 0x4F4, arg1);
    sum += func_0885CF9C(D_08A62C54, arg0 + 0x4E8, arg1);
    sum += func_0885D1D4(D_08A62C54, arg0, arg1);
    return sum;
}

void func_088D8ED4(char *arg0) {
    s32 v = 0;

    if (is_own(arg0) == 1) {
        v += func_0885D300(D_08A62C54, arg0, 0, 0);
        if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 8) == 0) {
            if (func_088568AC(D_089CC438, 0x26) > 0) {
                v += 6;
            }
            if (func_088568AC(D_089CC438, 0x27) > 0) {
                v += 9;
            }
        }
        v += *(s8 *)(arg0 + 0x38A);
        v += *(s8 *)(arg0 + 0x3D4);
        if (*(u8 *)(arg0 + 0x1E8) == 7 && *(s16 *)(arg0 + 0x610) != 0) {
            v += 10;
        }
        if ((u8) func_088D6A1C(arg0, 0x4E) == 1 || (u8) func_088D6A1C(arg0, 0xD1) == 1) {
            v += 0x14;
        } else if ((u8) func_088D6A1C(arg0, 0x4C) == 1) {
            v += 10;
        } else if ((u8) func_088D6A1C(arg0, 0x4D) == 1) {
            v += 15;
        } else if ((u8) func_088D6A1C(arg0, 0x4F) == 1) {
            v -= 5;
        } else if ((u8) func_088D6A1C(arg0, 0x50) == 1) {
            v -= 10;
        } else if ((u8) func_088D6A1C(arg0, 0x51) == 1) {
            v -= 15;
        }
        if ((u8) func_088DAE98(arg0, 2) == 1) {
            switch (*(u8 *)(arg0 + 0x5F8)) {
            case 1:
                v = 1.1f * v;
                break;
            case 2:
            case 3:
                v = 1.15f * v;
                break;
            case 4:
                v = 1.2f * v;
                break;
            }
        }
        if (*(s16 *)(arg0 + 0x2E4) <= 10 && (u8) func_088D6A54(arg0, 0x15) == 1) {
            v = 1.35f * v;
        } else if ((u8) func_088D6A1C(arg0, 0xA4) == 1 || (u8) func_088D6A1C(arg0, 0xD3) == 1) {
            if ((float) *(s16 *)(arg0 + 0x2E4) / (float) *(s16 *)(arg0 + 0x41E) <= 0.4f) {
                v = 1.3f * v;
            }
        } else if ((u8) func_088D6A1C(arg0, 0xA5) == 1) {
            if ((float) *(s16 *)(arg0 + 0x2E4) / (float) *(s16 *)(arg0 + 0x41E) <= 0.4f) {
                v = 0.7f * v;
            }
        }
        if (v <= 0) {
            v = 1;
        }
        *(u16 *)(arg0 + 0x420) = v;
    }
    *(float *)(arg0 + 0x380) = (float) (u32) *(u16 *)(arg0 + 0x420) / 100.0f;
}

}
