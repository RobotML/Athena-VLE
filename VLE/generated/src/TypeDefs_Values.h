
#ifndef _TypeDefs_Values_h_
#define _TypeDefs_Values_h_

// 
// Includes ----------------------------------------------------------------------
// 

#include "TypeDefs.h"
#include <vle/value.hpp>

using namespace vle;

//
namespace generated
{

//
// Data type definitions ----------------------------------------------------------
//

// -------------------------------------------------------- Pointer
// basic type Pointer	
value::Value* Pointer_toValue(const Pointer& _val);
Pointer Pointer_fromValue(const value::Value* _node, const Pointer& _initialValue = NULL);

		
// -------------------------------------------------------- String
// basic type String	
value::Value* String_toValue(const String& _val);
String String_fromValue(const value::Value* _node, const String& _initialValue = "");

		
// -------------------------------------------------------- Logical
// basic type Logical	
value::Value* Logical_toValue(const Logical& _val);
Logical Logical_fromValue(const value::Value* _node, const Logical& _initialValue = false);

		
// -------------------------------------------------------- Int
// basic type Int	
value::Value* Int_toValue(const Int& _val);
Int Int_fromValue(const value::Value* _node, const Int& _initialValue = 0);

		
// -------------------------------------------------------- Long
// basic type Long	
value::Value* Long_toValue(const Long& _val);
Long Long_fromValue(const value::Value* _node, const Long& _initialValue = 0);

		
// -------------------------------------------------------- Real
// basic type Real	
value::Value* Real_toValue(const Real& _val);
Real Real_fromValue(const value::Value* _node, const Real& _initialValue = 0);

		
// -------------------------------------------------------- Vec3
// Vec3 is an array of Real
value::Value* Vec3_toValue(const Vec3& _val);
void Vec3_fromValue(const value::Value* _node,Vec3& _val);
		
// -------------------------------------------------------- Vec5
// Vec5 is an array of Real
value::Value* Vec5_toValue(const Vec5& _val);
void Vec5_fromValue(const value::Value* _node,Vec5& _val);
		
// -------------------------------------------------------- VecX
// VecX is an array of Real
value::Value* VecX_toValue(const VecX& _val);
void VecX_fromValue(const value::Value* _node,VecX& _val);
		
// -------------------------------------------------------- gisement
// gisement is a Real
// Not processed
		
// -------------------------------------------------------- site
// site is a Real
// Not processed
		
// -------------------------------------------------------- VecOne
// VecOne is an array of gisement
value::Value* VecOne_toValue(const VecOne& _val);
void VecOne_fromValue(const value::Value* _node,VecOne& _val);
		
// -------------------------------------------------------- VecY
// VecY is an array of gisement
value::Value* VecY_toValue(const VecY& _val);
void VecY_fromValue(const value::Value* _node,VecY& _val);
		
// -------------------------------------------------------- test3
// test3 is a structure
value::Value* test3_toValue(const test3& _val) ;
void test3_fromValue(const value::Value* _node, test3& _val);
		
// -------------------------------------------------------- Ints
// Ints is a vector of Int
value::Value* Ints_toValue(const Ints& _val); 
void Ints_fromValue(const value::Value* _node, Ints& _val);
		
// -------------------------------------------------------- Longs
// Longs is a vector of Long
value::Value* Longs_toValue(const Longs& _val); 
void Longs_fromValue(const value::Value* _node, Longs& _val);
		
// -------------------------------------------------------- Reals
// Reals is a vector of Real
value::Value* Reals_toValue(const Reals& _val); 
void Reals_fromValue(const value::Value* _node, Reals& _val);
		
// -------------------------------------------------------- EntityType
// basic type EntityType	
value::Value* EntityType_toValue(const EntityType& _val);
EntityType EntityType_fromValue(const value::Value* _node, const EntityType& _initialValue = ABSTRACT_ENTITY);

		
// -------------------------------------------------------- NetworkID
// basic type NetworkID	
value::Value* NetworkID_toValue(const NetworkID& _val);
NetworkID NetworkID_fromValue(const value::Value* _node, const NetworkID& _initialValue = INVALID_NETWORK);

		
// -------------------------------------------------------- SensorType
// basic type SensorType	
value::Value* SensorType_toValue(const SensorType& _val);
SensorType SensorType_fromValue(const value::Value* _node, const SensorType& _initialValue = INVALID_SENSOR_TYPE);

		
// -------------------------------------------------------- SensorFunction
// basic type SensorFunction	
value::Value* SensorFunction_toValue(const SensorFunction& _val);
SensorFunction SensorFunction_fromValue(const value::Value* _node, const SensorFunction& _initialValue = INVALID_SENSOR_FUNCTION);

		
// -------------------------------------------------------- EquipmentType
// basic type EquipmentType	
value::Value* EquipmentType_toValue(const EquipmentType& _val);
EquipmentType EquipmentType_fromValue(const value::Value* _node, const EquipmentType& _initialValue = PLATFORM);

		
// -------------------------------------------------------- EquipmentStatus
// EquipmentStatus is a structure
value::Value* EquipmentStatus_toValue(const EquipmentStatus& _val) ;
void EquipmentStatus_fromValue(const value::Value* _node, EquipmentStatus& _val);
		
// -------------------------------------------------------- EquipmentStatusList
// EquipmentStatusList is a map with key type Long and value type EquipmentStatus
value::Value* EquipmentStatusList_toValue(const EquipmentStatusList& _val);
void EquipmentStatusList_fromValue(const value::Value* _node, EquipmentStatusList& _val);
		
// -------------------------------------------------------- ExternalInput
// ExternalInput is a structure
value::Value* ExternalInput_toValue(const ExternalInput& _val) ;
void ExternalInput_fromValue(const value::Value* _node, ExternalInput& _val);
		
// -------------------------------------------------------- vExternalInput
// vExternalInput is a vector of ExternalInput
value::Value* vExternalInput_toValue(const vExternalInput& _val); 
void vExternalInput_fromValue(const value::Value* _node, vExternalInput& _val);
		
// -------------------------------------------------------- ExternalInputListForOneTypeOfEquipment
// ExternalInputListForOneTypeOfEquipment is a map with key type EquipmentType and value type vExternalInput
value::Value* ExternalInputListForOneTypeOfEquipment_toValue(const ExternalInputListForOneTypeOfEquipment& _val);
void ExternalInputListForOneTypeOfEquipment_fromValue(const value::Value* _node, ExternalInputListForOneTypeOfEquipment& _val);
		
// -------------------------------------------------------- ExternalInputList
// ExternalInputList is a map with key type Long and value type ExternalInputListForOneTypeOfEquipment
value::Value* ExternalInputList_toValue(const ExternalInputList& _val);
void ExternalInputList_fromValue(const value::Value* _node, ExternalInputList& _val);
		
// -------------------------------------------------------- EntityState
// EntityState is a structure
value::Value* EntityState_toValue(const EntityState& _val) ;
void EntityState_fromValue(const value::Value* _node, EntityState& _val);
		
// -------------------------------------------------------- EntityStates
// EntityStates is a map with key type Long and value type EntityState
value::Value* EntityStates_toValue(const EntityStates& _val);
void EntityStates_fromValue(const value::Value* _node, EntityStates& _val);
		
// -------------------------------------------------------- EmitterBeam
// EmitterBeam is a structure
value::Value* EmitterBeam_toValue(const EmitterBeam& _val) ;
void EmitterBeam_fromValue(const value::Value* _node, EmitterBeam& _val);
		
// -------------------------------------------------------- Beams
// Beams is a vector of EmitterBeam
value::Value* Beams_toValue(const Beams& _val); 
void Beams_fromValue(const value::Value* _node, Beams& _val);
		
// -------------------------------------------------------- EmitterState
// EmitterState is a structure
value::Value* EmitterState_toValue(const EmitterState& _val) ;
void EmitterState_fromValue(const value::Value* _node, EmitterState& _val);
		
// -------------------------------------------------------- EmitterStates
// EmitterStates is a vector of EmitterState
value::Value* EmitterStates_toValue(const EmitterStates& _val); 
void EmitterStates_fromValue(const value::Value* _node, EmitterStates& _val);
		
// -------------------------------------------------------- JammerState
// JammerState is a structure
value::Value* JammerState_toValue(const JammerState& _val) ;
void JammerState_fromValue(const value::Value* _node, JammerState& _val);
		
// -------------------------------------------------------- JammerStates
// JammerStates is a vector of JammerState
value::Value* JammerStates_toValue(const JammerStates& _val); 
void JammerStates_fromValue(const value::Value* _node, JammerStates& _val);
		
// -------------------------------------------------------- Detonation
// Detonation is a structure
value::Value* Detonation_toValue(const Detonation& _val) ;
void Detonation_fromValue(const value::Value* _node, Detonation& _val);
		
// -------------------------------------------------------- Detonations
// Detonations is a map with key type Long and value type Detonation
value::Value* Detonations_toValue(const Detonations& _val);
void Detonations_fromValue(const value::Value* _node, Detonations& _val);
		
// -------------------------------------------------------- EnvironmentInteractions
// EnvironmentInteractions is a structure
value::Value* EnvironmentInteractions_toValue(const EnvironmentInteractions& _val) ;
void EnvironmentInteractions_fromValue(const value::Value* _node, EnvironmentInteractions& _val);
		
// -------------------------------------------------------- AngularBounds
// AngularBounds is a structure
value::Value* AngularBounds_toValue(const AngularBounds& _val) ;
void AngularBounds_fromValue(const value::Value* _node, AngularBounds& _val);
		
// -------------------------------------------------------- AngularDelta
// AngularDelta is a structure
value::Value* AngularDelta_toValue(const AngularDelta& _val) ;
void AngularDelta_fromValue(const value::Value* _node, AngularDelta& _val);
		
// -------------------------------------------------------- SensorAngularBounds
// SensorAngularBounds is a vector of AngularBounds
value::Value* SensorAngularBounds_toValue(const SensorAngularBounds& _val); 
void SensorAngularBounds_fromValue(const value::Value* _node, SensorAngularBounds& _val);
		
// -------------------------------------------------------- SensorAngularDelta
// SensorAngularDelta is a vector of AngularDelta
value::Value* SensorAngularDelta_toValue(const SensorAngularDelta& _val); 
void SensorAngularDelta_fromValue(const value::Value* _node, SensorAngularDelta& _val);
		
// -------------------------------------------------------- JammerDefinition
// JammerDefinition is a structure
value::Value* JammerDefinition_toValue(const JammerDefinition& _val) ;
void JammerDefinition_fromValue(const value::Value* _node, JammerDefinition& _val);
		
// -------------------------------------------------------- EmitterJammed
// EmitterJammed is a structure
value::Value* EmitterJammed_toValue(const EmitterJammed& _val) ;
void EmitterJammed_fromValue(const value::Value* _node, EmitterJammed& _val);
		
// -------------------------------------------------------- EmitterJammList
// EmitterJammList is a vector of EmitterJammed
value::Value* EmitterJammList_toValue(const EmitterJammList& _val); 
void EmitterJammList_fromValue(const value::Value* _node, EmitterJammList& _val);
		
// -------------------------------------------------------- JammerStatus
// JammerStatus is a structure
value::Value* JammerStatus_toValue(const JammerStatus& _val) ;
void JammerStatus_fromValue(const value::Value* _node, JammerStatus& _val);
		
// -------------------------------------------------------- JammersStatus
// JammersStatus is a map with key type Long and value type JammerStatus
value::Value* JammersStatus_toValue(const JammersStatus& _val);
void JammersStatus_fromValue(const value::Value* _node, JammersStatus& _val);
		
// -------------------------------------------------------- JammOp
// JammOp is a structure
value::Value* JammOp_toValue(const JammOp& _val) ;
void JammOp_fromValue(const value::Value* _node, JammOp& _val);
		
// -------------------------------------------------------- JammOperationList
// JammOperationList is a vector of JammOp
value::Value* JammOperationList_toValue(const JammOperationList& _val); 
void JammOperationList_fromValue(const value::Value* _node, JammOperationList& _val);
		
// -------------------------------------------------------- JammerOrder
// JammerOrder is a structure
value::Value* JammerOrder_toValue(const JammerOrder& _val) ;
void JammerOrder_fromValue(const value::Value* _node, JammerOrder& _val);
		
// -------------------------------------------------------- JammersOrders
// JammersOrders is a map with key type Long and value type JammerOrder
value::Value* JammersOrders_toValue(const JammersOrders& _val);
void JammersOrders_fromValue(const value::Value* _node, JammersOrders& _val);
		
// -------------------------------------------------------- JammerDefinitions
// JammerDefinitions is a map with key type Long and value type JammerDefinition
value::Value* JammerDefinitions_toValue(const JammerDefinitions& _val);
void JammerDefinitions_fromValue(const value::Value* _node, JammerDefinitions& _val);
		
// -------------------------------------------------------- LocalisationInit
// LocalisationInit is a structure
value::Value* LocalisationInit_toValue(const LocalisationInit& _val) ;
void LocalisationInit_fromValue(const value::Value* _node, LocalisationInit& _val);
		
// -------------------------------------------------------- LocalisationConst
// LocalisationConst is a structure
value::Value* LocalisationConst_toValue(const LocalisationConst& _val) ;
void LocalisationConst_fromValue(const value::Value* _node, LocalisationConst& _val);
		
// -------------------------------------------------------- LocalisationState
// LocalisationState is a structure
value::Value* LocalisationState_toValue(const LocalisationState& _val) ;
void LocalisationState_fromValue(const value::Value* _node, LocalisationState& _val);
		
// -------------------------------------------------------- LocalisationError
// LocalisationError is a structure
value::Value* LocalisationError_toValue(const LocalisationError& _val) ;
void LocalisationError_fromValue(const value::Value* _node, LocalisationError& _val);
		
// -------------------------------------------------------- LocalisationEquipmentState
// LocalisationEquipmentState is a structure
value::Value* LocalisationEquipmentState_toValue(const LocalisationEquipmentState& _val) ;
void LocalisationEquipmentState_fromValue(const value::Value* _node, LocalisationEquipmentState& _val);
		
// -------------------------------------------------------- LocDefinitions
// LocDefinitions is a map with key type Long and value type LocalisationConst
value::Value* LocDefinitions_toValue(const LocDefinitions& _val);
void LocDefinitions_fromValue(const value::Value* _node, LocDefinitions& _val);
		
// -------------------------------------------------------- Waypoint
// Waypoint is a structure
value::Value* Waypoint_toValue(const Waypoint& _val) ;
void Waypoint_fromValue(const value::Value* _node, Waypoint& _val);
		
// -------------------------------------------------------- NavigationPts
// NavigationPts is a vector of Waypoint
value::Value* NavigationPts_toValue(const NavigationPts& _val); 
void NavigationPts_fromValue(const value::Value* _node, NavigationPts& _val);
		
// -------------------------------------------------------- FlightConfig
// FlightConfig is a structure
value::Value* FlightConfig_toValue(const FlightConfig& _val) ;
void FlightConfig_fromValue(const value::Value* _node, FlightConfig& _val);
		
// -------------------------------------------------------- NavigationUpdate
// NavigationUpdate is a structure
value::Value* NavigationUpdate_toValue(const NavigationUpdate& _val) ;
void NavigationUpdate_fromValue(const value::Value* _node, NavigationUpdate& _val);
		
// -------------------------------------------------------- NavigationState
// NavigationState is a structure
value::Value* NavigationState_toValue(const NavigationState& _val) ;
void NavigationState_fromValue(const value::Value* _node, NavigationState& _val);
		
// -------------------------------------------------------- SStateVector
// SStateVector is a structure
value::Value* SStateVector_toValue(const SStateVector& _val) ;
void SStateVector_fromValue(const value::Value* _node, SStateVector& _val);
		
// -------------------------------------------------------- SensorTechno
// SensorTechno is a structure
value::Value* SensorTechno_toValue(const SensorTechno& _val) ;
void SensorTechno_fromValue(const value::Value* _node, SensorTechno& _val);
		
// -------------------------------------------------------- SensorTechnos
// SensorTechnos is a vector of SensorTechno
value::Value* SensorTechnos_toValue(const SensorTechnos& _val); 
void SensorTechnos_fromValue(const value::Value* _node, SensorTechnos& _val);
		
// -------------------------------------------------------- SensorDefinition
// SensorDefinition is a structure
value::Value* SensorDefinition_toValue(const SensorDefinition& _val) ;
void SensorDefinition_fromValue(const value::Value* _node, SensorDefinition& _val);
		
// -------------------------------------------------------- RadarDefinition
// RadarDefinition is a structure
value::Value* RadarDefinition_toValue(const RadarDefinition& _val) ;
void RadarDefinition_fromValue(const value::Value* _node, RadarDefinition& _val);
		
// -------------------------------------------------------- EsmDefinition
// EsmDefinition is a structure
value::Value* EsmDefinition_toValue(const EsmDefinition& _val) ;
void EsmDefinition_fromValue(const value::Value* _node, EsmDefinition& _val);
		
// -------------------------------------------------------- SensorPlot
// SensorPlot is a structure
value::Value* SensorPlot_toValue(const SensorPlot& _val) ;
void SensorPlot_fromValue(const value::Value* _node, SensorPlot& _val);
		
// -------------------------------------------------------- SensorImage
// SensorImage is a structure
value::Value* SensorImage_toValue(const SensorImage& _val) ;
void SensorImage_fromValue(const value::Value* _node, SensorImage& _val);
		
// -------------------------------------------------------- SensorImages
// SensorImages is a vector of SensorImage
value::Value* SensorImages_toValue(const SensorImages& _val); 
void SensorImages_fromValue(const value::Value* _node, SensorImages& _val);
		
// -------------------------------------------------------- SensorPlotVector
// SensorPlotVector is a vector of SensorPlot
value::Value* SensorPlotVector_toValue(const SensorPlotVector& _val); 
void SensorPlotVector_fromValue(const value::Value* _node, SensorPlotVector& _val);
		
// -------------------------------------------------------- SensorTrack
// SensorTrack is a structure
value::Value* SensorTrack_toValue(const SensorTrack& _val) ;
void SensorTrack_fromValue(const value::Value* _node, SensorTrack& _val);
		
// -------------------------------------------------------- SensorTracks
// SensorTracks is a map with key type Long and value type SensorTrack
value::Value* SensorTracks_toValue(const SensorTracks& _val);
void SensorTracks_fromValue(const value::Value* _node, SensorTracks& _val);
		
// -------------------------------------------------------- SensorStatus
// SensorStatus is a structure
value::Value* SensorStatus_toValue(const SensorStatus& _val) ;
void SensorStatus_fromValue(const value::Value* _node, SensorStatus& _val);
		
// -------------------------------------------------------- SensorsStatus
// SensorsStatus is a map with key type Long and value type SensorStatus
value::Value* SensorsStatus_toValue(const SensorsStatus& _val);
void SensorsStatus_fromValue(const value::Value* _node, SensorsStatus& _val);
		
// -------------------------------------------------------- SensorOrder
// SensorOrder is a structure
value::Value* SensorOrder_toValue(const SensorOrder& _val) ;
void SensorOrder_fromValue(const value::Value* _node, SensorOrder& _val);
		
// -------------------------------------------------------- SensorOrders
// SensorOrders is a map with key type Long and value type SensorOrder
value::Value* SensorOrders_toValue(const SensorOrders& _val);
void SensorOrders_fromValue(const value::Value* _node, SensorOrders& _val);
		
// -------------------------------------------------------- SGD
// SGD is a structure
value::Value* SGD_toValue(const SGD& _val) ;
void SGD_fromValue(const value::Value* _node, SGD& _val);
		
// -------------------------------------------------------- SensorMemory
// SensorMemory is a map with key type Long and value type SGD
value::Value* SensorMemory_toValue(const SensorMemory& _val);
void SensorMemory_fromValue(const value::Value* _node, SensorMemory& _val);
		
// -------------------------------------------------------- SensorDefinitions
// SensorDefinitions is a map with key type Long and value type SensorDefinition
value::Value* SensorDefinitions_toValue(const SensorDefinitions& _val);
void SensorDefinitions_fromValue(const value::Value* _node, SensorDefinitions& _val);
		
// -------------------------------------------------------- SAElementStatus
// SAElementStatus is a structure
value::Value* SAElementStatus_toValue(const SAElementStatus& _val) ;
void SAElementStatus_fromValue(const value::Value* _node, SAElementStatus& _val);
		
// -------------------------------------------------------- SAElementStatusList
// SAElementStatusList is a map with key type Long and value type SAElementStatus
value::Value* SAElementStatusList_toValue(const SAElementStatusList& _val);
void SAElementStatusList_fromValue(const value::Value* _node, SAElementStatusList& _val);
		
// -------------------------------------------------------- SAElementOrder
// SAElementOrder is a structure
value::Value* SAElementOrder_toValue(const SAElementOrder& _val) ;
void SAElementOrder_fromValue(const value::Value* _node, SAElementOrder& _val);
		
// -------------------------------------------------------- SAElementOrderList
// SAElementOrderList is a map with key type Long and value type SAElementOrder
value::Value* SAElementOrderList_toValue(const SAElementOrderList& _val);
void SAElementOrderList_fromValue(const value::Value* _node, SAElementOrderList& _val);
		
// -------------------------------------------------------- SASystemState
// SASystemState is a structure
value::Value* SASystemState_toValue(const SASystemState& _val) ;
void SASystemState_fromValue(const value::Value* _node, SASystemState& _val);
		
// -------------------------------------------------------- FlightData
// FlightData is a structure
value::Value* FlightData_toValue(const FlightData& _val) ;
void FlightData_fromValue(const value::Value* _node, FlightData& _val);
		
// -------------------------------------------------------- NavigationData
// NavigationData is a structure
value::Value* NavigationData_toValue(const NavigationData& _val) ;
void NavigationData_fromValue(const value::Value* _node, NavigationData& _val);
		
// -------------------------------------------------------- NetworkDefinition
// NetworkDefinition is a structure
value::Value* NetworkDefinition_toValue(const NetworkDefinition& _val) ;
void NetworkDefinition_fromValue(const value::Value* _node, NetworkDefinition& _val);
		
// -------------------------------------------------------- NetworkMessagePrivateHeader
// NetworkMessagePrivateHeader is a structure
value::Value* NetworkMessagePrivateHeader_toValue(const NetworkMessagePrivateHeader& _val) ;
void NetworkMessagePrivateHeader_fromValue(const value::Value* _node, NetworkMessagePrivateHeader& _val);
		
// -------------------------------------------------------- NetworkMessageUserHeader
// NetworkMessageUserHeader is a structure
value::Value* NetworkMessageUserHeader_toValue(const NetworkMessageUserHeader& _val) ;
void NetworkMessageUserHeader_fromValue(const value::Value* _node, NetworkMessageUserHeader& _val);
		
// -------------------------------------------------------- NetworkMessageUserData
///
/// ERROR NetworkMessageUserData is unrecognized by the generator - org.eclipse.emf.ecore.impl.EClassImpl@1cd6b3c (name: unionType) (instanceClassName: null) (abstract: false, interface: false)
///
		
// -------------------------------------------------------- NetworkMessage
// NetworkMessage is a structure
value::Value* NetworkMessage_toValue(const NetworkMessage& _val) ;
void NetworkMessage_fromValue(const value::Value* _node, NetworkMessage& _val);
		
// -------------------------------------------------------- NetworkMessageDeliveryReport
// NetworkMessageDeliveryReport is a map with key type Long and value type Long
value::Value* NetworkMessageDeliveryReport_toValue(const NetworkMessageDeliveryReport& _val);
void NetworkMessageDeliveryReport_fromValue(const value::Value* _node, NetworkMessageDeliveryReport& _val);
		
// -------------------------------------------------------- NetworkMessageDeliveryReports
// NetworkMessageDeliveryReports is a map with key type Long and value type NetworkMessageDeliveryReport
value::Value* NetworkMessageDeliveryReports_toValue(const NetworkMessageDeliveryReports& _val);
void NetworkMessageDeliveryReports_fromValue(const value::Value* _node, NetworkMessageDeliveryReports& _val);
		
// -------------------------------------------------------- NetworkList
// NetworkList is a map with key type Long and value type Long
value::Value* NetworkList_toValue(const NetworkList& _val);
void NetworkList_fromValue(const value::Value* _node, NetworkList& _val);
		
// -------------------------------------------------------- NetworkMessageList
// NetworkMessageList is a vector of NetworkMessage
value::Value* NetworkMessageList_toValue(const NetworkMessageList& _val); 
void NetworkMessageList_fromValue(const value::Value* _node, NetworkMessageList& _val);
		
// -------------------------------------------------------- NetworkDefinitions
// NetworkDefinitions is a map with key type Long and value type NetworkDefinition
value::Value* NetworkDefinitions_toValue(const NetworkDefinitions& _val);
void NetworkDefinitions_fromValue(const value::Value* _node, NetworkDefinitions& _val);
		
// -------------------------------------------------------- test
// test is a structure
value::Value* test_toValue(const test& _val) ;
void test_fromValue(const value::Value* _node, test& _val);
		
// -------------------------------------------------------- TestMatlabStruct2
// TestMatlabStruct2 is a structure
value::Value* TestMatlabStruct2_toValue(const TestMatlabStruct2& _val) ;
void TestMatlabStruct2_fromValue(const value::Value* _node, TestMatlabStruct2& _val);
		
// -------------------------------------------------------- TestMatlabStruct2List
// TestMatlabStruct2List is a vector of TestMatlabStruct2
value::Value* TestMatlabStruct2List_toValue(const TestMatlabStruct2List& _val); 
void TestMatlabStruct2List_fromValue(const value::Value* _node, TestMatlabStruct2List& _val);
		
// -------------------------------------------------------- TestMatlabStruct
// TestMatlabStruct is a structure
value::Value* TestMatlabStruct_toValue(const TestMatlabStruct& _val) ;
void TestMatlabStruct_fromValue(const value::Value* _node, TestMatlabStruct& _val);
		
// -------------------------------------------------------- TestJavaStruct2
// TestJavaStruct2 is a structure
value::Value* TestJavaStruct2_toValue(const TestJavaStruct2& _val) ;
void TestJavaStruct2_fromValue(const value::Value* _node, TestJavaStruct2& _val);
		
// -------------------------------------------------------- TestJavaStruct2List
// TestJavaStruct2List is a vector of TestJavaStruct2
value::Value* TestJavaStruct2List_toValue(const TestJavaStruct2List& _val); 
void TestJavaStruct2List_fromValue(const value::Value* _node, TestJavaStruct2List& _val);
		
// -------------------------------------------------------- TestJavaStruct
// TestJavaStruct is a structure
value::Value* TestJavaStruct_toValue(const TestJavaStruct& _val) ;
void TestJavaStruct_fromValue(const value::Value* _node, TestJavaStruct& _val);
		

//
// --------------------------------------------------------------------------------
//

} // eof namespace generated

#endif


