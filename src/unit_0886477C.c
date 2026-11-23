/* unit_0886477C: 0x0886477C-0x08865044 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * try_unit.py scores 99.81 % only because the split piece has no %hi/%lo
 * relocations for the spilled `lui` of D_089CC000; the linked bytes are
 * identical (BOOT.BIN checksum).
 */

/* func_0886477C: writes the GE commands of one model group (materials, textures, bone matrices, calls). */

#pragma optimize_for_size off
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Mat {
    u8 unk0[16];
} Mat;

typedef struct Part {
    char *unk0;
    s32 unk4;
    Mat *unk8;
} Part;

typedef struct Sub {
    s8 unk0;
    s8 unk1;
    u16 unk2;
    s32 unk4;
    u8 unk8[8];
} Sub;

extern u32 *D_089CC000;
extern char *func_0886272C(char *, s32);
extern char *func_08862E54(void *, s32);
extern void func_08862E64(char *);
extern s32 func_08862748(char *, s32);
extern u8 *func_08862768(char *, s32, s32);
extern char *func_088627B4(char *, s32, s32);

void func_0886477C(Part *arg0, char *arg1, char *arg2, s32 arg3) {
    char *bones;
    char *entry;
    u8 *ids;
    s32 prevMat;
    s32 prevTex;
    Sub *sub;
    s32 i;
    char *data;
    s32 m;
    Mat *mat;
    u32 *tex;
    u8 *verts;
    s32 j;
    char *b;
    u32 addr;
    u32 call;

    bones = *(char **)(arg1 + 0x110);
    data = arg0->unk0;
    entry = func_0886272C(data, arg3);
    func_08862E64(func_08862E54(arg0, arg3));
    *D_089CC000 = (*(u32 *)(entry + 0) >> 8) | 0x48000000;
    D_089CC000++;
    *D_089CC000 = (*(u32 *)(entry + 4) >> 8) | 0x49000000;
    D_089CC000++;
    func_08862748(data, arg3);
    ids = func_08862768(data, arg3, 0);
    prevMat = -1;
    prevTex = -1;
    sub = (Sub *)func_088627B4(data, arg3, 0);
    for (i = 0; i < *(u16 *)(entry + 0x14); i++, sub++) {
        m = ids[sub->unk0];
        if (m != prevMat) {
            mat = &arg0->unk8[m];
            if (mat->unk0[3] == 0) {
                continue;
            }
            *D_089CC000 = 0x53000003;
            D_089CC000++;
            *D_089CC000 = (mat->unk0[2] << 16) | 0x56000000 | (mat->unk0[1] << 8) | mat->unk0[0];
            D_089CC000++;
            *D_089CC000 = mat->unk0[3] | 0x58000000;
            D_089CC000++;
            *D_089CC000 = (mat->unk0[6] << 16) | 0x55000000 | (mat->unk0[5] << 8) | mat->unk0[4];
            D_089CC000++;
            if (mat->unk0[8] != 0xFF) {
                if (mat->unk0[8] != prevTex) {
                    tex = (u32 *)(*(char **)(arg2 + 4) + mat->unk0[8] * 32);
                    *D_089CC000 = 0x1E000001;
                    D_089CC000++;
                    *D_089CC000 = 0xC2000001;
                    D_089CC000++;
                    *D_089CC000 = tex[0];
                    D_089CC000++;
                    *D_089CC000 = tex[1];
                    D_089CC000++;
                    *D_089CC000 = tex[2];
                    D_089CC000++;
                    *D_089CC000 = tex[3];
                    D_089CC000++;
                    *D_089CC000 = tex[4];
                    D_089CC000++;
                    *D_089CC000 = tex[5];
                    D_089CC000++;
                    *D_089CC000 = tex[6];
                    D_089CC000++;
                    *D_089CC000 = tex[7];
                    D_089CC000++;
                    *D_089CC000 = 0xCB000000;
                    D_089CC000++;
                    prevTex = mat->unk0[8];
                }
            } else {
                *D_089CC000 = 0x1E000000;
                D_089CC000++;
                prevTex = mat->unk0[8];
            }
            prevMat = m;
        } else {
            *D_089CC000 = 0xFF000000;
            D_089CC000++;
        }
        verts = (u8 *)(data + *(s32 *)(data + 0x2C) + sub->unk2 * 2);
        for (j = 0; j < sub->unk1; j++, verts += 2) {
            b = bones + verts[1] * 0x250;
            *D_089CC000 = (verts[0] * 12) | 0x2A000000;
            D_089CC000++;
            *D_089CC000 = (*(u32 *)(b + 0x50) >> 8) | 0x2B000000;
            D_089CC000++;
            *D_089CC000 = (*(u32 *)(b + 0x54) >> 8) | 0x2B000000;
            D_089CC000++;
            *D_089CC000 = (*(u32 *)(b + 0x58) >> 8) | 0x2B000000;
            D_089CC000++;
            *D_089CC000 = (*(u32 *)(b + 0x60) >> 8) | 0x2B000000;
            D_089CC000++;
            *D_089CC000 = (*(u32 *)(b + 0x64) >> 8) | 0x2B000000;
            D_089CC000++;
            *D_089CC000 = (*(u32 *)(b + 0x68) >> 8) | 0x2B000000;
            D_089CC000++;
            *D_089CC000 = (*(u32 *)(b + 0x70) >> 8) | 0x2B000000;
            D_089CC000++;
            *D_089CC000 = (*(u32 *)(b + 0x74) >> 8) | 0x2B000000;
            D_089CC000++;
            *D_089CC000 = (*(u32 *)(b + 0x78) >> 8) | 0x2B000000;
            D_089CC000++;
            *D_089CC000 = (*(u32 *)(b + 0x80) >> 8) | 0x2B000000;
            D_089CC000++;
            *D_089CC000 = (*(u32 *)(b + 0x84) >> 8) | 0x2B000000;
            D_089CC000++;
            *D_089CC000 = (*(u32 *)(b + 0x88) >> 8) | 0x2B000000;
            D_089CC000++;
        }
        addr = arg0->unk4 + sub->unk4;
        *D_089CC000 = ((addr & 0xFF000000) >> 8) | 0x10000000;
        call = (addr & 0xFFFFFF) | 0x0A000000;
        D_089CC000++;
        *D_089CC000 = 0x13000000;
        D_089CC000++;
        *D_089CC000 = call;
        D_089CC000++;
    }
    *D_089CC000 = 0x27000000;
    D_089CC000++;
}
