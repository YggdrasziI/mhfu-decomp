/* unit_08823A50: 0x08823A50-0x08823AE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern s32 D_089CC438;
extern s32 D_08A631A8;
extern int func_08823B58(char *);
extern int func_08825DA8(char *);
extern s32 func_088567B4(s32);
extern int func_0885A1B8(char *);
extern int func_08890E08(s32, s32);

void func_08823A50(char *arg0) {
    s32 var_s1;
    char *var_s0;

    var_s0 = arg0;
    if ((func_088567B4(D_089CC438) & 0xFF) != 1) {
        *(s8 *)(var_s0 + 0x534) = 0xE;
        func_08890E08(D_08A631A8, 5);
        func_08825DA8(var_s0);
        func_08823B58(var_s0);
        var_s1 = 0;
        do {
            if (*(u8 *)(var_s0 + 0xE28) != 0) {
                func_0885A1B8(var_s0 + 0xE28);
            }
            var_s1 += 1;
            var_s0 += 0x24;
        } while (var_s1 < 0x14);
    }
}
