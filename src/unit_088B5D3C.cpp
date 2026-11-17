/* unit_088B5D3C: 0x088B5D3C-0x088B5EDC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: structure copied member by member.
 *
 * NonMatching: the image keeps the original code.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    s8 unk0[6];
} Addr6;

typedef struct {
    Addr6 unk0;
    u8 unk6;
    u8 unk7;
} Addr8;

typedef struct {
    s8 unk0[0x12];
} Bytes12;

typedef struct {
    s8 unk0[0xA0];
} BytesA0;

typedef struct {
    Addr6 unk0;
    u8 unk6;
    u8 unk7;
    Bytes12 unk8;
    u16 unk1A;
    u8 unk1C;
    u8 unk1D;
    char unk1E[2];
    BytesA0 unk20;
    u16 unkC0;
    u8 unkC2;
    u8 unkC3;
    u8 unkC4;
    u8 unkC5;
    u8 unkC6;
    u8 unkC7;
} UnkC8;

extern "C" {

extern char D_09A28B98;
extern UnkC8 D_09A28BFC;
extern u8 D_09A28C02;
extern u8 D_09A28C03;
extern Bytes12 D_09A28C04;
extern u16 D_09A28C16;
extern u8 D_09A28C18;
extern u8 D_09A28C19;
extern BytesA0 D_09A28C1C;
extern u16 D_09A28CBC;
extern u8 D_09A28CBE;
extern u8 D_09A28CBF;
extern u8 D_09A28CC0;
extern u8 D_09A28CC1;
extern u8 D_09A28CC2;
extern u8 D_09A28CC3;

extern int func_088AEF64(char *);
extern void *func_088AFE84(void);
extern s32 func_088B0318(char *, s32);
extern s32 func_088B0324(char *, s32);
extern s32 func_088B0370(char *, s32);
extern s32 func_088B04EC(char *arg0);
extern s32 func_088B0514(char *arg0, char *arg1);
extern void func_088B6B14(s32);

/* NonMatching, 96.1 %: from unk1A on, the original loads each pair of members
 * into $v1 then $a0 where this loads $a0 then $v1 (same instructions
 * otherwise). Tried: statement orders, temporaries, a pointer to the local,
 * nested structures assigned whole (word copies), casts. */
void func_088B5D3C(void) {
    Addr8 own;
    UnkC8 rec;
    s32 src = (s32) func_088AFE84();

    func_088AEF64((char *) &own);
    src = func_088B0318((char *) &rec, src);
    src = func_088B0324((char *) &rec.unk8, src);
    func_088B0370((char *) &rec.unk20, src);
    if (func_088B04EC((char *) &rec) != 0) {
        if (func_088B0514(&D_09A28B98, (char *) &own) == 0) {
            *(Addr6 *) &D_09A28BFC = *(Addr6 *) &rec;
            D_09A28C02 = rec.unk6;
            D_09A28C03 = rec.unk7;
            D_09A28C04 = rec.unk8;
            D_09A28C16 = rec.unk1A;
            D_09A28C18 = rec.unk1C;
            D_09A28C19 = rec.unk1D;
            D_09A28C1C = rec.unk20;
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

}