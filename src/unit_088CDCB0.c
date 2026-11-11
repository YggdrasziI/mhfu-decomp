/* unit_088CDCB0: 0x088CDCB0-0x088CDCC8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;

u8 func_088CDCB0(char *arg0) {
    return *(u8 *)((*(char **)((char *)((arg0 + (*(u8 *)(arg0 + 1) << 5))) + 0x20)) + 6);
}
