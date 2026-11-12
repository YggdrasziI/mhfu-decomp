/* unit_088DB534: 0x088DB534-0x088DB5C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char *D_08A62C5C;
extern void func_08867008(void *, u8, u8);
extern void func_08867020(void *, u8);
extern void func_08867034(void *, u8);

void func_088DB534(s32 arg0, u8 arg1) {
    s32 var_s2;

    var_s2 = 0;
    do {
        func_08867008(D_08A62C5C, arg1, var_s2 & 0xFF);
        var_s2 += 1;
    } while (var_s2 < 6);
    func_08867034(D_08A62C5C, arg1);
    func_08867020(D_08A62C5C, arg1);
    ((s32 *)((char *)arg0 + 0x24))[arg1 & 0xFF] = 0;
}
