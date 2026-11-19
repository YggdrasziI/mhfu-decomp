/* unit_088C7184: 0x088C7184-0x088C7424 (ULES01213)
 *
 * Bounds (hypothesis): the first five functions of the text_088C7184 asm
 * piece, after unit_088C7130; func_088C7424 and func_088C75D4 (VFPU) follow.
 *
 * C++: virtual calls. func_088C7280 and func_088C7298 end with a jump through
 * the vtable (`jr $t9`): `#pragma exceptions off` (notes/MATCHING.md).
 * func_088C722C and func_088C72B0 are optimized for speed (loops rotated
 * behind a guard; notes/COMPILER.md, "Speed and space").
 * Unlinks a node of the list of unit_088C7130 and frees it; looks up a 16-bit
 * key in a table; finds the 0x34-byte area record that contains a point.
 */

#pragma exceptions off

typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct V0C_0 { virtual void vfunc_08(s32); } V0C_0;

typedef struct Node : V0C_0 {
    char pad4[0xC];
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct Obj {
    char pad0[0xA28C];
    char heap[0x54];
    Node *head;
} Obj;

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    s32 w;
} Vec;

typedef struct Area {
    u16 id;
    s16 type;
    f32 x;
    f32 y;
    f32 z;
    f32 radius;
    f32 height;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    char pad24[0x10];
} Area;

typedef struct Source {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28();
    virtual Area *vfunc_2C(s32);
    virtual s8 vfunc_30(s32);
} Source;

typedef struct Owner {
    Source *src;
    char pad4[0x280];
    s32 unk284;
} Owner;

typedef struct Table {
    s32 count;
    u16 *keys;
} Table;

extern "C" {

extern Table D_09CE4708[];
extern void func_08859C40(void *, Node *);
extern s32 func_09C36758(Vec *, Vec *, Vec *, f32, f32);

void func_088C7184(Obj *arg0, Node *arg1) {
    Node *next;

    next = arg1->next;
    if (arg0->head == arg1) {
        arg0->head = next;
        if (next != 0) {
            next->prev = 0;
        }
    } else if (next == 0) {
        arg1->prev->next = next;
    } else {
        arg1->prev->next = next;
        arg1->next->prev = arg1->prev;
    }
    if (arg1 != 0) {
        arg1->vfunc_08(1);
    }
    func_08859C40(arg0->heap, arg1);
}

#pragma optimize_for_size off
u16 func_088C722C(s32 arg0, s32 arg1, u16 arg2) {
    s32 i;

    for (i = 0; i < D_09CE4708[arg1].count; i++) {
        if (D_09CE4708[arg1].keys[i] == arg2) {
            return i;
        }
    }
    return 0xFFFF;
}

#pragma optimize_for_size reset
Area *func_088C7280(Owner *arg0) {
    return arg0->src->vfunc_2C(arg0->unk284);
}

s8 func_088C7298(Owner *arg0) {
    return arg0->src->vfunc_30(arg0->unk284);
}

#pragma optimize_for_size off
Area *func_088C72B0(Owner *arg0, Vec *arg1) {
    Area *a;
    s8 i;
    Vec v1;
    Vec v2;
    f32 dx;
    f32 dz;

    if ((a = func_088C7280(arg0)) == 0) {
        return 0;
    }
    for (i = 0; i < func_088C7298(arg0); i++, a++) {
        if (arg1->y >= a->y && arg1->y < a->y + a->height) {
            switch (a->type) {
            case 0:
                dx = arg1->x - a->x;
                dz = arg1->z - a->z;
                if (dx * dx + dz * dz <= a->radius * a->radius) {
                    return a;
                }
                break;
            case 1:
                v1.x = a->x;
                v1.y = a->y;
                v1.z = a->z;
                v1.w = 0;
                v2.x = a->unk18;
                v2.y = a->unk1C;
                v2.z = a->unk20;
                v2.w = 0;
                if (func_09C36758(arg1, &v1, &v2, a->height, a->radius) != 0) {
                    return a;
                }
                break;
            }
        }
    }
    return 0;
}

}
