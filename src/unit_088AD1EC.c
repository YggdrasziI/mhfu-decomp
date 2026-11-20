/* unit_088AD1EC: 0x088AD1EC-0x088AD2FC (ULES01213)
 *
 * NonMatching: compiled for the report only, the code is linked from assembly.
 * Bounds (hypothesis): one function between code already in units.
 */

typedef unsigned short u16;
typedef int s32;

extern int memset(void *, s32, s32);
extern void func_088AD134(void *);

/* 99.8 %: the last call loads $a0 (+4) after $a2 (+8) in the original; tried: the size
 * or both arguments in locals, a structure, a char * parameter. */
void func_088AD1EC(char *arg0) {
    if ((*(s32 *)(arg0 + 0) > 0) && (*(char **)(arg0 + 4) != 0) && (*(s32 *)(arg0 + 8) > 0) && (*(char **)(arg0 + 0xC) != 0) && (*(s32 *)(arg0 + 0x10) >= 2) && ((s32) *(u16 *)(arg0 + 0x14) < 2)) {
        func_088AD134(arg0);
        memset(*(char **)(arg0 + 0xC), 0, *(s32 *)(arg0 + 0x10) * 0xC);
        *(char **)(arg0 + 0x18) = (char *) *(char **)(arg0 + 0xC);
        *(char **)(arg0 + 0x1C) = (char *) (*(char **)(arg0 + 0xC) + 0xC);
        *(s32 *)((char *)(*(char **)(arg0 + 0x18)) + 0) = (s32) *(s32 *)(arg0 + 0);
        *(s32 *)((char *)(*(char **)(arg0 + 0x18)) + 4) = (s32) (*(char **)(arg0 + 4) - *(s32 *)(arg0 + 0));
        *(char **)((char *)(*(char **)(arg0 + 0x18)) + 8) = (char *) *(char **)(arg0 + 0x1C);
        *(s32 *)((char *)(*(char **)(arg0 + 0x1C)) + 0) = (s32) *(s32 *)(arg0 + 0);
        *(s32 *)((char *)(*(char **)(arg0 + 0x1C)) + 4) = (s32) (*(char **)(arg0 + 4) + *(s32 *)(arg0 + 8));
        *(s32 *)((char *)(*(char **)(arg0 + 0x1C)) + 8) = 0;
        memset(*(char **)(arg0 + 4), 0, *(s32 *)(arg0 + 8));
        *(s32 *)(arg0 + 0x20) = 0;
        *(s32 *)(arg0 + 0x24) = 0;
    }
}
