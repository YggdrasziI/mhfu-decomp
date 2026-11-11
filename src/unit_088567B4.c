/* unit_088567B4: 0x088567B4-0x088567C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

s32 func_088567B4(char *arg0) {
    return *(u8 *)(arg0 + 0x6AF1A) != 0;
}
