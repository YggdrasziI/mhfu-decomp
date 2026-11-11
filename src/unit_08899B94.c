/* unit_08899B94: 0x08899B94-0x08899BE8 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef int s32;

extern char func_0889A32C;
extern char func_0889A3D8;
extern char func_0889A554;
extern int func_088B0DBC(char *, char *);
extern int func_088B0E04(char *, char *);
extern int func_088B3620(char *, char *);

void func_08899B94(char *arg0) {
    *(s32 *)(arg0 + 0x12C0) = (s32) (*(s32 *)(arg0 + 0x12C0) | 0x10);
    func_088B0DBC(&func_0889A32C, arg0);
}

void func_08899BB0(char *arg0) {
    *(s32 *)(arg0 + 0x12C0) = (s32) (*(s32 *)(arg0 + 0x12C0) | 0x20);
    func_088B0E04(&func_0889A3D8, arg0);
}

void func_08899BCC(char *arg0) {
    *(s32 *)(arg0 + 0x12C0) = (s32) (*(s32 *)(arg0 + 0x12C0) | 0x40);
    func_088B3620(&func_0889A554, arg0);
}
