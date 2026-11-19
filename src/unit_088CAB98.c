/* unit_088CAB98: 0x088CAB98-0x088CACCC (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088CAB98 asm piece, 1 function
 * between unit_088CAB64 and unit_088CACCC.
 *
 * Writes three GE commands to the display list (0xCF, 0xCD, 0xCE) from the
 * two distances and the colour at +0x448 of the object.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Fog {
    f32 near;
    f32 far;
    f32 color;
} Fog;

extern s32 *D_089CC000;
extern s32 D_089CBFFC;
extern f32 *D_08A62C40;
extern s32 func_0884C89C(s32, s32);
extern void func_0884C914(s32);

void func_088CAB98(char *arg0) {
    Fog *fog;
    f32 scale;
    f32 color;
    f32 near;
    f32 far;
    f32 dist;
    f32 inv;

    fog = (Fog *)(arg0 + 0x448);
    if (func_0884C89C(D_089CBFFC, 1) == 0) {
        return;
    }
    color = fog->color;
    scale = *D_08A62C40;
    near = fog->near * scale;
    far = fog->far * scale;
    dist = far - near;
    inv = 1.0f / (dist ? dist : 1.0f);
    *D_089CC000 = 0xCF000000 | (((u8 *)&color)[2] << 16) | (((u8 *)&color)[1] << 8) | ((u8 *)&color)[0];
    D_089CC000++;
    *D_089CC000 = 0xCD000000 | (*(u32 *)&far >> 8);
    D_089CC000++;
    *D_089CC000 = 0xCE000000 | (*(u32 *)&inv >> 8);
    D_089CC000++;
    func_0884C914(D_089CBFFC);
}
