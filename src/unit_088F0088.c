/* unit_088F0088: 0x088F0088-0x088F012C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between a unit and code still in assembly.
 * It calls one of the five functions that follow, by kind.
 */

typedef int s32;

extern char *D_089CC438;
extern void func_088F012C(char *, char *);
extern void func_088F1664(char *, char *, char *);
extern void func_088F2224(char *, char *);
extern void func_088F2B0C(char *, char *);
extern void func_088F368C(char *, char *, char *);

void func_088F0088(char *arg0, char *arg1, s32 arg2) {
    switch (arg2) {
    case 0:
        func_088F368C(arg0, arg1, D_089CC438 + 0x67758);
        break;
    case 1:
        func_088F1664(arg0, arg1, D_089CC438 + 0x67758);
        break;
    case 2:
        func_088F2224(arg0, arg1);
        break;
    case 3:
        func_088F012C(arg0, arg1);
        break;
    default:
        func_088F2B0C(arg0, arg1);
        break;
    }
}
