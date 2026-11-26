/* unit_088239FC: 0x088239FC-0x08823A50 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char *D_089CC438;

s32 func_088239FC(char *arg0) {
    if (!((s32)((*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) != 0) &&
        (s32)((*(s32 *)(*(char **)(arg0 + 0x530) + 0x614) & 4) != 0) != 1) {
        return 0;
    }
    return 1;
}
