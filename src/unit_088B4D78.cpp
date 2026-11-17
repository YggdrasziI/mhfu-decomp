/* unit_088B4D78: 0x088B4D78-0x088B4E54 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: structure copied member by member.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

typedef struct {
    s8 unk0[6];
} Addr6;

typedef struct {
    Addr6 unk0;
    u8 unk6;
    u8 unk7;
} Addr8;

extern "C" {
extern s32 D_09A2886C;
extern Addr8 D_09A29CD0;
extern u8 D_09A29CD6;
extern u8 D_09A29CD7;

extern void func_0880C464(void *p, int v, int n);
extern void *func_088AFE84(void);
extern s32 func_088B0318(char *, s32);
extern s32 func_088B66D0(char *);
extern void func_088B6A80(s32);
extern void func_088B6B14(s32);
extern s32 func_088B7A10(char *);
extern void func_088B7A50(s32);

void func_088B4D78(void) {
    Addr8 addr;
    s32 src = (s32) func_088AFE84();

    func_0880C464(&addr, 0, 8);
    func_088B0318((char *) &addr, src);
    if (func_088B7A10((char *) &addr) == 0) {
        if (D_09A2886C == 1 || D_09A2886C == 2) {
            func_088B7A50(4);
            func_088B6A80(0xE);
        }
    }
    if (func_088B66D0((char *) &addr) != 0) {
        *(Addr6 *) &D_09A29CD0 = *(Addr6 *) &addr;
        D_09A29CD6 = addr.unk6;
        D_09A29CD7 = addr.unk7;
        func_088B6B14(0xD);
    }
}

}