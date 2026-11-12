/* unit_088D3A84: 0x088D3A84-0x088D3ADC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern s32 D_089CC438;
extern s32 func_08851DBC(s32, s32, s32);

void func_088D3A84(char *arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        *(s8 *)((char *)((arg0 + var_s0)) + 0x10E4) = func_08851DBC(D_089CC438, (s32) *(u16 *)(arg0 + 0x1E6), var_s0);
        var_s0 += 1;
    } while (var_s0 < 6);
}
