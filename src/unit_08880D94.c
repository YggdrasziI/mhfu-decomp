/* unit_08880D94: 0x08880D94-0x08880E50 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

#pragma optimize_for_size off
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned char u8;

u8 func_08880D94(char *arg0, u16 *arg1, s8 arg2) {
    char *base;
    u16 *list;
    u8 ret;
    s32 i;
    s32 k;
    s32 j;

    base = arg0 + 0x56243C;
    ret = 0;
    switch (arg2) {
    case 0:
        list = (u16 *)base;
        break;
    case 1:
        list = (u16 *)(base + 8);
        break;
    case 2:
        list = (u16 *)(base + 0x10);
        break;
    }
    for (i = 0, k = 1; i < 4; k++, i++) {
        for (j = k; j < 4; j++) {
            if (list[i] == list[j]) {
                if (arg1[j] != 0xFFFF) {
                    arg1[j] = 0xFFFF;
                    ret = 1;
                }
            }
        }
    }
    return ret;
}
