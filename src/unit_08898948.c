/* unit_08898948: 0x08898948-0x08898980 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern void func_088B0C68(void);

void func_08898948(char *arg0) {
    func_088B0C68();
    *(s8 *)(arg0 + 4) = 0;
    *(s8 *)(arg0 + 0x1AFC) = 0;
    *(s8 *)(arg0 + 0x12D5) = 0;
    *(s32 *)(arg0 + 0x12C4) = 0;
    *(s32 *)(arg0 + 0x12C0) = 0;
}
