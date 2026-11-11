/* unit_08857C18: 0x08857C18-0x08857C2C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef short s16;

void func_08857C18(char *arg0) {
    *(s16 *)(arg0 + 0x4B8) = 0xE;
}

void func_08857C24(char *arg0) {
    *(s16 *)(arg0 + 0x4B8) = 0;
}
