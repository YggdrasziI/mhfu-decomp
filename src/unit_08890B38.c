/* unit_08890B38: 0x08890B38-0x08890BBC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern int func_0880C464(void *, s32, s32);

void func_08890B38(char *arg0) {
    s32 var_a2;
    char *var_a1;

    var_a1 = arg0 + 0x2628;
    var_a2 = 0;
    do {
        *(u16 *)var_a1 = 0xFFFF;
        *(u16 *)(var_a1 + 2) = 0xFFFF;
        *(u16 *)(var_a1 + 4) = 0xFFFF;
        *(u16 *)(var_a1 + 6) = 0xFFFF;
        *(u16 *)(var_a1 + 8) = 0xFFFF;
        *(u16 *)(var_a1 + 0xA) = 0xFFFF;
        *(u16 *)(var_a1 + 0xC) = 0xFFFF;
        var_a2 += 8;
        *(u16 *)(var_a1 + 0xE) = 0xFFFF;
        var_a1 += 0x10;
    } while (var_a2 < 0xFFF0);
    *(u16 *)(arg0 + 0x158) = 0;
    func_0880C464(arg0 + 0x22968, 0, 0x1B0);
    *(u16 *)(arg0 + 0x15A) = 0;
    *(u16 *)(arg0 + 0x162) = 0;
}
