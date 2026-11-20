/* unit_088D92F8: 0x088D92F8-0x088D9EB8 (ULES01213)
 *
 * Bounds (hypothesis): 3 functions between unit_088D8DF4 and
 * unit_088D9EB8; the end is where func_088D96BC's call of func_088D9EB8
 * needs an `s32` second parameter, the definition an `s16` one.
 *
 * func_088D92F8, sibling of func_088D8ED4: computes the 16-bit value at
 * +0x422 of the object whose id is the global one and stores half of it,
 * at least 1, at +0x384. func_088D96BC fills the five floats at +0x39C
 * from func_0885D300 and applies the bonuses: func_088D9880 (states of
 * func_088D6A1C), func_088D9EB8 for the five keys of D_089B64F0, then
 * func_088D9F3C and func_088DA008.
 *
 * C++: bool conversions, an inline test of the object id against the
 * global one. Optimized for speed (float constants as immediates).
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

extern s32 func_0885D300(char *, char *, s32, s32);
extern s32 func_088568AC(char *, s32);
extern s32 func_08856E34(char *);
extern s32 func_088D6A1C(char *, u8);
extern s32 func_088D6A54(char *, u8);
extern s32 func_088DAE98(char *, s32);
void func_088D9880(char *arg0);
extern void func_088D9EB8(char *, s32, float);
extern void func_088D9F3C(char *);
extern void func_088DA008(char *);
extern s32 func_088DA150(char *, s32);

extern s16 D_089B64F0[];

static inline bool is_own(char *obj) {
    return *(u16 *)(obj + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

void func_088D92F8(char *arg0) {
    s32 v;
    float f;

    if (is_own(arg0) == 0) {
        return;
    }
    v = 1;
    v += (s16) func_0885D300(D_08A62C54, arg0, v, 0);
    if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 8) == 0) {
        if (func_088568AC(D_089CC438, 0x28) > 0) {
            v += 0x10;
        }
        if (func_088568AC(D_089CC438, 0x29) > 0) {
            v += 0x18;
        }
    }
    v += *(s8 *)(arg0 + 0x38B);
    v += *(s8 *)(arg0 + 0x3D8);
    if ((u8) func_088D6A1C(arg0, 0x52) == 1) {
        v += 0x14;
    } else if ((u8) func_088D6A1C(arg0, 0x53) == 1) {
        v += 0x1E;
    } else if ((u8) func_088D6A1C(arg0, 0x54) == 1) {
        v += 0x28;
    } else if ((u8) func_088D6A1C(arg0, 0x55) == 1) {
        v -= 0x14;
    } else if ((u8) func_088D6A1C(arg0, 0x56) == 1) {
        v -= 0x1E;
    } else if ((u8) func_088D6A1C(arg0, 0x57) == 1) {
        v -= 0x28;
    }
    if (v <= 0) {
        v = 1;
    }
    if ((float) *(s16 *)(arg0 + 0x2E4) / (float) *(s16 *)(arg0 + 0x41E) <= 0.4f) {
        if ((u8) func_088D6A1C(arg0, 0xA3) == 1 || (u8) func_088D6A1C(arg0, 0xA4) == 1
            || (u8) func_088D6A1C(arg0, 0xD3) == 1) {
            v += 0x5A;
        } else if ((u8) func_088D6A1C(arg0, 0xA5) == 1) {
            v += 0x2A;
        } else {
            v += 0x3C;
        }
    }
    if ((u8) func_088DAE98(arg0, 4) == 1) {
        switch (*(u8 *)(arg0 + 0x5F9)) {
        case 1:
            v = 1.15f * v;
            break;
        case 2:
        case 3:
            v = 1.2f * v;
            break;
        case 4:
            v = 1.3f * v;
            break;
        }
    }
    *(u16 *)(arg0 + 0x422) = v;
    if (*(s16 *)(arg0 + 0x2E4) <= 10 && func_088D6A54(arg0, 0x15) != 0) {
        *(u16 *)(arg0 + 0x422) += *(u16 *)(arg0 + 0x422) / 2;
    }
    if ((u8) func_08856E34(D_089CC438) == 1) {
        if (*(s16 *)(arg0 + 0x110E) > 0) {
            *(u16 *)(arg0 + 0x422) = *(u16 *)(arg0 + 0x422) >> 1;
        }
    }
    f = (float) (u32) *(u16 *)(arg0 + 0x422) / 2.0f;
    *(float *)(arg0 + 0x384) = f;
    if (f < 1.0f) {
        *(float *)(arg0 + 0x384) = 1.0f;
    }
}

void func_088D96BC(char *arg0) {
    s32 i;
    s32 k;

    *(float *)(arg0 + 0x39C) = func_0885D300(D_08A62C54, arg0, 2, 0);
    *(float *)(arg0 + 0x3A0) = func_0885D300(D_08A62C54, arg0, 3, 0);
    *(float *)(arg0 + 0x3A4) = func_0885D300(D_08A62C54, arg0, 4, 0);
    *(float *)(arg0 + 0x3A8) = func_0885D300(D_08A62C54, arg0, 5, 0);
    *(float *)(arg0 + 0x3AC) = func_0885D300(D_08A62C54, arg0, 0xD, 0);
    func_088D9880(arg0);
    for (i = 0; i < 5; i++) {
        k = D_089B64F0[i];
        if ((u8) func_088DA150(arg0, k) == 1) {
            switch (*(u8 *)(arg0 + (s16) k + 0x5F7)) {
            case 1:
                func_088D9EB8(arg0, k, 10.0f);
                break;
            case 2:
            case 3:
                func_088D9EB8(arg0, k, 15.0f);
                break;
            case 4:
                func_088D9EB8(arg0, k, 20.0f);
                break;
            }
        }
    }
    func_088D9F3C(arg0);
    func_088DA008(arg0);
}

void func_088D9880(char *arg0) {
    s32 i;

    if ((u8) func_088D6A1C(arg0, 0x67) == 1 || (u8) func_088D6A1C(arg0, 0xD4) == 1) {
        *(float *)(arg0 + 0x39C) += 10.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x66) == 1) {
        *(float *)(arg0 + 0x39C) += 5.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x69) == 1) {
        *(float *)(arg0 + 0x39C) -= 10.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x68) == 1) {
        *(float *)(arg0 + 0x39C) -= 5.0f;
    }
    if ((u8) func_088D6A1C(arg0, 0x6B) == 1) {
        *(float *)(arg0 + 0x3A0) += 10.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x6A) == 1) {
        *(float *)(arg0 + 0x3A0) += 5.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x6D) == 1) {
        *(float *)(arg0 + 0x3A0) -= 10.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x6C) == 1) {
        *(float *)(arg0 + 0x3A0) -= 5.0f;
    }
    if ((u8) func_088D6A1C(arg0, 0x73) == 1) {
        *(float *)(arg0 + 0x3A4) += 10.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x72) == 1) {
        *(float *)(arg0 + 0x3A4) += 5.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x75) == 1) {
        *(float *)(arg0 + 0x3A4) -= 10.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x74) == 1) {
        *(float *)(arg0 + 0x3A4) -= 5.0f;
    }
    if ((u8) func_088D6A1C(arg0, 0x77) == 1) {
        *(float *)(arg0 + 0x3A8) += 10.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x76) == 1) {
        *(float *)(arg0 + 0x3A8) += 5.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x79) == 1) {
        *(float *)(arg0 + 0x3A8) -= 10.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x78) == 1) {
        *(float *)(arg0 + 0x3A8) -= 5.0f;
    }
    if ((u8) func_088D6A1C(arg0, 0x6F) == 1) {
        *(float *)(arg0 + 0x3AC) += 10.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x6E) == 1) {
        *(float *)(arg0 + 0x3AC) += 5.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x71) == 1) {
        *(float *)(arg0 + 0x3AC) -= 10.0f;
    } else if ((u8) func_088D6A1C(arg0, 0x70) == 1) {
        *(float *)(arg0 + 0x3AC) -= 5.0f;
    }
    if ((u8) func_088D6A1C(arg0, 0x60) == 1) {
        for (i = 0; i < 5; i++) {
            ((float *)(arg0 + 0x39C))[i] += 3.0f;
        }
    } else if ((u8) func_088D6A1C(arg0, 0x61) == 1) {
        for (i = 0; i < 5; i++) {
            ((float *)(arg0 + 0x39C))[i] += 5.0f;
        }
    } else if ((u8) func_088D6A1C(arg0, 0x62) == 1) {
        for (i = 0; i < 5; i++) {
            ((float *)(arg0 + 0x39C))[i] += 10.0f;
        }
    } else if ((u8) func_088D6A1C(arg0, 0x63) == 1) {
        for (i = 0; i < 5; i++) {
            ((float *)(arg0 + 0x39C))[i] -= 3.0f;
        }
    } else if ((u8) func_088D6A1C(arg0, 0x64) == 1) {
        for (i = 0; i < 5; i++) {
            ((float *)(arg0 + 0x39C))[i] -= 5.0f;
        }
    } else if ((u8) func_088D6A1C(arg0, 0x65) == 1) {
        for (i = 0; i < 5; i++) {
            ((float *)(arg0 + 0x39C))[i] -= 10.0f;
        }
    }
}

}
