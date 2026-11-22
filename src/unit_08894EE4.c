/* unit_08894EE4: 0x08894EE4-0x08894F7C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

extern char D_089AD408[];
extern int func_0880E8F0(char *, char *, ...);
extern void func_08891BC8(s32 arg0, char *src, char *dst);
extern void func_08891D4C(s32 arg0, char *src, char *dst);

void func_08894EE4(s32 arg0, char *arg1, s16 arg2, u8 arg3) {
    char buf[0x300];

    switch (arg2) {
    case 0:
    case 1:
        func_0880E8F0(arg1, D_089AD408, arg2 == 0 ? 0x720 : 0x244);
        break;
    case 2:
        buf[0] = '0';
        buf[1] = 0;
        if (arg3 == 1) {
            func_08891BC8(arg0, buf, arg1);
        } else {
            func_08891D4C(arg0, buf, arg1);
        }
        break;
    }
}
