/* unit_08896CA0: 0x08896CA0-0x08896CF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_09A44C5C;
extern u8 *D_089B1630[];
extern u16 *D_089B1408[];

void func_09A63188(s32, u16);

void func_08896CA0(s32 arg0, u8 arg1, u8 arg2, u8 arg3) {
    u8 *q;
    u16 *s;

    q = D_089B1630[arg1];
    q += arg2 * 2;
    s = D_089B1408[*q];
    s += arg3;
    func_09A63188(D_09A44C5C, *s);
}
