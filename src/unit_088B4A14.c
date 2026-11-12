/* unit_088B4A14: 0x088B4A14-0x088B4A6C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_0880C464(void *, s32, s32);
extern int func_088AEFE4(signed char);
extern void *func_088AFE84(void);
extern int func_088B6458(void *, s32);
extern int func_088B65FC(void *);

void func_088B4A14(void) {
    char sp1C[0x64];
    char *temp_s0;

    temp_s0 = func_088AFE84();
    if (func_088AEFE4(0) == 0) {
        func_0880C464(sp1C, 0, 0x64);
        func_088B6458(sp1C, (s32) temp_s0);
        func_088B65FC(sp1C);
    }
}
