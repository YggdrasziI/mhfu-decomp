/* unit_08842EE8: 0x08842EE8-0x08842F70 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08842EE8 */

typedef int s32;
typedef unsigned char u8;

extern void func_08842F70(char *, float, s32, s32, s32);
extern void func_08843A7C(char *, float, s32, s32);
extern void func_08844304(char *);

void func_08842EE8(char *arg0) {
    if (*(s32 *)(arg0 + 0x1194) & 4) {
        return;
    }
    if (*(u8 *)(arg0 + 0x5DD) != 0) {
        return;
    }
    if (*(u8 *)(arg0 + 0x5DB) != 0) {
        return;
    }
    if (*(u8 *)(arg0 + 0x576) == 0) {
        func_08842F70(arg0, 1.0f, 0x13C, 0x20, 0);
        func_08844304(arg0);
    } else {
        func_08843A7C(arg0, 1.0f, 0x13C, 0x20);
    }
}
