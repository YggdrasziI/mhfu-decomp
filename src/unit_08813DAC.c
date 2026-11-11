/* unit_08813DAC: 0x08813DAC-0x08813DD8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

void func_08813DAC(char *arg0) {
    *(s8 *)(arg0 + 0x968) = 0;
    *(s16 *)(arg0 + 0x964) = 0;
    *(s8 *)(arg0 + 0x9BE) = 0;
    *(s8 *)(arg0 + 0x9BF) = 0;
    *(s32 *)(arg0 + 0x9C0) = 0;
    *(s8 *)(arg0 + 0xA0B) = 0;
    *(s8 *)(arg0 + 0xAAA) = 1;
    *(s8 *)(arg0 + 0xA80) = 0;
    *(s8 *)(arg0 + 0xA0A) = 0;
}
