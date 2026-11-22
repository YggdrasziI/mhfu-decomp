/* unit_088A4504: 0x088A4504-0x088A464C (ULES01213)
 *
 * The 0x1C bytes at 0x09A0E3B0 (cleared together with memset in
 * func_088A4178) are one record of a 16-byte and a 12-byte member: the copy
 * goes through four then three float registers, the code of two structure
 * copies.
 */

typedef int s32;

typedef struct {
    s32 v[4];
} W4;

typedef struct {
    s32 v[3];
} W3;

typedef struct {
    W4 a;
    W3 b;
} Rec;

extern void func_08897738(s32);
extern void func_088977BC(s32, s32);
extern void func_088976A4(s32, s32);
extern void func_08897610(s32, s32);

extern Rec D_09A0E3B0;

void func_088A4504(Rec *arg0) {
    if (D_09A0E3B0.a.v[0] != arg0->a.v[0]) {
        func_08897738(arg0->a.v[0]);
    }
    if (D_09A0E3B0.a.v[1] != arg0->a.v[1] || D_09A0E3B0.a.v[2] != arg0->a.v[2]) {
        func_088977BC(arg0->a.v[1], arg0->a.v[2]);
    }
    if (D_09A0E3B0.a.v[3] != arg0->a.v[3] || D_09A0E3B0.b.v[0] != arg0->b.v[0]) {
        if (arg0->a.v[0] != -1) {
            func_088976A4(arg0->a.v[3], arg0->b.v[0]);
        } else {
            func_088976A4(0, 0);
        }
    }
    if (D_09A0E3B0.b.v[1] != arg0->b.v[1] || D_09A0E3B0.b.v[2] != arg0->b.v[2]) {
        func_08897610(arg0->b.v[1], arg0->b.v[2]);
    }
    D_09A0E3B0.a = arg0->a;
    D_09A0E3B0.b = arg0->b;
}
