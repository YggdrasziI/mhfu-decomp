/* unit_0884E884: 0x0884E884-0x0884E998 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_08903A94(void *, s32, s32);
extern s32 func_08903C64(void *, void *);
extern s32 func_08903E60(void *);
extern s32 func_089040A0(s32, s32, void *);

void func_0884E884(char *arg0, char *arg1) {
    s32 temp_s2;
    u8 temp_v1;

    temp_v1 = *(u8 *)(arg1 + 0x19);
    temp_s2 = *(s32 *)(arg1 + 4) + *(s32 *)(arg1 + 0xC);
    if ((temp_v1 != 0) && (*(u8 *)(arg1 + 0x1A) != 0)) {
        func_089040A0(temp_s2, *(s32 *)(arg1 + 8), arg0 + 0x2FB4C);
        return;
    }
    if (temp_v1 != 0) {
        func_08903E60(arg0 + 0x2FB60);
        func_08903A94(arg0 + 0x2FB60, temp_s2, *(s32 *)(arg1 + 8));
        return;
    }
    if ((temp_v1 == 0) && (*(u8 *)(arg1 + 0x1A) == 0)) {
        func_08903A94(arg0 + 0x2FB60, temp_s2, *(s32 *)(arg1 + 8));
        return;
    }
    func_08903A94(arg0 + 0x2FB60, temp_s2, *(s32 *)(arg1 + 8));
    func_08903C64(arg0 + 0x2FB60, arg0 + 0x2FB4C);
}
