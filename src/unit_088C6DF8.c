/* unit_088C6DF8: 0x088C6DF8-0x088C7064 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088C6DF8 asm piece, 1 function
 * between unit_088C6D2C and unit_088C7064.
 *
 * Sets up the object of unit_088C6ADC (0xA000-byte heap buffer at 0x28C,
 * heap at 0xA28C): reads the parts 0-5 of a resource (func_088B89B0) and
 * copies two of them into memory returned by func_088C70D8 (DMA copy).
 *
 * NonMatching: the image keeps the original code.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Obj {
    char *unk0;
    char pad4[0x288];
    char buf[0xA000];
    char heap[0x34];
    s32 unkA2C0;
    char padA2C4[0x20];
    char *unkA2E4;
    u8 flags[0x100];
    u8 unkA3E8;
} Obj;

extern char *D_089CBBE4;
extern char *D_09D1A060;
extern void func_08859AE4(void *, void *, s32);
extern s32 func_08859B44(void *, s32, s32);
extern char *func_088B89B0(char *, s32);
extern s32 func_088627AC(char *);
extern s32 func_0886271C(char *);
extern char *func_08862710(char *);
extern s32 func_088C70D8(Obj *, s32);
extern void func_088623DC(char *, s32, char *, s32);
extern void func_08862518(char *, s32, char *, s32);
extern void func_088CAEC8(char *, char *);
extern void func_08814A14(char *, char *);
extern void func_09C386E8(char *, char *);
extern void sceKernelDcacheWritebackInvalidateAll(void);
extern s32 sceDmacMemcpy(s32, char *, s32);

/* NonMatching, 99.84 %: in the first part, the allocation (buf) and the size
 * returned by func_0886271C sit in swapped saved registers ($s2 / $s4); the
 * original gives the size the register of the 16-bit count. The second part
 * matches. The size is computed through a temporary (`buf = x * 16;` then
 * `buf + n * 8`): written in one expression the `addu` operands swap.
 * Tried: every declaration order, the count / temporary in each local, an
 * inline helper for both parts, block-scoped locals, sizeof / shift forms. */
void func_088C6DF8(Obj *arg0, char *arg1, u8 arg2) {
    s32 buf;
    char *r;
    s32 size;
    s32 dst;
    s32 n;

    func_08859AE4(arg0->heap, arg0->buf, 0xA000);
    arg0->unkA2C0 = 0;
    arg0->unkA2E4 = arg1;

    r = func_088B89B0(arg1, 0);
    n = *(u16 *)(r + 0x1C);
    buf = func_088627AC(r) * 16;
    buf = func_08859B44(arg0->heap, buf + n * 8, 0x10);
    size = func_0886271C(r);
    dst = func_088C70D8(arg0, size);
    sceKernelDcacheWritebackInvalidateAll();
    sceDmacMemcpy(dst, func_08862710(r), size);
    func_088623DC(arg0->unk0 + 0x50, buf, r, dst);

    r = func_088B89B0(arg1, 1);
    if (r != 0) {
        func_08862518(arg0->unk0 + 0x70, func_08859B44(arg0->heap, *(s32 *)(r + 8) << 5, 0x10), r, 0);
    }

    r = func_088B89B0(arg1, 3);
    if (r != 0) {
        func_088CAEC8(arg0->unk0, r);
    }

    r = func_088B89B0(arg1, 2);
    if (r != 0) {
        n = *(u16 *)(r + 0x1C);
        buf = func_088627AC(r) * 16;
        buf = func_08859B44(arg0->heap, buf + n * 8, 0x10);
        size = func_0886271C(r);
        dst = func_088C70D8(arg0, size);
        sceKernelDcacheWritebackInvalidateAll();
        sceDmacMemcpy(dst, func_08862710(r), size);
        func_088623DC(arg0->unk0 + 0x1D0, buf, r, dst);
    }

    if (arg2 == 1) {
        func_08814A14(D_089CBBE4, func_088B89B0(arg1, 4));
        r = func_088B89B0(arg1, 5);
        if (r != 0) {
            func_09C386E8(D_09D1A060, r);
        }
    }
    arg0->unkA3E8 = 1;
}
