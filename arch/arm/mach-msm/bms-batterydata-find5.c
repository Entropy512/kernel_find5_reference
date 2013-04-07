/* Copyright (c) 2011-2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/mfd/pm8xxx/batterydata-lib.h>

static struct single_row_lut fcc_temp = {
	.x		= {-20, 0, 25, 40, 60},
	.y		= {2530, 2531, 2509, 2457, 2512},
	.cols	= 5
};

static struct single_row_lut fcc_sf = {
	.x		= {0},
	.y		= {100},
	.cols	= 1
};

static struct sf_lut rbatt_sf = { 
        .rows           = 28, 
        .cols           = 5,
        /* row_entries are temperature */
        .row_entries            = {-20, 0, 25, 40, 60},
        .percent        = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        .sf                     = {
			{991,260,100,101,102},
			{936,268,104,105,92},
			{905,273,107,107,100},
			{872,282,111,109,96},
			{868,289,117,111,97},
			{874,278,120,111,98},
			{883,279,124,110,99},
			{894,283,121,107,98},
			{912,288,176,104,92},
			{935,298,128,105,92},
			{963,314,132,108,94},
			{1000,337,136,110,96},
			{1036,364,141,114,97},
			{1085,392,147,115,96},
			{1141,421,152,117,95},
			{1206,449,153,115,96},
			{1298,485,156,119,95},
			{1694,556,177,126,101},
			{1220,530,168,121,101},
			{1279,551,169,122,101},
			{1428,575,169,124,101},
			{1604,605,170,129,101},
			{1821,633,175,133,101},
			{2132,664,180,134,102},
			{2569,695,189,138,105},
			{3255,729,204,146,109},
			{4528,766,244,154,112},
			{10131,1591,478,419,131},

		}
};

static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4330, 4329, 4303, 4281, 4301},
				{4233, 4251, 4237, 4219, 4239},
				{4161, 4189, 4181, 4164, 4183},
				{4100, 4132, 4127, 4113, 4129},
				{4027, 4082, 4077, 4063, 4078},
				{3968, 4028, 4027, 4017, 4030},
				{3924, 3968, 3981, 3975, 3986},
				{3886, 3923, 3944, 3938, 3946},
				{3855, 3882, 3897, 3896, 3909},
				{3829, 3848, 3855, 3853, 3860},
				{3807, 3821, 3827, 3825, 3830},
				{3789, 3801, 3805, 3803, 3807},
				{3774, 3787, 3789, 3786, 3789},
				{3760, 3775, 3776, 3773, 3774},
				{3746, 3764, 3767, 3762, 3755},
				{3732, 3750, 3754, 3747, 3735},
				{3715, 3729, 3729, 3721, 3711},
				{3690, 3704, 3695, 3687, 3673},
				{3656, 3683, 3678, 3669, 3661},
				{3646, 3678, 3675, 3662, 3659},
				{3634, 3672, 3671, 3654, 3656},
				{3621, 3663, 3662, 3644, 3645},
				{3602, 3648, 3639, 3626, 3616},
				{3577, 3620, 3597, 3594, 3574},
				{3544, 3576, 3542, 3544, 3525},
				{3493, 3515, 3473, 3485, 3464},
				{3419, 3429, 3391, 3409, 3381},
				{3292, 3299, 3271, 3295, 3251},
				{3000, 3000, 3000, 3000, 3000}
	}
};


struct pm8921_bms_battery_data OPPO_palladium_2500mAh_data = {
	.fcc				= 2500,
	.fcc_temp_lut		= &fcc_temp,
	.fcc_sf_lut			= &fcc_sf,
	.pc_temp_ocv_lut	= &pc_temp_ocv,
	.rbatt_sf_lut		= &rbatt_sf,
	.default_rbatt_mohm		=184,
	/*
	 * jb_2.5 branch added an rbatt_capacitive_mohm member
	 * May need to add a value for that here, but leave
	 * it unset for now
	 */
};
