/* unit_088B46EC: 0x088B46EC-0x088B4738 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_088B4738(s32);
extern s32 func_088B4824(s32);

void func_088B46EC(char *arg0) {
    u8 temp_a1;

    temp_a1 = *(u8 *)(arg0 + 0x22);
    switch (temp_a1) {                              /* irregular */
    case 0:
        func_088B4738((s32) arg0);
        return;
    case 1:
        func_088B4824((s32) arg0);
        return;
    }
}
