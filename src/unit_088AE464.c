/* unit_088AE464: 0x088AE464-0x088AE4A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 D_09A202C8;
extern char D_09A202D0;
extern int func_088AB028(char *);
extern void func_088ACD38(void);

void func_088AE464(char *arg0) {
    *(u8 *)(arg0 + 0x22) = (u8) (*(u8 *)(arg0 + 0x22) + 1);
    func_088AB028(&D_09A202D0);
    func_088ACD38();
    D_09A202C8 = 0;
}
