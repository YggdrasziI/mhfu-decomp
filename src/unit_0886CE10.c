/* unit_0886CE10: 0x0886CE10-0x0886CE4C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886CE10 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    char pad0[0x14];
    u16 unk14;
    char pad16[0x20 - 0x16];
} Entry;

extern Entry *D_09A4F060;
extern void func_0886D114(char *, s8);

void func_0886CE10(char *arg0, s32 arg1) {
    if (arg1 != -1) {
        D_09A4F060[arg1].unk14 = 0xFFFF;
        func_0886D114(arg0, arg1);
    }
}
