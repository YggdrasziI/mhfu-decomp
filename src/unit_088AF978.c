/* unit_088AF978: 0x088AF978-0x088AFA2C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern u8 D_09A1FDE0;
extern int memset(void *, s32, s32);
extern s32 func_088B0514(void *, void *);
extern s32 func_088B7BD8(s32);

s32 func_088AF978(char *arg0) {
    s32 var_s2;
    u8 *var_s1;

    var_s2 = 0;
    var_s1 = &D_09A1FDE0;
loop_1:
    if (func_088B0514(var_s1 + 0xB8, arg0) == 0) {
        memset(&D_09A1FDE0 + (var_s2 * 0xC8) + 0xB8, 0, 0xC8);
    } else {
        var_s2 += 1;
        var_s1 += 0xC8;
        if (var_s2 < 4) {
            goto loop_1;
        }
    }
    if (D_09A1FDE0 != 2) {
        func_088B7BD8((s32) arg0);
    }
    return 0;
}
