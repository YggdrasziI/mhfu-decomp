/* unit_088B2058: 0x088B2058-0x088B20C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B2024 and unit_088B20C4.
 *
 * Reads the sender address of the current message; error 0x8000 when
 * D_09A28876 is clear, 0x8021 when func_088B6768 accepts the address.
 * Replies with func_088B20C4 (as func_088B1DB0).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[6];
} Addr6;

typedef struct {
    Addr6 unk0;
    u8 unk6;
    u8 unk7;
} Addr8;

typedef struct {
    s8 b[0x14];
} Id;

extern u8 D_09A28876;

extern void func_088AEF64(Addr8 *);
extern s32 func_088B6768(Addr8 *);
extern void func_088B20C4(Id *, Addr8 *, u16);

void func_088B2058(void) {
    Addr8 own;
    Id b;
    u16 err;

    err = 0;
    func_088AEF64(&own);
    if (D_09A28876 == 0) {
        err = 0x8000;
    } else if (func_088B6768(&own) != 0) {
        err = 0x8021;
    }
    func_088B20C4(&b, &own, err);
}
