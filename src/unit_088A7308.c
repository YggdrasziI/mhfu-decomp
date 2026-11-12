/* unit_088A7308: 0x088A7308-0x088A7368 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern s32 func_088A9CDC(void);
extern void func_088A9EBC(void);
extern s32 func_088A9EF4(void);

void func_088A7308(void) {
    if (func_088A9CDC() != 0) {
        func_088A9EF4();
        func_088A9EBC();
    }
}

void func_088A733C(void) {
    if (func_088A9CDC() != 0) {
        func_088A9EF4();
    }
}
