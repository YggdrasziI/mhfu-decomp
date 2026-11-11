/* unit_0889A064: 0x0889A064-0x0889A09C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern char func_0889ABA4;
extern char func_0889AC14;
extern int func_088B1888(char *, char *);
extern int func_088B1968(char *, char *);

void func_0889A064(char *arg0) {
    *(s32 *)(arg0 + 0x12C0) = (s32) (*(s32 *)(arg0 + 0x12C0) | 0x2000);
    func_088B1888(&func_0889ABA4, arg0);
}

void func_0889A080(char *arg0) {
    *(s32 *)(arg0 + 0x12C0) = (s32) (*(s32 *)(arg0 + 0x12C0) | 0x4000);
    func_088B1968(&func_0889AC14, arg0);
}
