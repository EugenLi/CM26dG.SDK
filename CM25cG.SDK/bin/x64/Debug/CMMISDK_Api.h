//Copyright (C) KONICA MINOLTA, INC.  All rights reserved. 2018

#pragma once

#include "CMMISDK_TypeDefine.h"
#include "TypeDefine.h"
#include "CMMISDK_Error.h"
#include "CMMISDK_Parameters.h"

#if defined(__cplusplus)
extern "C"{
#endif

	error_km KMAPI CMMISDK_Connect(const CMMISDK_Port* inPortInfo, int32_km* outInstrumentNo);
	error_km KMAPI CMMISDK_Disconnect(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_GetInstrumentInfo(int32_km inInstrumentNo, CMMISDK_InstrumentInfo* outInfo);
	error_km KMAPI CMMISDK_GetSDKVersion(CMMISDK_Version* version);
	error_km KMAPI CMMISDK_GetWarning(int32_km inInstrumentNo, CMMISDK_Warning* warning);

	error_km KMAPI CMMISDK_GetCalibrationStatus(int32_km inInstrumentNo, CMMISDK_CalStatus* outCalStatus);
	error_km KMAPI CMMISDK_PerformZeroCalibration(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_PerformWhiteCalibration(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_PerformGlossCalibration(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_PerformUserCalibration(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_PerformMeasurement(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_PollingMeasurement(int32_km inInstrumentNo, CMMISDK_MeasStatus* outStatus);
	error_km KMAPI CMMISDK_CancelMeasurement(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_ReadLatestDataSpec(int32_km inInstrumentNo, CMMISDK_DataType inDataType, CMMISDK_Data* outData);
	error_km KMAPI CMMISDK_ReadLatestDataColor(int32_km inInstrumentNo, CMMISDK_DataType inDataType, const CMMISDK_ColorCond *inColorCond, CMMISDK_Data* outData);
	error_km KMAPI CMMISDK_LoadLatestData(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_GetLatestDataSpec(int32_km inInstrumentNo, CMMISDK_DataType inDataType, CMMISDK_Data* outData);
	error_km KMAPI CMMISDK_GetLatestDataColor(int32_km inInstrumentNo, CMMISDK_DataType inDataType, const CMMISDK_ColorCond *inColorCond, CMMISDK_Data* outData);
	error_km KMAPI CMMISDK_SetWhiteCalibrationData(int32_km inInstrumentNo, CMMISDK_CalDataType inDataType, int32_km inCalId, const CMMISDK_Data* inCalData);
	error_km KMAPI CMMISDK_GetWhiteCalibrationData(int32_km inInstrumentNo, CMMISDK_CalDataType inDataType, int32_km* outCalId, CMMISDK_Data* outCalData);
	error_km KMAPI CMMISDK_SetGlossCalibrationData(int32_km inInstrumentNo, CMMISDK_MeasArea inArea, int32_km inCalId, float64_km inCalData);
	error_km KMAPI CMMISDK_GetGlossCalibrationData(int32_km inInstrumentNo, CMMISDK_MeasArea inArea, int32_km* outCalId, float64_km* outCalData);
	error_km KMAPI CMMISDK_SetUserCalibrationData(int32_km inInstrumentNo, CMMISDK_CalDataType inDataType, const CMMISDK_UserCalId* inCalId, const CMMISDK_Data* inCalData);
	error_km KMAPI CMMISDK_GetUserCalibrationData(int32_km inInstrumentNo, CMMISDK_CalDataType inDataType, CMMISDK_UserCalId* outCalId, CMMISDK_Data* outCalData);
	error_km KMAPI CMMISDK_SetUserCalibrationEnable(int32_km inInstrumentNo, CMMISDK_OnOff inCalEnable);
	error_km KMAPI CMMISDK_GetUserCalibrationEnable(int32_km inInstrumentNo, CMMISDK_OnOff* outCalEnable);
	error_km KMAPI CMMISDK_SetTriggerMode(int32_km inInstrumentNo, CMMISDK_OnOff inTrigger);
	error_km KMAPI CMMISDK_GetTriggerMode(int32_km inInstrumentNo, CMMISDK_OnOff* outTrigger);
	error_km KMAPI CMMISDK_ClearTriggerData(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_IsTriggerData(int32_km inInstrumentNo, CMMISDK_OnOff* outData);
	error_km KMAPI CMMISDK_GetZeroCalibrationDate(int32_km inInstrumentNo, CMMISDK_DateType inType, CMMISDK_DateTime* outDate);
	error_km KMAPI CMMISDK_GetWhiteCalibrationDate(int32_km inInstrumentNo, CMMISDK_DateTime* outDate);
	error_km KMAPI CMMISDK_GetGlossCalibrationDate(int32_km inInstrumentNo, CMMISDK_DateTime* outDate);
	error_km KMAPI CMMISDK_GetUserCalibrationDate(int32_km inInstrumentNo, CMMISDK_DateTime* outDate);
	error_km KMAPI CMMISDK_ClearUvAdjustInfo(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_SetProfileForUvAdjust(int32_km inInstrumentNo, const CMMISDK_Data* inData);
	error_km KMAPI CMMISDK_GetProfileForUvAdjust(int32_km inInstrumentNo, CMMISDK_Data* outData);
	error_km KMAPI CMMISDK_SetWiForUvAdjust(int32_km inInstrumentNo, const CMMISDK_UvAdjustIndex* inData);
	error_km KMAPI CMMISDK_GetWiForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustIndex* outData);
	error_km KMAPI CMMISDK_SetTintForUvAdjust(int32_km inInstrumentNo, const CMMISDK_UvAdjustIndex* inData);
	error_km KMAPI CMMISDK_GetTintForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustIndex* outData);
	error_km KMAPI CMMISDK_SetIsoBrightnessForUvAdjust(int32_km inInstrumentNo, const CMMISDK_UvAdjustIndex* inData);
	error_km KMAPI CMMISDK_GetIsoBrightnessForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustIndex* outData);
	error_km KMAPI CMMISDK_SetGanzForUvAdjust(int32_km inInstrumentNo, const CMMISDK_UvAdjustGG* inData);
	error_km KMAPI CMMISDK_GetGanzForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustGG* outData);
	error_km KMAPI CMMISDK_SetEachProfileForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustDataType inType, const CMMISDK_Data* inData);
	error_km KMAPI CMMISDK_GetEachProfileForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustDataType inType, CMMISDK_Data* outData);
	error_km KMAPI CMMISDK_SetEachWiForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustDataType inType, const CMMISDK_UvAdjustIndex* inData);
	error_km KMAPI CMMISDK_GetEachWiForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustDataType inType, CMMISDK_UvAdjustIndex* outData);
	error_km KMAPI CMMISDK_SetEachTintForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustDataType inType, const CMMISDK_UvAdjustIndex* inData);
	error_km KMAPI CMMISDK_GetEachTintForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustDataType inType, CMMISDK_UvAdjustIndex* outData);
	error_km KMAPI CMMISDK_SetEachIsoBrightnessForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustDataType inType, const CMMISDK_UvAdjustIndex* inData);
	error_km KMAPI CMMISDK_GetEachIsoBrightnessForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustDataType inType, CMMISDK_UvAdjustIndex* outData);
	error_km KMAPI CMMISDK_SetEachGanzForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustDataType inType, const CMMISDK_UvAdjustGG* inData);
	error_km KMAPI CMMISDK_GetEachGanzForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustDataType inType, CMMISDK_UvAdjustGG* outData);
	error_km KMAPI CMMISDK_SetDataForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustDataType inType, int32_km inNum, const CMMISDK_Data* inFull, const CMMISDK_Data* inCut);
	error_km KMAPI CMMISDK_GetDataForUvAdjust(int32_km inInstrumentNo, CMMISDK_UvAdjustDataType inType, int32_km inNum, CMMISDK_Data* outFull, CMMISDK_Data* outCut);
	error_km KMAPI CMMISDK_PerformUvAdjust(int32_km inInstrumentNo, CMMISDK_CondUvAdjust inCond);
	error_km KMAPI CMMISDK_PerformUvAdjustUsingData(int32_km inInstrumentNo, CMMISDK_CondUvAdjust inCond);
	error_km KMAPI CMMISDK_ClearCoefForUvAdjust(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_SetCoefForUvAdjust(int32_km inInstrumentNo, CMMISDK_MeasArea inArea, CMMISDK_UvAdjustDataType inType, CMMISDK_CondUvAdjust inCond, const CMMISDK_UvAdjustCoef* inCoef);
	error_km KMAPI CMMISDK_GetCoefForUvAdjust(int32_km inInstrumentNo, CMMISDK_MeasArea inArea, CMMISDK_UvAdjustDataType inType, CMMISDK_CondUvAdjust* outCond, CMMISDK_UvAdjustCoef* outCoef);
	error_km KMAPI CMMISDK_SetOutputMinus(int32_km inInstrumentNo, CMMISDK_OnOff inEnable);
	error_km KMAPI CMMISDK_GetOutputMinus(int32_km inInstrumentNo, CMMISDK_OnOff* outEnable);

	error_km KMAPI CMMISDK_SetMeasurementArea(int32_km inInstrumentNo, CMMISDK_MeasArea inArea);
	error_km KMAPI CMMISDK_GetMeasurementArea(int32_km inInstrumentNo, CMMISDK_MeasArea* outArea);
	error_km KMAPI CMMISDK_SetMeasurementType(int32_km inInstrumentNo, CMMISDK_MeasType inType);
	error_km KMAPI CMMISDK_GetMeasurementType(int32_km inInstrumentNo, CMMISDK_MeasType* outType);
	error_km KMAPI CMMISDK_SetMeasurementAngle(int32_km inInstrumentNo, CMMISDK_MeasAngle inAngle);
	error_km KMAPI CMMISDK_GetMeasurementAngle(int32_km inInstrumentNo, CMMISDK_MeasAngle* outAngle);
	error_km KMAPI CMMISDK_SetTiltDetection(int32_km inInstrumentNo, CMMISDK_OnOff inDetection);
	error_km KMAPI CMMISDK_GetTiltDetection(int32_km inInstrumentNo, CMMISDK_OnOff* outDetection);
	error_km KMAPI CMMISDK_SetMeasurementMode(int32_km inInstrumentNo, CMMISDK_MeasMode inMode);
	error_km KMAPI CMMISDK_GetMeasurementMode(int32_km inInstrumentNo, CMMISDK_MeasMode* outMode);
	error_km KMAPI CMMISDK_SetSpecularComponent(int32_km inInstrumentNo, CMMISDK_SpecularComponent inSpecularComponent);
	error_km KMAPI CMMISDK_GetSpecularComponent(int32_km inInstrumentNo, CMMISDK_SpecularComponent* outSpecularComponent);
	error_km KMAPI CMMISDK_SetUv(int32_km inInstrumentNo, CMMISDK_Uv inUv);
	error_km KMAPI CMMISDK_GetUv(int32_km inInstrumentNo, CMMISDK_Uv* outUv);
	error_km KMAPI CMMISDK_SetAutoAverageTimes(int32_km inInstrumentNo, int32_km inTimes);
	error_km KMAPI CMMISDK_GetAutoAverageTimes(int32_km inInstrumentNo, int32_km* outTimes);
	error_km KMAPI CMMISDK_SetManualAverageTimes(int32_km inInstrumentNo, int32_km inTimes);
	error_km KMAPI CMMISDK_GetManualAverageTimes(int32_km inInstrumentNo, int32_km* outTimes);
	error_km KMAPI CMMISDK_SetManualAverageSaveMode(int32_km inInstrumentNo, CMMISDK_SaveMode inMode);
	error_km KMAPI CMMISDK_GetManualAverageSaveMode(int32_km inInstrumentNo, CMMISDK_SaveMode* outMode);
	error_km KMAPI CMMISDK_SetCondSMC(int32_km inInstrumentNo, const CMMISDK_CondSMC* inCond);
	error_km KMAPI CMMISDK_GetCondSMC(int32_km inInstrumentNo, CMMISDK_CondSMC* outCond);

	error_km KMAPI CMMISDK_SetDisplayType(int32_km inInstrumentNo, CMMISDK_DisplayType inDisplayType);
	error_km KMAPI CMMISDK_GetDisplayType(int32_km inInstrumentNo, CMMISDK_DisplayType* outDisplayType);
	error_km KMAPI CMMISDK_SetObserverAndIlluminant(int32_km inInstrumentNo, int32_km inNum, CMMISDK_Observer inObs, CMMISDK_Illuminant inIll);
	error_km KMAPI CMMISDK_GetObserverAndIlluminant(int32_km inInstrumentNo, int32_km inNum, CMMISDK_Observer* outObs, CMMISDK_Illuminant* outIll);
	error_km KMAPI CMMISDK_SetUserIlluminant(int32_km inInstrumentNo, const CMMISDK_UserIlluminant* inIllData);
	error_km KMAPI CMMISDK_GetUserIlluminant(int32_km inInstrumentNo, CMMISDK_UserIlluminant* outIllData);
	error_km KMAPI CMMISDK_SetColorSpace(int32_km inInstrumentNo, CMMISDK_ColorSpace inColorSpace);
	error_km KMAPI CMMISDK_GetColorSpace(int32_km inInstrumentNo, CMMISDK_ColorSpace* outColorSpace);
	error_km KMAPI CMMISDK_SetEquation(int32_km inInstrumentNo, CMMISDK_Equation inEquation);
	error_km KMAPI CMMISDK_GetEquation(int32_km inInstrumentNo, CMMISDK_Equation* outEquation);
	error_km KMAPI CMMISDK_SetCustomIndex(int32_km inInstrumentNo, int32_km inCustomNum, CMMISDK_CustomIndex inCustomIndex);
	error_km KMAPI CMMISDK_GetCustomIndex(int32_km inInstrumentNo, int32_km inCustomNum, CMMISDK_CustomIndex* outCustomIndex);
	error_km KMAPI CMMISDK_SetDirection(int32_km inInstrumentNo, CMMISDK_Direction inDirection);
	error_km KMAPI CMMISDK_GetDirection(int32_km inInstrumentNo, CMMISDK_Direction* outDirection);
	error_km KMAPI CMMISDK_SetUserEquation(int32_km inInstrumentNo, int32_km inNum, const CMMISDK_UserEquation* inEquation);
	error_km KMAPI CMMISDK_GetUserEquation(int32_km inInstrumentNo, int32_km inNum, CMMISDK_UserEquation* outEquation);

	error_km KMAPI CMMISDK_SetActiveTarget(int32_km inInstrumentNo, int32_km inNum);
	error_km KMAPI CMMISDK_GetActiveTarget(int32_km inInstrumentNo, int32_km* outNum);
	error_km KMAPI CMMISDK_GetSavedTargetList(int32_km inInstrumentNo, CMMISDK_SavedTargetList* outList);
	error_km KMAPI CMMISDK_GetTargetListInFilter(int32_km inInstrumentNo, CMMISDK_SavedTargetList* outList);
	error_km KMAPI CMMISDK_DeleteTargetData(int32_km inInstrumentNo, int32_km inNum);
	error_km KMAPI CMMISDK_DeleteAllTargetData(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_ClearTargetInfo(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_LoadTargetInfo(int32_km inInstrumentNo, int32_km inNum);
	error_km KMAPI CMMISDK_SaveTargetInfo(int32_km inInstrumentNo, int32_km inNum);
	error_km KMAPI CMMISDK_SetTargetProperty(int32_km inInstrumentNo, const CMMISDK_TargetProperty* inProperty);
	error_km KMAPI CMMISDK_GetTargetProperty(int32_km inInstrumentNo, CMMISDK_TargetProperty* outProperty);
	error_km KMAPI CMMISDK_SetTargetData(int32_km inInstrumentNo, CMMISDK_DataType inDataType, const CMMISDK_Data* inData);
	error_km KMAPI CMMISDK_SetTargetDataColor(int32_km inInstrumentNo, CMMISDK_DataType inDataType, int32_km inNum, const CMMISDK_ColorCond *inCond, const CMMISDK_Data* inData);
	error_km KMAPI CMMISDK_GetTargetDataColor(int32_km inInstrumentNo, CMMISDK_DataType inDataType, int32_km inNum, CMMISDK_ColorCond *outCond, CMMISDK_Data* outData);
	error_km KMAPI CMMISDK_GetTargetData(int32_km inInstrumentNo, CMMISDK_DataType inDataType, CMMISDK_Data* outData);
	error_km KMAPI CMMISDK_SetToleranceForTarget(int32_km inInstrumentNo, CMMISDK_ToleranceType inType, int32_km inObsIll, CMMISDK_ToleranceId inId, const CMMISDK_ToleranceData* inTolerance);
	error_km KMAPI CMMISDK_GetToleranceForTarget(int32_km inInstrumentNo, CMMISDK_ToleranceType inType, int32_km inObsIll, CMMISDK_ToleranceId inId, CMMISDK_ToleranceData* outTolerance);
	error_km KMAPI CMMISDK_SetParametricForTarget(int32_km inInstrumentNo, CMMISDK_ToleranceType inType, CMMISDK_ParametricId inId, const CMMISDK_ParametricCoef* inParametric);
	error_km KMAPI CMMISDK_GetParametricForTarget(int32_km inInstrumentNo, CMMISDK_ToleranceType inType, CMMISDK_ParametricId inId, CMMISDK_ParametricCoef* outParametric);
	error_km KMAPI CMMISDK_SetTargetFilter(int32_km inInstrumentNo, CMMISDK_FilterIndex inIndex, const CMMISDK_GroupList* inGroup);
	error_km KMAPI CMMISDK_GetTargetFilter(int32_km inInstrumentNo, CMMISDK_FilterIndex* outIndex, CMMISDK_GroupList* outGroup);
	error_km KMAPI CMMISDK_SetTargetProtect(int32_km inInstrumentNo, CMMISDK_OnOff inProtect);
	error_km KMAPI CMMISDK_GetTargetProtect(int32_km inInstrumentNo, CMMISDK_OnOff* outProtect);
	error_km KMAPI CMMISDK_GetSavedSampleCount(int32_km inInstrumentNo, int32_km* outCount);
	error_km KMAPI CMMISDK_DeleteSampleData(int32_km inInstrumentNo, int32_km inNum);
	error_km KMAPI CMMISDK_DeleteAllSampleData(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_LoadSampleInfo(int32_km inInstrumentNo, int32_km inNum);
	error_km KMAPI CMMISDK_GetSampleProperty(int32_km inInstrumentNo, CMMISDK_SampleProperty* outProperty);
	error_km KMAPI CMMISDK_GetSampleData(int32_km inInstrumentNo, CMMISDK_DataType inDataType, CMMISDK_Data* outData);

	error_km KMAPI CMMISDK_SetActiveGroup(int32_km inInstrumentNo, const CMMISDK_GroupList* inGroup);
	error_km KMAPI CMMISDK_GetActiveGroup(int32_km inInstrumentNo, CMMISDK_GroupList* outGroup);
	error_km KMAPI CMMISDK_SetGroupName(int32_km inInstrumentNo, int32_km inGroup, const CMMISDK_Group* inName);
	error_km KMAPI CMMISDK_GetGroupName(int32_km inInstrumentNo, int32_km inGroup, CMMISDK_Group* outName);
	error_km KMAPI CMMISDK_SetMultipleGroupName(int32_km inInstrumentNo, const CMMISDK_GroupAll* inName);
	error_km KMAPI CMMISDK_GetMultipleGroupName(int32_km inInstrumentNo, CMMISDK_GroupAll* outName);
	error_km KMAPI CMMISDK_LoadDefaultInfo(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_SaveDefaultInfo(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_SetTolerance(int32_km inInstrumentNo, CMMISDK_ToleranceType inType, int32_km inObsIll, CMMISDK_ToleranceId inId, const CMMISDK_ToleranceData* inTolerance);
	error_km KMAPI CMMISDK_GetTolerance(int32_km inInstrumentNo, CMMISDK_ToleranceType inType, int32_km inObsIll, CMMISDK_ToleranceId inId, CMMISDK_ToleranceData* outTolerance);
	error_km KMAPI CMMISDK_SetParametric(int32_km inInstrumentNo, CMMISDK_ToleranceType inType, CMMISDK_ParametricId inId, const CMMISDK_ParametricCoef* inParametric);
	error_km KMAPI CMMISDK_GetParametric(int32_km inInstrumentNo, CMMISDK_ToleranceType inType, CMMISDK_ParametricId inId, CMMISDK_ParametricCoef* outParametric);
	error_km KMAPI CMMISDK_SetWarningLevel(int32_km inInstrumentNo, int32_km inLevel);
	error_km KMAPI CMMISDK_GetWarningLevel(int32_km inInstrumentNo, int32_km* outLevel);
	error_km KMAPI CMMISDK_SetInstrumentMode(int32_km inInstrumentNo, CMMISDK_InstrumentMode inMode);
	error_km KMAPI CMMISDK_GetInstrumentMode(int32_km inInstrumentNo, CMMISDK_InstrumentMode* outMode);
	error_km KMAPI CMMISDK_SetUserType(int32_km inInstrumentNo, CMMISDK_UserType inType);
	error_km KMAPI CMMISDK_GetUserType(int32_km inInstrumentNo, CMMISDK_UserType* outType);
	error_km KMAPI CMMISDK_SetAdminPassword(int32_km inInstrumentNo, const CMMISDK_AdminPass *inPass);
	error_km KMAPI CMMISDK_GetAdminPassword(int32_km inInstrumentNo, CMMISDK_AdminPass* outPass);

	error_km KMAPI CMMISDK_SetAutoPrint(int32_km inInstrumentNo, CMMISDK_OnOff inPrint);
	error_km KMAPI CMMISDK_GetAutoPrint(int32_km inInstrumentNo, CMMISDK_OnOff* outPrint);
	error_km KMAPI CMMISDK_SetBrightness(int32_km inInstrumentNo, int32_km inBrightness);
	error_km KMAPI CMMISDK_GetBrightness(int32_km inInstrumentNo, int32_km* outBrightness);
	error_km KMAPI CMMISDK_SetScreenDirection(int32_km inInstrumentNo, CMMISDK_ScreenDirection inScreenDirection);
	error_km KMAPI CMMISDK_GetScreenDirection(int32_km inInstrumentNo, CMMISDK_ScreenDirection* outScreenDirection);
	error_km KMAPI CMMISDK_SetSound(int32_km inInstrumentNo, CMMISDK_OnOff inSound);
	error_km KMAPI CMMISDK_GetSound(int32_km inInstrumentNo, CMMISDK_OnOff* outSound);
	error_km KMAPI CMMISDK_SetCalibrationInterval(int32_km inInstrumentNo, int32_km inInterval);
	error_km KMAPI CMMISDK_GetCalibrationInterval(int32_km inInstrumentNo, int32_km* outInterval);
	error_km KMAPI CMMISDK_SetAnnualCalibration(int32_km inInstrumentNo, CMMISDK_OnOff inCal);
	error_km KMAPI CMMISDK_GetAnnualCalibration(int32_km inInstrumentNo, CMMISDK_OnOff* outCal);
	error_km KMAPI CMMISDK_SetZeroCalibrationSkip(int32_km inInstrumentNo, CMMISDK_OnOff inSkip);
	error_km KMAPI CMMISDK_GetZeroCalibrationSkip(int32_km inInstrumentNo, CMMISDK_OnOff* outSkip);
	error_km KMAPI CMMISDK_SetDateTime(int32_km inInstrumentNo, const CMMISDK_DateTime *inDate);
	error_km KMAPI CMMISDK_SetDateFormat(int32_km inInstrumentNo, CMMISDK_DateFormat inFormat);
	error_km KMAPI CMMISDK_GetDateFormat(int32_km inInstrumentNo, CMMISDK_DateFormat* outFormat);
	error_km KMAPI CMMISDK_SetLanguage(int32_km inInstrumentNo, CMMISDK_Language inLanguage);
	error_km KMAPI CMMISDK_GetLanguage(int32_km inInstrumentNo, CMMISDK_Language* outLanguage);
	error_km KMAPI CMMISDK_SetPowerSaving(int32_km inInstrumentNo, int32_km inPowerSaving);
	error_km KMAPI CMMISDK_GetPowerSaving(int32_km inInstrumentNo, int32_km* outPowerSaving);

	error_km KMAPI CMMISDK_ClearJobInfo(int32_km inInstrumentNo, int32_km inJobNum);
	error_km KMAPI CMMISDK_SetJobInfo(int32_km inInstrumentNo, int32_km inJobNum, const CMMISDK_JobInfo* inInfo);
	error_km KMAPI CMMISDK_GetJobInfo(int32_km inInstrumentNo, int32_km inJobNum, CMMISDK_JobInfo* outInfo);
	error_km KMAPI CMMISDK_GetJobStepType(int32_km inInstrumentNo, int32_km inJobNum, int32_km inStepNum, CMMISDK_JobStepType* outType);
	error_km KMAPI CMMISDK_SetJobStepForOperation(int32_km inInstrumentNo, int32_km inJobNum, int32_km inStepNum, const CMMISDK_JobStepOperation* inOperation);
	error_km KMAPI CMMISDK_GetJobStepForOperation(int32_km inInstrumentNo, int32_km inJobNum, int32_km inStepNum, CMMISDK_JobStepOperation* outOperation);
	error_km KMAPI CMMISDK_SetJobStepForResult(int32_km inInstrumentNo, int32_km inJobNum, int32_km inStepNum, const CMMISDK_JobStepResult* inResult);
	error_km KMAPI CMMISDK_GetJobStepForResult(int32_km inInstrumentNo, int32_km inJobNum, int32_km inStepNum, CMMISDK_JobStepResult* outResult);
	error_km KMAPI CMMISDK_SetJobImage(int32_km inInstrumentNo, int32_km inJobNum, int32_km inImageNum, const CMMISDK_JobImage* inImage);
	error_km KMAPI CMMISDK_GetJobImage(int32_km inInstrumentNo, int32_km inJobNum, int32_km inImageNum, CMMISDK_JobImage* outImage);
	error_km KMAPI CMMISDK_ResetSetting(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_ResetSettingAndData(int32_km inInstrumentNo);
	error_km KMAPI CMMISDK_SetFinderEnable(int32_km inInstrumentNo, CMMISDK_OnOff inEnable);
	error_km KMAPI CMMISDK_GetFinderImage(int32_km inInstrumentNo, CMMISDK_FinderImage* outImage);
	error_km KMAPI CMMISDK_GetMeasurementImage(int32_km inInstrumentNo, CMMISDK_FinderImage* outImage);
	error_km KMAPI CMMISDK_GetDetectedMask(int32_km inInstrumentNo, CMMISDK_MeasArea* outArea);

#if defined(__cplusplus)
}
#endif
