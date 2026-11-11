/* unit_088AE354: 0x088AE354-0x088AE368 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;

void func_088AE354(char *arg0) {
    *(u8 *)(arg0 + 0x21) = (u8) (*(u8 *)(arg0 + 0x21) + 1);
    *(s8 *)(arg0 + 0x22) = 0;
}
