/* unit_0889EB84: 0x0889EB84-0x0889EC14 (ULES01213)
 *
 * NonMatching: compiled for the report only, the code is linked from assembly.
 * Bounds (hypothesis): 1 function between unit_0889EAE8 and unit_0889EC14.
 */

typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 count;
    s32 v[16];
} T44;

extern s32 func_088A464C(void);
extern s32 func_088A59FC(void);
extern s32 func_088A4A30(void);
extern s32 func_088A658C(s32);
extern void func_088A5FC0(void);
extern T44 D_09A0B56C;

/* 70.8 %: the original unrolls the fill loop by 8 (eight stores through a pointer
 * stepping 0x20, unsigned counter += 8); mwccpsp 3.0.1 -O4 keeps one store per
 * iteration. Tried: u32/s32/u8/u16 counters, for / while / do while, pointer
 * walks, a plain array, an inline helper taking the structure's address,
 * `#pragma opt_unroll_loops on`. */
s32 func_0889EB84(s32 arg0) {
    u32 i;

    func_088A464C();
    func_088A59FC();
    func_088A4A30();
    func_088A658C(arg0);
    func_088A5FC0();
    D_09A0B56C.count = 0;
    for (i = 0; i < 16; i++) {
        D_09A0B56C.v[i] = -1;
    }
    return 0;
}
