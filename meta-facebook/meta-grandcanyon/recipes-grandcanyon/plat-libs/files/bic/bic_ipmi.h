/*
 *
 * Copyright 2020-present Facebook. All Rights Reserved.
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __BIC_IPMI_H__
#define __BIC_IPMI_H__

#include "bic_xfer.h"

#ifdef __cplusplus
extern "C" {
#endif

// command for INF VR
#define CMD_INF_VR_SET_PAGE       0x00
#define CMD_INF_VR_READ_DATA_LOW  0x42
#define CMD_INF_VR_READ_DATA_HIGH 0x43
// command for ISL VR
#define CMD_ISL_VR_DEVICE_ID      0xAD
#define CMD_ISL_VR_DMAFIX         0xC5
#define CMD_ISL_VR_DMAADDR        0xC7
#define ISL_MFR_CODE              "49"
// command for TI VR
#define CMD_TI_VR_NVM_CHECKSUM    0xF0

#define MAX_IPMB_BUFFER           256


int bic_get_fw_ver(uint8_t slot_id, uint8_t comp, uint8_t *ver);
int bic_me_recovery(uint8_t command);
int bic_get_vr_device_id(uint8_t *rbuf, uint8_t *rlen, uint8_t bus, uint8_t addr);
int bic_get_ifx_vr_remaining_writes(uint8_t bus, uint8_t addr, uint8_t *writes);
int bic_get_isl_vr_remaining_writes(uint8_t bus, uint8_t addr, uint8_t *writes);
int bic_get_vr_ver(uint8_t bus, uint8_t addr, char *key, char *ver_str);
int bic_get_vr_ver_cache(uint8_t bus, uint8_t addr, char *ver_str);
int bic_switch_mux_for_bios_spi(uint8_t mux);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* __BIC_IPMI_H__ */