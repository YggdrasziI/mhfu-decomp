/* unit_088428EC: 0x088428EC-0x088429EC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088428EC (ULES01213)
 *
 * The default case ends in returns inside the switch: this keeps the dead
 * `lbu v1, 0x67C(s0)` left after the `b` whose delay slot was filled from it.
 */

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern u16 func_088D7AD8(char *, u16, u8);
extern void func_088429EC(char *, s32);
extern void func_08842BE4(char *, s32);

void func_088428EC(char *arg0) {
    char *p = *(char **)(arg0 + 0x530);

    if (*(s16 *)(p + 0x646) == 0) {
        if ((s32)((*(u32 *)(p + 0x410) & 8) != 0) == 1) {
            if (func_088D7AD8(p, *(u8 *)(p + 0x686), 1) != 0xFF) {
                func_088429EC(arg0, 2);
            }
        }
        return;
    }
    func_08842BE4(arg0, *(s8 *)(arg0 + 0x57B) == 0);
    switch (*(u16 *)(p + 0x324)) {
    case 0x57C:
    case 0x58E:
    case 0x58F:
        func_088429EC(arg0, 1);
        return;
    default:
        if (*(u8 *)(p + 0x67C) > 0) return;
        if ((s32)((*(u32 *)(p + 0x410) & 8) != 0) != 1) return;
        func_088429EC(arg0, 0);
        return;
    }
}
