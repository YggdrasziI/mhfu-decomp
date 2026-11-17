/* unit_088B2B28: 0x088B2B28-0x088B2BC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_088B2BC0. Its jump table (0x08932154-0x0893216C) is linked from this
 * unit.
 */

typedef unsigned char u8;

extern void func_088B2BC0(char *arg0);
extern void func_088B2C20(char *arg0);
extern void func_088B2D74(char *arg0);
extern void func_088B2ED4(char *arg0);
extern void func_088B2FFC(char *arg0);
extern void func_088B30CC(char *arg0);

void func_088B2B28(char *arg0) {
    switch (*(u8 *)(arg0 + 0x22)) {
    case 0:
        func_088B2BC0(arg0);
        break;
    case 1:
        func_088B2C20(arg0);
        break;
    case 2:
        func_088B2D74(arg0);
        break;
    case 3:
        func_088B2ED4(arg0);
        break;
    case 4:
        func_088B2FFC(arg0);
        break;
    case 5:
        func_088B30CC(arg0);
        break;
    }
}
