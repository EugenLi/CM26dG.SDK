//Copyright (C) KONICA MINOLTA, INC.  All rights reserved. 2018

#pragma once

//Calibration status
enum CMMISDK_CalStatus : int32_km
{
	StatusZero = 0,		//Zero calibration is required
	StatusWhite,		//White calibration is required
	StatusGloss,		//Gloss calibration is required
	StatusMeasure,		//Measurement is possible
	StatusMeasureWrn,	//Measurement is possible (calibration recommended)
	StatusUser,			//User calibration is required
};

//Data type for Calibration
enum CMMISDK_CalDataType : int32_km
{
	//CM-25cG/CM-3630A
	CALTYPE_MAV = 0,	//MAV
	//CM-25cG
	CALTYPE_SAV,		//SAV
	//CM-3630A
	CALTYPE_LAV,		//LAV

	//CM-26dG/CM-26d/CM-25d/CM-36dG/CM-36d
	CALTYPE_MAV_SCI = 0,//MAV,SCI
	CALTYPE_MAV_SCE,	//MAV,SCE
	CALTYPE_SAV_SCI,	//SAV,SCI
	CALTYPE_SAV_SCE,	//SAV,SCE

	//CM-M6
	CALTYPE_L_ANGLE_M15 = 0,//LEFT -15
	CALTYPE_L_ANGLE_15,		//LEF 15
	CALTYPE_L_ANGLE_25,		//LEF　25
	CALTYPE_L_ANGLE_45,		//LEF　45
	CALTYPE_L_ANGLE_75,		//LEF　75
	CALTYPE_L_ANGLE_110,	//LEF　110
	CALTYPE_R_ANGLE_M15,	//RIGHT　-15
	CALTYPE_R_ANGLE_15,		//RIGHT　15
	CALTYPE_R_ANGLE_25,		//RIGHT　25
	CALTYPE_R_ANGLE_45,		//RIGHT　45
	CALTYPE_R_ANGLE_75,		//RIGHT　75
	CALTYPE_R_ANGLE_110,	//RIGHT　110

	//CM-36dG/CM-36d
	CALTYPE_LAV_SCI = 4,	//LAV・SCI
	CALTYPE_LAV_SCE,		//LAV・SCE
	//CM-36dG
	CALTYPE_LMAV_SCI = 6,	//LMAV・SCI
	CALTYPE_LMAV_SCE,		//LMAV・SCE
	CALTYPE_TRA,			//透過(LAV固定)
};

//Measurement status
enum CMMISDK_MeasStatus : int32_km
{
	Idling = 0,	//Idle state
	Measuring	//Measuring
};

//Data type
enum CMMISDK_DataType : int32_km
{
	DATATYPE_GLOSS = 0,			//CM-25cG/CM-26dG/CM-36dG:GU (1 item)
	DATATYPE_SPEC = 1,			//CM-25cG/CM-3630A(UV condition: Only when number of outputs is 1):spectrum data

	DATATYPE_SCI = 1,			//CM-26dG/CM-26d/CM-25d/CM-23d/CM-36dG/CM-36d:SCI (UV condition: Only when number of outputs is 1)
	DATATYPE_SCE = 2,			//CM-26dG/CM-26d/CM-25d/CM-23d/CM-36dG/CM-36d:SCE (UV condition: Only when number of outputs is 1)
	DATATYPE_BACKWHITE = 3,		//CM-26dG/CM-26d/CM-25d/CM-23d:Opacity back white
	DATATYPE_BACKBLACK = 4,		//CM-26dG/CM-26d/CM-25d/CM-23d:Opacity back black

	DATATYPE_SCI_UVFULL = 10,	//CM-26dG/CM-26d/CM-36dG:SCI (UV100%)
	DATATYPE_SCE_UVFULL = 11,	//CM-26dG/CM-26d/CM-36dG:SCE (UV100%)
	DATATYPE_SCI_UVCUT = 12,	//CM-26dG/CM-26d/CM-36dG:SCI (UV cut)
	DATATYPE_SCE_UVCUT = 13,	//CM-26dG/CM-26d/CM-36dG:SCE (UV cut)
	DATATYPE_SCI_UVADJ = 14,	//CM-26dG/CM-26d/CM-36dG:SCI (UV adjustment)
	DATATYPE_SCE_UVADJ = 15,	//CM-26dG/CM-26d/CM-36dG:SCE (UV adjustment)

	DATATYPE_SPEC_UVFULL = 10,	//CM-3630A:(UV100%)
	DATATYPE_SPEC_UVCUT = 12,	//CM-3630A:(UV cut)
	DATATYPE_SPEC_UVADJ = 14,	//CM-3630A:(UV adjustment)

	DATATYPE_TRA = 16,			//CM-36dG

	DATATYPE_L_ANGLE_M15 = 0,	//CM-M6:LEFT -15
	DATATYPE_L_ANGLE_15,		//CM-M6:LEFT 15
	DATATYPE_L_ANGLE_25,		//CM-M6:LEFT 25
	DATATYPE_L_ANGLE_45,		//CM-M6:LEFT 45
	DATATYPE_L_ANGLE_75,		//CM-M6:LEFT 75
	DATATYPE_L_ANGLE_110,		//CM-M6:LEFT 110
	DATATYPE_R_ANGLE_M15,		//CM-M6:RIGHT -15
	DATATYPE_R_ANGLE_15,		//CM-M6:RIGHT 15
	DATATYPE_R_ANGLE_25,		//CM-M6:RIGHT 25
	DATATYPE_R_ANGLE_45,		//CM-M6:RIGHT 45
	DATATYPE_R_ANGLE_75,		//CM-M6:RIGHT 75
	DATATYPE_R_ANGLE_110,		//CM-M6:RIGHT 110
	DATATYPE_DP_ANGLE_M15,		//CM-M6:DP -15
	DATATYPE_DP_ANGLE_15,		//CM-M6:DP 15
	DATATYPE_DP_ANGLE_25,		//CM-M6:DP 25
	DATATYPE_DP_ANGLE_45,		//CM-M6:DP 45
	DATATYPE_DP_ANGLE_75,		//CM-M6:DP 75
	DATATYPE_DP_ANGLE_110,		//CM-M6:DP 110
};

//Fluorescence adjustment condition
enum CMMISDK_CondUvAdjust : int32_km
{
	UVADJ_PROFILE =	0,	//Profile
	UVADJ_WI,			//WI
	UVADJ_TINT,			//Tint
	UVADJ_WITINT,		//WI&Tint
	UVADJ_BRIGHTNESS,	//ISO Bightness
	UVADJ_GG,			//Ganz&Griesser
	UVADJ_NONE = -1,	//None
};

//Data type for fluorescence coefficient
enum CMMISDK_UvAdjustDataType : int32_km
{
	UVADJ_DATATYPE_SCI = 0,		//SCI
	UVADJ_DATATYPE_SCE,			//SCE
	UVADJ_DATATYPE_NONE = -1,	//None
};

//Measurement type
enum CMMISDK_MeasType : int32_km
{
	MEASTYPE_REF = 0,	//Reflectance
	MEASTYPE_TRA,		//Transparent
	MEASTYPE_NONE = -1,	//None
};

//Measurement area
enum CMMISDK_MeasArea : int32_km
{
	AREA_MAV = 0,	//MAV
	AREA_SAV = 1,	//SAV
	AREA_LAV = 2,	//LAV
	AREA_LMAV = 3,	//LMAV
	AREA_AUTO = 10,	//Mask detection
	AREA_NONE = -1,	//None
	AREA_MOVING = -99,	//Moving
};

//Measurement angle
enum CMMISDK_MeasAngle : int32_km
{
	MEAS_ANGLE_M15 = 0x01,	//-15
	MEAS_ANGLE_15 = 0x02,	//15
	MEAS_ANGLE_25 = 0x04,	//25
	MEAS_ANGLE_45 = 0x08,	//45
	MEAS_ANGLE_75 = 0x10,	//75
	MEAS_ANGLE_110 = 0x20,	//110
	MEAS_ANGLE_NONE = -1,	//None
};

//Measurement mode
enum CMMISDK_MeasMode : int32_km
{
	MEASMODE_COLORANDGLOSS = 0,	//color value and gloss value
	MEASMODE_COLORONLY,			//only color value
	MEASMODE_GLOSSONLY,			//only gloss value
	MEASMODE_OPACITY,			//opacity
	MEASMODE_NONE = -1,			//None
};

//正反射光処理
enum CMMISDK_SpecularComponent : int32_km
{
	SC_SCI = 0,		//SCI
	SC_SCE,			//SCE
	SC_SCIE,		//SCI+SCE
	SC_NONE = -1,	//None
};

//UV条件
enum CMMISDK_Uv : int32_km
{
	UV_100 = 0,				//UV full
	UV_CUT400 = 1,			//UV 400nm cut Normal
	UV_CUT420 = 2,			//UV 420nm cut Normal
	UV_CUT400LOW = 13,		//UV 400nm cut Low
	UV_CUT420LOW = 14,		//UV 420nm cut Low
	UV_CUT400N = 3,			//UV adjust 400nm cut Normal flash
	UV_CUT400L = 4,			//UV adjust 400nm cut Low flash
	UV_CUT420N = 5,			//UV adjust 420nm cut Normal flash
	UV_CUT420L = 6,			//UV adjust 420nm cut Low flash
	UV_100_CUT400 = 7,		//UV full + 400nm cut Normal
	UV_100_CUT420 = 8,		//UV full + 420nm cut Normal
	UV_100_CUT400LOW = 15,	//UV full + 400nm cut Low
	UV_100_CUT420LOW = 16,	//UV full + 420nm cut Low
	UV_100_CUT400N = 9,		//UV full + adjust 400nm cut Normal flash
	UV_100_CUT400L = 10,	//UV full + adjust 400nm cut Low flash
	UV_100_CUT420N = 11,	//UV full + adjust 420nm cut Normal flash
	UV_100_CUT420L = 12,	//UV full + adjust 420nm cut Low flash

	UV_NONE = -1,	//None
};

//Save mode
enum CMMISDK_SaveMode : int32_km
{
	SAVEMODE_AUTO = 0,	//Auto save
	SAVEMODE_MANUAL,	//Manual save
};

//Display type
typedef int32_km CMMISDK_DisplayType;
#define DISPTYPE_ABS			0x001	//Absolute values
#define DISPTYPE_DIF			0x002	//Color difference
#define DISPTYPE_ABSDIF			0x004	//Absolute value & color difference
#define DISPTYPE_CUSTOM			0x008	//Custom
#define DISPTYPE_GRAPH_ABS		0x010	//Absolute value graph
#define DISPTYPE_GRAPH_DIF		0x020	//Color difference graph
#define DISPTYPE_GRAPH_REF		0x040	//Spectral graph
#define DISPTYPE_PASS_FAIL		0x080	//Pass or fail
#define DISPTYPE_MI				0x100	//MI
#define DISPTYPE_GRAPH_LINE		0x200	//Line graph
#define DISPTYPE_AUDI2000_EC	0x400	//DeltaEc(Audi2000)
#define DISPTYPE_AUDI2000_EP	0x800	//DeltaEp(Audi2000)

//Observation field
enum CMMISDK_Observer : int32_km
{
	OBS_02 = 0,	//2
	OBS_10,		//10
};

//Observation illuminant
enum CMMISDK_Illuminant : int32_km
{
	ILL_NONE = 0,	//None
	ILL_A,			//A
	ILL_C,			//C
	ILL_D50,		//D50
	ILL_D65,		//D65
	ILL_ID50,		//ID50
	ILL_ID65,		//ID65
	ILL_F2,			//F2
	ILL_F6,			//F6
	ILL_F7,			//F7
	ILL_F8,			//F8
	ILL_F10,		//F10
	ILL_F11,		//F11
	ILL_F12,		//F12
	ILL_USER1,		//User1
};

//Color space
enum CMMISDK_ColorSpace : int32_km
{
	COLOR_LAB = 0,		//L*a*b
	COLOR_LCH,			//L*C*h
	COLOR_HLAB,			//Hunter Lab
	COLOR_YXY,			//Yxy
	COLOR_XYZ,			//XYZ
	COLOR_MUNSELL_C,	//Munsell (C)
};

//Color difference equation
enum CMMISDK_Equation : int32_km
{
	EQUATION_DE1976 = 0,	//DeltaE*ab
	EQUATION_CMC,			//CMC
	EQUATION_DE1994,		//DeltaE*94
	EQUATION_DE2000,		//DeltaE00
	EQUATION_DEH,			//DeltaE(Hunter)
	EQUATION_DEP,			//DeltaEp(DIN6175)
	EQUATION_DEC,			//DeltaEc(DIN6175)
	EQUATION_DE99o,			//DeltaE99(DN99o)
};

//Custom items
enum CMMISDK_CustomIndex : int32_km
{
	CUSTOM_NONE = 0,		//None

	CUSTOM_L,				// L*
	CUSTOM_A,				// a*
	CUSTOM_B,				// b*
	CUSTOM_C,				// C*
	CUSTOM_H,				// h
	CUSTOM_HL,				// L (Hunter)
	CUSTOM_HA,				// a (Hunter)
	CUSTOM_HB,				// b (Hunter)
	CUSTOM_X,				// X
	CUSTOM_Y,				// Y
	CUSTOM_Z,				// Z
	CUSTOM_SX,				// x
	CUSTOM_SY,				// y
	CUSTOM_MH,				// H (Munsell)
	CUSTOM_MV,				// V (Munsell)
	CUSTOM_MC,				// C (Munsell)
	CUSTOM_WI_E,			// WI(E313-73)
	CUSTOM_WI_C,			// WI(CIE)
	CUSTOM_TINT_C,			// Tint(CIE)
	CUSTOM_YI_E,			// YI(E313)
	CUSTOM_YI_D,			// YI(D1925)
	CUSTOM_B_ISO,			// B(ISO)
	CUSTOM_GU,				// GU
	CUSTOM_USER_E1,			// UserE1
	CUSTOM_USER_C1,			// UserC1
	CUSTOM_USER_E2,			// UserE2
	CUSTOM_USER_C2,			// UserC2
	CUSTOM_USER_E3,			// UserE3
	CUSTOM_USER_C3,			// UserC3
	CUSTOM_GLOSS8,			// GU(8deg)
	CUSTOM_WI_G,			// WI(Ganz)
	CUSTOM_TINT_G,			// TINT(Ganz)

	CUSTOM_DL = -1,			// DeltaL*
	CUSTOM_DA = -2,			// Deltaa*
	CUSTOM_DB = -3,			// Deltab*
	CUSTOM_DC = -4,			// DeltaC*
	CUSTOM_DH = -5,			// DeltaH*
	CUSTOM_DHL = -6,		// DeltaL(Hunter)
	CUSTOM_DHA = -7,		// Deltaa(Hunter)
	CUSTOM_DHB = -8,		// Deltab(Hunter)
	CUSTOM_DX = -9,			// DeltaX 
	CUSTOM_DY = -10,		// DeltaY
	CUSTOM_DZ = -11,		// DeltaZ
	CUSTOM_DSX = -12,		// Deltax
	CUSTOM_DSY = -13,		// Deltay
	CUSTOM_DWI_E = -14,		// DeltaWI(E313-73)
	CUSTOM_DWI_C = -15,		// DeltaWI(CIE)
	CUSTOM_DTINT_C = -16,	// DeltaTint(CIE)
	CUSTOM_DYI_E = -17,		// DeltaYI(E313)
	CUSTOM_DYI_D = -18,		// DeltaYI(D1925)
	CUSTOM_DB_ISO = -19,	// DeltaB(ISO)
	CUSTOM_DGU = -20,		// DeltaGU
	CUSTOM_MI = -21,		// MI
	CUSTOM_DE = -22,		// DeltaE*ab
	CUSTOM_CMC = -23,		// CMC
	CUSTOM_DE94 = -24,		// DeltaE*94
	CUSTOM_DE00 = -25,		// DeltaE00
	CUSTOM_DEH = -26,		// DeltaE(Hunter)
	CUSTOM_DE99O = -27,		// DeltaE99o
	CUSTOM_STRENGTH_XYZ = -28,	// StrengthXYZ
	CUSTOM_STRENGTH_X = -29,	// StrengthX
	CUSTOM_STRENGTH_Y = -30,	// StrengthY
	CUSTOM_STRENGTH_Z = -31,	// StrengthZ
	CUSTOM_GREYSCALE = -32,		// GreyScale
	CUSTOM_DWI_G = -33,			// DeltaWI(Ganz)
	CUSTOM_DTINT_G = -34,		// DeltaTINT(Ganz)
};

//Irradiation direction to display
enum CMMISDK_Direction : int32_km
{
	DIRECTION_DP = 0,	//DP
	DIRECTION_L,		//LEFT
};

//Light direction
enum CMMISDK_LightDirection : int32_km
{
	LDIRECTION_NONE = 0,	//None
	LDIRECTION_L = 0x01,	//LEFT
	LDIRECTION_R = 0x02,	//RIGHT
	LDIRECTION_DP = 0x04,	//DP
};

//Data attribute
enum CMMISDK_DataAttr : int32_km
{
	DATAATTR_SPEC = 0,	//Spectrum data
	DATAATTR_LAB,		//L*a*b
	DATAATTR_HLAB,		//Hunter Lab
	DATAATTR_XYZ,		//XYZ
};

//Filter settings
enum CMMISDK_FilterIndex : int32_km
{
	FILTER_OFF = 0,	//OFF
	FILTER_SAVE,	//Displays only the saved data
	FILTER_GROUP,	//Displays only the data corresponding to the specified group number
};

//Instrument mode
enum CMMISDK_InstrumentMode : int32_km
{
	INSTRUMENTMODE_NORMAL = 0,	//Normal
	INSTRUMENTMODE_SIMPLE,		//Simple
};

//User type
enum CMMISDK_UserType : int32_km
{
	USERTYPE_ADMIN = 0,	//Administrator
	USERTYPE_WORKER,	//Worker

};

//Screen direction
enum CMMISDK_ScreenDirection : int32_km
{
	SCREENDIR_0 = 0,	//Not rotated
	SCREENDIR_180,		//Rotated 180°
};

//Date format
enum CMMISDK_DateFormat : int32_km
{
	DF_YYYYMMDD = 0,	//YYYYMMDD
	DF_MMDDYYYY,		//MMDDYYYY
	DF_DDMMYYYY,		//DDMMYYYY
};

//Language
enum CMMISDK_Language : int32_km
{
	LANGUAGE_ENGLISH = 0,	//English
	LANGUAGE_JAPANESE,		//Japanese
	LANGUAGE_GERMAN,		//German
	LANGUAGE_FRENCH,		//French
	LANGUAGE_SPANISH,		//Spanish
	LANGUAGE_ITALIAN,		//Italian
	LANGUAGE_CHINESE_S,		//Chinese (simplified)
	LANGUAGE_PORTUGUESE,	//Portuguese
	LANGUAGE_RUSSIAN,		//Russian
	LANGUAGE_POLISH,		//Polish
	LANGUAGE_TURKISH,		//Turkish
};

//Job ste type
enum CMMISDK_JobStepType : int32_km
{
	JOB_STEPTYPE_OPERATION = 0,	//Operation
	JOB_STEPTYPE_RESULT,		//Result
};

//ON/OFF
enum CMMISDK_OnOff : int32_km
{
	OFF = 0,	//OFF
	ON,			//ON
};

//Tolerance type
enum CMMISDK_ToleranceType : int32_km
{
	//CM-25cG
	TOLETYPE_SPEC = 0,

	//CM-26dG/CM-26d/CM-25d/CM-23d
	TOLETYPE_SCI = 0,	//SCI
	TOLETYPE_SCE = 1,	//SCE

	//CM-M6
	TOLETYPE_L_ANGLE_M15 = 0,	//LEFT -15
	TOLETYPE_L_ANGLE_15 = 1,	//LEFT 15
	TOLETYPE_L_ANGLE_25 = 2,	//LEFT 25
	TOLETYPE_L_ANGLE_45 = 3,	//LEFT 45
	TOLETYPE_L_ANGLE_75 = 4,	//LEFT 75
	TOLETYPE_L_ANGLE_110 = 5,	//LEFT 110
	TOLETYPE_R_ANGLE_M15 = 6,	//RIGHT -15
	TOLETYPE_R_ANGLE_15 = 7,	//RIGHT 15
	TOLETYPE_R_ANGLE_25 = 8,	//RIGHT 25
	TOLETYPE_R_ANGLE_45 = 9,	//RIGHT 45
	TOLETYPE_R_ANGLE_75 = 10,	//RIGHT 75
	TOLETYPE_R_ANGLE_110 = 11,	//RIGHT 110
	TOLETYPE_DP_ANGLE_M15 = 12,	//DP -15
	TOLETYPE_DP_ANGLE_15 = 13,	//DP 15
	TOLETYPE_DP_ANGLE_25 = 14,	//DP 25
	TOLETYPE_DP_ANGLE_45 = 15,	//DP 45
	TOLETYPE_DP_ANGLE_75 = 16,	//DP 75
	TOLETYPE_DP_ANGLE_110 = 17,	//DP 110
};

//Tolerance id
enum CMMISDK_ToleranceId : int32_km
{
	TOLERANCE_ID_L						= -1,	//DeltaL*
	TOLERANCE_ID_A						= -2,	//Deltaa*
	TOLERANCE_ID_B						= -3,	//Deltab*
	TOLERANCE_ID_C						= -4,	//DeltaC*
	TOLERANCE_ID_H						= -5,	//DeltaH*
	TOLERANCE_ID_HL						= -6,	//DeltaL(Hunter)
	TOLERANCE_ID_HA						= -7,	//Deltaa(Hunter)
	TOLERANCE_ID_HB						= -8,	//Deltab(Hunter)
	TOLERANCE_ID_X						= -9,	//DeltaX
	TOLERANCE_ID_Y						= -10,	//DeltaY
	TOLERANCE_ID_Z						= -11,	//DeltaZ
	TOLERANCE_ID_SX						= -12,	//Deltax
	TOLERANCE_ID_SY						= -13,	//Deltay
	TOLERANCE_ID_WI_E					= -14,	//DeltaWI(E313 - 73)
	TOLERANCE_ID_WI_C					= -15,	//DeltaWI(CIE)
	TOLERANCE_ID_TINT_C					= -16,	//DeltaTint(CIE)
	TOLERANCE_ID_YI_E					= -17,	//DeltaYI(E313)
	TOLERANCE_ID_YI_D					= -18,	//DeltaYI(D1925)
	TOLERANCE_ID_B_ISO					= -19,	//DeltaB(ISO)
	TOLERANCE_ID_GU						= -20,	//DeltaGU
	TOLERANCE_ID_MI						= -21,	//MI
	TOLERANCE_ID_DE						= -22,	//DeltaE*ab
	TOLERANCE_ID_CMC					= -23,	//CMC
	TOLERANCE_ID_DE94					= -24,	//DeltaE * 94
	TOLERANCE_ID_DE00					= -25,	//DeltaE00
	TOLERANCE_ID_DEH					= -26,	//DeltaE(Hunter)
	TOLERANCE_ID_DEP_DIN6175			= -27,	//DeltaEp(DIN6175)
	TOLERANCE_ID_DEC_DIN6175			= -28,	//DeltaEc(DIN6175)
	TOLERANCE_ID_FF						= -29,	//DeltaFF
	TOLERANCE_ID_DE99O					= -30,	//DeltaE99o
	TOLERANCE_ID_DEC_AUDI2000			= -31,	//DeltaEc(Audi2000)
	TOLERANCE_ID_MDEC_AUDI2000			= -32,	//DeltaEc average(Audi2000)
	TOLERANCE_ID_DECM_AUDI2000			= -33,	//DeltaEc max.(Audi2000)
	TOLERANCE_ID_DEP_AUDI2000			= -34,	//DeltaEp(Audi2000)
	TOLERANCE_ID_MDEP_AUDI2000			= -35,	//DeltaEp average(Audi2000)
	TOLERANCE_ID_DEPM_AUDI2000			= -36,	//DeltaEp max.(Audi2000)
	TOLERANCE_ID_DSTRENGTH_XYZ			= -37,	//DeltaStrengthXYZ
	TOLERANCE_ID_DSTRENGTH_X			= -38,	//DeltastrengthX
	TOLERANCE_ID_DSTRENGTH_Y			= -39,	//DeltastrengthY
	TOLERANCE_ID_DSTRENGTH_Z			= -40,	//DeltastrengthZ
	TOLERANCE_ID_DOPACITY				= -41,	//Delta opacity
	TOLERANCE_ID_DGRAYSCALE				= -42,	//Delta grey scale
	TOLERANCE_ID_WI_G					= -43,	//Delta WI(Ganz)
	TOLERANCE_ID_TINT_G					= -44,	//Delta TINT(Ganz)
};

//Parametric coef. id
enum CMMISDK_ParametricId : int32_km
{
	PARAMETRIC_ID_CMC = 0,	//CMC
	PARAMETRIC_ID_DE94,		//DeltaE*94
	PARAMETRIC_ID_DE00,		//DeltaE00
};

//Date type
enum CMMISDK_DateType : int32_km
{
	DATETYPE_COLOR = 0, //Color
	DATETYPE_GLOSS,		//Gloss
};

//Capability type
enum CMMISDK_CapabilityType : int32_km
{
	CAPTYPE_LIST_SINGLE = 0,	//Single selected
	CAPTYPE_LIST_MULTI,			//Multi selected
	CAPTYPE_VALUE,				//Range value
};

//Size definitions
#define SIZE_PORTNAME			32		//Size of port number name
#define SIZE_INSTRUMENT_NAME	32		//Size of instrument name
#define SIZE_DATA				39		//Amount of data
#define SIZE_USERCAL_ID			16		//Size of user ID
#define SIZE_GG					5		//Size of Ganz & Griesser
#define SIZE_GG_PARAM			7		//Parameter size of Ganz & Griesser
#define SIZE_USER_ILLUMINANT	85		//Amount of User illuminant data
#define SIZE_USER_ILL_NAME		16		//User illuminant name
#define SIZE_USER_EQUATION		200		//Size of user equation syntax
#define SIZE_TARGET				2500	//Amount of target data
#define SIZE_DATE				6		//Size of date/time
#define SIZE_GROUP				5		//Size of active group list
#define SIZE_GROUP_ALL			50		//Total size of groups
#define SIZE_DATANAME			64		//Size of data name
#define SIZE_PARAMETRIC_COEF	3		//Size of parametric coefficient
#define SIZE_GROUP_NAME			32		//Size of group name
#define SIZE_ADMIN_PASS			8		//Size of administrator password
#define SIZE_JOB_NAME			32		//Size of job name
#define SIZE_JOB_COMMENT		128		//Size of job comment
#define SIZE_JOB_INDEX			7		//Size of job custom item
#define SIZE_JOBIMAGE_NAME		32		//Size of job image name
#define SIZE_IMAGEDATA			153600	//Image size (assuming 320 × 480 max.)
#define SIZE_IMAGE_FINDER		307200	//Image size (assuming 640 × 480 max.)
#define SIZE_UUID				16		//Size of uuid
#define SIZE_CAMERA_ID			24		//Size of camera identification
#define SIZE_USER_NAME			16		//Size of user equation name

#pragma pack(push, 1) 

//COM port information
struct CMMISDK_Port
{
	char   port_name[SIZE_PORTNAME];	//COM port name
};

//Spectrophotometer information
struct CMMISDK_InstrumentInfo
{
	int32_km     DataSize;								//Reflectance    Size of data (determined by minimum wavelength, maximum wavelength, and wavelength pitch)
	int32_km     WaveLengthStart;						//Reflectance    Wavelength range: Minimum wavelength
	int32_km     WaveLengthEnd;							//Reflectance    Wavelength range: Maximum wavelength
	int32_km     WaveLengthPitch;						//Reflectance    Wavelength range: Wavelength pitch
	int32_km     SerialNo;								//Serial number
	int32_km     VersionMajor;							//Product version (Major)
	int32_km     VersionMinor;							//Product version (Minor)
	int32_km     VersionFree;							//Product version (Free)
	char         InstrumentName[SIZE_INSTRUMENT_NAME];	//Product name
};

//Version information
struct CMMISDK_Version
{
	int32_km     major;	//Major
	int32_km     minor;	//Minor
	int32_km     free;	//Free
};

//Measurement data
struct CMMISDK_Data
{
	float64_km   data[SIZE_DATA];	//Data
};

//Color value calculation conditions
struct CMMISDK_ColorCond
{
	CMMISDK_Observer	obs;			//Observer
	CMMISDK_Illuminant	ill;			//Illuminant
	CMMISDK_ColorSpace	colorSpace;		//Color space
										//	*A value other than COLOR_MUNSELL_C can be specified with CMMISDK_ReadLatestDataColor.
										//	*Only L*a*b*, Hunter Lab, and XYZ can be specified with CMMISDK_SetTargetDataColor and CMMISDK_GetTargetDataColor.
};

//User calibration ID
struct CMMISDK_UserCalId
{
	char   id[SIZE_USERCAL_ID];	//ID
};

//Index data for fluorescence adjustment
struct CMMISDK_UvAdjustIndex
{
	float64_km   value;				//value
	float64_km   tolerance;			//Allowable width
};

//Fluorescence adjustment coefficient
struct CMMISDK_UvAdjustCoef
{
	float64_km   coefficient[SIZE_DATA];	//Fluorescence coefficient
	float64_km   correction[SIZE_DATA];		//Fluorescence correction value
	float64_km   param[SIZE_GG_PARAM];		//Parameter
											//* In the case of Ganz & Griesser only, it is stored in the order of P · Q · C · m · n · k · dWdS
	int32_km     date[SIZE_DATE];			//Adjustment date
											//The array is stored in the order of year, month, day, hour, minute, second
};

//Ganz & Griesser fluorescence adjustment data
struct CMMISDK_UvAdjustGG
{
	int32_km     count;				//Number of samples used
	float64_km   WI[SIZE_GG];		//WI value for the number of samples used
	float64_km   Tint[SIZE_GG];		//Tint value for the number of samples used
};

//Measurement data for Ganz & Griesser
struct CMMISDK_GGData
{
	float64_km   UvFull[SIZE_GG][SIZE_DATA];	//UV full reflectance
	float64_km   UvCut[SIZE_GG][SIZE_DATA];		//UV cut reflectance
};

//SMC conditions
struct CMMISDK_CondSMC
{
	CMMISDK_OnOff			enable;		//Enable or disable function
	float64_km				threshold;	//Threshold value level (0.01 to 9.99)
	int32_km				times;		//Number of times to average (3 to 10 times)
};

//User illuminant data
struct CMMISDK_UserIlluminant
{
	float64_km	data[SIZE_USER_ILLUMINANT];		//User illuminant data
												//	85 items of data between 360 to 780 nm at 5-nm pitch
	char		name[SIZE_USER_ILL_NAME];		//User illuminant name
												//	Name to be displayed on the menu. If the character length is 0, it will be "User".
};

//Saved target list
struct CMMISDK_SavedTargetList
{
	int32_km   size;				//Number of saved targets
	int32_km   list[SIZE_TARGET];	//List of saved numbers
									//	*Stores the target numbers in the amount of the size variable.
};

//Target properties
struct CMMISDK_TargetProperty
{
	int32_km                   date[SIZE_DATE];			//Measurement (registration) date/time
														//	Values are stored in the array in year/month/day/hours/minutes/seconds order.
	int32_km                   group_list[SIZE_GROUP];	//Group number list
	CMMISDK_MeasType           meas_type;				//Measurement method
	CMMISDK_MeasMode           meas_mode;				//Measurement mode
	CMMISDK_MeasArea           meas_area;				//Measurement area
	CMMISDK_MeasAngle          meas_angle;				//Measurement angle
	CMMISDK_LightDirection     meas_ldirection;			//Irradiation direction
	CMMISDK_SpecularComponent  meas_scie;				//Specular component
	CMMISDK_Uv                 meas_uv;					//UV condition
	int32_km                   warning_level;			//Warning level
	CMMISDK_Warning            warning;					//Warning information
														//	0x01	Voltage drop 
														//	0x02	Calibration recommended
														//	0x04	Xe lamp deterioration
														//	0x08	LED lamp deterioration
														//	0x10	Reflectance outside of measurable range
														//	0x20	Gloss outside of measurable range
	int32_km                   diagnosis;				//Diagnosis information
														//	0x01	Repeatability Status: Red
														//	0x02	Repeatability Status: Yellow
														//	0x04	Reproducibility Status: Red
														//	0x08	Reproducibility Status: Yellow
														//	0x10	Intensity Status: Red
														//	0x20	Intensity Status: Yellow
	CMMISDK_DataAttr           data_attr;				//Data attribute
	char                       name[SIZE_DATANAME];		//Data name
														//	*The size is 64 bytes, but the character length depends on the instrument capabilities.
};

//Tolerance data
struct CMMISDK_ToleranceData
{
	int32_km  upper_enable;	//Upper limit enable/disable (0: disable, 1: enable)
	int32_km  upper_value;	//Upper limit (Value multiplied by 100. However, only x・y is a value multiplied by 10000.)
	int32_km  lower_enable;	//Lower limit enable/disable (0: disable, 1: enable)
	int32_km  lower_value;	//Lower limit (Value multiplied by 100. However, only x・y is a value multiplied by 10000.)
};

//Parametric coefficient data
struct CMMISDK_ParametricCoef
{
	float64_km  coef[SIZE_PARAMETRIC_COEF];	//Parametric coefficient
};

//Measurement value properties
struct CMMISDK_SampleProperty
{
	int32_km                   date[SIZE_DATE];		//Measurement (registration) date/time
													//	Values are stored in the array in year/month/day/hours/minutes/seconds order.
	CMMISDK_MeasType           meas_type;			//Measurement method
	CMMISDK_MeasMode           meas_mode;			//Measurement mode
	CMMISDK_MeasArea           meas_area;			//Measurement area
	CMMISDK_MeasAngle          meas_angle;			//Measurement angle
	CMMISDK_LightDirection     meas_ldirection;		//Irradiation direction
	CMMISDK_SpecularComponent  meas_scie;			//Specular component
	CMMISDK_Uv                 meas_uv;				//UV condition
	CMMISDK_Warning            warning;				//Warning information
													//	0x01	Voltage drop 
													//	0x02	Calibration recommended
													//	0x04	Xe lamp deterioration
													//	0x08	LED lamp deterioration
													//	0x10	Reflectance outside of measurable range
													//	0x20	Gloss outside of measurable range
	int32_km                   diagnosis;			//Diagnosis information
													//	0x01	Repeatability Status: Red
													//	0x02	Repeatability Status: Yellow
													//	0x04	Reproducibility Status: Red
													//	0x08	Reproducibility Status: Yellow
													//	0x10	Intensity Status: Red
													//	0x20	Intensity Status: Yellow
	CMMISDK_DataAttr           data_attr;			//Data attribute
	int32_km                   relation_target;		//Related target number
	char                       name[SIZE_DATANAME];	//Data name
													//	*The size is 64 bytes, but the character length depends on the instrument capabilities.
};

//Date and time data
struct CMMISDK_DateTime
{
	int32_km     year;		//Year
	int32_km     month;		//Month
	int32_km     day;		//Day
	int32_km     hour;		//Hour
	int32_km     minute;	//Minute
	int32_km     second;	//Second
};

//User equation information
struct CMMISDK_UserEquation
{
	char   formula[SIZE_USER_EQUATION];		//User equation
	char   user_class[SIZE_USER_EQUATION];	//User classes
};

//Group list
struct CMMISDK_GroupList
{
	int32_km   group[SIZE_GROUP];	//Group list
};

//Group information
struct CMMISDK_Group
{
	char   name[SIZE_GROUP_NAME];	//Name
};

//All group information
struct CMMISDK_GroupAll
{
	char   name[SIZE_GROUP_ALL][SIZE_GROUP_NAME];	//Name
};

//Administrator password
struct CMMISDK_AdminPass
{
	char   password[SIZE_ADMIN_PASS];	//Administrator password
};

//Job information
struct CMMISDK_JobInfo
{
	int32_km		step_count;				//Number of steps to register for job
	CMMISDK_OnOff	step_loop;				//Repeat job on/off
	char			name[SIZE_JOB_NAME];	//Name
};

//Job operation step
struct CMMISDK_JobStepOperation
{
	int32_km					image_num;					//Image number
	CMMISDK_MeasType			meas_type;					//Measurement type
	CMMISDK_MeasMode			meas_mode;					//Measurement mode
	CMMISDK_MeasArea			meas_area;					//Measurement area
	CMMISDK_MeasAngle			meas_angle;					//Measurement angle
	CMMISDK_LightDirection		meas_ldirection;			//Irradiation direction
	CMMISDK_SpecularComponent	meas_scie;					//Specular component
	CMMISDK_Uv					meas_uv;					//UV condition
	int32_km					auto_ave_times;				//Auto average count
	int32_km					manu_ave_times;				//Manual average count
	int32_km					relation_target;			//Related target number
	CMMISDK_OnOff				enable_meas;				//Display measurement button on/off
	CMMISDK_OnOff				enable_prev;				//Display previous button on/off
	CMMISDK_OnOff				enable_next;				//Display next button on/off
	CMMISDK_OnOff				enable_end;					//Display end button on/off
	char						name[SIZE_DATANAME];		//Name
	char						comment[SIZE_JOB_COMMENT];	//Comment
};

//Job result step
struct CMMISDK_JobStepResult
{
	CMMISDK_SpecularComponent	meas_scie;				//Specular component
	CMMISDK_Observer			obs1;					//Observer 1
	CMMISDK_Observer			obs2;					//Observer 2
	CMMISDK_Illuminant			ill1;					//Illuminant 1
	CMMISDK_Illuminant			ill2;					//Illuminant 2
	CMMISDK_CustomIndex			index[SIZE_JOB_INDEX];	//Custom items
	CMMISDK_OnOff				enable_meas;			//Display measurement button on/off
	CMMISDK_OnOff				enable_prev;			//Display previous button on/off
	CMMISDK_OnOff				enable_next;			//Display next button on/off
	CMMISDK_OnOff				enable_end;				//Display end button on/off
};

//Job image
struct CMMISDK_JobImage
{
	int32_km	width;						//Width (240 fixed)
	int32_km	height;						//Height (128 fixed)
	int32_km	data[SIZE_IMAGEDATA];		//Image data (arranged in Z order from top left)
											//	The data is stored as 1 pixel per element. R, G, and B are each 8 bits.
											//	The data is stored right-aligned in BGR order.
	char		name[SIZE_JOBIMAGE_NAME];	//Image name
};

//Finder image
struct CMMISDK_FinderImage
{
	int32_km  width;					//Width
	int32_km  height;					//Height
	int32_km  data[SIZE_IMAGE_FINDER];	//Image data (arranged in Z order from top left)
	//	The data is stored as 1 pixel per element. R, G, and B are each 8 bits.
	//	The data is stored right-aligned in BGR order.
};

//Image
struct CMMISDK_Image
{
	int32_km  width;					//Width
	int32_km  height;					//Height
	int32_km  data[SIZE_IMAGEDATA];		//Image data (arranged in Z order from top left)
										//	The data is stored as 1 pixel per element. R, G, and B are each 8 bits.
										//	The data is stored right-aligned in BGR order.
};

#pragma pack(pop)
