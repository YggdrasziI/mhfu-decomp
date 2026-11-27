/* unit_08847CB0: 0x08847CB0-0x0884853C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08847CB0 (ULES01213)
 *
 * Speed setting (float constant 0x3E37EA27 built with lui/ori). Square roots
 * are VFPU code in an `asm { }` block (sqrt_vfpu, as in unit_08814268.c).
 * The width argument is written `w, w = s`: a local used twice is not
 * forward-substituted, so with `w, w` the trunc.w.s lands before the two
 * unsigned conversions; the assignment in the last-evaluated argument puts it
 * after them, as in the original.
 */
#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

typedef struct {
    u16 a;
    s16 b;
} Ent;

typedef struct {
    char pad0[0x390];
    Ent ent[32];
    u32 bits[8];
} G;

extern G *D_089CC438;
extern char *D_08A62C7C;
extern char *D_08A631A8;
extern u16 D_089AC854[];
extern u16 D_089AC85A;
extern u16 D_089AC85C;
extern char D_0893B6FC[];
extern char D_0893B650[];
extern u8 D_0893B704;
extern u8 D_0893AA5C[];
extern u8 D_0899D198[][24];
extern u8 D_0899D19B[][24];
extern u8 D_0899D19D[][24];
extern u8 D_0899D19E[][24];

extern char *func_0885151C(G *, u16);
extern char *func_08851528(G *, u16);
extern void func_0882FC50(char *, char *, char *, s32);
extern void func_0882D6F0(char *, u16, u16, u16, u16, s32, s32, s32);
extern void func_08832B98(char *, s32);
extern s32 func_088303B8(char *, u8, s32);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);
extern void func_0882C11C(char *, s32, s32, s32, s32, u8, u8, u8, s32, s32);
extern s32 func_0882AF70(char *, u16, u16, u16, u16, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern s16 func_088569F8(G *, u16);
extern s32 func_088568AC(G *, u16);
extern int func_088915B0(char *, s16, s16, s32, char *, ...);
extern int func_0880E8F0(char *, char *, ...);
extern s32 func_08890E48(char *, char *);
extern void func_08825ADC(char *, s32, u16, s32);

static inline float sqrt_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vsqrt.s S000, S000
        sv.s S000, 0(pr)
    }
    return r;
}

void func_08847CB0(char *arg0) {
    char *p = *(char **)(arg0 + 0x530);
    s32 mask;
    s16 i;
    s32 off;
    G *g = D_089CC438;
    char buf[0x30];

    if ((s32)((*(u32 *)(p + 0x614) & 2) != 0) != 0) {
        if (D_08A62C7C[0x12D] == 0) {
            mask = g->bits[0];
        } else {
            mask = -1;
        }
        func_0882FC50(arg0, D_0893B6FC, func_0885151C(g, D_089AC854[0]), 0xFF);
        for (i = 0; i < 32; i++) {
            func_0882D6F0(arg0, (i & 7) * 28 + 0xE8, (i >> 3) * 24 + 0x38, 0x16, 0x16, 0, 0, 0);
        }
        func_08832B98(arg0, 1);
        for (i = 0, off = 0; i < 32; i++, off += 4) {
            if ((mask & (1 << (i & 0x1F))) == 0) {
                u16 id = *(u16 *)((s32)(char *)(off) + (char *)g + 0x390);
                if (id != 0) {
                    u8 *rec = D_0899D198[id];
                    if (rec[5] != 0xFF) {
                        u8 *col = &D_0893AA5C[rec[6] * 4];
                        s32 r = func_088303B8(arg0, rec[5], 1);
                        func_0882BE60(arg0, (i & 7) * 28 + 0xE8, (i >> 3) * 24 + 0x38, 0x16, 0x16,
                                      col[0], col[1], col[2], r);
                    }
                }
            }
        }
        {
            u32 a = *(u8 *)(arg0 + 0x5A1);
            if ((s32)a > 0) {
                f32 t = (f32)a / (f32)(u32)*(u8 *)(arg0 + 0x5A2);
                f32 u = 1.0f - t;
                u8 n = *(u8 *)(arg0 + 0x5A3);
                s16 x = (s16)(s32)(232.0f * u + t * (f32)((n & 7) * 28 + 0xE8));
                s16 y = (s16)(s32)(150.0f * u + t * (f32)((n >> 3) * 24 + 0x38));
                f32 v = 57.0f * sqrt_vfpu((f32)a);
                u16 k;
                u8 *col;
                s32 alpha;
                s32 r;
                s32 c5;
                if (v > 255.0f) {
                    v = 255.0f;
                }
                k = *(u16 *)(arg0 + 0x5A4);
                c5 = D_0899D19D[k][0];
                col = &D_0893AA5C[D_0899D19E[k][0] * 4];
                alpha = (u8)(u32)v;
                r = func_088303B8(arg0, c5, 1);
                func_0882C11C(arg0, (u16)x, (u16)y, 0x16, 0x16, col[0], col[1], col[2], alpha, r);
            }
        }
        {
            u8 n = p[0x55D];
            func_0882AF70(arg0, (n & 7) * 28 + 0xE6, (n >> 3) * 24 + 0x36, 0x1A, 0x1A, 0x49);
        }
        func_0882A9DC(arg0, 0xEB, 0x99, 0x1C);
        if (*(s16 *)(arg0 + 0x59E) > 0) {
            f32 h = (f32)(*(s16 *)(arg0 + 0x59E) & 0x1F);
            s32 c = (u8)(u32)(45.0f * sqrt_vfpu(h));
            f32 s = 32.0f * (1.0f + 0.17960416f * sqrt_vfpu(31.0f - h));
            u8 n = p[0x55D];
            f32 o = 2.0f + (0.5f * s - 16.0f);
            s32 w; /* arguments are evaluated right to left: w = s in arg 5 keeps the trunc after the conversions */
            func_0882C11C(arg0, (u32)((f32)((n & 7) * 28 + 0xE6) - o),
                          (u32)((f32)((n >> 3) * 24 + 0x36) - o), w, w = s, 0xFF, 0xFF, 0xFF, c, 0x49);
        }
        {
            u8 idx = p[0x55D];
            u16 id = (mask & (1 << (idx & 0x1F))) ? 0 : D_089CC438->ent[idx].a;
            char *text;
            if (id == 0) {
                text = func_08851528(D_089CC438, 0);
            } else {
                s16 lvl = g->ent[idx].b;
                s16 v = func_088569F8(D_089CC438, id);
                s16 st = -1;
                if (v < 0) {
                    st = 1;
                } else if (v < lvl) {
                    st = 2;
                } else if (v == 0xFF) {
                    if (func_088568AC(D_089CC438, id) != 0) {
                        st = 2;
                    }
                }
                if (st >= 0) {
                    func_088915B0(D_08A631A8, 0xE8, 0xB2, 2, D_0893B650,
                                  func_0885151C(D_089CC438, D_089AC854[st]));
                }
                switch (D_0899D19B[id][0]) {
                case 1:
                    func_0880E8F0(buf, func_08851528(D_089CC438, id));
                    break;
                case 0xFF:
                    func_0880E8F0(buf, func_0885151C(D_089CC438, D_089AC85A), func_08851528(D_089CC438, id));
                    break;
                default:
                    func_0880E8F0(buf, func_0885151C(D_089CC438, D_089AC85C), func_08851528(D_089CC438, id), lvl);
                    break;
                }
                text = buf;
            }
            func_088915B0(D_08A631A8, 0x1C2 - (D_0893B704 >> 1) * func_08890E48(D_08A631A8, text), 0x9C, 0,
                          D_0893B650, text);
            func_08832B98(arg0, 0);
            func_08825ADC(arg0, 1, id + 0x18, -1);
        }
    }
}
