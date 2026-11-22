/* unit_088701D8: 0x088701D8-0x08870264 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;

extern char *D_089CC438;
extern u8 *func_0884FC94(char *, u8);

s16 func_088701D8(char *arg0) {
    char *base;
    u8 *p;
    s16 sum;
    u8 c;

    base = *(char **)(arg0 + 0x50);
    sum = 0;
    p = func_0884FC94(D_089CC438, *(u8 *)(base + *(s32 *)(base + *(s32 *)(*(char **)(arg0 + 0x4C) + 0x14) + 0xC)));
    while ((c = *p) != 0xFF) {
        sum += *(s16 *)(arg0 + 0x29C + c * 2);
        p++;
    }
    return sum;
}
