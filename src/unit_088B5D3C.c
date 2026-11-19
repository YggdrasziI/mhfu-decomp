/* unit_088B5D3C: 0x088B5D3C-0x088B5EDC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B5C30 and unit_088B5EDC.
 *
 * func_088B5D3C reads a peer record from the message of func_088AFE84 and,
 * when it is accepted and does not come from the host address D_09A28B98,
 * stores it at D_09A28BFC (as func_088B4FAC) and calls func_088B6B14(0xF).
 *
 * NonMatching: the image keeps the original code.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[6];
} B6;

typedef struct {
    s8 b[0x12];
} B12;

typedef struct {
    s8 b[0xA0];
} BA0;

typedef struct {
    B6 unk0;
    u8 unk6;
    u8 unk7;
    B12 unk8;
    u16 unk1A;
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[2];
    BA0 unk20;
    u16 unkC0;
    u8 unkC2;
    u8 unkC3;
    u8 unkC4;
    u8 unkC5;
    u8 unkC6;
    u8 unkC7;
} RecC8;

typedef struct {
    s8 b[8];
} Addr8;

extern B6 D_09A28BFC;
extern u8 D_09A28C02;
extern u8 D_09A28C03;
extern B12 D_09A28C04;
extern u16 D_09A28C16;
extern u8 D_09A28C18;
extern u8 D_09A28C19;
extern BA0 D_09A28C1C;
extern u16 D_09A28CBC;
extern u8 D_09A28CBE;
extern u8 D_09A28CBF;
extern u8 D_09A28CC0;
extern u8 D_09A28CC1;
extern u8 D_09A28CC2;
extern u8 D_09A28CC3;
extern char D_09A28B98[];

extern void func_088AEF64(Addr8 *);
extern char *func_088AFE84(void);
extern char *func_088B0318(RecC8 *, char *);
extern char *func_088B0324(B12 *, char *);
extern void func_088B0370(BA0 *, char *);
extern s32 func_088B04EC(RecC8 *);
extern s32 func_088B0514(void *, void *);
extern void func_088B6B14(s32);

/* NonMatching, 97.12 %: in the member copies after each byte-array loop
 * (D_09A28C16 / C18 / C19, D_09A28CBC...CC3) the original puts the first
 * load of each pair in $v1 and the second in $a0, ours the reverse, and it
 * loads +0x1D after the address of D_09A28C1C (same gap as func_088B4FAC).
 * Tried: a nested structure for +0x8..+0x1F, char * casts for the arrays,
 * direct structure assignments (word copies), s16 globals, temporaries,
 * a pointer cast copy, an inline helper on a RecC8 pointer, C++, other
 * declaration orders. */
void func_088B5D3C(void) {
    Addr8 own;
    RecC8 rec;
    char *src;

    src = func_088AFE84();
    func_088AEF64(&own);
    src = func_088B0318(&rec, src);
    src = func_088B0324(&rec.unk8, src);
    func_088B0370(&rec.unk20, src);
    if (func_088B04EC(&rec) != 0) {
        if (func_088B0514(D_09A28B98, &own) == 0) {
            *(B6 *) &D_09A28BFC = *(B6 *) &rec;
            D_09A28C02 = rec.unk6;
            D_09A28C03 = rec.unk7;
            *(B12 *) &D_09A28C04 = *(B12 *) &rec.unk8;
            D_09A28C16 = rec.unk1A;
            D_09A28C18 = rec.unk1C;
            D_09A28C19 = rec.unk1D;
            *(BA0 *) &D_09A28C1C = *(BA0 *) &rec.unk20;
            D_09A28CBC = rec.unkC0;
            D_09A28CBE = rec.unkC2;
            D_09A28CBF = rec.unkC3;
            D_09A28CC0 = rec.unkC4;
            D_09A28CC1 = rec.unkC5;
            D_09A28CC2 = rec.unkC6;
            D_09A28CC3 = rec.unkC7;
            func_088B6B14(0xF);
        }
    }
}
