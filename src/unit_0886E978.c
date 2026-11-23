/* unit_0886E978: 0x0886E978-0x0886E9F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;

extern char *D_089CC438;

void func_0886E978(char *arg0, s32 arg1) {
    s16 *p = *(s16 **)(arg0 + 0x54);
    s16 i = 0;
    s16 key;

    switch (*(unsigned char *)(D_089CC438 + 0x2E)) {
    case 0:
    case 1:
    case 2:
        key = arg1 == 0 ? -1 : 0x26;
    loop:
        if (*p == key) goto done;
        p += 4;
        i++;
        goto loop;
    done:
        *(s16 *)(arg0 + 0x1C) = i;
        D_089CC438[0x2E] = 3;
        break;
    }
}
