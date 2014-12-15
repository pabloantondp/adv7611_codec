/*
 * Copyright (C) 2014 Vodalys
 * Author: Pablo Anton <pabloantondp@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ADV7611_H_
#define ADV7611_H_

#ifdef ADV7611_DRV_DEBUG
#define TDEBUG(msg, args...) printk(KERN_INFO "ADV7611_DRV: %s(%i, %s) - " msg "\n",\
		__func__, current->pid, current->comm, ## args)
#else
#define TDEBUG(msg, args...)
#endif


/* ADV7611 I2C ADDRESS FOR VODABOX V3
// TODO Define in other file*/
#define I2C_ADDRESS1					0x4C;
#define I2C_ADDRESS2					0x4D;

/* Global Control Register */
#define ADV7611_RD_INFO					0xEA

/**
 * IO Registers
 */
#define ADV7611_VIDEO STANDARD			0x00	// RW
#define ADV7611_PRIMARY MODE			0x01	// RW
#define ADV7611_IO_REG_02				0x02	// RW
#define ADV7611_IO_REG_03				0x03	// RW
#define ADV7611_IO_REG_04				0x04	// RW
#define ADV7611_IO_REG_05				0x05	// RW
#define ADV7611_IO_REG_06				0x06	// RW
#define ADV7611_PDN						0x0B	// RW
#define ADV7611_IO_REG_0C				0x0C	// RW

#define ADV7611_HDMI_EDG_RAW_STATUS_2	0x7E	// RO
#define ADV7611_HDMI_EDG_RAW_STATUS_3	0x83	// RO
/*
 * HDMI Registers
 */
#define ADV7611_HDMI_REGISTER_00		0x00	// RW
#define ADV7611_HDMI_REGISTER_01		0x01	// RW
#define ADV7611_HDMI_REGISTER_03		0x03	// RW
#define ADV7611_HDMI_REGISTER_04		0x04	// RO
#define ADV7611_HDMI_REGISTER_05		0x05	// RO
#define ADV7611_LINE WIDTH_1			0x07	// RO
#define ADV7611_LINE WIDTH_2			0x08	// RO
#define ADV7611_FIELD0 HEIGHT_1			0x09	// RO
#define ADV7611_FIELD0 HEIGHT_2			0x0A	// RO
#define ADV7611_FIELD1 HEIGHT_1			0x0B	// RO
#define ADV7611_FIELD1 HEIGHT_2			0x0C	// RO
#define ADV7611_HDMI_REGISTER_0D		0x0D	// RW
#define ADV7611_AUDIO MUTE_SPEED		0X0F	// RW
#define ADV7611_HDMI_REGISTER_10		0x10	// RW
#define ADV7611_AUDIO_FIFO_ALM_OST_FULL_THRES_HOLD		0x11	// RW
#define ADV7611_AUDIO_FIFO_ALM_OST_EMPTY_THRE_SHOLD		0x12	// RW
#define ADV7611_AUDIO_COAST_MASK		0x13	// RW
#define ADV7611_MUTE_MASK_21_16			0x14	// RW
#define ADV7611_MUTE_MASK_15_8			0x15	// RW
#define ADV7611_MUTE_MASK_7_0			0x16	// RW
#define ADV7611_PACKETS_DETECTED_2		0x18	// RO
#define ADV7611_PACKETS_DETECTED_3		0x19	// RO
#define ADV7611_MUTE_CTRL				0x1A	// RW
#define ADV7611_DEEPCOLOR_FIFO_DEBUG_1	0x1B	// RW
#define ADV7611_DEEPCOLOR_FIFO_DEBUG_2	0x1C	// RO
#define ADV7611_REGISTER_1DH			0x1D	// RW
#define ADV7611_TOTAL_LINE_WIDTH_1		0x1E	// RO
#define ADV7611_TOTAL_LINE_WIDTH_2		0x1F	// RO
#define ADV7611_HSYNC_FRONT_PORCH_1		0x20	// RO
#define ADV7611_HSYNC_FRONT_PORCH_2		0x21	// RO
#define ADV7611_HSYNC_PULSE_WIDTH_1		0x22	// RO
#define ADV7611_HSYNC_PULSE_WIDTH_2		0x23	// RO
#define ADV7611_HSYNC_BACK_PORCH_1		0x24	// RO
#define ADV7611_HSYNC_BACK_PORCH_2		0x25	// RO
#define ADV7611_FIELD0_TOTAL_HEIGHT_1	0x26	// RO
#define ADV7611_FIELD0_TOTAL_HEIGHT_2	0x27	// RO
#define ADV7611_FIELD1_TOTAL_HEIGHT_1	0x28	// RO
#define ADV7611_FIELD1_TOTAL_HEIGHT_2	0x29	// RO
#define ADV7611_FIELD0_VS_FRONT_PORCH_1	0x2A	// RO
#define ADV7611_FIELD0_VS_FRONT_PORCH_2	0x2B	// RO
#define ADV7611_FIELD1_VS_FRONT_PORCH_1	0x2C	// RO
#define ADV7611_FIELD1_VS_FRONT_PORCH_2	0x2D	// RO
#define ADV7611_FIELD0_VS_PULSE_WIDTH_1	0x2E	// RO
#define ADV7611_FIELD0_VS_PULSE_WIDTH_2	0x2F	// RO
#define ADV7611_FIELD1_VS_PULSE_WIDTH_1	0x30	// RO
#define ADV7611_FIELD1_VS_PULSE_WIDTH_2	0x31	// RO
#define ADV7611_FIELD0_VS_BACK_PORCH_1	0x32	// RO
#define ADV7611_FIELD0_VS_BACK_PORCH_2	0x33	// RO
#define ADV7611_FIELD1_VS_BACK_PORCH_1	0x34	// RO
#define ADV7611_FIELD1_VS_BACK_PORCH_2	0x35	// RO
#define ADV7611_CHANNEL STATUS_DATA_1	0x36	// RO
#define ADV7611_CHANNEL STATUS_DATA_2	0x37	// RO
#define ADV7611_CHANNEL STATUS_DATA_3	0x38	// RO
#define ADV7611_CHANNEL STATUS_DATA_4	0x39	// RO
#define ADV7611_CHANNEL STATUS_DATA_5	0x3A	// RO
#define ADV7611_REGISTER_3CH			0x3C	// RW
#define ADV7611_REGISTER_40H			0x40	// RW
#define ADV7611_REGISTER_41H			0x41	// RW
#define ADV7611_REGISTER_47H			0x47	// RW
#define ADV7611_REGISTER_48H			0x48	// RW
#define ADV7611_REGISTER_4CH			0x4C	// RW
#define ADV7611_HDMI_REGISTER_50		0x50	// RW
#define ADV7611_TMDSFREQ_8_1			0x51	// RO
#define ADV7611_TMDSFREQ_FRAC			0x52	// RO
#define ADV7611_HDMI_COLORSPACE			0x53	// RO
#define ADV7611_FILT_5V_DET_REG			0x56	// RW
#define ADV7611_REGISTER_5AH			0x5A	// SC
#define ADV7611_CTS_N_1					0x5B	// RO
#define ADV7611_CTS_N_2					0x5C	// RO
#define ADV7611_CTS_N_3					0x5D	// RO
#define ADV7611_CTS_N_4					0x5E	// RO
#define ADV7611_CTS_N_5					0x5F	// RO
#define ADV7611_HPA_DELAY_SEL_3_0		0x6C	// RW
#define ADV7611_DSD_MAP_ROT_2_0			0x6D	// RW
#define ADV7611_DDC PAD					0x73	// RW
#define ADV7611_HDMI_REGISTER_02		0x83	// RW
#define ADV7611_EQ DYNAMIC_FREQ			0x8C	// RW
#define ADV7611_EQ_DYN1_LF				0x8D	// RW
#define ADV7611_EQ_DYN1_HF				0x8E	// RW
#define ADV7611_EQ_DYN2_LF				0x90	// RW
#define ADV7611_EQ_DYN2_HF				0x91	// RW
#define ADV7611_EQ_DYN3_LF				0x93	// RW
#define ADV7611_EQ_DYN3_HF				0x94	// RW
#define ADV7611_EQ DYNAMIC_ENABLE		0x96	// RW

/**
 * IO Fields Definitions
 */
// Power-Down controls
#define ADV7611_POWER_DOWN_MASK			0x20	// 0 - Chip is operational , 1 - Enables chip power down
#define ADV7611_POWER_DOWN_SHIFT		5
#define ADV7611_POWER_DOWN_WIDTH		1

#define ADV7611_CP_PWRDN_MASK			0x04	// 0 - Powers-up CP(component processor) core clock
#define ADV7611_CP_PWRDN_SHIFT			2
#define ADV7611_CP_PWRDN_WIDTH			1

#define ADV7611_PWR_SAVE_MODE_MASK		0x08	// 0 - Disables power save mode , 1 - Enables
#define ADV7611_PWR_SAVE_MODE_SHIFT		3
#define ADV7611_PWR_SAVE_MODE_WIDTH		1
#define ADV7611_PWR_SAVE_MODE_ENABLE	1
#define ADV7611_PWR_SAVE_MODE_DISABLE	0

/*
 * HDMI Field Definitions.
 */
#define ADV7611_HDCP_A0_MASK			0x80	// RW - 0 - I2C address for HDCP port is 0x74, 1 - 0x76

// HDMI Port select
#define ADV7611_HDMI_PORT_SELECT_MASK	0x07	// RW - 000 - Port A
#define ADV7611_HDMI_PORT_SELECT_SHIFT	0
#define ADV7611_HDMI_PORT_SELECT_WIDTH	3
#define ADV7611_HDMI_PORT_SELECT_A		0x00

// DSD (Direct-Stream Digital) output
#define ADV7611_MUX_DSD_OUT_MASK		0x10	// RW - 0 - Override by outputting I2S data , 1 - Override by outputting DSD/DST data
#define ADV7611_MUX_DSD_OUT_SHIFT		4
#define ADV7611_MUX_DSD_OUT_WIDTH		1

// Audio PLL Locked
#define ADV7611_AUDIO_PLL_LOCKED		0X01	// RO

// Audio FIFO Control- IO Register HDMI_EDG_RAW_STATUS_2/3
#define ADV7611_FIFO_UNDERFLO_RAW		0x20	// RO - 0 - Audio FIFO has not underflowed , 1 - underflowed.
#define ADV7611_FIFO_OVERFLO_RAW		0x40	// RO - 0 - Audio FIFO has not overflowed , 1 - overflowed
#define ADV7611_FIFO_NEAR_OVFL_RAW		0x80	// RO - 0 - Audio FIFO has not reached high threshold , 1 - reached high threshold
#define ADV7611_FIFO_NEAR_UFLO_RAW		0X01	// RO - 0 - Audio FIFO has not reached low threshold , 1 - reached low threshold

// Audio FIFO Configurable - HDMI Registers
#define ADV7611_AUDIO_FIFO_ALMOST_EMPTY_THRESHOLD_MASK	0x7F 	// RW - Sets the threshold used for FIFO_NEAR_UFLO_RAW
#define ADV7611_AUDIO_FIFO_ALMOST_EMPTY_THRESHOLD_SHIFT	0
#define ADV7611_AUDIO_FIFO_ALMOST_EMPTY_THRESHOLD_WIDTH	7
#define ADV7611_AUDIO_FIFO_ALMOST_FULL_THRESHOLD		0x7F
#define ADV7611_AUDIO_FIFO_ALMOST_FULL_THRESHOLD		0
#define ADV7611_AUDIO_FIFO_ALMOST_FULL_THRESHOLD		7

#define AUDIO_FIFO_OVERFLO_CLR
#define FIFO_NEAR_UFLO_ST


#endif /* ADV7611_H_ */
