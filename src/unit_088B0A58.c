/* unit_088B0A58: 0x088B0A58-0x088B0B14 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B09D0 and unit_088B0B14.
 *
 * Resets the network state (0x1C740 bytes at D_09A2851C, 0x873C bytes at
 * D_09A1FDE0), keeps the 24 bytes arg0 at the start of D_09A2851C,
 * registers func_088B047C as event callback (func_088AD064), reads the
 * console address into D_09A201F0 and resets the peer table with it
 * (func_088AD63C) through a 16-byte local copy. Returns 0.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s8 b[24];
} Bytes24;

extern char D_09A2851C[];
extern u8 D_09A1FDE0[];
extern u8 D_09A201F0[];

extern void memset(void *, s32, s32);
extern void memcpy(void *, void *, s32);
extern void func_088B047C(void);
extern void func_088AD064(void (*)(void), void *);
extern s32 func_088B0554(u8 *);
extern void func_088AD63C(u8 *);

s32 func_088B0A58(Bytes24 *arg0) {
    u8 buf[0x10];

    memset(D_09A2851C, 0, 0x1C740);
    memset(D_09A1FDE0, 0, 0x873C);
    D_09A1FDE0[0] = 0;
    *(Bytes24 *) D_09A2851C = *arg0;
    func_088AD064(func_088B047C, 0);
    func_088B0554(D_09A201F0);
    memcpy(buf, D_09A201F0, 6);
    func_088AD63C(buf);
    return 0;
}
