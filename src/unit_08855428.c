/* unit_08855428: 0x08855428-0x08855ED0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned short u16;

extern char *D_08A631A0;
extern char *D_08A62C54;
extern u16 func_088900C4(char *, s32);
extern void func_0884FAC4(char *, s32);
extern void func_0884FAFC(char *, s32);
extern void func_08856B24(char *);
extern void func_0885F434(char *);

void func_08855428(char *arg0) {
    u16 r;
    if (func_088900C4(D_08A631A0, 1) & 1) {
        func_0884FAC4(arg0, 0x4E);
    } else {
        func_0884FAFC(arg0, 0x4E);
    }
    if (func_088900C4(D_08A631A0, 1) & 1) {
        func_0884FAC4(arg0, 0x4F);
    } else {
        func_0884FAFC(arg0, 0x4F);
    }
    if (func_088900C4(D_08A631A0, 1) & 1) {
        func_0884FAC4(arg0, 0x50);
    } else {
        func_0884FAFC(arg0, 0x50);
    }
    if (func_088900C4(D_08A631A0, 1) & 1) {
        func_0884FAC4(arg0, 0x5B);
    } else {
        func_0884FAFC(arg0, 0x5B);
    }
    if (func_088900C4(D_08A631A0, 1) & 1) {
        func_0884FAC4(arg0, 0x1B2);
    } else {
        func_0884FAFC(arg0, 0x1B2);
    }
    if (func_088900C4(D_08A631A0, 1) & 1) {
        func_0884FAC4(arg0, 0x1B7);
    } else {
        func_0884FAFC(arg0, 0x1B7);
    }
    if (func_088900C4(D_08A631A0, 1) & 1) {
        func_0884FAC4(arg0, 0x1B8);
    } else {
        func_0884FAFC(arg0, 0x1B8);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x4C);
        func_0884FAFC(arg0, 0x4D);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x4C);
        func_0884FAC4(arg0, 0x4D);
    } else {
        func_0884FAFC(arg0, 0x4C);
        func_0884FAFC(arg0, 0x4D);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x4A);
        func_0884FAFC(arg0, 0x4B);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x4A);
        func_0884FAC4(arg0, 0x4B);
    } else {
        func_0884FAFC(arg0, 0x4A);
        func_0884FAFC(arg0, 0x4B);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x48);
        func_0884FAFC(arg0, 0x49);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x48);
        func_0884FAC4(arg0, 0x49);
    } else {
        func_0884FAFC(arg0, 0x48);
        func_0884FAFC(arg0, 0x49);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x46);
        func_0884FAFC(arg0, 0x47);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x46);
        func_0884FAC4(arg0, 0x47);
    } else {
        func_0884FAFC(arg0, 0x46);
        func_0884FAFC(arg0, 0x47);
    }
    if ((u16)(func_088900C4(D_08A631A0, 1) % 10) < 8) {
        func_0884FAC4(arg0, 0x1AE);
    } else {
        func_0884FAFC(arg0, 0x1AE);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x1AF);
        func_0884FAFC(arg0, 0x1B0);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x1AF);
        func_0884FAC4(arg0, 0x1B0);
    } else {
        func_0884FAFC(arg0, 0x1AF);
        func_0884FAFC(arg0, 0x1B0);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x1B3);
        func_0884FAFC(arg0, 0x1B4);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x1B3);
        func_0884FAC4(arg0, 0x1B4);
    } else {
        func_0884FAFC(arg0, 0x1B3);
        func_0884FAFC(arg0, 0x1B4);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x1B5);
        func_0884FAFC(arg0, 0x1B6);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x1B5);
        func_0884FAC4(arg0, 0x1B6);
    } else {
        func_0884FAFC(arg0, 0x1B5);
        func_0884FAFC(arg0, 0x1B6);
    }
    if ((u16)(func_088900C4(D_08A631A0, 1) % 10) < 8) {
        func_0884FAC4(arg0, 0x3B);
    } else {
        func_0884FAFC(arg0, 0x3B);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x44);
        func_0884FAFC(arg0, 0x45);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x44);
        func_0884FAC4(arg0, 0x45);
    } else {
        func_0884FAFC(arg0, 0x44);
        func_0884FAFC(arg0, 0x45);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x42);
        func_0884FAFC(arg0, 0x43);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x42);
        func_0884FAC4(arg0, 0x43);
    } else {
        func_0884FAFC(arg0, 0x42);
        func_0884FAFC(arg0, 0x43);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x39);
        func_0884FAFC(arg0, 0x3A);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x39);
        func_0884FAC4(arg0, 0x3A);
    } else {
        func_0884FAFC(arg0, 0x39);
        func_0884FAFC(arg0, 0x3A);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x37);
        func_0884FAFC(arg0, 0x38);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x37);
        func_0884FAC4(arg0, 0x38);
    } else {
        func_0884FAFC(arg0, 0x37);
        func_0884FAFC(arg0, 0x38);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x35);
        func_0884FAFC(arg0, 0x36);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x35);
        func_0884FAC4(arg0, 0x36);
    } else {
        func_0884FAFC(arg0, 0x35);
        func_0884FAFC(arg0, 0x36);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x1B9);
        func_0884FAFC(arg0, 0x1BA);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x1B9);
        func_0884FAC4(arg0, 0x1BA);
    } else {
        func_0884FAFC(arg0, 0x1B9);
        func_0884FAFC(arg0, 0x1BA);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x1BB);
        func_0884FAFC(arg0, 0x1BC);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x1BB);
        func_0884FAC4(arg0, 0x1BC);
    } else {
        func_0884FAFC(arg0, 0x1BB);
        func_0884FAFC(arg0, 0x1BC);
    }
    r = (u16)(func_088900C4(D_08A631A0, 1) % 10);
    if (r < 4) {
        func_0884FAC4(arg0, 0x1BD);
        func_0884FAFC(arg0, 0x1BE);
    } else if (r < 8) {
        func_0884FAFC(arg0, 0x1BD);
        func_0884FAC4(arg0, 0x1BE);
    } else {
        func_0884FAFC(arg0, 0x1BD);
        func_0884FAFC(arg0, 0x1BE);
    }
    func_08856B24(arg0);
    func_0885F434(D_08A62C54);
}
