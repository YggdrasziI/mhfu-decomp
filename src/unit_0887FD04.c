/* unit_0887FD04: 0x0887FD04-0x0887FD64 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

void func_0887FD04(s32 arg0, s32 arg1) {
    char *temp_a0;

    temp_a0 = (char *) (arg0 + (arg1 * 0x14));
    *(u16 *)(temp_a0 + 0x24) = 0xFFFF;
    *(u16 *)(temp_a0 + 0x2A) = (u16) (*(u16 *)(temp_a0 + 0x2A) & 0xFFFE);
}

void func_0887FD2C(s32 arg0, s32 arg1) {
    *(u16 *)((char *)((arg0 + (arg1 * 0x14))) + 0x26) = 0xFFFF;
}

void func_0887FD48(s32 arg0, s32 arg1) {
    *(u16 *)((char *)((arg0 + (arg1 * 0x14))) + 0x28) = 0xFFFF;
}
