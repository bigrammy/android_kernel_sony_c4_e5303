/*****************************************************************************
 *
 * Filename:
 * ---------
 *   S-24CS64A.h
 *
 * Project:
 * --------
 *   ALPS
 *
 * Description:
 * ------------
 *   Header file of CAM_CAL driver
 *
 *
 * Author:
 * -------
 *   Ronnie Lai (MTK01420)
 *
 *============================================================================*/
#ifndef __CAM_CAL_H
#define __CAM_CAL_H

#define CAM_CAL_DEV_MAJOR_NUMBER 226

/* CAM_CAL READ/WRITE ID */
#define imx241OTP_DEVICE_ID							0x6E
#define I2C_UNIT_SIZE                                  1 //in byte
#define OTP_START_ADDR                            0x0000
#define OTP_SIZE                                      24


#endif /* __CAM_CAL_H */

