/* unit_0882A168: 0x0882A168-0x0882A248 (ULES01213)
 *
 * Bounds (hypothesis): 1 function walking 6 entries of 0xC bytes at 0x112A.
 */

typedef signed char s8;
typedef int s32;

extern char *D_08A631A8;

extern int func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern void func_08832A9C(char *, s32);
extern void func_0882A28C(char *, char *);
extern void func_0882A43C(char *, char *);
extern void func_0882A660(char *, char *);

void func_0882A168(char *p) {
    s32 i;
    char *q;

    p[0x534] = 0xC;
    func_08890E08(D_08A631A8, 3);
    func_08825DA8(p);
    func_08832A9C(p, 1);
    i = 0;
    q = p;
    do {
        if (*(s8 *)(q + 0x112C) == 1) {
            switch (*(s8 *)(q + 0x112D)) {
            case 0:
                func_0882A28C(p, q + 0x112A);
                break;
            case 1:
                func_0882A43C(p, q + 0x112A);
                break;
            case 2:
                func_0882A660(p, q + 0x112A);
                break;
            }
        }
        i++;
        q += 0xC;
    } while (i < 6);
    func_08832A9C(p, 0);
}
