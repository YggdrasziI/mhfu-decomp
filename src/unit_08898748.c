/* unit_08898748: 0x08898748-0x088987D4 (ULES01213) */

typedef int s32;

extern int func_08859C40(void *, s32);

void func_08898748(char *arg0, s32 arg1) {
    s32 i;
    char *p;

    for (i = 0, p = arg0; i < 0x200; i++) {
        if (*(s32 *) (p + 0x83C030) == arg1) {
            func_08859C40(arg0, *(s32 *) (p + 0x83C034));
            *(s32 *) (p + 0x83C030) = -1;
        }
        p += 0xC;
    }
}
