/* unit_08869750: 0x08869750-0x08869774 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08869750: returns the address of entry arg1 of an offset table
 * stored relative to the block whose offset is at arg0 + 0x50. */

typedef int s32;

extern char *D_08A5C464;

s32 func_08869750(char *arg0, s32 arg1) {
    s32 off = *(s32 *)(arg0 + 0x50);
    return (s32)(*(char **)(D_08A5C464 + off + arg1 * 4) + off);
}
