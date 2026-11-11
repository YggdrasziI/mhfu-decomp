/* unit_08856550: 0x08856550-0x0885658C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;

void func_08856550(char *arg0) {
    *(s8 *)(arg0 + 0x6AF1A) = 0;
}

void func_08856560(char *arg0) {
    if (*(u8 *)(arg0 + 0x6AF1A) == 4) {
        *(u8 *)(arg0 + 0x6AF1A) = 0U;
    }
}
