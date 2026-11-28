/* unit_0888B884: 0x0888B884-0x0888B994 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0888B884: VFPU asm block (notes/COMPILER.md, "VFPU in asm blocks").
 * Speed setting, rolled inline clear (opt_unroll_loops off) and the asm base
 * pointers set by hand in the loop pre-header (opt_loop_invariants off). The
 * declaration order pt, pd, i sets the loop registers. */

#pragma optimize_for_size off
#pragma opt_unroll_loops off
#pragma opt_loop_invariants off

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

static inline void clear(char *q, u32 n) {
    if (q != 0) {
        do {
            *q = 0;
            n--;
            q++;
        } while (n != 0);
    }
}

s32 func_0888B884(void *arg0, char *obj, Vec *pos) {
    f32 dist[16];
    f32 r;
    Vec v;
    f32 min;
    s32 idx;
    f32 *pt;
    f32 *pd;
    s32 i;
    s32 n;
    f32 *pr;
    Vec *pv;

    min = 10000000.0f;
    pt = (f32 *)(obj + 0x100);
    pd = dist;
    idx = 0;
    i = 0;
    if (i < (n = *(u8 *)(obj + 0x260))) {
        pr = &r;
        pv = &v;
        do {
            clear((char *)&v, 16);
            v.x = pt[0];
            v.y = pt[1];
            v.z = pt[2];
            asm {
                lv.q C000, 0(pos)
                lv.q C010, 0(pv)
                vsub.t C000, C000, C010
                nop
                vdot.t S010, C000, C000
                vsqrt.s S010, S010
                sv.s S010, 0(pr)
            }
            *pd = r;
            if (min > r) {
                min = r;
                idx = i;
            }
            pt += 3;
            pd++;
            i++;
        } while (i < (n = *(u8 *)(obj + 0x260)));
    }
    if (idx != 0 && idx < n - 1) {
        if (dist[idx - 1] < dist[idx + 1]) {
            idx--;
        }
    } else if (idx >= n - 1) {
        idx = n - 2;
    }
    return idx;
}
