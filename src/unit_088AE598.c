/* unit_088AE598: 0x088AE598-0x088AE610 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char D_09A28884;
extern int func_088AFE78(void);
extern int func_088AFE90(s32, s32);
extern int func_088AFFD0(s32);
extern int func_088B00DC(s32, char *, u16);
extern int func_088B012C(s32);
extern int func_088B01BC(s32, s32);
extern int func_088B0284(s32, char *);

void func_088AE598(char *arg0) {
    s32 temp_s0;

    temp_s0 = func_088AFE78();
    func_088B01BC(0, 0);
    func_088AFE90(temp_s0, 0xA);
    func_088B0284(temp_s0, &D_09A28884);
    func_088B00DC(temp_s0, arg0, *(u16 *)(arg0 + 0x300));
    func_088AFFD0(temp_s0);
    func_088B012C(temp_s0);
}
