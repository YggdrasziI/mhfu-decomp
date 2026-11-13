/* unit_088C7064: 0x088C7064-0x088C70D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern void func_08859AE4(void *, void *, s32);

void func_088C7064(char *arg0) {
    char *temp_a1;

    func_08859AE4(arg0 + 0x2294 + 0x7FF8, arg0 + 0x28C, 0xA000);
    *(s32 *)(arg0 + 0xA2C0) = 0;
    *(s32 *)(arg0 + 0xA2B8) = 0;
    temp_a1 = *(char **)arg0;
    if (temp_a1 != 0) {
        *(s32 *)(temp_a1 + 4) = (s32) (*(s32 *)(temp_a1 + 4) & ~2);
    }
    *(s8 *)(arg0 + 0xA3E8) = 0;
}
