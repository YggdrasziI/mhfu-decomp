/* unit_08815108: 0x08815108-0x08815260 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;
#pragma optimize_for_size off
typedef float f32;

extern u8 func_088DA324(char *, char *);
extern u8 func_08815260(void *arg0, f32 *p, f32 *q);

s32 func_08815108(char *arg0, u8 *arg1, s32 arg2) {
    char *e;
    s32 n;
    char *b;
    f32 d[3];
    f32 r;

    if (arg1[6] & 0x80) {
        if (func_088DA324(*(char **)(arg0 + 0xA84), *(char **)(arg0 + 0xA84)) == 0) {
            return 2;
        }
    }
    e = *(char **)(arg1 + 0x18);
    for (n = arg1[5]; n > 0; n--, e += 0x40) {
        if (((u8 *)e)[0x2C] & (u8)arg2) {
            continue;
        }
        b = *(char **)(arg0 + 0xA84);
        d[0] = *(f32 *)(b + 0x200) - *(f32 *)(e + 0x20);
        d[1] = *(f32 *)(b + 0x204) - *(f32 *)(e + 0x24);
        d[2] = *(f32 *)(b + 0x208) - *(f32 *)(e + 0x28);
        {
        f32 *pr = &r;
        f32 *pa = (f32 *)(e + 0x30);
        f32 *pb = d;
        asm {
            lv.s S000, 0x0(pa)
            lv.s S001, 0x4(pa)
            lv.s S002, 0x8(pa)
            lv.s S010, 0x0(pb)
            lv.s S011, 0x4(pb)
            lv.s S012, 0x8(pb)
            vdot.t S100, C000, C010
            sv.s S100, 0x0(pr)
        }
        }
        if (r < 0.0f) {
            continue;
        }
        if (r > *(f32 *)(e + 0x3C)) {
            continue;
        }
        if (func_08815260(arg0, (f32 *)e, (f32 *)(b + 0x200)) == 0) {
            return 0;
        }
    }
    return 2;
}
