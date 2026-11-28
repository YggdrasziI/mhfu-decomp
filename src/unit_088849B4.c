/* unit_088849B4: 0x088849B4-0x08884C9C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;
typedef float f32;

extern f32 D_089AA35C[];
extern f32 D_089AA360[];
extern f32 D_089AA364[];
extern s32 *D_089AB710[];
extern s32 D_089AB7F8[];
extern s32 D_089AB83C[];
extern s32 D_08A62D40[];
extern char *D_08A62D90;

extern void func_08883384(char *arg0);
extern s32 func_0888616C(char *arg0);
extern f32 func_08897D28(f32 x);

static inline f32 vec3_dist(f32 *a, f32 *b) {
    f32 r;
    f32 *pr = &r;
    f32 *pb = b;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(pb)
        vsub.t C000, C000, C010
        nop
        vdot.t S010, C000, C000
        vsqrt.s S010, S010
        sv.s S010, 0(pr)
    }
    return r;
}

#pragma optimize_for_size off

s32 func_088849B4(char *arg0, f32 *pos, s32 kind) {
    s32 *row;
    s32 *tbl;
    f32 dist;
    f32 step;
    f32 limit;
    f32 n;
    f32 frac;
    s32 i;
    s32 v;
    s32 a;

    if (((u8 *)arg0)[0x5623E0] == 0) {
        return 0;
    }
    step = D_089AA360[kind * 3];
    limit = D_089AA364[kind * 3];
    if (kind == 0x11) {
        tbl = D_089AB7F8;
    } else if (kind == 0x20) {
        tbl = D_089AB83C;
    } else if (kind == 0x21) {
        tbl = D_08A62D40;
    }
    func_08883384(arg0);
    row = D_089AB710[kind];
    if ((u8)func_0888616C(D_08A62D90) == 1) {
        row += 0x11;
    }
    dist = vec3_dist(pos, (f32 *)(arg0 + 0x5623F0));
    if (kind == 0x1F || *(f32 *)(arg0 + 0x56246C) == 30.0f) {
        dist = *(f32 *)(arg0 + 0x562460);
        *(s32 *)(arg0 + 0x56246C) = 0;
    }
    if (dist >= limit) {
        if (limit == 19800.0f) {
            dist = limit;
        } else {
            if (kind == 0x21 || kind == 0x20 || kind == 0x11) {
                *(s32 *)(arg0 + 0x562438) = tbl[0];
            }
            return 0;
        }
    }
    if (dist < D_089AA35C[kind * 3]) {
        return 0x7F;
    }
    n = func_08897D28(dist / step);
    frac = (dist - step * n) / step;
    i = (s32)n;
    v = row[i] - (s32)(frac * (f32)(row[i] - row[i + 1]));
    if (kind == 0x21 || kind == 0x20 || kind == 0x11) {
        if (((u8 *)arg0)[0x562464] != 0) {
            a = tbl[i];
            *(s32 *)(arg0 + 0x562438) = a - (s32)(frac * (f32)(a - tbl[i + 1]));
        }
    }
    return v;
}
