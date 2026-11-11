/* unit_0884B19C: 0x0884B19C-0x0884B234 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char *D_089CBFFC;
extern s32 D_089CC000;

char *func_0884B19C(char *arg0) {
    D_089CBFFC = arg0;
    *(s32 *)(arg0 + 0x1BC) = 0;
    *(s32 *)(arg0 + 0x1C0) = 0;
    *(char **)(arg0 + 0x1C4) = arg0;
    *(char **)(arg0 + 0x1C8) = (char *) (arg0 + 4);
    *(char **)(arg0 + 0x1CC) = (char *) (arg0 + 8);
    *(char **)(arg0 + 0x1D0) = (char *) (arg0 + 0xC);
    *(char **)(arg0 + 0x1D4) = (char *) (arg0 + 0x8C);
    *(char **)(arg0 + 0x1D8) = (char *) (arg0 + 0xAC);
    *(char **)(arg0 + 0x1DC) = (char *) (arg0 + 0x1AC);
    *(char **)(arg0 + 0x1E0) = (char *) (arg0 + 0x1B0);
    *(s32 *)(arg0 + 0x1E4) = 0;
    *(s32 *)(arg0 + 0x1E8) = 0;
    *(s32 *)(arg0 + 0x1EC) = 0;
    *(s32 *)(arg0 + 0x1F0) = 0;
    *(s32 *)(arg0 + 0x1F4) = 0;
    *(s32 *)(arg0 + 0x1F8) = 0;
    *(char **)(arg0 + 0x1FC) = (char *) (arg0 + 0x1B4);
    *(s32 *)(arg0 + 0x200) = 0;
    *(char **)(arg0 + 0x204) = (char *) (arg0 + 0x1B8);
    *(s32 *)(arg0 + 0x208) = 0;
    *(s8 *)(arg0 + 0x20C) = 0;
    D_089CC000 = 0;
    *(s32 *)(arg0 + 0x210) = 0;
    *(s8 *)(arg0 + 0x214) = 0;
    return arg0;
}
