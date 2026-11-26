/* unit_08832884: 0x08832884-0x08832940 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;

extern char *D_089CC438;
extern char D_089386E8[];
extern char D_08938784[];
extern u16 D_089AD048[];

extern int func_0880E8F0(char *, char *, ...);
extern char *func_0885151C(char *, u16);

void func_08832884(s32 arg0, s32 arg1, char *arg2) {
    char buf[8];
    u16 idx;
    u32 flags;
    s32 c;

    flags = *(u32 *)(D_089CC438 + 0x6AF14);
    c = (u32)(((flags & 8) != 0) ^ 1) < 1;
    if (!c) {
        c = (u32)(((flags & 4) != 0) ^ 1) < 1;
    }
    idx = c ? 2 : 1;
    func_0880E8F0(buf, D_089386E8, arg1 + 1);
    func_0880E8F0(arg2, D_08938784, func_0885151C(D_089CC438, D_089AD048[idx]), buf);
}
