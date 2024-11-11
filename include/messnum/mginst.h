#ifndef MESSNUM_MGINST_H
#define MESSNUM_MGINST_H

#include "messdir_enum.h"

#define MGINST_MG_MESS(mgId) \
    MGINST_M##mgId##_1, \
    MGINST_M##mgId##_2, \
    MGINST_M##mgId##_3, \
    MGINST_M##mgId##_4, \
    MGINST_M##mgId##_5

#define MGINST_DECA_MG_MESS(mgId) \
    MGINST_DECA_M##mgId##_1, \
    MGINST_DECA_M##mgId##_2, \
    MGINST_DECA_M##mgId##_3, \
    MGINST_DECA_M##mgId##_4, \
    MGINST_DECA_M##mgId##_5
    
enum {
    MGINST_DUMMY_MESS = MESSNUM(MESS_MGINST, 0)-1,
    MGINST_MG_MESS(501),
    MGINST_MG_MESS(502),
    MGINST_MG_MESS(503),
    MGINST_MG_MESS(504),
    MGINST_MG_MESS(505),
    MGINST_MG_MESS(506),
    MGINST_MG_MESS(507),
    MGINST_MG_MESS(508),
    MGINST_MG_MESS(509),
    MGINST_MG_MESS(510),
    MGINST_MG_MESS(511),
    MGINST_MG_MESS(512),
    MGINST_MG_MESS(513),
    MGINST_MG_MESS(514),
    MGINST_MG_MESS(515),
    MGINST_MG_MESS(516),
    MGINST_MG_MESS(524),
    MGINST_MG_MESS(563),
    MGINST_MG_MESS(564),
    MGINST_MG_MESS(565),
    MGINST_MG_MESS(566),
    MGINST_MG_MESS(576),
    MGINST_MG_MESS(579),
    MGINST_MG_MESS(517),
    MGINST_MG_MESS(518),
    MGINST_MG_MESS(519),
    MGINST_MG_MESS(520),
    MGINST_MG_MESS(522),
    MGINST_MG_MESS(523),
    MGINST_MG_MESS(525),
    MGINST_MG_MESS(567),
    MGINST_MG_MESS(568),
    MGINST_MG_MESS(569),
    MGINST_MG_MESS(570),
    MGINST_MG_MESS(577),
    MGINST_MG_MESS(521),
    MGINST_MG_MESS(526),
    MGINST_MG_MESS(527),
    MGINST_MG_MESS(528),
    MGINST_MG_MESS(529),
    MGINST_MG_MESS(530),
    MGINST_MG_MESS(531),
    MGINST_MG_MESS(532),
    MGINST_MG_MESS(533),
    MGINST_MG_MESS(534),
    MGINST_MG_MESS(574),
    MGINST_MG_MESS(575),
    MGINST_MG_MESS(535),
    MGINST_MG_MESS(536),
    MGINST_MG_MESS(537),
    MGINST_MG_MESS(538),
    MGINST_MG_MESS(539),
    MGINST_MG_MESS(540),
    MGINST_MG_MESS(541),
    MGINST_MG_MESS(542),
    MGINST_MG_MESS(543),
    MGINST_MG_MESS(544),
    MGINST_MG_MESS(545),
    MGINST_MG_MESS(546),
    MGINST_MG_MESS(547),
    MGINST_MG_MESS(548),
    MGINST_MG_MESS(549),
    MGINST_MG_MESS(550),
    MGINST_MG_MESS(551),
    MGINST_MG_MESS(552),
    MGINST_MG_MESS(553),
    MGINST_MG_MESS(554),
    MGINST_MG_MESS(555),
    MGINST_MG_MESS(559),
    MGINST_MG_MESS(560),
    MGINST_MG_MESS(561),
    MGINST_MG_MESS(562),
    MGINST_M562_CTRL2,
    MGINST_MG_MESS(571),
    MGINST_MG_MESS(572),
    MGINST_MG_MESS(573),
    MGINST_MG_MESS(578),
    MGINST_MG_MESS(580),
    MGINST_DECA_NONE,
    MGINST_DECA_MG_MESS(502),
    MGINST_DECA_MG_MESS(504),
    MGINST_DECA_MG_MESS(506),
    MGINST_DECA_MG_MESS(507),
    MGINST_DECA_MG_MESS(510),
    MGINST_DECA_MG_MESS(511),
    MGINST_DECA_MG_MESS(512),
    MGINST_DECA_MG_MESS(513),
    MGINST_DECA_MG_MESS(514),
    MGINST_DECA_MG_MESS(563),
};

#undef MGINST_MG_MESS
#undef MGINST_DECA_MG_MESS

#endif