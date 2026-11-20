/* unit_088B4120: 0x088B4120-0x088B4184 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern u8 D_09A28876;
extern char D_09A28B98;
extern char D_09A28CC4;
extern char D_09A291D4;
extern int memset(char *, s32, s32);
extern int func_088B65FC(char *);

void func_088B4120(char *arg0) {
    *(u8 *)(arg0 + 0x22) = (u8) (*(u8 *)(arg0 + 0x22) + 1);
    memset(&D_09A28CC4, 0, 0x190);
    memset(&D_09A291D4, 0, 0x190);
    if (D_09A28876 != 0) {
        func_088B65FC(&D_09A28B98);
    }
}
