#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "dolphin.h"
#include "game/process.h"
#include "game/hu3d.h"
#include "game/mgdata.h"

#define DLL(name) DLL_##name,

typedef enum omOvl_e {
    DLL_NONE = -1,
    #include "ovl_table.h"
    DLL_MAX
} OMOVL;

#undef DLL

#define OM_STAT_DELETED (1 << 0)
#define OM_STAT_DISABLED (1 << 1)
#define OM_STAT_ACTIVE (1 << 2)
#define OM_STAT_PAUSED (1 << 4)
#define OM_STAT_NOPAUSE (1 << 5)
#define OM_STAT_SPRPAUSE (1 << 7)
#define OM_STAT_MODELPAUSE (1 << 8)

#define OM_GRP_NONE -1

typedef HUPROCESS OMOBJMAN;
typedef struct omObj_s OMOBJ;
typedef void (*OMOBJFUNC)(OMOBJ *obj);

#define OM_GRP_MAX 10
#define OM_OBJ_NONE -1

typedef struct omObjGrp_s {
    u16 memberNo;
    u16 objMax;
    u16 objNum;
    u16 *memberNext;
    OMOBJ **memberList;
} OMOBJGRP;

typedef struct omObjWork_s {
    s16 objMax;
    s16 objIdx;
    s16 objNext;
    s16 objLast;
    s16 objFirst;
    OMOBJ *objData;
    OMOBJGRP *grpData;
} OMOBJWORK;

struct omObj_s {
    u16 stat;
    s16 objNext;
    s16 prio;
    s16 prev;
    s16 next;
    s16 nextNo;
    s16 grpNo;
    u16 memberNo;
    u32 mode;
    OMOBJFUNC objFunc;
    Vec trans;
    Vec rot;
    Vec scale;
    u16 mdlcnt;
    HU3DMODELID *mdlId;
    u16 mtncnt;
    HU3DMOTID *mtnId;
    u32 work[4];
    void *data;
};

typedef struct omOvlHis_s {
    OMOVL ovl;
    s32 evtno;
    s32 stat;
} OMOVLHIS;

typedef struct ovlTbl_s {
    char *name;
    s32 entryNum;
} OVLTBL;

typedef struct omCameraView_s {
    HuVecF center;
    HuVecF rot;
    float zoom;
} OMCAMERAVIEW;

#define omOvlCall(ovl, evtno, stat) omOvlCallEx(ovl, TRUE, evtno, stat)
#define omOvlGoto(ovl, evtno, stat) omOvlGotoEx(ovl, TRUE, evtno, stat)
#define omOvlReturn(hisOfs) omOvlReturnEx(hisOfs, TRUE)
#define omAddObj(objman, prio, mdlcnt, mtncnt, objFunc) omAddObjEx(objman, prio, mdlcnt, mtncnt, OM_GRP_NONE, objFunc)
#define omDelObj omDelObjEx
#define omMakeGroup omMakeGroupEx
#define omGetGroupMemberList omGetGroupMemberListEx

#define omObjGetWork(obj, type) ((type *)(&((obj)->work[0])))
#define omObjGetDataAs(obj, type) ((type *)((obj)->data))

#define OM_CAMERA_SINGLE 0x10000

#define OM_CAMERAMOVE_SIMPLE 0
#define OM_CAMERAMOVE_COS 1
#define OM_CAMERAMOVE_LINEAR 2
#define OM_CAMERAMOVE_COSSIN 2

void omOvlCallEx(OMOVL ovl, s16 unlinkF, s32 evtno, s32 stat);
void omOvlGotoEx(OMOVL ovl, s16 unlinkF, s32 evtno, s32 stat);
void omOvlReturnEx(s16 hisOfs, s16 unlinkF);
void omOvlKill(s16 unlinkF);
void omOvlHisChg(s32 hisOfs, OMOVL ovl, s32 evtno, s32 stat);
OMOVLHIS *omOvlHisGet(s32 hisOfs);
OMOBJMAN *omInitObjMan(s16 objMax, s32 objManPrio);
OMOBJ *omAddObjEx(OMOBJMAN *objMan, s16 prio, u16 mdlcnt, u16 mtncnt, s16 grpNo, OMOBJFUNC objFunc);
void omAddMember(OMOBJMAN *objMan, u16 grpNo, OMOBJ *obj);
void omDelObjEx(OMOBJMAN *objMan, OMOBJ *obj);
void omDelMember(OMOBJMAN *objMan, OMOBJ *obj);
void omMakeGroupEx(OMOBJMAN *objMan, u16 grpNo, u16 objMax);
OMOBJ **omGetGroupMemberListEx(OMOBJMAN *objMan, s16 grpNo);
void omSetStatBit(OMOBJ *obj, u16 bit);
void omResetStatBit(OMOBJ *obj, u16 bit);

void omSetTra(OMOBJ *obj, float x, float y, float z);
void omSetRot(OMOBJ *obj, float x, float y, float z);
void omSetSca(OMOBJ *obj, float x, float y, float z);

void omAllPause(BOOL pauseF);
char omPauseChk(void);
OMOVL omCurrentOvlGet(void);

void omOutView(OMOBJ *obj);
void omOutViewMulti(OMOBJ *obj);
void omDBGSystemKeyCheckSetup(OMOBJMAN *objman);
void omSystemKeyCheckSetup(OMOBJMAN *objman);
void omSystemKeyCheck(OMOBJ *obj);
void omSysPauseEnable(u8 flag);
void omSysPauseCtrl(s16 flag);
void omCameraViewInit(void);
void omCameraViewSetMulti(s16 cameraBit, OMCAMERAVIEW *cameraView);
void omCameraViewSet(OMCAMERAVIEW *cameraView);
s16 omCameraViewMoveMulti(u32 camera, OMCAMERAVIEW *cameraView, s32 time, s16 moveType);
s16 omCameraViewMove(OMCAMERAVIEW *cameraView, s32 time, s16 moveType);
s16 omCameraViewMoveSimpleMulti(u32 camera, OMCAMERAVIEW *cameraView, s32 time);
s16 omCameraViewMoveSimple(OMCAMERAVIEW *cameraView, s32 time);
BOOL omCameraViewCheck(u32 cameraBit);

void omGameSysInit(OMOBJMAN *objman);
void omVibrate(s16 playerNo, s16 duration, s16 off, s16 on);

extern s16 omSysExitReq;
extern OMOBJ *omDBGSysKeyObj;
extern u8 omSysPauseEnableFlag;
extern OMOVL omcurovl;
extern s32 omcurdll;
extern s32 omovlhisidx;
extern s32 omovlevtno;
extern s32 omovlstat;
extern u8 omUPauseFlag;
extern s16 omdispinfo;
extern float CZoomM[HU3D_CAM_MAX];
extern HuVecF CenterM[HU3D_CAM_MAX];
extern HuVecF CRotM[HU3D_CAM_MAX];
extern float CZoom;
extern HuVecF Center;
extern HuVecF CRot;


#endif