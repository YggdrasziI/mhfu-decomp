/* unit_0883BB10: 0x0883BB10-0x0883D0EC (ULES01213)
 *
 * Bounds (hypothesis): 1 menu state function between code still in assembly.
 *
 * C++: the two 0x70-byte records at D_089CC438 + 0x69BEC are swapped through
 * copy ASSIGNMENTS (member by member; an initialised declaration copies by
 * words). Rec's member types and grouping (small arrays, separate floats,
 * wrapped byte arrays) come from the load/store order of that copy; names
 * are placeholders. Flag tests keep their `sltu` (bool). Speed setting:
 * the 3-byte copy loops are unrolled.
 */
#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

struct F2 {
    f32 a, b;
};

struct B18 {
    s8 b[18];
};

struct B16 {
    s8 b[16];
};

struct Id8 {
    s8 b[6];
    u8 c[2];
};

struct Rec {
    s8 b0;
    u8 b1;
    s8 b2;
    s8 b3;
    s16 h4;
    s8 b6;
    u8 b7[3];
    u8 bA[3];
    s8 bD;
    s8 bE;
    u8 bF;
    u16 h10;
    s16 h12[2];
    u8 b16;
    f32 f18;
    f32 f1C;
    u16 h20;
    u16 h22;
    u8 b24;
    u8 b25;
    u16 h26;
    u8 b28;
    s8 b29;
    s16 h2A;
    u8 b2C;
    s32 w30;
    F2 f34;
    F2 f3C;
    u8 b44[2];
    u8 b46[3];
    u8 b49;
    u8 b4A;
    u8 b4B;
    u8 b4C;
    u8 b4D;
    B18 a4E;
    B16 a60;
};

extern "C" {

extern char *D_089CC438;
extern s32 D_08A62D8C;
extern s32 D_09CFBBC8;
extern char *D_09A0B544;

extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0881C2E4(char *, u8 *, s32, u8);
extern s32 func_0881C45C(s32, void *, s32, s32);
extern void func_0881C520(char *, s32, s32);
extern char *func_0883B3D4(s32, s32);
extern int func_0882A8B8(s32, s32);
extern void func_0889D504(char *, char *, char *);
extern void func_0889D6EC(char *);
extern int func_09C26678(s32);
extern void func_088490C8(char *arg0);
extern void func_08834548(void *p);
extern int memset(void *, s32, s32);
extern int memcpy(void *, void *, s32);

s32 func_0883BB10(char *arg0, s32 arg1) {
    char *q = *(char **)(arg0 + 0x530);
    u8 st = *(u8 *)(arg0 + 0x57E);

    if (st != 0 && st != 11) {
        if ((bool) (*(s32 *)(q + 0x614) & 4) == 0) {
            *(u8 *)(arg0 + 0x57E) = 0;
        }
    }

    switch (*(u8 *)(arg0 + 0x57E)) {
    case 0:
        if ((u16) arg1 & 0x4000) {
            if ((bool) (*(s32 *)(q + 0x614) & 4) == 1) {
                s32 count;
                u32 i;
                char *rec;

                count = 0;
                rec = D_089CC438;
                for (i = 0; i < 13; i++) {
                    if (*(s8 *)(rec + 0x69BEC) != 0) {
                        count++;
                    }
                    rec += 0x70;
                }
                if ((u8) count != 0) {
                    switch (*(u8 *)(arg0 + 0x57F)) {
                    case 0:
                        *(u16 *)(arg0 + 0x5FC) = 0x20;
                        *(u8 *)(arg0 + 0x117D) = 4;
                        break;
                    case 2:
                        *(u16 *)(arg0 + 0x5FC) = 0x27;
                        *(u8 *)(arg0 + 0x117D) = 4;
                        break;
                    case 1: {
                        u8 k;

                        *(u8 *)(arg0 + 0x117D) = 2;
                        *(u16 *)(arg0 + 0x5FC) = 0xE;
                        for (k = 0; k < 3; k++) {
                            *(u8 *)(arg0 + 0x117F + k) = *(u8 *)(D_089CC438 + 0x6A19D + k);
                        }
                        for (; k < 13; k++) {
                            (arg0 + 0x117F)[k] = 0;
                        }
                        break;
                    }
                    }
                    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                    (*(u8 *)(arg0 + 0x57E))++;
                    *(u8 *)(arg0 + 0x117A) = 0;
                    *(u8 *)(arg0 + 0x117B) = 0xFF;
                    *(u8 *)(arg0 + 0x117C) = 0;
                    *(s32 *)(arg0 + 0x5E8) &= ~4;
                    *(u8 *)(arg0 + 0x117E) = 0;
                    *(char **)(arg0 + 0x118C) = D_089CC438 + *(u8 *)(arg0 + 0x117E) * 0x70 + 0x69BEC;
                    break;
                }
            }
            func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
        } else {
            s32 count;
            u32 i;
            char *rec;

            func_0881C2E4(arg0, (u8 *)(arg0 + 0x57F), arg1, 3);
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
        }
        break;
    case 1:
    case 2: {
        u8 a;
        u8 b;
        u8 base;
        u8 n;

        switch (*(u8 *)(arg0 + 0x57F)) {
        case 0:
            *(u16 *)(arg0 + 0x5FC) = 0x20;
            break;
        case 2:
            *(u16 *)(arg0 + 0x5FC) = 0x27;
            break;
        case 1:
            if (*(u8 *)(arg0 + 0x57E) == 1) {
                *(u16 *)(arg0 + 0x5FC) = 0xE;
            } else {
                *(u16 *)(arg0 + 0x5FC) = 0x22;
            }
            break;
        }
        if ((u16) arg1 & 0x4000) {
            switch (*(u8 *)(arg0 + 0x57F)) {
            case 0:
                if (*(s8 *)((char *) (*(u8 *)(arg0 + 0x117E) * 0x70) + (s32) D_089CC438 + 0x69BEC) != 0) {
                    *(u8 *)(arg0 + 0x57E) = 10;
                    *(u16 *)(arg0 + 0x5FC) = 0x28;
                    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                } else {
                    func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                }
                break;
            case 1:
                if (*(u8 *)(arg0 + 0x57E) == 1) {
                    *(u8 *)(arg0 + 0x117B) = *(u8 *)(arg0 + 0x117E);
                    *(u8 *)(arg0 + 0x57E) = 2;
                } else {
                    a = *(u8 *)(arg0 + 0x117E);
                    b = *(u8 *)(arg0 + 0x117B);
                    if (b != a) {
                        char *r = D_089CC438 + 0x69BEC;

                        if (((*(s8 *)(r + a * 0x70) & 2) || (*(s8 *)(r + b * 0x70) & 2)) && (a >= 3 || b >= 3)) {
                            *(u8 *)(arg0 + 0x57E) = 3;
                            *(u8 *)(arg0 + 0x537) = 1;
                            *(u16 *)(arg0 + 0x5FC) = 0xF;
                        } else {
                            *(u8 *)(arg0 + 0x57E) = 4;
                        }
                    } else {
                        func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                        break;
                    }
                }
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                break;
            case 2:
                if (*(s8 *)((char *) (*(u8 *)(arg0 + 0x117E) * 0x70) + (s32) D_089CC438 + 0x69BEC) != 0) {
                    *(u16 *)(arg0 + 0x5FC) = 0x1F;
                    *(u8 *)(arg0 + 0x57E) = 3;
                    *(u8 *)(arg0 + 0x537) = 1;
                    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                } else {
                    func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                }
                break;
            }
            break;
        }
        if ((u16) arg1 & 0x2000) {
            if (*(u8 *)(arg0 + 0x57E) == 1) {
                *(u8 *)(arg0 + 0x57E) = 0;
                *(s32 *)(arg0 + 0x5E8) |= 4;
                *(u16 *)(arg0 + 0x5FC) = *(u8 *)(arg0 + 0x57F) + 0x12;
            } else {
                *(u8 *)(arg0 + 0x57E) = 1;
                *(u8 *)(arg0 + 0x117B) = 0xFF;
            }
            arg1 = (u16) (arg1 & 0xDFFF);
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else {
            if (func_0881C45C((s32) arg0, arg0 + 0x117C, arg1, 3) != 0) {
                *(u8 *)(arg0 + 0x117A) = 0;
            }
        }
        switch (*(u8 *)(arg0 + 0x117C)) {
        case 0:
            base = 0;
            n = 3;
            break;
        case 1:
            base = 3;
            n = 5;
            break;
        case 2:
            base = 8;
            n = 5;
            break;
        }
        func_0881C2E4(arg0, (u8 *)(arg0 + 0x117A), arg1, n);
        *(u8 *)(arg0 + 0x117E) = *(u8 *)(arg0 + 0x117A) + base;
        *(char **)(arg0 + 0x118C) = D_089CC438 + *(u8 *)(arg0 + 0x117E) * 0x70 + 0x69BEC;
        break;
    }
    case 3:
        if ((u16) arg1 & 0x4000) {
            if (*(u8 *)(arg0 + 0x537) == 0) {
                if (*(u8 *)(arg0 + 0x57F) == 1) {
                    *(s8 *)((char *) (*(u8 *)(arg0 + 0x117E) * 0x70) + (s32) D_089CC438 + 0x69BEC) &= ~2;
                    *(s8 *)((char *) (*(u8 *)(arg0 + 0x117B) * 0x70) + (s32) D_089CC438 + 0x69BEC) &= ~2;
                }
                *(u8 *)(arg0 + 0x57E) = 4;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            } else {
                *(u8 *)(arg0 + 0x57E) = 1;
                *(u8 *)(arg0 + 0x117B) = 0xFF;
                arg1 = (u16) (arg1 & 0xDFFF);
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            }
        } else if ((u16) arg1 & 0x2000) {
            *(u8 *)(arg0 + 0x57E) = 1;
            *(u8 *)(arg0 + 0x117B) = 0xFF;
            arg1 = (u16) (arg1 & 0xDFFF);
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else {
            func_0881C520(arg0, arg1, 0xA0);
        }
        break;
    case 4:
        if (*(u8 *)(arg0 + 0x57F) == 1) {
            Rec a;
            Rec b;
            u8 t;
            s32 k;

            a = *(Rec *)(D_089CC438 + *(u8 *)(arg0 + 0x117E) * 0x70 + 0x69BEC);
            b = *(Rec *)(D_089CC438 + *(u8 *)(arg0 + 0x117B) * 0x70 + 0x69BEC);

            *(Rec *)(D_089CC438 + *(u8 *)(arg0 + 0x117E) * 0x70 + 0x69BEC) = b;
            *(Rec *)(D_089CC438 + *(u8 *)(arg0 + 0x117B) * 0x70 + 0x69BEC) = a;
            t = *(u8 *)((char *) (s32) *(u8 *)(arg0 + 0x117E) + (s32) arg0 + 0x117F);
            *(u8 *)((char *) (s32) *(u8 *)(arg0 + 0x117E) + (s32) arg0 + 0x117F) = *(u8 *)((char *) (s32) *(u8 *)(arg0 + 0x117B) + (s32) arg0 + 0x117F);
            *(u8 *)((char *) (s32) *(u8 *)(arg0 + 0x117B) + (s32) arg0 + 0x117F) = t;
            for (k = 0; k < 3; k++) {
                *(u8 *)(D_089CC438 + 0x6A19D + k) = *(u8 *)(arg0 + 0x117F + k);
            }
            *(u8 *)(arg0 + 0x57E) = 1;
            *(u8 *)(arg0 + 0x117B) = 0xFF;
            func_09C26678(D_09CFBBC8);
        } else {
            s32 e = *(u8 *)(arg0 + 0x117E);

            memset(D_089CC438 + e * 0x70 + 0x69BEC, 0, 0x70);
            *(u16 *)(D_089CC438 + 0x6A1A0) &= ~(1 << (u8) e);
            ((long long *)(D_089CC438 + 0x6A1A8))[e] = 0;
            func_09C26678(D_09CFBBC8);
            arg1 = (u16) (arg1 | 0x2000);
        }
        break;
    case 10:
        if ((u16) arg1 & 0x2000) {
            *(u8 *)(arg0 + 0x57E) = 1;
            *(u16 *)(arg0 + 0x5FC) = 0x20;
            arg1 = (u16) (arg1 & 0xDFFF);
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            break;
        }
        if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 1) {
            func_0881C2E4(arg0, (u8 *)(arg0 + 0x587), arg1, 3);
        } else if ((u16) arg1 & 0x10) {
            if (--*(s8 *)(arg0 + 0x587) < 0) {
                *(s8 *)(arg0 + 0x587) = 3;
            }
            if (*(s8 *)(arg0 + 0x587) == *(u8 *)(D_089CC438 + 0x28)) {
                *(s8 *)(arg0 + 0x587) = *(s8 *)(arg0 + 0x587) - 1;
            }
            if (*(s8 *)(arg0 + 0x587) < 0) {
                *(s8 *)(arg0 + 0x587) = 3;
            }
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        } else if ((u16) arg1 & 0x40) {
            if (++*(s8 *)(arg0 + 0x587) > 3) {
                *(s8 *)(arg0 + 0x587) = 0;
            }
            if (*(s8 *)(arg0 + 0x587) == *(u8 *)(D_089CC438 + 0x28)) {
                *(s8 *)(arg0 + 0x587) = *(s8 *)(arg0 + 0x587) + 1;
            }
            if (*(s8 *)(arg0 + 0x587) > 3) {
                *(s8 *)(arg0 + 0x587) = 0;
            }
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
        if ((u16) arg1 & 0x4000) {
            u8 ok;

            if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0) {
                ok = *(u8 *)((char *) (*(u8 *)(arg0 + 0x587) * 0x8C) + (s32) D_089CC438 + 0x30) != 0;
            } else {
                char *p = func_0883B3D4((s32) arg0, *(s8 *)(arg0 + 0x587));

                if (p == 0 || *(u8 *)(p + 0xBF) == 5) {
                    ok = 0;
                } else {
                    ok = (u8) func_0882A8B8((s32) arg0, *(s8 *)(arg0 + 0x587)) == 0;
                }
            }
            if (ok == 1) {
                char *o = *(char **)(arg0 + 0x530);
                s32 e;

                o[0x5C9] = *(s8 *)(arg0 + 0x587);
                e = *(u8 *)(arg0 + 0x117E);
                *(s32 *)(o + 0x5D8) = e;
                memcpy(o + 0x5DC, D_089CC438 + e * 0x70 + 0x69C4C, 0x10);
                *(s32 *)(o + 0x614) |= 0x40;
                if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) {
                    char *p = func_0883B3D4((s32) arg0, *(s8 *)(arg0 + 0x587));

                    *(Id8 *)(o + 0x5CE) = *(Id8 *)p;
                    func_0889D504(D_09A0B544, p, D_089CC438 + *(u8 *)(arg0 + 0x117E) * 0x70 + 0x69C4C);
                    func_0889D6EC(D_09A0B544);
                }
                (*(u8 *)(arg0 + 0x57E))++;
                arg1 = 0;
            } else {
                func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
            }
        }
        break;
    case 11:
        if ((bool) (*(s32 *)(*(char **)(arg0 + 0x530) + 0x614) & 8) != 0) {
            if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0) {
                func_088490C8(arg0);
            } else {
                func_08834548(arg0);
            }
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            arg1 = 0;
        } else {
            *(u8 *)(arg0 + 0x57E) = *(u8 *)(arg0 + 0x57E) - 1;
            func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
            arg1 = 0;
        }
        break;
    }
    return arg1;
}

}
