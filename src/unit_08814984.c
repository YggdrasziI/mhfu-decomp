/* unit_08814984: 0x08814984-0x08814A14 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern void func_08814BE0(char *);

void func_08814984(char *arg0) {
    if (*(char **)(arg0 + 0xAAC) == 0) {
        func_08814BE0(arg0);
    }
    *(u16 *)(arg0 + 0xB1C) = (u16) *(u16 *)((*(char **)(arg0 + 0xAAC)) + 4);
    *(u16 *)(arg0 + 0xB1E) = (u16) *(u16 *)((*(char **)(arg0 + 0xAAC)) + 6);
    *(u16 *)(arg0 + 0xB20) = (u16) *(u16 *)((*(char **)(arg0 + 0xAAC)) + 8);
    *(u16 *)(arg0 + 0xB22) = (u16) *(u16 *)((*(char **)(arg0 + 0xAAC)) + 0xA);
    *(s32 *)(arg0 + 0xB24) = (s32) *(s32 *)((*(char **)(arg0 + 0xAAC)) + 0xC);
    *(s32 *)(arg0 + 0xB28) = (s32) *(s32 *)((*(char **)(arg0 + 0xAAC)) + 0x10);
    *(s32 *)(arg0 + 0xB2C) = (s32) *(s32 *)((*(char **)(arg0 + 0xAAC)) + 0x14);
    *(s32 *)(arg0 + 0xB30) = (s32) *(s32 *)((*(char **)(arg0 + 0xAAC)) + 0x18);
}
