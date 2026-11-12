/* unit_08886780: 0x08886780-0x088867F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_088866D8(s32, s32);
extern s32 func_088A2068(void *, s32, s32);
extern s32 func_088A2338(void *);

void func_08886780(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    char *temp_s1;
    char *temp_v0_2;

    temp_s1 = (char *) (arg0 + (arg1 * 0x18));
    temp_v0 = func_088866D8(arg0, arg2);
    *(s32 *)(temp_s1 + 4) = temp_v0;
    if (temp_v0 != -1) {
        temp_v0_2 = (char *) (arg0 + (*(s32 *)(temp_s1 + 4) * 0x10));
        func_088A2068(*(char **)temp_s1, *(s32 *)(temp_v0_2 + 0x30), *(s32 *)(temp_v0_2 + 0x38));
        *(s32 *)(temp_s1 + 8) = func_088A2338(*(char **)temp_s1);
    }
}
