/* unit_088D81E4: 0x088D81E4-0x088D81F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;

void func_088D81E4(char *arg0) {
    *(s8 *)(arg0 + 0x5F6) = (s8) *(u16 *)(arg0 + 0x686);
}
