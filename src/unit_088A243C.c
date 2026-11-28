/* unit_088A243C: 0x088A243C-0x088A2F88 (ULES01213)
 *
 * Bounds (hypothesis): func_088A243C is a static function defined before its
 * caller func_088A2A78, which keeps a0 live across a call after calling it
 * (the compiler only does this for a static callee defined earlier in the
 * same file), so the unit holds func_088A243C, func_088A2498 and
 * func_088A2A78.
 *
 * func_088A2498 is NonMatching (99.87 %): thread loop; optional per-sample
 * gain limiter on a double-buffered s16 block, then func_08897AE0 with values
 * scaled by func_0880816C / func_088084C4 of the same angle-like argument.
 * The byte clear of cnt is written out with its own q/k locals after the
 * buffer and u assignments (this moves the counter to v0; 99.92 %).
 * Remaining (99.92 %): the t->unk98[t->unk28] address temporaries use v0
 * instead of a1 (the register of the result). Tried: statement orders,
 * declaration orders and levels, index/pointer forms, inline helpers,
 * register keyword, parameter reuse, every opt_* pragma on/off.
 *
 * func_088A2A78: the state-3 decode step is an inline helper that writes the
 * result through a pointer. Jump table jtbl_08931F50 (6 words) is the switch
 * on unk54.
 *
 * Stream and Mixer are two views of the same object (the decoder fields used
 * by func_088A2A78, and the output fields used by func_088A2498).
 */

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s16 l;
    s16 r;
} Smp;

typedef struct {
    char unk0[0x8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    char unk1C[0x8];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    char unk30[0x4];
    u32 unk34;
    u32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    char unk50[0x4];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    char unk64[0x14];
    s32 unk78;
    s32 unk7C;
    char unk80[0x4];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    char unk90[0x8];
    Smp *unk98[2];
    char unkA0[0x4];
    s32 unkA4;
    s32 unkA8;
    char unkAC[0x4];
    s32 unkB0[16][2];
    s32 unk130;
    s32 unk134;
    s32 unk138;
    s32 unk13C;
} Stream;

typedef struct {
    char unk0[0x2C];
    float unk2C;
    char unk30[0x8];
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    float unk50;
    float unk54[4];
    char unk64[0x10];
    float unk74[4];
} U;

typedef struct {
    char unk0[0x24];
    s32 unk24;
    s32 unk28;
    char unk2C[0x38];
    s32 unk64;
    char unk68[0x8];
    u32 unk70;
    u32 unk74;
    char unk78[0x10];
    s32 unk88;
    char unk8C[0xC];
    char *unk98[2];
    char unkA0[0xB0];
    U unk150;
} Mixer;

extern char D_09A0D258;
extern char D_09A0D25C;
extern s8 D_09A0DB44;
extern s32 D_09A0DA70;
extern float D_089B24D0;
extern s32 D_089B24D4;

extern float func_0880816C(float);
extern float func_088084C4(float);
extern void func_088979B4(s32, s32, s32);
extern int func_08897A08(s32, s32);
extern void func_08897AE0(s32, s32, s32, char *);
extern s32 func_08897B84(s32);
extern void func_088A177C(char *);
extern void func_088A178C(char *);
extern void func_088A1798(void *);
extern void func_088A1814(char *);
extern s32 func_088A1E70(char *, s32, s32);
extern void func_088A2410(void *);
extern int sceAtracDecodeData(s32, Smp *, s32 *, s32 *, s32 *);
extern int sceAtracGetNextDecodePosition(s32, s32 *);
extern int sceAtracGetStreamDataInfo(s32, s32 *, s32 *, s32 *);
extern int sceAtracGetLoopStatus(s32, s32 *, s32 *);
extern int sceAtracSetLoopNum(s32, s32);
extern s32 sceKernelDelayThread(u32);
extern s32 sceKernelDelayThreadCB(u32);
extern s32 sceKernelExitThread(s32);

s32 func_088A2A78(Stream *arg0);

#pragma optimize_for_size off

static s32 func_088A243C(Stream *arg0, s32 *arg1) {
    if (arg0->unkA4 != 0) {
        arg1[0] = arg0->unkB0[arg0->unkA8][0];
        arg1[1] = arg0->unkB0[arg0->unkA8][1];
        arg0->unkA8 = (arg0->unkA8 + 1) & 0xF;
        arg0->unkA4--;
        return 1;
    }
    return 0;
}

static inline void clear(void *p, u32 n) {
    char *q = p;
    if (q != 0) {
        do {
            *q = 0;
            n--;
            q++;
        } while (n != 0);
    }
}

#pragma opt_unroll_loops off

s32 func_088A2498(s32 arg0, Mixer **arg1) {
    Mixer *t = *arg1;
    volatile s32 ret = 0;

    while (t->unk64 == 0) {
        func_088A177C(&D_09A0D258);
        ret = func_088A2A78((Stream *)t);
        func_088A178C(&D_09A0D258);
        if (ret >= 0) {
            float a;
            s32 x;
            func_08897A08(t->unk24, t->unk88);
            if (D_09A0DB44 & 2) {
                s32 cnt[2];
                char *q;
                u32 k;
                U *u;
                s16 *buf;
                s32 i;
                s32 n;
                float hi, lo, top, bot, lim, gmin, gmax, scale;
                float p3, p2, p1, p0;
                float g3, g1, g2, g0;
                float v3, v0, v1, v2;

                buf = (s16 *)t->unk98[t->unk28]; u = &t->unk150; q = (char *)cnt; k = 8; if (q != 0) do { *q = 0; k--; q++; } while (k != 0);
                hi = u->unk44;
                lo = u->unk40;
                top = u->unk4C;
                bot = u->unk50;
                lim = u->unk48;
                gmin = u->unk3C;
                gmax = u->unk38;
                scale = u->unk2C;
                p0 = u->unk54[0];
                p1 = u->unk54[1];
                p2 = u->unk54[2];
                p3 = u->unk54[3];
                g0 = u->unk74[0];
                g1 = u->unk74[1];
                g2 = u->unk74[2];
                g3 = u->unk74[3];
                n = t->unk88 * 2;
                for (i = 0; i < n; i += 4) {
                    v0 = buf[0];
                    v1 = buf[1];
                    v2 = buf[2];
                    v3 = buf[3];
                    v0 *= scale;
                    v1 *= scale;
                    v2 *= scale;
                    v3 *= scale;
                    v0 += p0 * g0;
                    v1 += p1 * g1;
                    v2 += p2 * g2;
                    v3 += p3 * g3;
                    p0 = v0;
                    p1 = v1;
                    p2 = v2;
                    p3 = v3;
                    if (v0 < hi) v0 = hi;
                    if (v1 < hi) v1 = hi;
                    if (v2 < hi) v2 = hi;
                    if (v3 < hi) v3 = hi;
                    if (v0 >= lo) v0 = lo;
                    if (v1 >= lo) v1 = lo;
                    if (v2 >= lo) v2 = lo;
                    if (v3 >= lo) v3 = lo;
                    if (v0 > top || v0 < bot) cnt[0]++;
                    if (v1 > top || v1 < bot) cnt[1]++;
                    if (v2 > top || v2 < bot) cnt[0]++;
                    if (v3 > top || v3 < bot) cnt[1]++;
                    v0 = v0 / scale;
                    v1 = v1 / scale;
                    v2 = v2 / scale;
                    v3 = v3 / scale;
                    buf[0] = v0;
                    buf[1] = v1;
                    buf[2] = v2;
                    buf[3] = v3;
                    if ((i & 0x1FF) == 0) {
                        if (cnt[0] > lim) {
                            g0 -= 0.3f;
                            g2 -= 0.3f;
                            if (g0 < gmin) g0 = gmin;
                            if (g2 < gmin) g2 = gmin;
                        } else {
                            g0 += 0.025f;
                            g2 += 0.025f;
                            if (g0 > gmax) g0 = gmax;
                            if (g2 > gmax) g2 = gmax;
                        }
                        if (cnt[1] > lim) {
                            g1 -= 0.3f;
                            g3 -= 0.3f;
                            if (g1 < gmin) g1 = gmin;
                            if (g3 < gmin) g3 = gmin;
                        } else {
                            g1 += 0.025f;
                            g3 += 0.025f;
                            if (g1 > gmax) g1 = gmax;
                            if (g3 > gmax) g3 = gmax;
                        }
                        cnt[1] = 0;
                        cnt[0] = 0;
                    }
                    buf += 4;
                }
                u->unk54[0] = p0;
                u->unk54[1] = p1;
                u->unk54[2] = p2;
                u->unk54[3] = p3;
                u->unk74[0] = g0;
                u->unk74[1] = g1;
                u->unk74[2] = g2;
                u->unk74[3] = g3;
            }
            a = (float)t->unk74 / 127.0f * D_089B24D0;
            x = (float)D_09A0DA70 * ((float)t->unk70 * func_0880816C(a)) / 127.0f;
            func_08897AE0(t->unk24, x,
                          (float)D_09A0DA70 * ((float)t->unk70 * func_088084C4(a)) / 127.0f,
                          t->unk98[t->unk28]);
            t->unk28 = (t->unk28 + 1) & 1;
        } else {
            sceKernelDelayThread(D_089B24D4 - 2000);
        }
        sceKernelDelayThread(1000);
        sceKernelDelayThreadCB(1000);
    }
    while (func_08897B84(t->unk24) > 0) {
        sceKernelDelayThread(1000);
        sceKernelDelayThreadCB(1000);
    }
    sceKernelExitThread(0);
    return 0;
}

#pragma opt_unroll_loops reset

static inline void decode(Stream *arg0, s32 *out) {
    s32 res;
    s32 loop;
    s32 i;
    s32 n;
    Smp *src;
    Smp *dst;
    Smp *p;
    u32 j;
    s32 info[2];

    *out = 0;
    func_088A177C(&D_09A0D25C);
    res = sceAtracDecodeData(arg0->unk8, arg0->unk98[arg0->unk28] + arg0->unk8C,
                             &arg0->unkC, &arg0->unk10, &arg0->unk14);
    sceAtracGetNextDecodePosition(arg0->unk8, &arg0->unk18);
    arg0->unk88 = (arg0->unkC + arg0->unk8C) & ~0x3F;
    arg0->unk8C = (arg0->unkC + arg0->unk8C) & 0x3F;
    if (arg0->unk14 != -1 && arg0->unk14 != -2 && arg0->unk14 <= arg0->unk130) {
        sceAtracGetStreamDataInfo(arg0->unk8, &arg0->unk134, &arg0->unk138, &arg0->unk13C);
    } else {
        arg0->unk134 = 0;
        arg0->unk138 = 0;
        arg0->unk13C = 0;
    }
    n = arg0->unk8C;
    src = arg0->unk98[arg0->unk28] + arg0->unk88;
    dst = arg0->unk98[(arg0->unk28 + 1) & 1];
    for (i = 0; i < n; i++) {
        dst->l = src->l;
        dst->r = src->r;
        src++;
        dst++;
    }
    if (arg0->unk88 == 0) {
        arg0->unk88 = 0x40;
        arg0->unk8C = 0;
    }
    loop = sceAtracGetLoopStatus(arg0->unk8, &arg0->unk3C, &arg0->unk40);
    if (arg0->unk44 == 1) {
        if (arg0->unk48 == 1) {
            sceAtracSetLoopNum(arg0->unk8, 0x7FFFFFFF);
        } else {
            sceAtracSetLoopNum(arg0->unk8, 0);
        }
    }
    func_088A178C(&D_09A0D25C);
    if (res < 0) {
        arg0->unk5C = arg0->unk54;
        arg0->unk58 = 4;
        arg0->unk54 = 6;
        func_088A2410(arg0);
        *out = -1;
        return;
    }
    if (loop < 0) {
        arg0->unk5C = arg0->unk54;
        arg0->unk58 = 5;
        arg0->unk54 = 6;
        func_088A2410(arg0);
        *out = -1;
        return;
    }
    arg0->unk84 = arg0->unk84 + arg0->unkC;
    if (arg0->unk44 != 1) {
        arg0->unk4C = 0;
    } else if (arg0->unk84 < arg0->unk38) {
        arg0->unk4C = 0;
    } else {
        arg0->unk4C = (arg0->unk84 - arg0->unk34) / (arg0->unk38 - arg0->unk34);
    }
    if (arg0->unk10 != 0) {
        switch (arg0->unk2C) {
        case 1:
        case 3:
            arg0->unk54 = 4;
            break;
        case 2:
            if (func_088A243C(arg0, info) == 0) {
                arg0->unk54 = 4;
                break;
            }
            func_088A1798(arg0);
            arg0->unk54 = 5;
            if ((*out = func_088A1E70((char *)arg0, info[0], info[1])) < 0) {
                arg0->unk5C = arg0->unk8;
                arg0->unk58 = 3;
                arg0->unk54 = 6;
                func_088A2410(arg0);
                return;
            }
            func_088A1814((char *)arg0);
            arg0->unk54 = 3;
            break;
        }
    }
    if (arg0->unk78 & 0x80) {
        p = arg0->unk98[arg0->unk28];
        for (j = 0; j < arg0->unkC; j++) {
            p->l = -p->l;
            p++;
        }
    }
}

s32 func_088A2A78(Stream *arg0) {
    s32 ret;

    ret = 0;
    switch (arg0->unk54) {
    case 4:
        func_088979B4(arg0->unk24, 0, 0);
        func_088A1798(arg0);
        arg0->unk54 = 5;
    case 0:
    case 1:
    case 2:
    case 5:
        ret = -1;
        arg0->unk88 = arg0->unk7C & ~0x3F;
        arg0->unk8C = arg0->unk7C & 0x3F;
        break;
    case 3:
        if (arg0->unk60 == 1) {
            ret = -1;
            arg0->unk88 = arg0->unk7C & ~0x3F;
            arg0->unk8C = arg0->unk7C & 0x3F;
            break;
        }
        decode(arg0, &ret);
        break;
    }
    return ret;
}

#pragma optimize_for_size reset
