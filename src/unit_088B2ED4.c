/* unit_088B2ED4: 0x088B2ED4-0x088B2FFC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B2D74 and unit_088B2FFC.
 *
 * Starts the next phase of the record arg0 (+0x14 = 3, timer +0xC = 5),
 * then rebuilds the record list at D_09A29684: of the four records it held,
 * keeps those accepted by func_088B04B4 whose byte at +0xC5 is set
 * (renumbered at +0xC4, count in D_09A29685) and replies with
 * func_088B25B4 to the others.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

typedef struct {
    s32 unk0;
    char unk4[0xC0];
    u8 unkC4;
    u8 unkC5;
    char padC6[2];
} Rec;

extern u8 D_09A29684;
extern u8 D_09A29685;
extern Rec D_09A29688[];
extern u16 D_09A28BF0;

extern void func_0880C084(void *, void *, s32);
extern void func_0880C464(void *, s32, s32);
extern s32 func_088B04B4(Rec *);
extern void func_088B25B4(Id *, Rec *, u16);

void func_088B2ED4(u8 *arg0) {
    Rec old[4];
    Id a;
    s32 i;
    u8 n;
    Rec *dst;
    Rec *src;

    arg0[0x22]++;
    *(s32 *) (arg0 + 0x14) = 3;
    *(s32 *) (arg0 + 0xC) = 5;
    *(s32 *) (arg0 + 0x10) = 0;
    arg0[0x23] = 0;
    func_0880C084(old, D_09A29688, sizeof(old));
    dst = D_09A29688;
    func_0880C464(&D_09A29684, 0, 4);
    func_0880C464(dst, 0, sizeof(old));
    n = 0;
    i = 0;
    src = old;
    do {
        if (func_088B04B4(src)) {
            if (src->unkC5 != 0) {
                *dst = *src;
                dst->unkC4 = n;
                dst++;
                n++;
            } else {
                func_088B25B4(&a, src, D_09A28BF0);
            }
        }
        i++;
        src++;
    } while (i < 4);
    D_09A29685 = n;
}
