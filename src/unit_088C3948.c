/* unit_088C3948: 0x088C3948-0x088C3A64 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088C3948 asm piece, 1 function
 * between unit_088C354C and unit_088C3A64.
 *
 * Allocates a 0x70-byte object from the heap at +0xA28C, constructs it
 * with func_09CBBF40 (overlay code), adds it to the list (func_088C7130),
 * points +0x2C / +0x30 into the record at *arg0 and initialises it with
 * func_09CBC010 and the seven other arguments.
 */

typedef int s32;
typedef unsigned int u32;

extern void memset(void *, s32, s32);
extern s32 func_08859B44(void *, s32, s32);
extern void func_08859C40(void *, s32);
extern void func_088C7130(char *, s32);
extern s32 func_09CBBF40(s32);
extern void func_09CBC010(s32, s32, s32, s32, s32, s32, s32);

/* The constructor result goes through an unsigned local and a signed copy
 * (like the temporary of a C++ new-expression): with a single local it
 * shares the saved register of obj and the free path loses its `b` over
 * the dead `obj = 0`. */
void func_088C3948(char *arg0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    u32 v;
    s32 p;
    s32 obj;
    s32 tmp;
    s32 base;

    tmp = func_08859B44(arg0 + 0xA28C, 0x70, 0x10);
    if (tmp != 0) {
        memset((char *) tmp, 0, 0x70);
        v = tmp;
        if (tmp != 0) {
            v = func_09CBBF40(tmp);
        }
        p = (s32) v;
        if (p == 0) {
            func_08859C40(arg0 + 0xA28C, tmp);
        }
        obj = p;
    } else {
        obj = 0;
    }
    func_088C7130(arg0, obj);
    base = *(s32 *) arg0;
    *(s32 *) (obj + 0x2C) = base + 0x1D0;
    *(s32 *) (obj + 0x30) = base + 0x70;
    func_09CBC010(obj, a1, a2, a3, a4, a5, a6);
}
