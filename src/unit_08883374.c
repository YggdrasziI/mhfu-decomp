/* unit_08883374: 0x08883374-0x08883384 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;

void func_08883374(char *arg0) {
    *(u8 *)((char *)arg0 + 0x5623E0) = 0;
}
