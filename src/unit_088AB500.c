/* unit_088AB500: 0x088AB500-0x088AB514 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;

void func_088AB500(u8 *arg0, u8 *arg1, char *arg2) {
    *arg1 = *(u8 *)(arg2 + 2);
    *arg0 = *(u8 *)(arg2 + 3);
}
