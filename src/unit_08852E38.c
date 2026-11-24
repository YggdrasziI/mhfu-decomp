/* unit_08852E38: 0x08852E38-0x08852EE0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern u32 D_0899C49C[];
extern u32 D_0899C514;
extern u8 func_0884FCB0(char *);

void func_08852E38(char *arg0, u8 *arg1, u32 *arg2, u32 *arg3) {
    char *q = arg0 + 0x4A0;
    u32 *p;

    *arg2 = *(u32 *)(q + 0x6924C);
    for (p = D_0899C49C; *p != D_0899C514; p++) {
        if (*(u32 *)(q + 0x6924C) < *p) {
            break;
        }
    }
    *arg1 = func_0884FCB0(arg0) + 1;
    *arg3 = *p;
}
