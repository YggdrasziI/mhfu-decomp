/* unit_08880708: 0x08880708-0x08880760 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char *D_08A62D84;
extern s32 D_08A62D94;
extern void func_0887F8D4(void *);
extern void func_08881840(char *);
extern int func_08883374(char *);
extern int func_08886468(s32);

void func_08880708(char *arg0) {
    if (*(u8 *)((char *)arg0 + 0x562420) != 0) {
        func_08881840(arg0);
        func_08886468(D_08A62D94);
        func_0887F8D4(D_08A62D84);
        func_08883374(arg0);
    }
}
