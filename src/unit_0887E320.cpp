/* unit_0887E320: 0x0887E320-0x0887E9AC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_0887E030 and unit_0887E9AC.
 *
 * C++: bool test. Optimized for speed: loops unrolled by 8, divisions by a
 * constant are multiplications.
 *
 * The digit array is sized from the original frame (6 words, 4 used). rec is
 * read before being set, as in the original. Each insertion loop has its own
 * counters (register allocation).
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u32 code : 15;
    u32 time : 17;
} Rec;

extern "C" {

extern char *D_089CC438;
extern s32 D_08A62C54;
extern char *D_08A631A0;

extern u8 func_0885CD18(s32, u8, u16);
extern s32 func_0887EB80(char *);

s32 func_0887E320(char *arg0) {
    Rec rec;
    Rec rec2;
    s32 d[6];
    bool hard;
    u8 *p;
    Rec *e;
    Rec *b;
    Rec *a;
    s32 n;
    s32 idx;
    s32 i;
    s32 m;
    s32 m2;
    s32 ret;
    char *g;
    s32 q;
    s32 j;
    s32 j2;

    p = (u8 *) D_089CC438 + 0x30;
    for (i = 0; i < 4; i++) {
        s32 k;

        if (p[0] != 0) {
            k = func_0885CD18(D_08A62C54, p[0x31], *(u16 *) (p + 0x32));
        } else {
            k = 0xB;
        }
        d[0] = (u32) rec.code % 12;
        d[1] = (u32) rec.code / 12 % 12;
        d[2] = (u32) rec.code / 144 % 12;
        d[3] = (u32) rec.code / 1728 % 12;
        d[(u32) i] = k;
        rec.code = d[0] + d[1] * 12 + d[2] * 12 * 12 + d[3] * 12 * 12 * 12;
        p += 0x8C;
    }
    rec.time = func_0887EB80(arg0);
    rec2 = rec;
    rec2.time = *(s32 *) (arg0 + 0x120);
    hard = (bool) (*(s32 *) (D_08A631A0 + 0xF7A57C) & 1);
    g = D_089CC438;
    q = *(u16 *) (g + 0x6AF12);
    if (hard == 0) {
        if (q >= 0x5209 && q < 0x5221) {
            idx = q - 0x5209;
            a = (Rec *) (g + idx * 4 + 0x679A8);
            b = (Rec *) (g + idx * 4 + 0x67B94);
            n = 1;
        } else {
            return 0;
        }
    } else {
        if (q >= 0x55F1 && q < 0x55F8) {
            idx = q - 0x55F1;
            a = (Rec *) (g + idx * 20 + 0x67A04);
            b = (Rec *) (g + idx * 20 + 0x67BF0);
        } else {
            idx = q - 0xEE43;
            a = (Rec *) (g + idx * 20 + 0x67A04);
            b = (Rec *) (g + idx * 20 + 0x67BF0);
        }
        n = 5;
    }
    ret = 0;
    for (e = a, m = 0; m < n; m++, e++) {
        if (e->time == 0) {
            *e = rec;
            ret |= 1;
            break;
        }
        if (rec.time < e->time) {
            for (j = n - 1; j >= m + 1; j--) {
                a[j] = a[j - 1];
            }
            *e = rec;
            ret |= 1;
            break;
        }
    }
    for (e = b, m2 = 0; m2 < n; m2++, e++) {
        if (e->time == 0) {
            *e = rec2;
            ret |= 2;
            break;
        }
        if (e->time < rec2.time) {
            for (j2 = n - 1; j2 >= m2 + 1; j2--) {
                b[j2] = b[j2 - 1];
            }
            *e = rec2;
            ret |= 2;
            break;
        }
    }
    return ret;
}

}
