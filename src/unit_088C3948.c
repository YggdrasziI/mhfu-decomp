/* unit_088C3948: 0x088C3948-0x088C3A64 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088C3948 asm piece, 1 function
 * between unit_088C354C and unit_088C3A64.
 *
 * Allocates a 0x70-byte object from the heap at +0xA28C, constructs it
 * with func_09CBBF40 (overlay code), adds it to the list (func_088C7130),
 * points +0x2C / +0x30 into the record at *arg0 and initialises it with
 * func_09CBC010 and the seven other arguments.
 *
 * NonMatching: the image keeps the original code.
 */

typedef int s32;

extern void memset(void *, s32, s32);
extern s32 func_08859B44(void *, s32, s32);
extern void func_08859C40(void *, s32);
extern void func_088C7130(char *, s32);
extern s32 func_09CBBF40(s32);
extern void func_09CBC010(s32, s32, s32, s32, s32, s32, s32);

/* NonMatching, 95.77 %: after freeing a failed object the original jumps
 * over the `else` (`b` with `addu a0, s4` in the slot, then the dead
 * `addu s6, zero, zero` of `obj = 0`); ours falls through. Probably a C++
 * placement `new` with an inline allocator. Tried: the assignment before or
 * after the test, a goto, a ternary, the branches swapped, C++, every
 * declaration order. */
void func_088C3948(char *arg0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    s32 v;
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
        obj = v;
        if (v == 0) {
            func_08859C40(arg0 + 0xA28C, tmp);
        }
    } else {
        obj = 0;
    }
    func_088C7130(arg0, obj);
    base = *(s32 *) arg0;
    *(s32 *) (obj + 0x2C) = base + 0x1D0;
    *(s32 *) (obj + 0x30) = base + 0x70;
    func_09CBC010(obj, a1, a2, a3, a4, a5, a6);
}
