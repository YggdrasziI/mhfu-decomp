/* unit_088FD170: 0x088FD170-0x089015F8 (ULES01213), NonMatching
 *
 * Bounds (hypothesis): 1 function.
 * NonMatching, 99.82 %: the code stays in the assembly piece text_088FD170.
 * Gap: the loop that copies the entries of D_089B8770 to arg0 + 0xBC28 uses
 * one register too many (t2/t3; the original keeps the destination in t0)
 * and hoists the address of the count at arg0 + 0xC2B0 above the byte
 * stores. Tried: seven forms of the bit test, four destination forms, a
 * destination local, field-by-field copy, an inline helper, pointer and
 * `continue` loops, five forms of the count increment, 50 declaration
 * orders.
 *
 * Recomputes the bit set at D_089CC438 + 0x479C (0x1A2 bits): sets each bit
 * whose condition holds (func_08850044 / func_08854BEC / func_08854C5C /
 * func_08855278 / func_08901664 checks, counters of D_089CC438 against
 * thresholds, sums of small tables). When a whole group of bits is set and
 * func_08855278(D_089CC438, n) is still zero, func_088551F0 and
 * func_08830728(D_089CBBEC, 7, n, 0) are called for n. Then copies the
 * entries of D_089B8770 whose bit is set to arg0 + 0xBC28 (count at
 * arg0 + 0xC2B0) and fills the rest of the 0x1A2 entries with id 0x1A2.
 *
 * C++ (the 4-byte entry is copied member by member, the two bytes as a
 * sub-structure). Optimized for speed: unrolled sums, the last loop is
 * unrolled by 8. One variable (sum) holds every sum and count, as in the
 * original register allocation.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct {
    u16 id;
    struct {
        u8 a;
        u8 b;
    } ab;
} Entry;

typedef struct {
    char pad[0xBC28];
    Entry list[0x1A2];
    u16 count;
} Obj;

typedef struct {
    u32 lo : 24;
    u32 hi : 8;
} BF;

extern "C" {

extern char *D_089CC438;
extern char *D_089CBBEC;
extern char *D_08A62C50;
extern u32 D_089B86F8[];
extern u32 D_089B839C[];
extern Entry D_089B8770[];

extern s32 func_0880BFF0(void *, void *, s32);
extern u8 func_08830728(char *, s8, s16, s16);
extern s32 func_0884FB38(char *, s32);
extern u16 func_0884FF4C(char *, u8);
extern s32 func_08850044(char *, s32, s32);
extern s32 func_08854BEC(char *, s32);
extern s32 func_08854C5C(char *, s32);
extern s32 func_08855038(char *);
extern void func_088551F0(char *, s32);
extern s32 func_08855278(char *, s32);
extern s32 func_088581C0(char *, s32);
extern u16 func_0885B048(char *, s32);
extern s8 func_089015F8(char *);
extern s32 func_08901664(char *, s8, s8);

#define SET(n) (flags[(u32)(n) >> 5] |= 1u << ((n) & 0x1F))
#define TEST(n) (flags[(n) >> 5] & (1u << ((n) & 0x1F)))
#define U8(o) (*(u8 *)(D_089CC438 + (o)))
#define U32(o) (*(u32 *)(D_089CC438 + (o)))
#define S32(o) (*(s32 *)(D_089CC438 + (o)))
#define COUNT (*(u16 *)(arg0 + 0xC2B0))
#define AWARD(n)                                        \
    if (!func_08855278(D_089CC438, (n))) {              \
        func_088551F0(D_089CC438, (n));                 \
        func_08830728(D_089CBBEC, 7, (n), 0);           \
    }

static inline s32 test_flag(char *g, u32 n) {
    return ((u32 *)(g + 0x479C))[n >> 5] & (1 << (n & 0x1F));
}

void func_088FD170(char *arg0) {
    u32 *flags;
    char *s6;
    char *p;
    char *e;
    u8 *s0;
    s32 found;
    s32 sum;
    s32 i;

    flags = (u32 *)(D_089CC438 + 0x479C);
    SET(0x0); SET(0x1); SET(0x2); SET(0x3); SET(0x4); SET(0x5); SET(0x6); SET(0x7); SET(0x8);
    SET(0xF5); SET(0xF6); SET(0xF7); SET(0xF8); SET(0xF9); SET(0xFA); SET(0xFB);
    if (func_08854BEC(D_089CC438, 0)) SET(0x9);
    if (func_08854BEC(D_089CC438, 0x1)) SET(0xA);
    if (func_08854BEC(D_089CC438, 0x2)) SET(0xB);
    if (func_08854BEC(D_089CC438, 0x3)) SET(0xC);
    if (func_08854BEC(D_089CC438, 0x4)) SET(0xD);
    if (func_08854BEC(D_089CC438, 0x5)) SET(0xE);
    if (func_08854BEC(D_089CC438, 0x6)) SET(0xFC);
    if (func_08854BEC(D_089CC438, 0x7)) SET(0xFD);
    if (func_08854BEC(D_089CC438, 0x8)) SET(0xFE);
    if (func_08854C5C(D_089CC438, 0)) SET(0xF);
    if (func_08854C5C(D_089CC438, 0x1)) SET(0x10);
    if (func_08854C5C(D_089CC438, 0x2)) SET(0x11);
    if (func_08854C5C(D_089CC438, 0x3)) SET(0x12);
    if (func_08854C5C(D_089CC438, 0x4)) SET(0x13);
    if (func_08854C5C(D_089CC438, 0x5)) SET(0x14);
    if (func_08854C5C(D_089CC438, 0x6)) SET(0x15);
    if (func_08854C5C(D_089CC438, 0x7)) SET(0x16);
    if (func_08854C5C(D_089CC438, 0x8)) SET(0xFF);
    if (func_08854C5C(D_089CC438, 0x9)) SET(0x100);
    if (func_08854C5C(D_089CC438, 0xA)) SET(0x101);
    if (func_08855038(D_089CC438)) SET(0x102);
    if (func_08850044(D_089CC438, 0x1B, 0x14)) SET(0x17);
    if (func_08850044(D_089CC438, 0x4D, 0x14)) SET(0x18);
    if (func_08850044(D_089CC438, 0x1C, 0x14)) SET(0x19);
    if (func_08850044(D_089CC438, 0x1F, 0x14)) SET(0x1A);
    if (func_08850044(D_089CC438, 0x44, 0x14)) SET(0x1B);
    if (func_08850044(D_089CC438, 0x6, 0x14)) SET(0x1C);
    if (func_08850044(D_089CC438, 0x14, 0x14)) SET(0x1D);
    if (func_08850044(D_089CC438, 0x8, 0x14)) SET(0x1E);
    if (func_08850044(D_089CC438, 0x1, 0x14)) SET(0x1F);
    if (func_08850044(D_089CC438, 0xF, 0x14)) SET(0x20);
    if (func_08850044(D_089CC438, 0x15, 0x14)) SET(0x21);
    if (func_08850044(D_089CC438, 0x1A, 0x14)) SET(0x22);
    if (func_08850044(D_089CC438, 0xE, 0x14)) SET(0x23);
    if (func_08850044(D_089CC438, 0x16, 0x14)) SET(0x24);
    if (func_08850044(D_089CC438, 0x11, 0x14)) SET(0x25);
    if (func_08850044(D_089CC438, 0xB, 0x14)) SET(0x26);
    if (func_08850044(D_089CC438, 0x21, 0x14)) SET(0x27);
    if (func_08850044(D_089CC438, 0x28, 0x14)) SET(0x28);
    if (func_08850044(D_089CC438, 0x30, 0x14)) SET(0x29);
    if (func_08850044(D_089CC438, 0x43, 0x14)) SET(0x2A);
    if (func_08850044(D_089CC438, 0x33, 0x14)) SET(0x2B);
    if (func_08850044(D_089CC438, 0x34, 0x14)) SET(0x2C);
    if (func_08850044(D_089CC438, 0x35, 0x14)) SET(0x2D);
    if (func_08850044(D_089CC438, 0x4B, 0x14)) SET(0x2E);
    if (func_08850044(D_089CC438, 0x4F, 0x14)) SET(0x103);
    if (func_08850044(D_089CC438, 0x50, 0x14)) SET(0x104);
    if (func_08850044(D_089CC438, 0x51, 0x14)) SET(0x105);
    if (func_08850044(D_089CC438, 0x52, 0x14)) SET(0x106);
    if (func_08850044(D_089CC438, 0x53, 0x14)) SET(0x107);
    if (func_08850044(D_089CC438, 0x36, 0xA)) SET(0x2F);
    if (func_08850044(D_089CC438, 0x3B, 0xA)) SET(0x30);
    if (func_08850044(D_089CC438, 0x41, 0xA)) SET(0x31);
    if (func_08850044(D_089CC438, 0x40, 0xA)) SET(0x32);
    if (func_08850044(D_089CC438, 0x37, 0xA)) SET(0x33);
    if (func_08850044(D_089CC438, 0x7, 0xA)) SET(0x34);
    if (func_08850044(D_089CC438, 0x4C, 0xA)) SET(0x35);
    if (func_0884FF4C(D_089CC438, 0x2) >= 0xA) SET(0x36);
    if (func_0884FF4C(D_089CC438, 0x24) >= 0xA) SET(0x37);
    if (func_0884FF4C(D_089CC438, 0x47) >= 0xA) SET(0x38);
    if (func_08850044(D_089CC438, 0x3A, 0xA)) SET(0x108);
    if (func_08850044(D_089CC438, 0x58, 0xA)) SET(0x109);
    if (func_08850044(D_089CC438, 0x1B, 0x1E)) SET(0x39);
    if (func_08850044(D_089CC438, 0x4D, 0x1E)) SET(0x3A);
    if (func_08850044(D_089CC438, 0x1C, 0x1E)) SET(0x3B);
    if (func_08850044(D_089CC438, 0x1F, 0x1E)) SET(0x3C);
    if (func_08850044(D_089CC438, 0x44, 0x1E)) SET(0x3D);
    if (func_08850044(D_089CC438, 0x6, 0x1E)) SET(0x3E);
    if (func_08850044(D_089CC438, 0x14, 0x1E)) SET(0x3F);
    if (func_08850044(D_089CC438, 0x8, 0x1E)) SET(0x40);
    if (func_08850044(D_089CC438, 0x1, 0x1E)) SET(0x41);
    if (func_08850044(D_089CC438, 0xF, 0x1E)) SET(0x42);
    if (func_08850044(D_089CC438, 0x15, 0x1E)) SET(0x43);
    if (func_08850044(D_089CC438, 0x1A, 0x1E)) SET(0x44);
    if (func_08850044(D_089CC438, 0xE, 0x1E)) SET(0x45);
    if (func_08850044(D_089CC438, 0x16, 0x1E)) SET(0x46);
    if (func_08850044(D_089CC438, 0x11, 0x1E)) SET(0x47);
    if (func_08850044(D_089CC438, 0xB, 0x1E)) SET(0x48);
    if (func_08850044(D_089CC438, 0x21, 0x1E)) SET(0x49);
    if (func_08850044(D_089CC438, 0x28, 0x1E)) SET(0x4A);
    if (func_08850044(D_089CC438, 0x30, 0x1E)) SET(0x4B);
    if (func_08850044(D_089CC438, 0x43, 0x1E)) SET(0x4C);
    if (func_08850044(D_089CC438, 0x33, 0x1E)) SET(0x4D);
    if (func_08850044(D_089CC438, 0x34, 0x1E)) SET(0x4E);
    if (func_08850044(D_089CC438, 0x35, 0x1E)) SET(0x4F);
    if (func_08850044(D_089CC438, 0x4B, 0x1E)) SET(0x50);
    if (func_08850044(D_089CC438, 0x4F, 0x1E)) SET(0x10A);
    if (func_08850044(D_089CC438, 0x50, 0x1E)) SET(0x10B);
    if (func_08850044(D_089CC438, 0x51, 0x1E)) SET(0x10C);
    if (func_08850044(D_089CC438, 0x52, 0x1E)) SET(0x10D);
    if (func_08850044(D_089CC438, 0x53, 0x1E)) SET(0x10E);
    if (func_08850044(D_089CC438, 0x36, 0xF)) SET(0x51);
    if (func_08850044(D_089CC438, 0x3B, 0xF)) SET(0x52);
    if (func_08850044(D_089CC438, 0x41, 0xF)) SET(0x53);
    if (func_08850044(D_089CC438, 0x40, 0xF)) SET(0x54);
    if (func_08850044(D_089CC438, 0x37, 0xF)) SET(0x55);
    if (func_08850044(D_089CC438, 0x7, 0xF)) SET(0x56);
    if (func_08850044(D_089CC438, 0x4C, 0xF)) SET(0x57);
    if (func_0884FF4C(D_089CC438, 0x2) >= 0xF) SET(0x58);
    if (func_0884FF4C(D_089CC438, 0x24) >= 0xF) SET(0x59);
    if (func_08850044(D_089CC438, 0x3A, 0xF)) SET(0x10F);
    if (func_08850044(D_089CC438, 0x58, 0xF)) SET(0x110);
    if (func_08850044(D_089CC438, 0x1B, 0x28)) SET(0x5A);
    if (func_08850044(D_089CC438, 0x4D, 0x28)) SET(0x5B);
    if (func_08850044(D_089CC438, 0x1C, 0x28)) SET(0x5C);
    if (func_08850044(D_089CC438, 0x1F, 0x28)) SET(0x5D);
    if (func_08850044(D_089CC438, 0x44, 0x28)) SET(0x5E);
    if (func_08850044(D_089CC438, 0x6, 0x28)) SET(0x5F);
    if (func_08850044(D_089CC438, 0x14, 0x28)) SET(0x60);
    if (func_08850044(D_089CC438, 0x8, 0x28)) SET(0x61);
    if (func_08850044(D_089CC438, 0x1, 0x28)) SET(0x62);
    if (func_08850044(D_089CC438, 0xF, 0x28)) SET(0x63);
    if (func_08850044(D_089CC438, 0x15, 0x28)) SET(0x64);
    if (func_08850044(D_089CC438, 0x1A, 0x28)) SET(0x65);
    if (func_08850044(D_089CC438, 0xE, 0x28)) SET(0x66);
    if (func_08850044(D_089CC438, 0x16, 0x28)) SET(0x67);
    if (func_08850044(D_089CC438, 0x11, 0x28)) SET(0x68);
    if (func_08850044(D_089CC438, 0xB, 0x28)) SET(0x69);
    if (func_08850044(D_089CC438, 0x21, 0x28)) SET(0x6A);
    if (func_08850044(D_089CC438, 0x28, 0x28)) SET(0x6B);
    if (func_08850044(D_089CC438, 0x30, 0x28)) SET(0x6C);
    if (func_08850044(D_089CC438, 0x43, 0x28)) SET(0x6D);
    if (func_08850044(D_089CC438, 0x33, 0x28)) SET(0x6E);
    if (func_08850044(D_089CC438, 0x34, 0x28)) SET(0x6F);
    if (func_08850044(D_089CC438, 0x35, 0x28)) SET(0x70);
    if (func_08850044(D_089CC438, 0x4B, 0x28)) SET(0x71);
    if (func_08850044(D_089CC438, 0x4F, 0x28)) SET(0x111);
    if (func_08850044(D_089CC438, 0x50, 0x28)) SET(0x112);
    if (func_08850044(D_089CC438, 0x51, 0x28)) SET(0x113);
    if (func_08850044(D_089CC438, 0x52, 0x28)) SET(0x114);
    if (func_08850044(D_089CC438, 0x53, 0x28)) SET(0x115);
    if (func_08850044(D_089CC438, 0x36, 0x14)) SET(0x72);
    if (func_08850044(D_089CC438, 0x3B, 0x14)) SET(0x73);
    if (func_08850044(D_089CC438, 0x41, 0x14)) SET(0x74);
    if (func_08850044(D_089CC438, 0x40, 0x14)) SET(0x75);
    if (func_08850044(D_089CC438, 0x37, 0x14)) SET(0x76);
    if (func_08850044(D_089CC438, 0x7, 0x14)) SET(0x77);
    if (func_08850044(D_089CC438, 0x4C, 0x14)) SET(0x78);
    if (func_0884FF4C(D_089CC438, 0x2) >= 0x14) SET(0x79);
    if (func_0884FF4C(D_089CC438, 0x24) >= 0x14) SET(0x7A);
    if (func_0884FF4C(D_089CC438, 0x47) >= 0x14) SET(0x116);
    if (func_08850044(D_089CC438, 0x3A, 0x14)) SET(0x117);
    if (func_08850044(D_089CC438, 0x58, 0x14)) SET(0x118);
    if (func_08850044(D_089CC438, 0x1B, 0x32)) SET(0x7B);
    if (func_08850044(D_089CC438, 0x4D, 0x32)) SET(0x7C);
    if (func_08850044(D_089CC438, 0x1C, 0x32)) SET(0x7D);
    if (func_08850044(D_089CC438, 0x1F, 0x32)) SET(0x7E);
    if (func_08850044(D_089CC438, 0x44, 0x32)) SET(0x7F);
    if (func_08850044(D_089CC438, 0x6, 0x32)) SET(0x80);
    if (func_08850044(D_089CC438, 0x14, 0x32)) SET(0x81);
    if (func_08850044(D_089CC438, 0x8, 0x32)) SET(0x82);
    if (func_08850044(D_089CC438, 0x1, 0x32)) SET(0x83);
    if (func_08850044(D_089CC438, 0xF, 0x32)) SET(0x84);
    if (func_08850044(D_089CC438, 0x15, 0x32)) SET(0x85);
    if (func_08850044(D_089CC438, 0x1A, 0x32)) SET(0x86);
    if (func_08850044(D_089CC438, 0xE, 0x32)) SET(0x87);
    if (func_08850044(D_089CC438, 0x16, 0x32)) SET(0x88);
    if (func_08850044(D_089CC438, 0x11, 0x32)) SET(0x89);
    if (func_08850044(D_089CC438, 0xB, 0x32)) SET(0x8A);
    if (func_08850044(D_089CC438, 0x21, 0x32)) SET(0x8B);
    if (func_08850044(D_089CC438, 0x28, 0x32)) SET(0x8C);
    if (func_08850044(D_089CC438, 0x30, 0x32)) SET(0x8D);
    if (func_08850044(D_089CC438, 0x43, 0x32)) SET(0x8E);
    if (func_08850044(D_089CC438, 0x33, 0x32)) SET(0x8F);
    if (func_08850044(D_089CC438, 0x34, 0x32)) SET(0x90);
    if (func_08850044(D_089CC438, 0x35, 0x32)) SET(0x91);
    if (func_08850044(D_089CC438, 0x4B, 0x32)) SET(0x92);
    if (func_08850044(D_089CC438, 0x4F, 0x32)) SET(0x119);
    if (func_08850044(D_089CC438, 0x50, 0x32)) SET(0x11A);
    if (func_08850044(D_089CC438, 0x51, 0x32)) SET(0x11B);
    if (func_08850044(D_089CC438, 0x52, 0x32)) SET(0x11C);
    if (func_08850044(D_089CC438, 0x53, 0x32)) SET(0x11D);
    if (func_08850044(D_089CC438, 0x36, 0x1E)) SET(0x93);
    if (func_08850044(D_089CC438, 0x36, 0x28)) SET(0x94);
    if (func_08850044(D_089CC438, 0x36, 0x32)) SET(0x95);
    if (func_08850044(D_089CC438, 0x3B, 0x1E)) SET(0x96);
    if (func_08850044(D_089CC438, 0x41, 0x1E)) SET(0x97);
    if (func_08850044(D_089CC438, 0x40, 0x1E)) SET(0x98);
    if (func_08850044(D_089CC438, 0x37, 0x1E)) SET(0x99);
    if (func_08850044(D_089CC438, 0x7, 0x1E)) SET(0x9A);
    if (func_08850044(D_089CC438, 0x4C, 0x1E)) SET(0x9B);
    if (func_0884FF4C(D_089CC438, 0x2) >= 0x1E) SET(0x9C);
    if (func_0884FF4C(D_089CC438, 0x24) >= 0x1E) SET(0x9D);
    if (func_0884FF4C(D_089CC438, 0x47) >= 0xF) SET(0x9E);
    if (func_0884FF4C(D_089CC438, 0x47) >= 0x1E) SET(0x11E);
    if (func_08850044(D_089CC438, 0x3A, 0x1E)) SET(0x11F);
    if (func_08850044(D_089CC438, 0x58, 0x1E)) SET(0x120);
    if (func_08850044(D_089CC438, 0x1B, 0x4B)) SET(0x121);
    if (func_08850044(D_089CC438, 0x4D, 0x4B)) SET(0x122);
    if (func_08850044(D_089CC438, 0x1C, 0x4B)) SET(0x123);
    if (func_08850044(D_089CC438, 0x1F, 0x4B)) SET(0x124);
    if (func_08850044(D_089CC438, 0x44, 0x4B)) SET(0x125);
    if (func_08850044(D_089CC438, 0x6, 0x4B)) SET(0x126);
    if (func_08850044(D_089CC438, 0x14, 0x4B)) SET(0x127);
    if (func_08850044(D_089CC438, 0x8, 0x4B)) SET(0x128);
    if (func_08850044(D_089CC438, 0x1, 0x4B)) SET(0x129);
    if (func_08850044(D_089CC438, 0xF, 0x4B)) SET(0x12A);
    if (func_08850044(D_089CC438, 0x15, 0x4B)) SET(0x12B);
    if (func_08850044(D_089CC438, 0x1A, 0x4B)) SET(0x12C);
    if (func_08850044(D_089CC438, 0xE, 0x4B)) SET(0x12D);
    if (func_08850044(D_089CC438, 0x16, 0x4B)) SET(0x12E);
    if (func_08850044(D_089CC438, 0x11, 0x4B)) SET(0x12F);
    if (func_08850044(D_089CC438, 0xB, 0x4B)) SET(0x130);
    if (func_08850044(D_089CC438, 0x21, 0x4B)) SET(0x131);
    if (func_08850044(D_089CC438, 0x28, 0x4B)) SET(0x132);
    if (func_08850044(D_089CC438, 0x30, 0x4B)) SET(0x133);
    if (func_08850044(D_089CC438, 0x43, 0x4B)) SET(0x134);
    if (func_08850044(D_089CC438, 0x33, 0x4B)) SET(0x135);
    if (func_08850044(D_089CC438, 0x34, 0x4B)) SET(0x136);
    if (func_08850044(D_089CC438, 0x35, 0x4B)) SET(0x137);
    if (func_08850044(D_089CC438, 0x4B, 0x4B)) SET(0x138);
    if (func_08850044(D_089CC438, 0x4F, 0x4B)) SET(0x139);
    if (func_08850044(D_089CC438, 0x50, 0x4B)) SET(0x13A);
    if (func_08850044(D_089CC438, 0x51, 0x4B)) SET(0x13B);
    if (func_08850044(D_089CC438, 0x52, 0x4B)) SET(0x13C);
    if (func_08850044(D_089CC438, 0x53, 0x4B)) SET(0x13D);
    if (func_08850044(D_089CC438, 0x3B, 0x28)) SET(0x13E);
    if (func_08850044(D_089CC438, 0x41, 0x28)) SET(0x13F);
    if (func_08850044(D_089CC438, 0x40, 0x28)) SET(0x140);
    if (func_08850044(D_089CC438, 0x37, 0x28)) SET(0x141);
    if (func_08850044(D_089CC438, 0x7, 0x28)) SET(0x142);
    if (func_08850044(D_089CC438, 0x4C, 0x28)) SET(0x143);
    if (func_0884FF4C(D_089CC438, 0x2) >= 0x28) SET(0x144);
    if (func_0884FF4C(D_089CC438, 0x24) >= 0x28) SET(0x145);
    if (func_0884FF4C(D_089CC438, 0x47) >= 0x28) SET(0x146);
    if (func_08850044(D_089CC438, 0x3A, 0x28)) SET(0x147);
    if (func_08850044(D_089CC438, 0x58, 0x28)) SET(0x148);
    if (func_08850044(D_089CC438, 0x1B, 0x64)) SET(0x149);
    if (func_08850044(D_089CC438, 0x4D, 0x64)) SET(0x14A);
    if (func_08850044(D_089CC438, 0x1C, 0x64)) SET(0x14B);
    if (func_08850044(D_089CC438, 0x1F, 0x64)) SET(0x14C);
    if (func_08850044(D_089CC438, 0x44, 0x64)) SET(0x14D);
    if (func_08850044(D_089CC438, 0x6, 0x64)) SET(0x14E);
    if (func_08850044(D_089CC438, 0x14, 0x64)) SET(0x14F);
    if (func_08850044(D_089CC438, 0x8, 0x64)) SET(0x150);
    if (func_08850044(D_089CC438, 0x1, 0x64)) SET(0x151);
    if (func_08850044(D_089CC438, 0xF, 0x64)) SET(0x152);
    if (func_08850044(D_089CC438, 0x15, 0x64)) SET(0x153);
    if (func_08850044(D_089CC438, 0x1A, 0x64)) SET(0x154);
    if (func_08850044(D_089CC438, 0xE, 0x64)) SET(0x155);
    if (func_08850044(D_089CC438, 0x16, 0x64)) SET(0x156);
    if (func_08850044(D_089CC438, 0x11, 0x64)) SET(0x157);
    if (func_08850044(D_089CC438, 0xB, 0x64)) SET(0x158);
    if (func_08850044(D_089CC438, 0x21, 0x64)) SET(0x159);
    if (func_08850044(D_089CC438, 0x28, 0x64)) SET(0x15A);
    if (func_08850044(D_089CC438, 0x30, 0x64)) SET(0x15B);
    if (func_08850044(D_089CC438, 0x43, 0x64)) SET(0x15C);
    if (func_08850044(D_089CC438, 0x33, 0x64)) SET(0x15D);
    if (func_08850044(D_089CC438, 0x34, 0x64)) SET(0x15E);
    if (func_08850044(D_089CC438, 0x35, 0x64)) SET(0x15F);
    if (func_08850044(D_089CC438, 0x4B, 0x64)) SET(0x160);
    if (func_08850044(D_089CC438, 0x4F, 0x64)) SET(0x161);
    if (func_08850044(D_089CC438, 0x50, 0x64)) SET(0x162);
    if (func_08850044(D_089CC438, 0x51, 0x64)) SET(0x163);
    if (func_08850044(D_089CC438, 0x52, 0x64)) SET(0x164);
    if (func_08850044(D_089CC438, 0x53, 0x64)) SET(0x165);
    if (func_08850044(D_089CC438, 0x3B, 0x32)) SET(0x166);
    if (func_08850044(D_089CC438, 0x41, 0x32)) SET(0x167);
    if (func_08850044(D_089CC438, 0x40, 0x32)) SET(0x168);
    if (func_08850044(D_089CC438, 0x37, 0x32)) SET(0x169);
    if (func_08850044(D_089CC438, 0x7, 0x32)) SET(0x16A);
    if (func_08850044(D_089CC438, 0x4C, 0x32)) SET(0x16B);
    if (func_0884FF4C(D_089CC438, 0x2) >= 0x32) SET(0x16C);
    if (func_0884FF4C(D_089CC438, 0x24) >= 0x32) SET(0x16D);
    if (func_0884FF4C(D_089CC438, 0x47) >= 0x32) SET(0x16E);
    if (func_08850044(D_089CC438, 0x3A, 0x32)) SET(0x16F);
    if (func_08850044(D_089CC438, 0x58, 0x32)) SET(0x170);
    if (func_08850044(D_089CC438, 0x36, 0x3C)) SET(0x171);
    if (func_08850044(D_089CC438, 0x36, 0x46)) SET(0x172);
    if (func_089015F8(arg0) >= 0x1F) SET(0x9F);
    if (func_08855278(D_089CC438, 0x6)) SET(0xA0);
    if (func_08855278(D_089CC438, 0x7)) SET(0xA1);
    if (func_08855278(D_089CC438, 0xE)) SET(0xA2);
    if (func_08855278(D_089CC438, 0xF)) SET(0xA3);
    if (func_08855278(D_089CC438, 0x25)) SET(0x173);
    if (func_0884FB38(D_089CC438, 0xC8)) SET(0xA4);
    if (U8(0X6A53D) >= 0x14) SET(0xA5);
    if (U8(0X6A53E) >= 0x14) SET(0xA6);
    if (U8(0X6A53F) >= 0x14) SET(0xA7);
    if (U8(0X6A541) >= 0x14) SET(0xA8);
    if (U8(0X6A540) >= 0x14) SET(0xA9);
    if (U8(0X6A53C) >= 0x14) SET(0xAA);
    if (U8(0X6A542) >= 0x14) SET(0xAB);
    if (U8(0X6A543) >= 0x14) SET(0x174);
    if (U8(0X6A544) >= 0x14) SET(0x175);
    if (U8(0X6A545) >= 0x14) SET(0x176);
    if (U8(0X6A546) >= 0x14) SET(0x177);
    if (U8(0X6A547) >= 0x14) SET(0x178);
    if (U8(0x6A548) >= 0x14 && U8(0x6A549) >= 0x14) SET(0x17A);
    s6 = D_089CC438 + 0x67758;
    sum = 0;
    for (i = 0; i < 7; i++) {
        sum += ((u16 *)(s6 + 0x20))[i];
    }
    if (sum >= 100) SET(0xAC);
    if (sum >= 1000) SET(0x179);
    if (TEST(0xA5) && TEST(0xA6) && TEST(0xA7) && TEST(0xA8) && TEST(0xA9) && TEST(0xAA) && TEST(0xAB)) {
        AWARD(0x17);
    }
    if (TEST(0x174) && TEST(0x175) && TEST(0x176) && TEST(0x177) && TEST(0x178)
        && func_08855278(D_089CC438, 0x17)) {
        AWARD(0x2F);
    }
    if (func_08855278(D_089CC438, 0xB)) SET(0xAD);
    if (func_08855278(D_089CC438, 0xC)) SET(0xAE);
    if (func_08855278(D_089CC438, 0xD)) SET(0xAF);
    if (func_08855278(D_089CC438, 0x26)) SET(0x17B);
    for (i = 0; i < 30; i++) {
        if (U32(0x696EC) < D_089B86F8[i]) break;
        SET(0xB0 + i);
    }
    if (TEST(0xCD)) {
        AWARD(0x28);
    }
    if (U8(0X6A5EA) >= 0x32) SET(0xCE);
    if (U8(0X6A5EA) >= 0x64) SET(0x17C);
    if (func_0884FB38(D_089CC438, 0x8)) SET(0xCF);
    if (func_08901664(arg0, 0, 0x4)) SET(0xD0);
    if (func_08901664(arg0, 0x1, 0x4)) SET(0xD1);
    if (func_08901664(arg0, 0x2, 0x4)) SET(0xD2);
    if (func_08901664(arg0, 0x3, 0x4)) SET(0xD3);
    if (func_08901664(arg0, 4, 4)) SET(0xD4);
    if (func_08901664(arg0, 0x5, 0x4)) SET(0xD5);
    if (func_08901664(arg0, 0x6, 0x4)) SET(0xD6);
    if (func_08901664(arg0, 0x7, 0x4)) SET(0xD7);
    if (func_08901664(arg0, 0x8, 0x4)) SET(0xD8);
    if (func_08901664(arg0, 0x9, 0x4)) SET(0xD9);
    if (func_08901664(arg0, 0xA, 0x4)) SET(0xDA);
    if (TEST(0xD0) && TEST(0xD1) && TEST(0xD2) && TEST(0xD3) && TEST(0xD4) && TEST(0xD5)
        && TEST(0xD6) && TEST(0xD7) && TEST(0xD8) && TEST(0xD9) && TEST(0xDA)) {
        AWARD(0x16);
        SET(0xDB);
    }
    s0 = (u8 *)(D_089CC438 + 0x6A238);
    if (func_08855278(D_089CC438, 0x13)) SET(0xDC);
    if (func_08855278(D_089CC438, 0x12)) SET(0xDD);
    if (s0[6] & 1) SET(0xDE);
    if (s0[2] >= 3) SET(0xDF);
    if (s0[2] >= 4) SET(0x17D);
    if (s0[6] & 2) SET(0xE0);
    if (s0[3] >= 3) SET(0xE1);
    if (s0[3] >= 4) SET(0x17E);
    if (s0[6] & 4) SET(0xE2);
    if (s0[4] >= 3) SET(0xE3);
    if (s0[5] >= 3) SET(0xE4);
    if (s0[6] & 8) SET(0xE5);
    if (U8(0X6ADA9) >= 0xA) SET(0x17F);
    if (U8(0X6ADA9) >= 0x32) SET(0x180);
    if (U8(0X6ADA9) >= 0x64) SET(0x181);
    p = D_089CC438 + 0x696FF;
    sum = 0;
    for (i = 0; i < 5; i++) {
        sum += *(s8 *)(p + i * 0x70);
    }
    if (sum >= 15) SET(0xE6);
    if (sum >= 25) SET(0xE7);
    if (sum >= 35) SET(0xE8);
    if (func_08855278(D_089CC438, 0x14)) SET(0xE9);
    sum = 0;
    found = 0;
    for (i = 0; i < 13; i++) {
        e = D_089CC438 + i * 0x70 + 0x69BEC;
        if (*(s8 *)e != 0) {
            sum += func_088581C0(D_089CC438, *(u16 *)(e + 0x2A));
            if (((u64)*(u32 *)(e + 0x3C) + ((u64)*(u32 *)(e + 0x40) << 32)) == 0xFFFFFFFFFULL
                && func_0880BFF0(D_089CC438 + 0x67758, e + 0x4E, 0x12) == 0) {
                found = 1;
            }
        }
    }
    if (sum >= 12) SET(0x182);
    if (sum >= 26) SET(0x183);
    if (sum >= 39) SET(0x184);
    if (sum >= 52) SET(0x185);
    if (sum >= 65) SET(0x186);
    if (found) SET(0x187);
    sum = 0;
    for (i = 0; i < 7; i++) {
        if (*(u32 *)(s6 + i * 4 + 0xA8) >= D_089B839C[i]) sum++;
    }
    if (sum >= 7) SET(0xEA);
    if (*(u64 *)(s6 + 0xA0) == 0x7FFFFFFFFULL) SET(0xEB);
    if (((BF *)(s6 + 0x148))->lo == 0xFFFFFFULL) SET(0xEC);
    if (*(u64 *)(s6 + 0x148) == 0xFFFFFFFFFFFFULL) SET(0x188);
    if (*(u32 *)(D_089CC438 + 0x4468) >= 360000) SET(0xED);
    if (S32(0x696F0) >= 200000) SET(0xEE);
    if (S32(0x696F0) >= 999999) SET(0x189);
    if (func_0885B048(D_08A62C50, 2) == 0xAC) {
        SET(0xEF);
        AWARD(0x15);
    }
    if (U8(0x6AC3D) & 1) SET(0xF0);
    if (U8(0x6AC3D) & 4) SET(0x18A);
    if (func_08855278(D_089CC438, 0x2D)) SET(0x18B);
    if (U32(0X6ADF8) & 0x8) SET(0xF1);
    if (U32(0X6ADF8) & 0x10) SET(0xF2);
    if (U32(0X6ADF8) & 0x20) SET(0xF3);
    if (U32(0X6ADF8) & 0x40) SET(0xF4);
    if (U32(0X6ADF8) & 0x100000) SET(0x18C);
    if (U32(0X6ADF8) & 0x200000) SET(0x18D);
    if (U32(0X6ADF8) & 0x800000) SET(0x18E);
    if (U32(0X6ADF8) & 0x400000) SET(0x18F);
    if (U32(0X6ADF8) & 0x40000) SET(0x190);
    if (U32(0X6ADF8) & 0x80000) SET(0x191);
    if (U32(0X6ADF8) & 0x20000) SET(0x192);
    if (U32(0X6ADF8) & 0x10000) SET(0x193);
    if (U32(0X6ADF8) & 0x4000) SET(0x194);
    if (U32(0X6ADF8) & 0x8000) SET(0x195);
    if (func_08901664(arg0, 0xB, 0x3)) SET(0x196);
    if (func_08901664(arg0, 0xC, 0x3)) SET(0x197);
    if (func_08901664(arg0, 0xD, 0x3)) SET(0x198);
    if (func_08901664(arg0, 0xE, 0x3)) SET(0x199);
    if (func_08901664(arg0, 0xF, 0x3)) SET(0x19A);
    if (TEST(0x196) && TEST(0x197) && TEST(0x198) && TEST(0x199) && TEST(0x19A)) SET(0x19B);
    if (func_08901664(arg0, 0xB, 0x5)) SET(0x19C);
    if (func_08901664(arg0, 0xC, 0x5)) SET(0x19D);
    if (func_08901664(arg0, 0xD, 0x5)) SET(0x19E);
    if (func_08901664(arg0, 0xE, 0x5)) SET(0x19F);
    if (func_08901664(arg0, 0xF, 0x5)) SET(0x1A0);
    if (TEST(0x19C) && TEST(0x19D) && TEST(0x19E) && TEST(0x19F) && TEST(0x1A0)) {
        AWARD(0x2E);
        SET(0x1A1);
    }
    COUNT = 0;
    for (i = 0; i < 0x1A2; i++) {
        if (test_flag(D_089CC438, D_089B8770[i].id)) {
            Entry *d = &((Obj *)arg0)->list[COUNT];
            *d = D_089B8770[i];
            COUNT = COUNT + 1;
        }
    }
    for (i = COUNT; i < 0x1A2; i++) {
        *(u16 *)(arg0 + i * 4 + 0xBC28) = 0x1A2;
    }

}

}

