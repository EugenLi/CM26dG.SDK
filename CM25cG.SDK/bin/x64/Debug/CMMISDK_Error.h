//Copyright (C) KONICA MINOLTA, INC.  All rights reserved. 2018

#pragma once

//警告状態
typedef int32_km CMMISDK_Warning;
#define KmWrBattery					0x01	// Battery voltage is low.
#define KmWrCalibration				0x02	// Much time has passed since calibration. Recalibration is recommended.
#define KmWrPreAnnualCalibraton		0x04	// The time for periodic calibration is approaching.
#define KmWrAnnualCalibraton		0x08	// Periodic calibration is necessary. Perform periodic calibration.
#define KmWrLampForColor			0x10	// Light output of light source for color measurement has decreased.
#define KmWrOutOfColorRange			0x20	// Reflectance exceeds guaranteed range.
#define KmWrOutOfGlossRange			0x40	// Gloss value exceeds guaranteed range.
#define KmWrLampForGloss			0x80	// Light output of light source for gloss measurement has decreased.
#define KmWrPreWavelengthCorrection 0x100	// The time to end the wavelength diagnosis is approaching.
#define KmWrWavelengthCorrection	0x200	// Wavelength diagnosis deadline has expired.
#define KmWrLampForDiagnosis		0x400	// The amount of light from the light source for wavelength diagnosis is decreasing.
#define KmWrInsufficientLampForDiagnosis      0x800		// Insufficient light source light for wavelength diagnosis.
#define KmWrOutOfTemperatureRangeForDiagnosis 0x1000	// Wavelength diagnosis is out of the temperature specification range. The correction accuracy has decreased.
#define KmWrOutOfCorrectionRangeForDiagnosis  0x2000	// Wavelength diagnosis is out of the correction specification range. The correction accuracy has decreased.


//エラーコード
enum error_km : int32_km
{
	KmSuccess = 0,					//The processing was completed normally.
	KmWarning = 1,					//The processing was completed with warning.
	KmErNoConnect = 10,				//No instrument is connected to the specified virtual COM port.
	KmErInvalidParameter = 25,		//The specified parameter is incorrect.
	KmErCannotCommand = 30,			//The current model does not support the specified API.
	KmErNoData = 45,				//No data.
	KmErDataProtected = 46,			//The target data is protected.
	KmErOutOfRangeValue = 50,		//It is a value outside the range measurable with this instrument.
	KmErConnectFailed = 100,		//Failed to connect to the instrument.Or, Connect was not performed.
	KmErDevice = 110,				//A device in the instrument is malfunctioning.
	KmErAd = 111,					//There was an error with the A/D conversion.
	KmErCharge = 112,				//There was an error with the charge circuit.
	KmErFlash = 113,				//There is no xenon output.Restart and try measuring again.
	KmErFinder = 114,				//Please close the viewfinder.
	KmErCalculation = 115,			//The data could not be calculated.
	KmErCamera = 116,				//Camera is not working. Unavailable because the camera is in operation
	KmErMeasuring = 117,			//Cannot use API because measurement is in progress
	KmErMotorDriving = 118,			//This API cannot be used because the motor is driving.
	KmErMask = 119,					//The mask is not attached.
	KmErCalibration = 120,			//Calibration was not executed with the correct procedure.
	KmErCalibrationRequired = 130,	//Necessary calibration was not executed beforehand.
	KmErNoCalibrationData = 131,	//Configure the calibration data.
	KmErTiltDetection = 140,		//The instrument is tilted.
	KmErNotUse = 170,				//Cannot use this parameter for other functions.
	KmErDisagreeCond = 171,			//The conditions do not match.
	KmErUvAdjust = 172,				//The measurement sample does not contain fluorescence.
	KmErBattery = 180,				//The power supply voltage is insufficient.
	KmErMemory = 181,				//A memory error has occurred.
	KmErMotor = 182,				//There was an error with the motor.
	KmErNotSupported = 190,			//Not Supported
	KmErCalculateColor = 195,		//The data could not be calculated color value.
	KmErCalculateCoef = 196,		//Fluorescence coefficient can not be calculated.
	KmErUuid = 198,					//Duplicate uuid.
	KmEr = 200,						//An unexpected error has occurred.
	KmErTimeout = 210,				//Operation timed out.
};
