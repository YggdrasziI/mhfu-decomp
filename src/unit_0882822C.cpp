/* unit_0882822C: 0x0882822C-0x08828524 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: the function returns bool; with an int return the 0x16 case reuses
 * the compared constant 1 as the returned value. The five-slot searches are
 * do/while loops (no jump to the test) that break to the shared return 1.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {

extern char *D_08A62C54;

extern u8 func_0885CD18(char *arg0, u8 arg1, u16 arg2);
extern u8 func_0885CE1C(char *arg0, u8 arg1);
extern char *func_0885CA50(char *, char *);
extern s32 func_088D7DE8(char *arg0);

bool func_0882822C(char *arg0, char *arg1, u8 arg2, u8 *arg3) {
    u8 a;
    u8 b;
    s32 i;
    s32 f;

    a = func_0885CD18(D_08A62C54, *(u8 *)(arg1 + 1), *(u16 *)(arg1 + 2));
    b = func_0885CE1C(D_08A62C54, a);
    switch (arg2) {
    case 0:
        return 0;
    case 0x12:
    case 0x24:
        return (b & 2) != 0;
    case 0x16:
        return a == 1 || a == 5;
    case 0x17:
    case 0x2D:
        return (b & 1) != 0;
    case 0x30:
        switch (a) {
        case 2:
        case 8:
            return 1;
        case 1:
        case 5:
            f = *(s32 *)(func_0885CA50(D_08A62C54, arg1) + 0x18);
            return ((f | func_088D7DE8(*(char **)(arg0 + 0x530))) & 0xE00) != 0;
        default:
            return 0;
        }
    case 7:
        i = 0;
        do {
            if (arg3[i] == 6) {
                return 0;
            }
            i++;
        } while (i < 5);
        break;
    case 0xB:
        i = 0;
        do {
            if (arg3[i] == 0xA) {
                return 0;
            }
            i++;
        } while (i < 5);
        break;
    case 0x14:
        i = 0;
        do {
            if (arg3[i] == 0x13) {
                return 0;
            }
            i++;
        } while (i < 5);
        break;
    case 0x28:
        i = 0;
        do {
            if (arg3[i] == 0x27) {
                return 0;
            }
            i++;
        } while (i < 5);
        break;
    case 0x1C:
        i = 0;
        do {
            if (arg3[i] == 0x1B) {
                return 0;
            }
            i++;
        } while (i < 5);
        break;
    }
    return 1;
}

}
