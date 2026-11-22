/* unit_08898980: 0x08898980-0x0889942C (ULES01213)
 *
 * Bounds (hypothesis): 1 function. C++ unit: the member copy at the end is
 * the implicit copy assignment of Member (sub-structures block-copied by
 * their alignment, arrays element by element), and the flag tests need
 * `bool`. Field names are placeholders; only offsets and sizes come from the
 * code. The 2 bytes at Member+0x1E are not copied (unnamed bit-field).
 * Each loop has its own counter and flag: their declaration order sets the
 * registers.
 */
#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct MemberId {
    u8 mac[6];
    u8 pad6[2];
} MemberId;

typedef struct MemberInfo {
    s16 unk0[11];
} MemberInfo;

typedef struct MemberState {
    s16 unk0[0x4C];
    u8 host[6];
    u8 unkBE;
    u8 unkBF;
    s16 unkC0[2];
} MemberState;

typedef struct Member {
    MemberId id;
    MemberInfo info;
    s16 : 16;
    MemberState st;
    u8 unkC4;
    u8 unkC5;
    u8 unkC6[2];
} Member;

extern "C" {
extern char *D_089CC434;
extern char *D_089CC438;
extern char *D_08A631A0;
extern s32 D_08A62D8C;
extern char *D_09A0B544;

extern u8 *func_0889C518(char *);
extern s32 func_0880BFF0(void *, void *, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0889CF34(char *, u8);
extern void func_0889D6EC(char *);
extern s32 func_088AE894(void);
extern void func_0889E508(char *);
extern void func_0889E6A4(char *);
extern s32 sceWlanGetSwitchState(void);

typedef struct Session {
    u8 pad0[0x57C];
    Member members[4];
    Member old[4];
} Session;

#define MEMBERS(s) (((Session *)(s))->members)
#define OLD(s) (((Session *)(s))->old)

static inline s32 cmp6(u8 *a, u8 *b) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (a[i] < b[i]) {
            return -1;
        }
        if (a[i] > b[i]) {
            return 1;
        }
    }
    return 0;
}

static inline Member *get_member(char *s, u8 i) {
    return &MEMBERS(s)[i];
}

static inline Member *find_member(char *s, u8 *mac) {
    s32 i;
    for (i = 0; i < *(s8 *)(s + 0xEE3); i++) {
        if (cmp6(mac, MEMBERS(s)[i].id.mac) == 0) {
            return &MEMBERS(s)[i];
        }
    }
    return 0;
}

static inline Member *find_host(char *s) {
    Member *me;
    s32 i;

    me = find_member(s, func_0889C518(s));
    if (me == 0) {
        return 0;
    }
    for (i = 0; i < *(s8 *)(s + 0xEE3); i++) {
        Member *m = get_member(s, i);
        if (func_0880BFF0(me->st.host, m, 6) == 0) {
            return m;
        }
    }
    return 0;
}

static inline bool flag8(void) {
    return (bool)(*(s32 *)(D_089CC438 + 0x6AF14) & 8);
}

void func_08898980(char *s) {
    s32 i1;
    s32 i2;
    s32 i3;
    bool ok1;
    bool ok2;
    bool ok3;
    s32 j1;
    s32 j2;
    s32 j3;

    if (*(u8 *)(s + 4) == 0) {
        return;
    }
    if ((u32)(*(u8 *)(s + 0x12D5) - 1) < 4) {
        if (*(u8 *)(s + 0x12D4) != 0) {
            if (*(s32 *)(s + 0x12D0) < 0) {
                *(s32 *)(s + 0x12D0) = 60;
                func_0889CF34(s, *(u8 *)(s + 0x12D5));
                func_0889D6EC(s);
            } else if (*(s32 *)(s + 0x12D0) > 60) {
                *(s32 *)(s + 0x12D0) = 60;
            } else {
                *(s32 *)(s + 0x12D0) = *(s32 *)(s + 0x12D0) - 1;
            }
        }
    }
    if ((u32)(*(u8 *)(s + 0x12D5) - 3) < 2) {
        for (i1 = 0; i1 < *(s8 *)(s + 0xEE3); i1++) {
            Session *e = (Session *)(s + i1 * 0xC8);
            if (flag8() == 0) {
                if (cmp6(e->members[0].id.mac, func_0889C518(s)) == 0) {
                    continue;
                }
                if (e->members[0].st.unkBE != 0) {
                    continue;
                }
                if (e->members[0].st.unkBF != 4) {
                    continue;
                }
                if (find_host(s) == 0) {
                    continue;
                }
                if (func_0880BFF0(find_host(s), e->members[0].st.host, 6) != 0) {
                    continue;
                }
                ok1 = 1;
                for (j1 = 0; j1 < *(s8 *)(s + 0xEE4); j1++) {
                    Session *f = (Session *)(s + j1 * 0xC8);
                    if (cmp6(e->members[0].id.mac, f->old[0].id.mac) == 0 && f->old[0].st.unkBF == 4) {
                        ok1 = 0;
                        break;
                    }
                }
                if (ok1) {
                    func_08883988(D_08A62D8C, 3, 0x1E, 0, 0, 0, 0, 0, 0);
                    break;
                }
            } else {
                if (cmp6(e->members[0].id.mac, func_0889C518(s)) == 0) {
                    continue;
                }
                if (e->members[0].st.unkBF != 4) {
                    continue;
                }
                if (find_host(s) == 0) {
                    continue;
                }
                if (func_0880BFF0(find_host(s), e->members[0].st.host, 6) != 0) {
                    continue;
                }
                ok2 = 1;
                for (j2 = 0; j2 < *(s8 *)(s + 0xEE4); j2++) {
                    Session *f = (Session *)(s + j2 * 0xC8);
                    if (cmp6(e->members[0].id.mac, f->old[0].id.mac) == 0 && f->old[0].st.unkBF == 4) {
                        ok2 = 0;
                        break;
                    }
                }
                if (ok2) {
                    func_08883988(D_08A62D8C, 3, 0x1E, 0, 0, 0, 0, 0, 0);
                    break;
                }
            }
        }
        for (i2 = 0; i2 < *(s8 *)(s + 0xEE4); i2++) {
            Session *e = (Session *)(s + i2 * 0xC8);
            if (cmp6(e->old[0].id.mac, func_0889C518(s)) == 0) {
                continue;
            }
            if (e->old[0].st.unkBE != 0) {
                continue;
            }
            if (e->old[0].st.unkBF != 4) {
                continue;
            }
            ok3 = 1;
            for (j3 = 0; j3 < *(s8 *)(s + 0xEE3); j3++) {
                Session *f = (Session *)(s + j3 * 0xC8);
                if (cmp6(e->old[0].id.mac, f->members[0].id.mac) == 0 && f->members[0].st.unkBF >= 4) {
                    ok3 = 0;
                    break;
                }
            }
            if (ok3) {
                break;
            }
        }
    }
    *(s8 *)(s + 0xEE4) = *(s8 *)(s + 0xEE3);
    for (i3 = 0; i3 < 4; i3++) {
        OLD(s)[i3] = MEMBERS(s)[i3];
    }
    func_088AE894();
    if (*(u8 *)(s + 0x1B00) != 0) {
        func_0889E508(s + 0x1B00);
    }
    if (*(u8 *)(s + 0x1B28) != 0) {
        func_0889E6A4(s + 0x1B28);
    }
    if (*(u8 *)(s + 0x1B48) != 0) {
        func_0889E6A4(s + 0x1B48);
    }
    if ((bool)(*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) {
        if (*(u8 *)(D_089CC434 + 0x2930C) != 0) {
            if (sceWlanGetSwitchState() != 1) {
                *(u8 *)(D_09A0B544 + 0x1AFC) = 1;
            }
        }
    }
}

}
