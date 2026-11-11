/* unit_088A0D70: 0x088A0D70-0x088A0DB0 (ULES01213)
 *
 * Bounds (hypothesis): one function (resets one entry of a table, or a spare entry for index 0xFF) between unrelated code; same structure as func_088A0938.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a, b, c, d;
    int e;
    u16 f;
} Rect;

typedef struct {
    char pad[8];
    u8 unk8;
} Msg;

extern Rect D_09A0D140[];
extern Rect D_09A0D240;

void func_088A0D70(Msg *m) {
    Rect *r;

    if (m->unk8 == 0xFF) {
        r = &D_09A0D240;
    } else {
        r = &D_09A0D140[m->unk8];
    }
    r->d = 0xFFF;
    r->c = 0;
    r->e = 0;
    r->f = 0;
}
