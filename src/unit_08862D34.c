/* unit_08862D34: 0x08862D34-0x08862DAC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08862D34: picks an entry with func_08862E54 and sets its word at
 * +0x4 from a small mode value. */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *func_08862E54(char *arg0, s32 arg1);

void func_08862D34(char *arg0, u16 arg1, u8 arg2) {
    char *p = func_08862E54(arg0, arg1);

    switch (arg2) {
    case 1:
        *(s32 *)(p + 4) = 0xDF000032;
        break;
    case 2:
        *(s32 *)(p + 4) = 0xDF0000A2;
        break;
    case 3:
        *(s32 *)(p + 4) = 0xDF0002A2;
        break;
    }
}
