/* unit_088B0FF8: 0x088B0FF8-0x088B118C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_088B118C.
 *
 * C++: structure copied member by member.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    s8 unk0[6];
} Addr6;

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
    char unkC4[4];
} UnkC8;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    char unk3[0x11];
} Unk14;

extern "C" {

extern u8 D_09A1FDE0;
extern char D_09A1FE98;
extern u8 D_09A28875;
extern UnkC8 D_09A2887C;
extern u8 D_09A28882;
extern u8 D_09A28883;
extern Bytes12 D_09A28884;
extern u16 D_09A28896;
extern u8 D_09A28898;
extern u8 D_09A28899;
extern BytesA0 D_09A2889C;
extern u16 D_09A2893C;
extern u8 D_09A2893E;
extern u8 D_09A2893F;

extern void func_0880C464(void *p, int v, int n);
extern void func_088AF848(UnkC8 *);
extern void func_088B1204(Unk14 *);

void func_088B0FF8(char *arg0) {
    Unk14 state;
    UnkC8 copy;

    (*(u8 *)(arg0 + 0x22))++;
    D_09A28875 = 0;
    if (D_09A1FDE0 == 1) {
        func_0880C464(&D_09A1FE98, 0, 0x320);
        *(Addr6 *) &copy = *(Addr6 *) &D_09A2887C;
        copy.unk6 = D_09A28882;
        copy.unk7 = D_09A28883;
        copy.unk8 = D_09A28884;
        copy.unk1A = D_09A28896;
        copy.unk1C = D_09A28898;
        copy.unk1D = D_09A28899;
        copy.unk20 = D_09A2889C;
        copy.unkC0 = D_09A2893C;
        copy.unkC2 = D_09A2893E;
        copy.unkC3 = D_09A2893F;
        func_088AF848(&copy);
        *(s32 *)(arg0 + 0xC) = 0x5A;
        func_088B1204(&state);
        if (state.unk2 == 0) {
            *(u16 *)(arg0 + 0x26) = 0x8003;
            *(u8 *)(arg0 + 0x21) = 2;
            *(u8 *)(arg0 + 0x22) = 0;
        }
    } else {
        *(u8 *)(arg0 + 0x21) = 1;
        *(u8 *)(arg0 + 0x22) = 0;
        D_09A1FDE0 = 1;
    }
}

}