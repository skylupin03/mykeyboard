/*
 * @Author: lalalademaxiya1 2831039915@qq.com
 * @Date: 2022-08-23 23:29:21
 * @LastEditors: lalalademaxiya1 2831039915@qq.com
 * @LastEditTime: 2022-08-27 11:00:26
 * @FilePath: /qmk_firmware/keyboards/keychron/q10/q10_ansi_stm32l432_ec11/q10_ansi_stm32l432_ec11.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

#define XXX KC_NO

// clang-format off

#define LAYOUT_ansi_89( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E,      K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E,      K1F, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E,      K2F, \
    K30, K31, K32, K33, K34, K35, K36, K38, K39, K3A, K3B, K3C, K3D,      K3E,      K3F, \
    K40, K41,      K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E, K4F,      \
    K50, K51, K52,      K53, K54, K57,           K58,      K59,           K5D, K5E, K5F  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F }, \
    { K30, K31, K32, K33, K34, K35, K36, XXX, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F }, \
    { K40, K41, XXX, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E, K4F }, \
    { K50, K51, K52, K53, K54, XXX, XXX, K57, K58, K59, XXX, XXX, XXX, K5D, K5E, K5F }  \
}
