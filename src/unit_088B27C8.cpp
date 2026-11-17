/* unit_088B27C8: 0x088B27C8-0x088B2854 (ULES01213)
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
extern Addr8 D_09A29CD0;
extern u8 D_09A29CD6;
extern u8 D_09A29CD7;

extern int func_088AEF64(char *);
extern s32 func_088B66D0(char *);
extern void func_088B6B14(s32);
extern s32 func_088B7A10(char *);

void func_088B27C8(void) {
    Addr8 addr;

    func_088AEF64((char *) &addr);
    if (func_088B7A10((char *) &addr) != 0) {
        if (func_088B66D0((char *) &addr) != 0) {
            *(Addr6 *) &D_09A29CD0 = *(Addr6 *) &addr;
            D_09A29CD6 = addr.unk6;
            D_09A29CD7 = addr.unk7;
            func_088B6B14(0xD);
        }
    }
}

}