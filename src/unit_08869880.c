/* unit_08869880: 0x08869880-0x088698B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08869880 */
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;

s32 func_08869880(char *arg0) {
    char *p = *(char **)(arg0 + 0x4C);

    if (*(u16 *)(D_089CC438 + 0x6AF12) == 0) {
        return 0;
    }
    return *(s32 *)(p + 8) + *(s32 *)(arg0 + 0x50);
}
