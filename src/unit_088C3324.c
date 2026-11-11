/* unit_088C3324: 0x088C3324-0x088C3364 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_089CBFFC;
extern int func_0884CB24(s32, s32, char *, s32);

void func_088C3324(char **arg0) {
    char *temp_a2;

    temp_a2 = *arg0;
    if ((temp_a2 != 0) && (*(s32 *)(temp_a2 + 0x50) != 0)) {
        func_0884CB24(D_089CBFFC, 3, temp_a2, 1);
    }
}
