/* unit_0887F8D4: 0x0887F8D4-0x0887F934 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern void func_088803D8(void *, int);
extern void func_0889E9D4(void);

void func_0887F8D4(char *arg0) {
    s16 temp_a1;
    s16 temp_a2;
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = *(s16 *)(arg0 + 0x17A);
    if (temp_v0 > 0) {
        temp_v0_2 = temp_v0 - 1;
        *(s16 *)(arg0 + 0x17A) = temp_v0_2;
        temp_a2 = *(s16 *)(arg0 + 0x178);
        temp_a1 = *(s16 *)(arg0 + 0x174);
        func_088803D8(arg0, temp_a1 + ((s32) ((*(s16 *)(arg0 + 0x176) - temp_a1) * (temp_a2 - temp_v0_2)) / temp_a2));
    }
    func_0889E9D4();
}
