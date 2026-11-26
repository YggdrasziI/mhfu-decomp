/* unit_088266CC: 0x088266CC-0x08826734 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char *D_08A631A0;
extern char *D_08A631A8;
extern char *D_089CC438;
extern char *D_09A0B544;
extern int func_088911A0(char *, char *);

void func_088266CC(char *arg0, char *arg1) {
    char *p;

    if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 1) {
        p = D_09A0B544 + *(u8 *)(arg1 + 0x1E6) * 200 + 0xBC8;
    } else {
        p = D_089CC438 + 0x4A0;
    }
    func_088911A0(D_08A631A8, p);
}
