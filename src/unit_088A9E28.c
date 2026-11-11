/* unit_088A9E28: 0x088A9E28-0x088A9EF4 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef int s32;

extern char D_09A1D584;
extern char D_09A1D590;
extern char D_09A1D5D0;
extern s32 D_09A1D5EC;
extern int func_088A812C(char *, char *, s32);
extern int func_088A85F4(char *, char *, s32);
extern int func_088A8D74(char *, char *);
extern int func_088A9CFC(void);
extern int func_088A9D60(void);

void func_088A9E28(s32 arg0) {
    if (D_09A1D5EC != 0) {
        func_088A85F4(&D_09A1D5D0, &D_09A1D584, arg0);
    }
}

void func_088A9E60(void) {
    if ((D_09A1D5EC != 0) && (func_088A9CFC() == 0) && (func_088A9D60() == 0)) {
        func_088A812C(&D_09A1D5D0, &D_09A1D584, 2);
    }
}

void func_088A9EBC(void) {
    if (D_09A1D5EC != 0) {
        func_088A8D74(&D_09A1D5D0, &D_09A1D590);
    }
}
