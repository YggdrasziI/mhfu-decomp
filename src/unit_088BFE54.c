/* unit_088BFE54: 0x088BFE54-0x088BFEF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char *D_08A62C64;
extern s32 D_08A631A0;
extern int func_0880C464(void *, s32, s32);
extern s32 func_088903BC(s32);
extern int sceUtilityMsgDialogInitStart(char *);

void func_088BFE54(char *arg0, s32 arg1) {
    func_0880C464(arg0 + 0x688, 0, 0x2C4);
    *(s32 *)(arg0 + 0x688) = 0x2C4;
    *(s32 *)(arg0 + 0x68C) = func_088903BC(D_08A631A0);
    *(s32 *)(arg0 + 0x690) = 1;
    *(s32 *)(arg0 + 0x694) = 0x32;
    *(s32 *)(arg0 + 0x698) = 0x34;
    *(s32 *)(arg0 + 0x69C) = 0x33;
    *(s32 *)(arg0 + 0x6A0) = 0x29;
    *(s32 *)(arg0 + 0x6BC) = 0;
    *(s32 *)(arg0 + 0x6C0) = arg1;
    *(s32 *)(arg0 + 0x8C4) = 0;
    sceUtilityMsgDialogInitStart(arg0 + 0x688);
    *(s8 *)(arg0 + 0x971) = 1;
    *(s8 *)(D_08A62C64 + 0x17) = 1;
}
