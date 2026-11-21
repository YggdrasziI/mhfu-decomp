/* unit_088A356C: 0x088A356C-0x088A3AB0 (ULES01213) */
#pragma optimize_for_size off
#pragma opt_unroll_loops off

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef signed char s8;

extern volatile s32 D_09A0DA84;
extern volatile s32 D_09A0DA88;
extern s32 D_09A0DA74;
extern s32 D_09A0DA78;
extern s32 D_09A0DA7C;
extern s8 D_09A0DB44;
extern s16 D_09A0DB80[2][512];
extern float D_09A0DAE4;
extern float D_09A0DAE8[2];
extern float D_09A0DAF0;
extern float D_09A0DB04;
extern float D_09A0DB08[2];
extern float D_09A0DB10;
extern float D_089B2508;
extern float D_089B2510[2];
extern float D_089B2518[2];
extern float D_089B2520[2];
extern float D_089B2528[2];
extern u32 D_089B258C;

extern void func_088A43C0(void);
extern void func_088972A0(s16 *);
extern s32 func_088975D4(void);
extern void func_08897AE0(s32, s32, s32, char *);
extern s32 func_08897B84(s32);
extern s32 sceKernelDelayThread(u32);
extern s32 sceKernelExitThread(s32);

static inline void clear(char *q, u32 n) {
    if (q != 0) {
        do {
            *q = 0;
            n--;
            q++;
        } while (n != 0);
    }
}

s32 func_088A356C(void) {
    s32 cnt[2];
    s32 buf;
    s32 cur;
    s32 i;
    s16 *p;
    float lo, hi, thi, tlo, cnt_th, gmin, gmax, k;
    float st3, st2, st1, st0;
    float g3, g1, g2, g0;
    float d, a, b, c;

    buf = 0;
    if (D_09A0DA84 == 0) do {
        func_088A43C0();
        cur = buf;
        if (D_09A0DA88 == 0) {
        p = D_09A0DB80[buf];
        func_088972A0(p);
        if (D_09A0DB44 & 1) {
            clear((char *) cnt, 8);
            lo = D_089B2520[0];
            hi = D_089B2518[1];
            thi = D_089B2528[0];
            tlo = D_089B2528[1];
            cnt_th = D_089B2520[1];
            gmin = D_089B2518[0];
            gmax = D_089B2510[1];
            k = D_089B2508;
            st0 = D_09A0DAE4;
            st1 = D_09A0DAE8[0];
            st2 = D_09A0DAE8[1];
            st3 = D_09A0DAF0;
            g0 = D_09A0DB04;
            g1 = D_09A0DB08[0];
            g2 = D_09A0DB08[1];
            g3 = D_09A0DB10;
            for (i = 0; i < 0x200; i += 4) {
                a = p[0];
                b = p[1];
                c = p[2];
                d = p[3];
                a *= k;
                b *= k;
                c *= k;
                d *= k;
                a += st0 * g0;
                b += st1 * g1;
                c += st2 * g2;
                d += st3 * g3;
                st0 = a;
                st1 = b;
                st2 = c;
                st3 = d;
                if (a < lo) a = lo;
                if (b < lo) b = lo;
                if (c < lo) c = lo;
                if (d < lo) d = lo;
                if (a >= hi) a = hi;
                if (b >= hi) b = hi;
                if (c >= hi) c = hi;
                if (d >= hi) d = hi;
                if (a > thi || a < tlo) cnt[0]++;
                if (b > thi || b < tlo) cnt[1]++;
                if (c > thi || c < tlo) cnt[0]++;
                if (d > thi || d < tlo) cnt[1]++;
                a = a / k;
                b = b / k;
                c = c / k;
                d = d / k;
                p[0] = a;
                p[1] = b;
                p[2] = c;
                p[3] = d;
                p += 4;
            }
            if (cnt[0] > cnt_th) {
                g0 -= 0.1f;
                g2 -= 0.1f;
                if (g0 < gmin) g0 = gmin;
                if (g2 < gmin) g2 = gmin;
            } else {
                g0 += 0.05f;
                g2 += 0.05f;
                if (g0 > gmax) g0 = gmax;
                if (g2 > gmax) g2 = gmax;
            }
            if (cnt[1] > cnt_th) {
                g1 -= 0.1f;
                g3 -= 0.1f;
                if (g1 < gmin) g1 = gmin;
                if (g3 < gmin) g3 = gmin;
            } else {
                g1 += 0.05f;
                g3 += 0.05f;
                if (g1 > gmax) g1 = gmax;
                if (g3 > gmax) g3 = gmax;
            }
            D_09A0DAE4 = st0;
            D_09A0DAE8[0] = st1;
            D_09A0DAE8[1] = st2;
            D_09A0DAF0 = st3;
            D_09A0DB04 = g0;
            D_09A0DB08[0] = g1;
            D_09A0DB08[1] = g2;
            D_09A0DB10 = g3;
            cnt[1] = 0;
            cnt[0] = 0;
        }
        buf = (buf + 1) % 2;
        D_09A0DA7C = func_088975D4();
        D_09A0DA78++;
        func_08897AE0(D_09A0DA74, 0x8000, 0x8000, (char *) D_09A0DB80[cur]);
        } else {
            sceKernelDelayThread(D_089B258C);
        }
    } while (D_09A0DA84 == 0);
    while (func_08897B84(0) > 0) {
        sceKernelDelayThread(1000);
    }
    sceKernelExitThread(0);
    return 0;
}
