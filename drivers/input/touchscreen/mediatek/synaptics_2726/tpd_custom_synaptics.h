/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#ifndef TOUCHPANEL_H__
#define TOUCHPANEL_H__

/* Pre-defined definition */
#define TPD_TYPE_CAPACITIVE
#define TPD_POWER_SOURCE	MT6325_POWER_LDO_VGP1         
#define TPD_I2C_BUS		0
#define TPD_I2C_ADDR		0x20
#define TPD_WAKEUP_TRIAL	60
#define TPD_WAKEUP_DELAY	100

 /*[i53M][Zihweishen]  Modify GPIO setting function for android M begin 2016/01/26*/
 //[SM20][zihweishen] Modify for android M of GPIO setting begin 2015/11/11
 //#define GTP_GPIO_AS_INT(pin) tpd_gpio_as_int(pin)
#define GTP_GPIO_AS_INPUT(pin)          do {\
	 if (pin == GPIO_CTP_EINT_PIN)\
		 mt_set_gpio_mode(pin, GPIO_CTP_EINT_PIN_M_GPIO);\
	 else\
		 mt_set_gpio_mode(pin, GPIO_CTP_RST_PIN_M_GPIO);\
	 mt_set_gpio_dir(pin, GPIO_DIR_IN);\
	 mt_set_gpio_pull_enable(pin, GPIO_PULL_DISABLE);\
 } while (0)
 
#define GTP_GPIO_AS_INT(pin)            do {\
	 mt_set_gpio_mode(pin, GPIO_CTP_EINT_PIN_M_EINT);\
	 mt_set_gpio_dir(pin, GPIO_DIR_IN);\
	 mt_set_gpio_pull_enable(pin, GPIO_PULL_DISABLE);\
 } while (0)
 
 //#define GTP_GPIO_OUTPUT(pin, level) tpd_gpio_output(pin, level)
#define GTP_GPIO_OUTPUT(pin, level)      do {\
	 if (pin == GPIO_CTP_EINT_PIN)\
		 mt_set_gpio_mode(pin, GPIO_CTP_EINT_PIN_M_GPIO);\
	 else\
		 mt_set_gpio_mode(pin, GPIO_CTP_RST_PIN_M_GPIO);\
	 mt_set_gpio_dir(pin, GPIO_DIR_OUT);\
	 mt_set_gpio_out(pin, level);\
 } while (0)

 //[SM20][zihweishen] Modify for android M of GPIO setting end 2015/11/11
 /*[i53M][Zihweishen] end 2016/01/26*/

//#define TPD_HAVE_TREMBLE_ELIMINATION

/* Define the virtual button mapping */
//#define TPD_HAVE_BUTTON
#define TPD_BUTTON_HEIGH        (100)
#define TPD_KEY_COUNT           3
#define TPD_KEYS                { KEY_MENU, KEY_HOMEPAGE,KEY_BACK}
#define TPD_KEYS_DIM            {{80,850,160,TPD_BUTTON_HEIGH},{240,850,160,TPD_BUTTON_HEIGH},{400,850,160,TPD_BUTTON_HEIGH}}

/* Define the touch dimension */
#ifdef TPD_HAVE_BUTTON
#define TPD_TOUCH_HEIGH_RATIO	80
#define TPD_DISPLAY_HEIGH_RATIO	73
#endif

/* Define the 0D button mapping */
#ifdef TPD_HAVE_BUTTON
#define TPD_0D_BUTTON		{}
#else
#define TPD_0D_BUTTON		{KEY_MENU, KEY_HOMEPAGE, KEY_BACK, KEY_SEARCH}
#endif

#endif /* TOUCHPANEL_H__ */

