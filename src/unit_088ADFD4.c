/* unit_088ADFD4: 0x088ADFD4-0x088AE020 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern void func_088AE020(void *);
extern s32 func_088AE074(s32);

void func_088ADFD4(char *arg0) {
    u8 temp_a1;

    temp_a1 = *(u8 *)(arg0 + 0x22);
    switch (temp_a1) {                              /* irregular */
    case 0:
        func_088AE020(arg0);
        return;
    case 1:
        func_088AE074((s32) arg0);
        return;
    }
}
