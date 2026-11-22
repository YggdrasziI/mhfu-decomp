/* unit_0888291C: 0x0888291C-0x08882A74 (ULES01213) */

typedef int s32;

extern char D_089AC1A8;
extern s32 D_08A62D94;

extern void func_08886618(s32 arg0, s32 arg1, char *arg2, s32 arg3);

void func_0888291C(char *arg0, s32 arg1) {
    char *ptr;
    s32 start;
    s32 i;
    s32 j;
    s32 size;

    ptr = arg0 + 0x8BC0;
    if (arg1 == 0) {
        start = 0;
    } else if (arg1 == 1) {
        start = 6;
    } else if (arg1 == 2) {
        start = 0x12;
    } else if (arg1 == 3) {
        start = 0x13;
    } else if (arg1 == 4) {
        start = 0x14;
    }
    if (*(s32 *)(arg0 + 0x308BC0) == -1) {
        return;
    }
    i = 0;
    j = 0;
    do {
        size = *(s32 *)(j + (&D_089AC1A8 + *(s32 *)(arg0 + 0x308BC0) * 0x54));
        if (size == 0) {
            return;
        }
        if (i >= start) {
            func_08886618(D_08A62D94, i, ptr, size);
            if (*(s32 *)(arg0 + 0x562434) != 3 && *(s32 *)(arg0 + 0x562434) == i - start + 1) {
                return;
            }
        }
        i++;
        ptr += size;
        j += 4;
    } while (i < 0x15);
}
