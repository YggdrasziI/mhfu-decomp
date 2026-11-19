/* unit_088C1178: 0x088C1178-0x088C12BC (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088C1178 asm piece, 1 function
 * between unit_088C0E58 and unit_088C12BC.
 *
 * For each of the three 0x8C-byte entries of D_089CC438 + 0x30 that is set,
 * flags its object (func_088DCEBC) with bit 2 unless it is entry sel; the
 * selected object's angle at +0x1F4 is turned back by 0x1000 while its
 * magnitude exceeds 0x1000, or set from +0x9A0. Then refreshes the scene.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned char u8;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern s32 D_089CBBE4;

extern s32 func_08808AC0(s32);
extern void func_08815964(s32);
extern void func_088DB068(s32);
extern void func_088DB0A0(s32);
extern void func_088DB338(s32);
extern void func_088DB39C(s32);
extern char *func_088DCEBC(s32, s32);

void func_088C1178(char *arg0, s16 sel) {
    s32 i;
    s32 off;
    char *o;
    s16 a;
    s32 v;

    i = 0;
    off = 0;
    do {
        if (*(u8 *) (D_089CC438 + off + 0x30) != 0) {
            o = func_088DCEBC(D_09A4F0C4, i);
            if (i == sel) {
                *(s32 *) (o + 4) &= ~4;
                v = *(u16 *) (arg0 + 0x9A0);
                if (v == 0) {
                    a = *(s16 *) (o + 0x1F4);
                    if (func_08808AC0(a) > 0x1000) {
                        if (a < 0) {
                            *(s32 *) (o + 0x1F4) += 0x1000;
                        } else {
                            *(s32 *) (o + 0x1F4) -= 0x1000;
                        }
                    } else {
                        *(s32 *) (o + 0x1F4) = *(u16 *) (arg0 + 0x9A0);
                    }
                } else {
                    *(s32 *) (o + 0x1F4) = (u16) v;
                }
            } else {
                *(s32 *) (o + 4) |= 4;
            }
        }
        i++;
        off += 0x8C;
    } while (i < 3);
    func_088DB068(D_09A4F0C4);
    func_088DB338(D_09A4F0C4);
    func_088DB39C(D_09A4F0C4);
    func_088DB0A0(D_09A4F0C4);
    func_08815964(D_089CBBE4);
}
