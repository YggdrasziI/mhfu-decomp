/* unit_0884F8D4: 0x0884F8D4-0x0884FA0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;

extern char *D_089CC438;
extern void memset(void *, s32, s32);

char *func_0884F8D4(char *arg0) {
    s32 i;
    char *p;

    D_089CC438 = arg0;
    *(s32 *)(arg0 + 0x6AF14) = 0;
    *(s16 *)(arg0 + 0x6AF0E) = 0xFF;
    *(s8 *)(arg0 + 0x6AF10) = 0;
    *(s16 *)(arg0 + 0x6AF12) = 0;
    *(s8 *)(arg0 + 0x2E) = 0;
    *(s8 *)(arg0 + 0x28) = 0;
    *(s8 *)(arg0 + 0x422) = 0;
    *(u16 *)(arg0 + 0x20) = 0xFFFF;
    *(s32 *)(arg0 + 0x47C) = 0;
    *(s32 *)(arg0 + 0x424) = 0;
    memset(arg0 + 0x4A0, 0, 0x6A938);
    i = 0;
    p = arg0;
    for (; i < 20; i++) {
        *(u16 *)(p + 0x47D4) = 0xFFFF;
        *(u16 *)(p + 0x47D6) = 0xFFFF;
        *(u16 *)(p + 0x47D8) = 0xFFFF;
        *(u16 *)(p + 0x47DA) = 0xFFFF;
        *(u16 *)(p + 0x47DC) = 0xFFFF;
        *(u16 *)(p + 0x47DE) = 0xFFFF;
        p += 0x20;
    }
    *(s8 *)(arg0 + 0x30) = 0;
    *(s8 *)(arg0 + 0xBC) = 0;
    *(s8 *)(arg0 + 0x148) = 0;
    *(s8 *)(arg0 + 0x1D4) = 0;
    *(s8 *)(arg0 + 0x260) = 0;
    *(s8 *)(arg0 + 0x2EC) = 0;
    *(s8 *)(arg0 + 0x6AF18) = -1;
    memset(arg0 + 0x6ADE8, 0, 0x14);
    *(s8 *)(arg0 + 0x480) = 0;
    *(s8 *)(arg0 + 0x6AF1B) = 0;
    *(s8 *)(arg0 + 0x6AF0A) = 0;
    *(s8 *)(arg0 + 0x6AF0B) = 0;
    *(s8 *)(arg0 + 0x6AF0C) = 0;
    return arg0;
}
