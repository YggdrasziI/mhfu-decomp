/* unit_088988EC: 0x088988EC-0x08898948 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern int func_0889E440(char *);
extern int func_0889E670(char *);

void func_088988EC(char *arg0) {
    *(s32 *)(arg0 + 0x12C0) = 0;
    *(s8 *)(arg0 + 0x12D5) = 0;
    *(s8 *)(arg0 + 0x12D6) = 0;
    *(s8 *)(arg0 + 0x1AFC) = 0;
    *(s32 *)(arg0 + 0x12C4) = 0;
    *(s8 *)(arg0 + 0x146C) = 0;
    *(s8 *)(arg0 + 0x146D) = -1;
    *(s8 *)(arg0 + 0x146E) = 0;
    func_0889E440(arg0 + 0x1B00);
    func_0889E670(arg0 + 0x1B28);
    func_0889E670(arg0 + 0x1B48);
}
