/* unit_088B5FC8: 0x088B5FC8-0x088B608C (ULES01213)
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
typedef struct {
    Addr8 unk0;
    char unk8[0xC0];
} UnkC8;

extern char D_09A28B98;
extern UnkC8 D_09A28BFC;
extern u8 D_09A28C02;
extern u8 D_09A28C03;

extern void memset(void *p, int v, int n);
extern int func_088AEF64(char *);
extern void *func_088AFE84(void);
extern s32 func_088B0318(char *, s32);
extern s32 func_088B04EC(char *arg0);
extern s32 func_088B0514(char *arg0, char *arg1);
extern void func_088B6B14(s32);

void func_088B5FC8(void) {
    Addr8 own;
    Addr8 addr;
    s32 src = (s32) func_088AFE84();

    func_088AEF64((char *) &own);
    func_088B0318((char *) &addr, src);
    if (func_088B04EC((char *) &addr) != 0) {
        if (func_088B0514(&D_09A28B98, (char *) &own) == 0) {
            memset(&D_09A28BFC, 0, 0xC8);
            *(Addr6 *) &D_09A28BFC = *(Addr6 *) &addr;
            D_09A28C02 = addr.unk6;
            D_09A28C03 = addr.unk7;
            func_088B6B14(0x10);
        }
    }
}

}