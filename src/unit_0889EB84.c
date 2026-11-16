/* unit_0889EB84: 0x0889EB84-0x0889EC14 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_0889EAE8 and unit_0889EC14.
 * Optimized for speed (`-opt speed`): the fill loop is unrolled by 8, which the
 * default -O4 does not do (notes/COMPILER.md).
 */

#pragma optimize_for_size off

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
