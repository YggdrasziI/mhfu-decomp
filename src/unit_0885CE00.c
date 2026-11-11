/* unit_0885CE00: 0x0885CE00-0x0885CE38 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char D_089314FC;
extern char D_089314FD;

u8 func_0885CE00(s32 arg0, s32 arg1) {
    return *(&D_089314FC + ((arg1 & 0xFF) * 2));
}

u8 func_0885CE1C(s32 arg0, s32 arg1) {
    return *(&D_089314FD + ((arg1 & 0xFF) * 2));
}
