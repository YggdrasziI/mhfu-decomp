/* unit_0886F65C: 0x0886F65C-0x0886F78C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;

extern char *D_089CC438;
extern char *D_08A62C7C;

extern void func_0884FAC4(char *, s32);

void func_0886F65C(s32 arg0, char *arg1) {
    s8 mode;

    if (*(s16 *)(arg1 + 0x2E4) != 0) {
        return;
    }
    mode = *(s8 *)(*(char **)(D_08A62C7C + 0x4C) + 0x44);
    if (mode == 5) {
        switch (*(u8 *)(arg1 + 0x1E8)) {
        case 0x36:
            func_0884FAC4(D_089CC438, 0xD5);
            break;
        case 0x41:
            func_0884FAC4(D_089CC438, 0xD6);
            break;
        case 0x3B:
            func_0884FAC4(D_089CC438, 0xD7);
            break;
        case 2:
            func_0884FAC4(D_089CC438, 0xD8);
            break;
        case 0x24:
            func_0884FAC4(D_089CC438, 0xD9);
            break;
        }
    } else if (mode == 2) {
        switch (*(u8 *)(arg1 + 0x1E8)) {
        case 2:
            func_0884FAC4(D_089CC438, 0xD3);
            break;
        case 0x24:
            func_0884FAC4(D_089CC438, 0xD4);
            break;
        }
    }
}
